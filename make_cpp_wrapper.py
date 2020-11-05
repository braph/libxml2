#!/usr/bin/python3

import sys, operator
from collections import defaultdict

from pycparser import c_parser, c_ast, c_generator, parse_file
g = c_generator.CGenerator()

from lxml import etree

# =============================================================================
# Documentation Data Classes
# =============================================================================

class LibXML2_Doc_Function():
    __slots__ = ('name', 'file', 'module', 'cond', 'info', 'returns', 'args')
    def __init__(self, **kw):
        for k, v in kw.items(): setattr(self, k, v)

    def __repr__(self):
        return "%s %s %s" % (self.returns, self.name, self.args)

    @staticmethod
    def from_xmlnode(node):
        d = dict(
            name     = node.attrib['name'],
            file     = node.attrib['file'],
            module   = node.attrib['module'],
            cond     = None,
            info     = None,
            returns  = None,
            args     = [])

        for n in node:
            if   n.tag == 'cond':   d['cond'] = n.text
            elif n.tag == 'info':   d['info'] = n.text
            elif n.tag == 'arg':    d['args'].append(LibXML2_Doc_Arg.from_xmlnode(n))
            elif n.tag == 'return': d['returns'] = LibXML2_Doc_Return.from_xmlnode(n)
        return LibXML2_Doc_Function(**d)

class LibXML2_Doc_Arg():
    __slots__ = ('name', 'type', 'info')
    def __init__(self, **kw):
        for k, v in kw.items(): setattr(self, k, v)

    def __repr__(self):
        return "%s %s" % (self.type, self.name)

    @staticmethod
    def from_xmlnode(node):
        return LibXML2_Doc_Arg(
            name=node.attrib.get('name'),
            type=node.attrib.get('type'),
            info=node.attrib.get('info'))

class LibXML2_Doc_Return():
    __slots__ = ('type', 'info')
    def __init__(self, **kw):
        for k, v in kw.items(): setattr(self, k, v)

    def __repr__(self):
        return self.type

    @staticmethod
    def from_xmlnode(node):
        return LibXML2_Doc_Return(
            type=node.attrib.get('type'),
            info=node.attrib.get('info',''))

# =============================================================================

class LibXML2_Function():
    __slots__ = ('doc', 'ast', 'own', 'ignore', 'free', 'this')
    def __init__(self, **kw):
        for s in self.__slots__: setattr(self, s, kw.get(s, None))

    def __repr__(self):
        return repr(self.doc)

def contains(string, *search):
    for s in search:
        if s in string: return True
    return False

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

    def resolve_identifier(self, name):
        if name in self.typedefs: return self.typedefs[name]
        if name in self.structs:  return self.structs[name]
        if name in self.unions:   return self.unions[name]
        return None

class Result():
    def __init__(self, node, quals):
        self.node = node
        self.quals = quals
        self.next = None

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
        n = meta.resolve_identifier(node.names[0])
        if n: normalize_impl(n, meta, result, quals)
        else: result.next = Result(node, quals)
    elif T in (c_ast.Struct, c_ast.Enum, c_ast.FuncDecl):
        result.next = Result(node, quals)
    else:
        raise Exception(node)
    return result

def FuncDecl_get_name(node): # TODO: rename
    typ = type(node)
    if   typ is c_ast.TypeDecl: return node.declname
    elif typ is c_ast.FuncDecl: return FuncDecl_get_name(node.type)
    elif typ is c_ast.PtrDecl:  return FuncDecl_get_name(node.type)
    raise

def make_id(names):
    ID = 0
    for name in names:
        if   name == 'int':      pass
        elif name == 'signed'  : pass
        elif name == 'unsigned': ID |= 1
        elif name == 'char':     ID += 1 << 2; ID |= (1 << 2)
        elif name == 'short':    ID += 1 << 3; ID |= (1 << 3)
        elif name == 'float':    ID += 1 << 4; ID |= (1 << 4)
        elif name == 'double':   ID += 1 << 5; ID |= (1 << 5)
        elif name == 'void':     ID += 1 << 6; ID |= (1 << 6)
        elif name == 'long':     ID += 1 << 7; ID |= (1 << 7)
        else: return names
    return ID

def unpack_id(ID):
    print('unpacked', ID)
    return {
        1<<2: 'char',
        1<<3: 'short',
        1<<4: 'float',
        1<<5: 'double',
        1<<6: 'void',
        1<<7: 'long',
        (1<<7)+(1<<7)+(1<<7): 'long long'}.get(ID, 'UNKNOWN')

def compare_identifier(names_a, names_b):
    id_a = make_id(names_a)
    id_b = make_id(names_b)
    return id_a == id_b

#print(unpack_id(make_id(['long','long'])))
#print(bin(make_id(['char', 'char', 'char'])))
#print(unpack_id(make_id(['char', 'char', 'char'])))
#print(bin(make_id(['char', 'char' ])))
#print(unpack_id(make_id(['char', 'char'])))
#print(unpack_id(make_id(['char'])))
#raise

#print(compare_identifier(['signed'], ['unsigned']))
#print(compare_identifier(['long'], ['long', 'int']))
#print(compare_identifier(['signed'], ['int']))
#print(compare_identifier(['signed', 'long'], ['long']))
#print(compare_identifier(['signed', 'long', 'long'], ['long', 'long']))
#print(compare_identifier(['long', 'long', 'signed'], ['long', 'long']))

def FuncDecl_param_count(node):
    return len(node.args.params)

def Decl_to_c(node):
    return g.visit(node.args)

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
                        doc=LibXML2_Doc_Function.from_xmlnode(symbol))

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
    meta = Meta(ast)

    # Step 3: Add AST to functions
    class FuncDefVisitor(c_ast.NodeVisitor):
        def visit_FuncDecl(self, node):
            name = FuncDecl_get_name(node)
            try:    funcs[name].ast = node
            except: print('Skipping',name,'...')

    FuncDefVisitor().visit(ast)

    for f in funcs.values():
        # Free() functions
        if 'Free' in f.doc.name and len(f.doc.args) == 1:
            f.free = True

        if contains(f.doc.name, 'Create', 'New',' Copy'):
            f.own = True

        if contains(f.doc.returns.info, 'newly created', 'a new', 'the new', 'the resulting document tree'):
            f.own = True

        for i, arg in enumerate(f.doc.args):
            if contains(arg.type, 'Ptr', '*'):
                f.this = i
                break

    # Collect all the ...
    struct_bindings = defaultdict(list)
    for f in funcs.values():
        if f.ast is not None and f.this is not None:
            #print(f.doc.name, normalize(f.ast.args.params[f.this], meta))
            n = normalize(f.ast.args.params[f.this], meta)
            struct_bindings[n].append(f)

    # Blooooh
    for struct_type, functions in struct_bindings.items():
        write_class(struct_type, functions)


def write_class(struct_type, functions):
    # Group functions by preprocessor conditions
    conditions = defaultdict(list)
    for f in functions:
        conditions[f.doc.cond].append(f)
    # And sort by function name
    for functions in conditions.values():
        functions.sort(key=lambda f: f.doc.name)

    print('class %s {' % struct_type)

    # First, functions that have no preprocessor conditions
    for f in conditions.pop(None, []): write_function(f)

    # Second, functions that have preprocessor conditions
    for condition, functions in conditions.items():
        print('#if', condition)
        for f in functions: write_function(f)
        print('#endif')

    print('};')

def write_function(function):
    print('\t%s %s %s { }' % (function.doc.returns.type, function.doc.name, function.doc.args))


if __name__ == "__main__":
    for filename in sys.argv[1:]:
        show_func_defs(filename)
