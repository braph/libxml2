#!/usr/bin/python3

import sys, re
from copy        import deepcopy
from collections import defaultdict
from lxml        import etree
from pycparser   import c_parser, c_ast, c_generator, parse_file

# TODO: sometimes structs/char* is reallocated! rebind cobj then!

# =============================================================================
# Util
# =============================================================================

def log(*a, **kw): print(*a, **kw, file=sys.stderr)
ast_to_c = c_generator.CGenerator().visit
def contains(string, *search):
    for s in search:
        if s in string:
            return True

#def Decl_to_c(node): return ast_to_c(node.args)

# =============================================================================
# LibXML2 API Documentation Data Classes
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

class LibXML2_Function():
    ''' Data class that ties all available information about a function together '''

    __slots__ = ('doc', 'ast', 'own', 'ignore', 'free', 'this')
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

# ./doc/apibuild.py
# free functions:  free in name and one param
# owned functions: create/new/copy and ptr return value
# functions: where to note the this parameter?

class Meta(c_ast.NodeVisitor):
    def __init__(self, ast):
        self.typedefs = {}
        self.structs  = {}
        self.unions   = {}
        self.visit(ast)

    def visit_Struct(self, node):  self.structs[node.name]  = node
    def visit_Union(self, node):   self.unions[node.name]   = node
    def visit_Typedef(self, node): self.typedefs[node.name] = node

    def resolve_identifier(self, name): # TODO use names[] array
        if name in self.typedefs: return self.typedefs[name]
        if name in self.structs:  return self.structs[name]
        if name in self.unions:   return self.unions[name]
        return None

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

def normalize(node, meta):
    return normalize_impl(node, meta, Result(None, []), set()).next

def normalize_impl(node, meta, result, quals):
    T = type(node)
    if T is c_ast.Decl:
        normalize_impl(node.type, meta, result, quals)
    elif T in (c_ast.Typedef, c_ast.TypeDecl, c_ast.Typename):
        normalize_impl(node.type, meta, result, quals | set(node.quals))
    elif T is c_ast.PtrDecl:
        result.next = Result(node, quals | set(node.quals))
        normalize_impl(node.type, meta, result.next, set())
    elif T is c_ast.IdentifierType:
        n = meta.resolve_identifier(node.names[0]) # TODO: node.names
        if n: normalize_impl(n, meta, result, quals)
        else: result.next = Result(node, quals)
    elif T in (c_ast.Struct, c_ast.Enum, c_ast.FuncDecl):
        result.next = Result(node, quals)
    elif T is c_ast.EllipsisParam:
        result.next = Result(node, quals) # TODO?
    else:
        raise Exception(node)
    return result

def FuncDecl_get_name(node): # TODO: rename
    typ = type(node)
    if   typ is c_ast.TypeDecl: return node.declname
    elif typ is c_ast.FuncDecl: return FuncDecl_get_name(node.type)
    elif typ is c_ast.PtrDecl:  return FuncDecl_get_name(node.type)
    raise

class NormalizedIdentifier():
    __slots__ = ('signed', 'unsigned', 'char', 'short', 'long', 'int', 'float', 'double', 'void')
    def __init__(self, names):
        for name in self.__slots__:
            setattr(self, name, 0)
        for name in names:
            setattr(self, name, getattr(self, name) + 1)

    def __eq__(self, other):
        eq = (
            bool(self.unsigned) == bool(other.unsigned) and
            self.char           == other.char           and
            self.float          == other.float          and
            self.double         == other.double         and
            self.void           == other.void           and
            self.long           == other.long           and
            bool(self.short)    == bool(other.short)
        )

        if self.char: # Special case: char has 3 distinct signed types
            eq &= (bool(self.signed) == bool(other.signed))

        eq &= ( # TODO?
            (self.int == other.int) or
            bool(self.short or self.long) == bool(other.short or other.long))

        return eq


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

def FuncDecl_param_count(node):
    return len(node.args.params)

def Decl_type(node):
    if type(node) == c_ast.PtrDecl:
        return Decl_type(node.type) + '*'
    elif type(node) == c_ast.TypeDecl:
        return node.type.names[0]
    else:
        raise
        return node
        return "?"

def Decl_name(node, default=None):
    return node.name if node.name else default

def show_func_defs(filename):
    funcs = {}

    # Step 1: Extract function documentation from libxml2-api.xml
    for section in etree.parse('doc/libxml2-api.xml').getroot():
        if section.tag == 'symbols':
            for symbol in section:
                if symbol.tag == 'function':
                    funcs[symbol.attrib['name']] = LibXML2_Function(
                        doc=API_Doc_Function.from_xmlnode(symbol))

    # Step 2: Parse header files
    ast = parse_file(filename, use_cpp=True,
        cpp_path='gcc',
        cpp_args=[
        '-E',
        '-D__attribute__(x)=',
        '-I.',
        '-Ifake_libc_include',
        '-I/usr/include/libxml2',
        # '-nostdinc', '-undef', '-I/usr/include',
    ])
    #print(ast_to_c(ast))
    #raise TODO
    meta = Meta(ast)

    # Step 3: Add AST to functions
    class FuncDefVisitor(c_ast.NodeVisitor):
        def visit_FuncDecl(self, node):
            name = FuncDecl_get_name(node)
            try:    funcs[name].ast = node
            except: log('Function not found in api.xml:', name)

    FuncDefVisitor().visit(ast)

    # Step 4: Drop functions that don't have the 'ast' attribute
    for name in list(funcs.keys()):
        if funcs[name].ast is None:
            funcs.pop(name)
            log('Function not found in headers:', name)

    # Step 5: ...
    for f in funcs.values():
        # Free() functions contain 'free' and have 1 arg [of Ptr type] TODO
        if 'Free' in f.doc.name and len(f.doc.args) == 1:
            f.free = True

        # Own functions return Ptr ... TODO 'not be freed'
        if contains(f.doc.returns.type, 'Ptr', '*') and (
           contains(f.doc.name, 'Create', 'New', 'Copy') or
           contains(f.doc.returns.info, 'newly created', 'a new', 'the new', 'the resulting document tree')):
            f.own = True

        # First argument should be a this pointer....
        #if len(f.doc.args) and contains(f.doc.args[0].type, 'Ptr', '*'):
        #    f.this = 0

        if len(f.doc.args):
            first_arg = normalize(f.ast.args.params[0], meta)
            if type(first_arg.node) is c_ast.PtrDecl:
                if type(first_arg.next.node) is c_ast.Struct:
                    f.this = 0
                elif type(first_arg.next.node) is c_ast.IdentifierType:
                    if NormalizedIdentifier(first_arg.next.node.names) == NormalizedIdentifier(['unsigned', 'char']):
                        f.this = 0

            #and type(normalize(f.ast.args.params[0], meta).node) is c_ast.PtrDecl:
            #f.this = 0

        # But 'cur' is better!
        for i, arg in enumerate(f.doc.args):
            if arg.name == 'cur':
                f.this = i
                break

    # We don't want to process free functions
    for name in list(funcs.keys()):
        if funcs[name].free:
            funcs.pop(name)

    # Collect all the ...
    klasses = defaultdict(LibXML2_Class)
    for f in funcs.values():
        return_type = normalize(f.ast.type, meta)
        return_type.clear_qualifiers()

        if f.this is None:
            if f.own:
                # No THIS but returns an owning ptr -> bind it to class of owning ptr
                klasses[return_type].functions.append(f)
                klasses[return_type].struct_type = return_type # TODO
        else:
            this_arg_type = normalize(f.ast.args.params[f.this], meta)
            this_arg_type.clear_qualifiers()
            klasses[this_arg_type].functions.append(f)
            klasses[this_arg_type].struct_type = this_arg_type # TODO

    # We're only interested in the values...
    klasses = list(klasses.values())

    # Collect all dependencies for the classes
    for klass in klasses:
        for function in klass.functions:
            return_type = normalize(function.ast.type, meta)
            return_type.clear_qualifiers()
            klass.type_dependencies.add(return_type)
            for argument in function.ast.args.params:
                arg_type = normalize(argument, meta)
                arg_type.clear_qualifiers()
                klass.type_dependencies.add(arg_type)

    # Blah
    klasses.sort(key=lambda k: len(k.type_dependencies))

    # DUMP
    #for klass in klasses:
    #    print(klass.struct_type)
    #    for x in klass.type_dependencies: print(' ', x)

    # Blooooh
    for e in klasses:
        write_class(e, meta)

def functionName_to_methodName(f, struct_type):
    # xmlParserInputGrow, xmlParser
    # TODO....

    try: struct_type = struct_type.next.node.name
    except: pass

    f = re.sub('^_?(x|ht)ml', '', f) # 
    if type(struct_type) is str:
        struct_type = re.sub('^_?(x|ht)ml', '', struct_type)

        common_prefix_len = 0
        for c1, c2 in zip(f, struct_type):
            if c1 != c2: break
            common_prefix_len += 1

        if common_prefix_len < 2:
            common_prefix_len = 0

        #print('<<<<<<<<<<<', f, struct_type, common_prefix)

        return f[common_prefix_len:]

    return f
    return re.sub('^[a-z]+[A-Z][a-z]+', '', s)

def write_class(klass, meta):
    # Sort alphabetically by function name
    klass.functions.sort(key=lambda f: f.doc.name)

    # Group functions by preprocessor conditions
    conditions = defaultdict(list)
    for f in klass.functions:
        conditions[f.doc.cond].append(f)

    print('class %s {' % StructType_to_class(klass.struct_type))

    # First, functions that have no preprocessor conditions
    for f in conditions.pop(None, []):
        print(' ', write_method(f, klass.struct_type, meta))

    # Second, functions that have preprocessor conditions
    for condition, functions in conditions.items():
        print('#if', condition)
        for f in functions: print(' ', write_method(f, klass.struct_type, meta))
        print('#endif')

    print('};\n')

def StructType_to_class(struct_type):
    # TODO.... eeerm .... idk 
    try:
        name = struct_type.next.node.name
        name = name.lstrip('_')
        name = re.sub('^(x|ht)ml', '', name)
        return name
    except:
        return struct_type

def PtrType_to_class(ast, owns, meta):
    normalized = normalize(ast, meta)
    if type(normalized.node) == c_ast.PtrDecl:
        if type(normalized.next.node) == c_ast.Struct: # TODO: or identifier.
            name = '%s<%d>' %(normalized.next.node.name, bool(owns))
            return re.sub('^_?(x|ht)ml', '', name).replace('Ptr','')

    # TODO.... ach leck mich doch am arsch
    ast = deepcopy(ast)
    class ClearDeclname(c_ast.NodeVisitor):
        def visit_TypeDecl(self, node):
            node.declname = ''
    ClearDeclname().visit(ast)
    name = ast_to_c(c_ast.Typename('', [], ast))
    return re.sub('^_?(x|ht)ml', '', name).replace('Ptr','')

def write_method(function, struct_type, meta):
    ''' Generate the code for a wrapped function '''
    s  = 'inline '
    if function.this is None: s += 'static '
    s += PtrType_to_class(function.ast.type, function.own, meta)
    #s += '<%d>' % bool(function.own)
    s += ' '
    s += functionName_to_methodName(function.doc.name, struct_type)
    s += '('
    s += ', '.join([str(arg) for i, arg in enumerate(function.doc.args) if i != function.this])
    s += ')'
    s += ' { return '
    s += function.doc.name
    s += '('
    s += ', '.join(['cobj' if i == function.this else arg.name for i, arg in enumerate(function.doc.args)])
    s += '); '
    s += '}'
    return s

if __name__ == "__main__":
    for filename in sys.argv[1:]:
        show_func_defs(filename)
