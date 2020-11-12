#!/usr/bin/python3

import sys, re
from copy        import deepcopy
from tempfile    import NamedTemporaryFile
from collections import defaultdict
from lxml        import etree
from pycparser   import c_parser, c_ast, c_generator, parse_file

# TODO:
# [x] constness on methods and return types
# [ ] also provide const methods for non-const....
# [ ] *EatName* functions
# [ ] generate templated free-functions
# [ ] generate copy/move constructors
# [ ] Overloads: func1(arg1), func2(arg1, arg2) -> func(arg1), func(arg1, arg2)
# [ ] Overloads: func(const char*) -> func(const char*), func(std::string)
# [ ] sometimes structs/char* is reallocated! rebind cobj then! (it seems that this only applies to char*?!)
# [ ] sometimes char* is reallocated but only if it differs!
# [ ] Error checking
# [ ] va_args handling?

# =============================================================================
# Main code ===================================================================
# =============================================================================

class LibXML2_Function():
    ''' Data class that ties all available information about a function together '''

    __slots__ = ('doc', 'ast', 'own', 'this')
    def __init__(self, **kw):
        for s in self.__slots__: setattr(self, s, kw.get(s, None))

    def __repr__(self):
        return repr(self.doc)

class LibXML2_Class():
    __slots__ = ('struct_type', 'functions', 'type_dependencies')
    def __init__(self, struct_type=None):
        self.struct_type        = struct_type
        self.functions          = []
        self.type_dependencies  = set()

class Converter():
    def __init__(self):
        self.api_xml_file = 'doc/libxml2-api.xml'
        self.header_files = []
        self.funcs        = defaultdict(LibXML2_Function)
        self.ast          = None
        self.meta         = None

    def run(self):
        self.read_api_xml()
        self.parse_header_files()
        self.add_ast_to_functions()
        self.other_stuff()

    def read_api_xml(self):
        for section in etree.parse(self.api_xml_file).getroot():
            if section.tag == 'symbols':
                for symbol in section:
                    if symbol.tag == 'function':
                        self.funcs[symbol.attrib['name']].doc = API_Doc_Function.from_xmlnode(symbol)
            elif section.tag == 'files':
                for file in section:
                    self.header_files.append(file.attrib['name'])

    def parse_header_files(self):
        fh = NamedTemporaryFile('w', prefix='libxml-cpp', suffix='.h')

        for f in self.header_files:
            fh.write('#include <libxml/%s.h>\n' % f)
        fh.flush()

        self.ast = parse_file(fh.name, use_cpp=True,
            cpp_path='gcc',
            cpp_args=[
            '-E',
            '-D__attribute__(x)=',
            '-I.',
            '-Ifake_libc_include',
            '-I/usr/include/libxml2',
            # '-nostdinc', '-undef', '-I/usr/include',
        ])

        self.meta = Meta(self.ast)

    def add_ast_to_functions(self):
        class FuncDefVisitor(c_ast.NodeVisitor):
            def visit_FuncDecl(_, node):
                self.funcs[AST_Get_Declname(node)].ast = node
        FuncDefVisitor().visit(self.ast)

    def other_stuff(self):
        self.funcs = list(self.funcs.values())

        # Drop functions that don't have ast
        self.missing_asts, self.funcs = partition(self.funcs, lambda f: not f.ast)

        # Drop functions that don't have doc
        self.missing_docs, self.funcs = partition(self.funcs, lambda f: not f.doc)

        # Functions inside the 'xmlstring' module are an edge case.
        # They are the only functions that don't operate on a pointer to struct.
        # Keeping them would increase complexity of the code generation, so we drop them.
        self.char_funcs, self.funcs = partition(self.funcs, lambda f: f.doc.module == 'xmlstring')

        # Free() functions contain 'Free' and have one arg
        self.free_funcs, self.funcs = partition(self.funcs,
            lambda f: 'Free' in f.doc.name and len(f.doc.args) == 1)

        for f in self.funcs:
            # Own functions return Ptr
            if AST_Is_Ptr_To_NonConst(f.ast.type, self.meta) and (
               contains(f.doc.name, 'Create', 'New', 'Copy') or
               contains(f.doc.returns.info, 'newly created', 'a new', 'the new', 'the resulting document tree')):
                f.own = True

            # If we find a struct pointer named 'cur' use it as 'this' ...
            for i, arg in enumerate(f.ast.args.params):
                if AST_Is_Ptr_To_Struct(arg, self.meta) and arg.name == 'cur':
                    f.this = i
                    break

            # ... else try to use the first arg as 'this' pointer
            if f.this is None:
                if len(f.doc.args) and AST_Is_Ptr_To_Struct(f.ast.args.params[0], self.meta):
                    f.this = 0


        # Bind functions to a class depending on return type / this parameter
        klasses_ = defaultdict(LibXML2_Class)
        for f in self.funcs:
            if f.this is None:
                if f.own:
                    # No THIS but returns an owning ptr -> bind it to class of owning ptr
                    try:
                        klasses_[AST_Find_Struct_Name(f.ast.type, self.meta)].functions.append(f)
                    except:
                        #raise Exception(f.ast)
                        pass # TODO
            else:
                try:
                    klasses_[AST_Find_Struct_Name(f.ast.args.params[f.this], self.meta)].functions.append(f)
                except:
                    pass #print(f.ast.args.params[f.this])


        # Add struct dependencies to klass
        klasses = list()
        for name, klass in klasses_.items():
            klass.struct_type = name
            for function in klass.functions:
                klass.type_dependencies |= AST_Find_All_Struct_Names(function.ast, self.meta)
            klass.type_dependencies.discard(name)
            klasses.append(klass)

        # Blah
        klasses.sort(key=lambda k: len(k.type_dependencies))

        #for k in klasses: print(k.struct_type, k.type_dependencies)

        for e in klasses:
            write_class(self, e)

def strip_xml_prefix(string):
    return re.sub('^(x|ht)ml', '', string.lstrip('_'))

def functionName_to_methodName(f, struct_type):
    f = strip_xml_prefix(f)
    struct_type = strip_xml_prefix(struct_type)

    for part in split_title_case(struct_type):
        if f.startswith(part) and f[len(part)].isupper():
            f = f[len(part):]

    return firstToLower(f)

def write_class(self, klass):
    # Sort alphabetically by function name
    klass.functions.sort(key=lambda f: f.doc.name)

    # Group functions by preprocessor conditions
    conditions = defaultdict(list)
    for f in klass.functions:
        conditions[f.doc.cond].append(f)

    name = firstToUpper(strip_xml_prefix(klass.struct_type))
    print('template<int owns = 0>')
    print('class %s {' % name)
    print(' %s* cobj;' % klass.struct_type)
    print('public:')
    print(' inline ~%s { if (own) free(cobj), cobj = NULL; }' % name)
    print(' inline %s(c_ptr) : cobj(ptr) {}' % name)
    print(' inline %s(%s<0> o) : cobj(o.cobj) {}' % (name, name))
    print(' inline %s(%s<1> o) : cobj(o.cobj) { if (owns) {} }' % (name, name))
    print(' inline %s<0> release() { }' % name) # TODO...

    # First, functions that have no preprocessor conditions
    for f in conditions.pop(None, []):
        print(' ', write_method(f, klass.struct_type, self.meta))

    # Second, functions that have preprocessor conditions
    for condition, functions in conditions.items():
        print('#if', condition)
        for f in functions: print(' ', write_method(f, klass.struct_type, self.meta))
        print('#endif')

    print('};\n')

def make_return_type(ast, owns, meta):
    normalized = meta.normalize_type(ast)
    if type(normalized.node) == c_ast.PtrDecl:
        if type(normalized.next.node) == c_ast.Struct:
            name = strip_xml_prefix(normalized.next.node.name)
            return '%s<%d>' % (name, bool(owns))

    ast = deepcopy(ast)
    class ClearDeclname(c_ast.NodeVisitor):
        def visit_TypeDecl(_, node):
            node.declname = ''
    ClearDeclname().visit(ast)
    name = ast_to_c(c_ast.Typename('', [], ast))
    return strip_xml_prefix(name).replace('Ptr','')

def write_method(function, struct_type, meta):
    ''' Generate the code for a wrapped function '''
    s  = 'inline '
    if function.this is None:
        s += 'static '
    s += make_return_type(function.ast.type, function.own, meta)
    s += ' '
    s += functionName_to_methodName(function.doc.name, struct_type)
    s += '('
    s += ', '.join([str(arg) for i, arg in enumerate(function.doc.args) if i != function.this])
    s += ')'
    if function.this is not None and AST_Is_Ptr_To_Const(function.ast.args.params[function.this], meta):
        s += ' const'
    s += ' { '
    if function.doc.returns.type != 'void':
        s += 'return '
    s += function.doc.name
    s += '('
    s += ', '.join(['cobj' if i == function.this else arg.name for i, arg in enumerate(function.doc.args)])
    s += '); '
    s += '}'
    return s

# =============================================================================
# Util ========================================================================
# =============================================================================

def log(*a, **kw):
    print(*a, **kw, file=sys.stderr)

def partition(iterable, predicate):
    r = ([],[])
    for i in iterable:
        r[not bool(predicate(i))].append(i)
    return r

def contains(string, *search):
    for s in search:
        if s in string:
            return True

def split_title_case(string):
    ''' 'fooBarBaz' -> ['foo', 'Bar', 'Baz'] '''
    part = ''
    for c in string:
        if c.isupper():
            if part:
                yield part
            part = c
        else:
            part += c
    if part:
        yield part

firstToLower = lambda s: s[0].lower() + s[1:]
firstToUpper = lambda s: s[0].upper() + s[1:]

ast_to_c = c_generator.CGenerator().visit

# =============================================================================
# LibXML2 API Documentation Data Classes ======================================
# =============================================================================

class API_Doc_Function():
    __slots__ = ('name', 'file', 'module', 'cond', 'info', 'returns', 'args')
    def __init__(self, **kw):
        for k, v in kw.items(): setattr(self, k, v)

    def __repr__(self):
        return "%s %s %s" % (self.returns, self.name, self.args)

    @staticmethod
    def from_xmlnode(node):
        r = API_Doc_Function(
            name     = node.attrib['name'],
            file     = node.attrib['file'],
            module   = node.attrib['module'],
            cond     = None,
            info     = None,
            returns  = None,
            args     = [])

        for n in node:
            if   n.tag == 'cond':   r.cond = n.text
            elif n.tag == 'info':   r.info = n.text
            elif n.tag == 'arg':    r.args.append(API_Doc_Arg.from_xmlnode(n))
            elif n.tag == 'return': r.returns = API_Doc_Return.from_xmlnode(n)
        return r

class API_Doc_Arg():
    __slots__ = ('name', 'type', 'info')
    def __init__(self, **kw):
        for k, v in kw.items(): setattr(self, k, v)

    def __repr__(self):
        return "%s %s" % (self.type, self.name)

    @staticmethod
    def from_xmlnode(node):
        return API_Doc_Arg(
            name=node.attrib['name'],
            type=node.attrib['type'],
            info=node.attrib['info'])

class API_Doc_Return():
    __slots__ = ('type', 'info')
    def __init__(self, **kw):
        for k, v in kw.items(): setattr(self, k, v)

    def __repr__(self):
        return self.type

    @staticmethod
    def from_xmlnode(node):
        return API_Doc_Return(
            type=node.attrib.get('type'),
            info=node.attrib.get('info',''))

# =============================================================================
# AST Stuff ===================================================================
# =============================================================================

class Meta(c_ast.NodeVisitor):
    def __init__(self, ast):
        self.typedefs = {}
        self.structs  = {}
        self.unions   = {}
        self.visit(ast)

    def visit_Struct(self, node):  self.structs[node.name]  = node
    def visit_Union(self, node):   self.unions[node.name]   = node
    def visit_Typedef(self, node): self.typedefs[node.name] = node

    def resolve_identifier(self, identifier):
        if len(identifier.names) == 1:
            name = identifier.names[0]
            if name in self.typedefs: return self.typedefs[name]
            if name in self.structs:  return self.structs[name]
            if name in self.unions:   return self.unions[name]
        return None

    def normalize_type(self, node):
        ''' Strips of empty node types and resolves typedefs '''
        return self._normalize_type(node, Result(None, []), set()).next

    def _normalize_type(self, node, result, quals):
        T = type(node)
        if T is c_ast.Decl:
            self._normalize_type(node.type, result, quals)
        elif T in (c_ast.Typedef, c_ast.TypeDecl, c_ast.Typename):
            self._normalize_type(node.type, result, quals | set(node.quals))
        elif T is c_ast.PtrDecl:
            result.next = Result(node, quals | set(node.quals))
            self._normalize_type(node.type, result.next, set())
        elif T is c_ast.IdentifierType:
            n = self.resolve_identifier(node)
            if n: self._normalize_type(n, result, quals)
            else: result.next = Result(node, quals)
        elif T in (c_ast.Struct, c_ast.Enum, c_ast.FuncDecl):
            result.next = Result(node, quals)
        elif T is c_ast.EllipsisParam:
            result.next = Result(node, set())
        else:
            raise Exception(node)
        return result

class Result(): # TODO rename
    def __init__(self, node, quals):
        self.node = node
        self.quals = quals
        self.next = None

    def clear_qualifiers(self):
        self.quals.clear()
        if self.next: self.next.clear_qualifiers()

    def __str__(self):
        x = ''
        if type(self.node) is c_ast.IdentifierType:
            x = ' '.join(self.node.names)
        elif type(self.node) is c_ast.Struct:
            x = self.node.name
        elif self.next:
            x = str(self.next)

        return '(%s %s %s)' % (type(self.node).__name__, ' '.join(self.quals), x)

    def __eq__(self, other):
        while self and other:
            if self.quals != other.quals:           return False
            if type(self.node) != type(other.node): return False
            t = type(self.node)
            if t is c_ast.Struct:
                if self.node.name != other.node.name: return False
            elif t is c_ast.IdentifierType:
                try:
                    if NormalizedIdentifier(self.node.names) != NormalizedIdentifier(other.node.names):
                        return False
                except:
                    if self.node.names != other.node.names:
                        return False
            self, other = self.next, other.next
        return True

    def __hash__(self):
        # TODO: Include qualifiers in hash value
        return id(type(self.node)) + hash(self.next)

class NormalizedIdentifier():
    __slots__ = ('signed', 'unsigned', 'char', 'short', 'long', 'int', 'float', 'double', 'void')
    def __init__(self, names):
        for name in self.__slots__:
            setattr(self, name, 0)
        for name in names:
            setattr(self, name, getattr(self, name) + 1)

    def __eq__(self, other):
        return (True
            and bool(self.unsigned) == bool(other.unsigned)
            and self.char           == other.char
            and self.float          == other.float
            and self.double         == other.double
            and self.void           == other.void
            and self.long           == other.long
            and bool(self.short)    == bool(other.short)

            # 'char'/'signed char' are distinct types
            and ((bool(self.signed) == bool(other.signed))
                or not self.char)

            # No need to compare 'int' if we have 'short' or 'long' set
            and ((bool(self.short + self.long) == bool(other.short + other.long))
                or self.int == other.int)
        )

    def __str__(self):
        l = []
        for name in self.__slots__:
            l.extend([name] * getattr(self, name))
        return ' '.join(l)

#print(NormalizedIdentifier(['unsigned','char']))
assert NormalizedIdentifier(['char'])            == NormalizedIdentifier(['char'])
assert NormalizedIdentifier(['unsigned','char']) != NormalizedIdentifier(['char'])
assert NormalizedIdentifier(['signed',  'char']) != NormalizedIdentifier(['char'])
assert NormalizedIdentifier(['short',   'int'])  == NormalizedIdentifier(['short'])
assert NormalizedIdentifier(['long',    'int'])  == NormalizedIdentifier(['long'])
assert NormalizedIdentifier(['signed'])          == NormalizedIdentifier(['int'])
assert NormalizedIdentifier(['unsigned'])        == NormalizedIdentifier(['unsigned', 'int'])

def AST_Find_All_Struct_Names(ast, meta):
    class Visitor(c_ast.NodeVisitor):
        def __init__(self):
            self.types = set()
        def visit_Struct(self, node):
            self.types.add(node.name)
        def visit_IdentifierType(self, node):
            node = meta.resolve_identifier(node)
            if node:
                self.visit(node)

    v = Visitor()
    v.visit(ast)
    return v.types

def AST_Find_Struct_Name(ast, meta):
    return AST_Find_All_Struct_Names(ast, meta).pop()

def AST_Get_Declname(node):
    T = type(node)
    if   T is c_ast.TypeDecl: return node.declname
    elif T is c_ast.FuncDecl: return AST_Get_Declname(node.type)
    elif T is c_ast.PtrDecl:  return AST_Get_Declname(node.type)
    raise

def AST_Is_Ptr_To_Const(ast, meta):
    norm = meta.normalize_type(ast)
    return type(norm.node) is c_ast.PtrDecl and 'const' in norm.next.quals

def AST_Is_Ptr_To_NonConst(ast, meta):
    norm = meta.normalize_type(ast)
    return type(norm.node) is c_ast.PtrDecl and 'const' not in norm.next.quals

def AST_Is_Ptr_To_Struct(ast, meta):
    norm = meta.normalize_type(ast)
    return type(norm.node) is c_ast.PtrDecl and type(norm.next.node) is c_ast.Struct


if __name__ == "__main__":
    # ./doc/apibuild.py
    Converter().run()
