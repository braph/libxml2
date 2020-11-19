#!/usr/bin/python3

import sys, re
import doc
from meta import Meta
from copy        import deepcopy
from tempfile    import NamedTemporaryFile
from collections import defaultdict
from pycparser   import c_parser, c_ast, c_generator, parse_file

# TODO:
#
# Ich wuerde gerne write_class() wirkich nur die Methoden *schreiben* lassen.
# Also nicht *generieren*, nur *schreiben*. Warum geht das nicht?...
#   Ich muesste die *generierten* methoden an LibXML2_Struct binden.
#   Allerdings in bereits ausgeschriebener Form (->String) ... hm.
#
# Nachstes Problem:
#    Ich muss irgendwann die Klassen um Methoden erweitern, die NICHT automatisch generiert werden.
#    Hmmmm vllt ... eine .cpp Datei? Mit $variablen? und ${code} oder so?
# 
#
# [ ] How to provide custom functions to classes?
# [ ] Add AST to LibXML2_Struct, generate methods for getting fields
# [ ] Also provide 'const' methods for methods that are NOT const
# [ ] Overload: func1(a1), func2(a1, a2) -> func(a1), func(a1, a2)
# [ ] Overload: func(const char*) -> func(const char*), func(std::string)
# -----------------------------------------------------------------------------
# [ ] Generate copy/move assignment
# [ ] namespace: Xml, Html
#       huge problem! xmlDoc and htmlDoc refer to same struct and xmlReadDoc/htmlReadDoc will bind to the same class
#       resulting in a name collision
# [ ] Sometimes struct*/char* is reallocated! rebind cobj then!
#     examples: xmlStrcat(), xmlXPathConvertBoolean() (search for 'is freed')
# [ ] Sometimes char* is reallocated but only if the returned pointer differs from original 'this' -> REBIND!
#     examples: xmlBuildQName
# [ ] Methods matching *EatName* should unown the passed argument
# [ ] Error checking based on the function documentation
# [ ] Enums: Rename them and put them into namespace (enum xmlStatus -> Xml::enum Status)
# [ ] Add Iterators for children of Nodes
# [ ] xmlSaveDoc() translates to Xml::Save::doc() *sigh*
# MAYBE TODO?
# [ ] Memoize Meta::normalize_type()? Doesn't seem to improve performance?!

# =============================================================================
# "Conversion Rules" ==========================================================
# =============================================================================

def functionName_to_methodName(function_name, struct_type):
    function_name = strip_xml_prefix(function_name)
    struct_type = strip_xml_prefix(struct_type)

    for part in split_title_case(struct_type):
        if function_name.startswith(part) and function_name[len(part)].isupper():
            function_name = function_name[len(part):]
        else:
            break

    function_name = firstToLower(function_name)

    if function_name == 'delete':
        return 'Delete' # C++ keyword

    return function_name

def structName_to_className(name):
    return firstToUpper(strip_xml_prefix(name))

def Function_Returns_Owning(f, meta):
    return AST_Is_Ptr_To_NonConst(f.ast.type, meta) and (
        contains(f.doc.name, 'Create', 'New', 'Copy') or
        contains(f.doc.returns.info,
            'newly created',
            'a new',
            'the new',
            'the resulting document tree',
            'the caller has to free the object'
            ))

def make_return_type(ast, owns, meta):
    normalized = meta.normalize_type(ast)
    if type(normalized.node) == c_ast.PtrDecl:
        if type(normalized.next.node) == c_ast.Struct:
            name = structName_to_className(normalized.next.node.name)
            return '%s<%d-Owning*0>' % (name, bool(owns))

        #if type(normalized.next.node) == c_ast.FuncDecl:
        #    return normalized.next.node.type.declname # TODO!!!!

    #if AST_Is_Enum(ast, meta):
    #    # TODO: move enum to Xml:: and strip off Xml-Preifx
    #    return ast.type.names[0] # TODO: handle this better

    #if AST_Is_Ptr_To_Unsigned_Char(ast, meta):
    #    return 'xmlChar* ' # TODO: handle const

    #if type(normalized.node) is c_ast.IdentifierType and normalized.node.names == ['unsigned','char']:
    #    return 'xmlChar ' # TODO!!!!!!

    ast = deepcopy(ast)
    class ClearDeclname(c_ast.NodeVisitor):
        def visit_TypeDecl(_, node):
            node.declname = ''
    ClearDeclname().visit(ast)
    name = ast_to_c(c_ast.Typename('', [], ast))
    return name
    return strip_xml_prefix(name).replace('Ptr','') # TODO: replace(Ptr) needed?! this line needed?

def Function_Is_Free(f, meta):
    return 'Free' in f.doc.name and len(f.doc.args) == 1

def Function_Argument_Is_This(arg, meta):
    return AST_Is_Ptr_To_Struct(arg, meta) and arg.name == 'cur'

def strip_xml_prefix(string):
    return re.sub('^(x|ht)ml', '', string.lstrip('_'))

# =============================================================================
# Main code ===================================================================
# =============================================================================

class LibXML2_Function():
    __slots__ = ('doc', 'ast', 'own', 'this')
    def __init__(self, **kw):
        self.doc  = None
        self.ast  = None
        self.own  = None
        self.this = None
        for key, value in kw.items():
            setattr(self, key, value)

    def __repr__(self):
        return repr(self.doc)

class LibXML2_Struct():
    __slots__ = ('doc', 'ast', 'struct_type', 'functions', 'type_dependencies')
    def __init__(self, **kw):
        self.doc               = None
        self.ast               = None
        self.struct_type       = None
        self.functions         = []
        self.type_dependencies = set()
        for key, value in kw.items():
            setattr(self, key, value)

class Converter():
    def __init__(self):
        self.api_xml_file = 'doc/libxml2-api.xml'
        self.funcs        = {}
        self.structs      = {}
        self.ast          = None
        self.meta         = None
        self.doc          = None

    def run(self):
        self.doc = doc.API_Doc()
        self.doc.read_xml(self.api_xml_file)

        for func in self.doc.functions.values():
            self.funcs[func.name] = LibXML2_Function(doc=func)

        for struct in self.doc.structs.values():
            self.structs[struct.name] = LibXML2_Struct(struct_type=struct.name, doc=struct)

        self.structs.pop('_xmlGlobalState') # Shouldn't be accessible
        self.structs.pop('_xmlSAXLocator')  # Makes problems atm

        self.parse_header_files()
        self.add_asts()
        self.other_stuff()

    def parse_header_files(self):
        fh = NamedTemporaryFile('w', prefix='libxml-cpp', suffix='.h')

        for f in self.doc.header_files:
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

    def add_asts(self):
        class Visitor(c_ast.NodeVisitor):
            def visit_FuncDecl(_, node):
                if AST_Get_Declname(node) in self.funcs:
                    self.funcs[AST_Get_Declname(node)].ast = node

            def visit_Struct(_, node):
                if AST_Get_Declname(node) in self.structs:
                    self.structs[AST_Get_Declname(node)].ast = node

        Visitor().visit(self.ast)

    def other_stuff(self):
        # Drop stuff that doesn't have an AST set
        self.structs = {name: s for name, s in self.structs.items() if s.ast}
        self.funcs   = {name: f for name, f in self.funcs.items()   if f.ast}

        self.funcs = list(self.funcs.values())

        # Functions inside the 'xmlstring' module are an edge case.
        # They are the only functions that don't operate on a pointer to struct.
        # Keeping them would increase complexity of the code generation, so we drop them.
        self.char_funcs, self.funcs = partition(self.funcs, lambda f: f.doc.module == 'xmlstring')

        # Free() functions contain 'Free' and have one arg
        self.free_funcs, self.funcs = partition(self.funcs, lambda f: Function_Is_Free(f, self.meta))

        for f in self.funcs:
            # Own functions return Ptr
            if Function_Returns_Owning(f, self.meta):
                f.own = True

            if len(f.doc.args):
                # We assume that the first argument is a 'this' ptr
                if AST_Is_Ptr_To_Struct(f.ast.args.params[0], self.meta):
                    f.this = 0

                # If we find a struct pointer named 'cur' use it as 'this' ...
                for i, arg in enumerate(f.ast.args.params):
                    if Function_Argument_Is_This(arg, self.meta):
                        f.this = i
                        break

        klasses = self.structs

        # Bind functions to a class depending on return type / this parameter
        for f in self.funcs:
            if f.this is None:
                if f.own:
                    # No THIS but returns an owning ptr -> bind it to class of owning ptr
                    try:
                        klasses[AST_Find_Struct_Name(f.ast.type, self.meta)].functions.append(f)
                    except:
                        #raise Exception(f.ast)
                        pass # TODO
            else:
                try:
                    klasses[AST_Find_Struct_Name(f.ast.args.params[f.this], self.meta)].functions.append(f)
                except:
                    pass #print(f.ast.args.params[f.this])

        # Add struct dependencies to klass
        for klass in klasses.values():
            for function in klass.functions:
                klass.type_dependencies |= AST_Find_All_Struct_Names(function.ast, self.meta)
            klass.type_dependencies.discard(klass.struct_type)

        # =====================================================================
        # Output ==============================================================
        # =====================================================================

        # Convert to list (we need to sort)
        klasses = list(klasses.values())

        print('''#include<utility>
inline const char* to_const_char(std::nullptr_t)         { return nullptr; }
inline const char* to_const_char(const char* s)          { return s; }
inline const char* to_const_char(const unsigned char* s) { return reinterpret_cast<const char*>(s); }
template<class T>
inline const char* to_const_char(const T& s)             { return to_const_char(s.c_str()); }

inline const unsigned char* to_const_unsigned_char(std::nullptr_t)         { return nullptr; }
inline const unsigned char* to_const_unsigned_char(const unsigned char* s) { return s; }
inline const unsigned char* to_const_unsigned_char(const char* s)          { return reinterpret_cast<const unsigned char*>(s); }
template<class T>
inline const unsigned char* to_const_unsigned_char(const T& s)             { return to_const_unsigned_char(s.c_str()); }
''')

        print('// LibXML2 Includes')
        for f in self.doc.header_files:
            print('#include <libxml/%s.h>' % f)

        print('\nnamespace LibXML_impl {')
        for klass in sorted(klasses, key=lambda k: k.struct_type):
            print('template<bool> class %s;' % structName_to_className(klass.struct_type))
        print()
        klasses.sort(key=lambda k: len(k.type_dependencies))
        for klass in klasses:
            write_class(self, klass)
        print('} // namespace LibXML_impl')

        print('\nnamespace Xml {')
        for klass in klasses:
            name = structName_to_className(klass.struct_type)
            print('using %s = LibXML_impl::%s<0>;' % (name, name))
        print('} // namespace Xml')

def FreeFunction_For_StructType(self, struct_type):
    for f in self.free_funcs:
        try:
            if struct_type == AST_Find_Struct_Name(f.ast.args.params[0], self.meta):
                return f.doc.name
        except:
            pass

def write_class(self, klass):
    name = structName_to_className(klass.struct_type)
    free_func = FreeFunction_For_StructType(self, klass.struct_type)
    print('template<bool Owning = 0>')
    print('class %s {' % name)
    print(' struct %s *cobj;' % klass.struct_type)
    print('public:')
    if free_func:
        print(' inline ~%s() { if (Owning) %s(cobj), cobj = NULL; }' % (name, free_func))
    print(' inline %s(%s *ptr) noexcept : cobj(ptr) {}' % (name, klass.struct_type))
    print(' inline %s(%s<1> &&rhs) noexcept : cobj(rhs.cobj) { rhs.cobj = NULL; }' % (name, name))
    #print(' inline %s& operator=()')
    print(' inline operator %s*() const noexcept { return cobj; }' % klass.struct_type)
    print(' inline %s<0> release() noexcept { if (Owning) { auto p = cobj; cobj = NULL; return p; } else { return cobj; } }' % name)

    # Getter for fields
    for field in (klass.ast.decls or []):
        print(create_function(
            make_return_type(field.type, False, self.meta),
            'get'+AST_Get_Declname(field),
            [],
            'return cobj->%s;'%AST_Get_Declname(field),
            inline = True,
            static = False,
            const =  False,
            noexcept = True))

    # Sort alphabetically by function name
    klass.functions.sort(key=lambda f: f.doc.name)

    # Group functions by preprocessor conditions
    conditions = defaultdict(list)
    for f in klass.functions:
        if not re.match('^xml', f.doc.name): continue # TODO: RM
        conditions[f.doc.cond].append(f)

    # First, functions that have no preprocessor conditions
    for f in conditions.pop(None, []):
        print(' '+ write_method(f, klass.struct_type, self.meta))

    # Second, functions that have preprocessor conditions
    for condition, functions in conditions.items():
        print('#if', condition)
        for f in functions:
            print(' '+ write_method(f, klass.struct_type, self.meta))
        print('#endif')

    print('};\n')

def write_method(function, struct_type, meta):
    ''' Generate the code for a wrapped function '''

    template_args = []
    function_args = []
    calling_args  = []

    for i, arg in enumerate(function.ast.args.params):
        if type(arg) is c_ast.EllipsisParam:
            template_args.append('typename... VArgs')
            function_args.append('VArgs&&... vargs')
            calling_args.append('std::forward<VArgs>(vargs)...')
        elif AST_Is_Void(arg, meta):
            pass
        elif AST_Is_Ptr_To_Const_Char(arg, meta) or AST_Is_Ptr_To_Const_Unsigned_Char(arg, meta):
            template_args.append('class TString%d' % i)
            function_args.append('TString%d %s' % (i, AST_Get_Declname(arg)))
            if AST_Is_Ptr_To_Const_Char(arg, meta):
                calling_args.append('to_const_char(%s)' % AST_Get_Declname(arg))
            else:
                calling_args.append('to_const_unsigned_char(%s)' % AST_Get_Declname(arg))
        elif i == function.this:
            calling_args.append('cobj')
        else:
            calling_args.append(AST_Get_Declname(arg))
            function_args.append(ast_to_c(arg))

    body = 'return ' if function.doc.returns.type != 'void' else ''
    body += '%s(%s);' % (function.doc.name, ', '.join(calling_args))

    tpl = ''
    if template_args:
        tpl = 'template<%s> ' % (', '.join(template_args))

    return tpl + create_function(
        make_return_type(function.ast.type, function.own, meta),
        functionName_to_methodName(function.doc.name, struct_type),
        function_args,
        body,
        inline = True,
        static = function.this is None,
        const =  function.this is not None and AST_Is_Ptr_To_Const(function.ast.args.params[function.this], meta),
        noexcept = True)

def create_function(ret, name, args, body, inline=False, static=False, const=False, noexcept=False):
    return '%s%s%s %s(%s) %s%s{ %s }' % (
        'inline '   if inline else '',
        'static '   if static else '',
        ret, name, ', '.join(args),
        'const '    if const else '',
        'noexcept ' if noexcept else '',
        body)

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

def AST_Find_Struct_Name(ast, meta): # TODO: rename this and exception blubber
    norm = meta.normalize_type(ast)
    if type(norm.node) is c_ast.PtrDecl and type(norm.next.node) is c_ast.Struct:
        return norm.next.node.name
    raise Exception()
    return AST_Find_All_Struct_Names(ast, meta).pop()

def AST_Get_Declname(node):
    T = type(node)
    if   T is c_ast.Decl:     return node.name
    elif T is c_ast.TypeDecl: return node.declname
    elif T is c_ast.Struct:   return node.name
    elif T is c_ast.FuncDecl: return AST_Get_Declname(node.type)
    elif T is c_ast.PtrDecl:  return AST_Get_Declname(node.type)
    raise Exception(node)

def AST_Is_Enum(ast, meta):
    norm = meta.normalize_type(ast)
    return type(norm.node) is c_ast.Enum

def AST_Is_Void(ast, meta):
    norm = meta.normalize_type(ast)
    return type(norm.node) is c_ast.IdentifierType and norm.node.names == ['void']

def AST_Is_Ptr_To_Const_Char(ast, meta):
    norm = meta.normalize_type(ast)
    return type(norm.node) is c_ast.PtrDecl and \
           type(norm.next.node) is c_ast.IdentifierType and \
           'const' in norm.next.quals and \
           norm.next.node.names == ['char']

def AST_Is_Ptr_To_Const_Unsigned_Char(ast, meta):
    norm = meta.normalize_type(ast)
    return type(norm.node) is c_ast.PtrDecl and \
           type(norm.next.node) is c_ast.IdentifierType and \
           'const' in norm.next.quals and \
           norm.next.node.names == ['unsigned', 'char'] # TODO: Normalized

def AST_Is_Ptr_To_Unsigned_Char(ast, meta):
    norm = meta.normalize_type(ast) # TODO NormalizedIdentifier
    return type(norm.node) is c_ast.PtrDecl and \
           type(norm.next.node) is c_ast.IdentifierType and \
           norm.next.node.names == ['unsigned', 'char']

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
