#!/usr/bin/python3

import sys, operator

from pycparser import c_parser, c_ast, c_generator, parse_file
g = c_generator.CGenerator()

# free functions:  free in name and one param
# owned functions: create/new/copy and ptr return value

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
        elif self.next:
            x = str(self.next)

        return '(%s %s %s)' % (type(self.node).__name__, ' '.join(self.quals), x)

    #TODO: class Identifier
    #def cmp(self, other):
    #    while self and other:
    #        self_type = type(self.node)
    #        other_type = type(self.other)
    #        if self_type is not other_type:
    #            return ORDER.index(self_type) - ORDER.index(other_type)

    #        if self_type is c_ast.IdentifierType:

    def cmp_foo(self, other, operator=operator.eq):
        ORDER = [c_ast.IdentifierType, c_ast.PtrDecl]

        self_T, other_T = type(self.node), type(other.node)
        if self_T is other_T:
            if self_T is c_ast.IdentifierType:
                self_ID, other_ID = make_id(self.node.names), make_id(other.node.names)
                if self_ID and other_ID:  return operator(self_ID, other_ID)
                if self_ID:               return operator(1, 0)
                if other_ID:              return operator(0, 1)
                return                    operator(self.node.names, other.node.names)

            elif self_T is c_ast.Struct:
                return operator(self.node.name, other.node.name)

        else:
            return operator(ORDER.index(self_T), ORDER.index(other_T))

        print(self.quals, other.quals)
        #return operator(self.quals, other.quals)

    def cmp(self, other, operator=operator.eq):
        if not self.cmp_foo(other, operator): return False
        if self.next and other.next:          return self.next.cmp(other.next, operator)
        if self.next:                         return operator(1, 0)
        if other.next:                        return operator(0, 1)
        if self.next and other.next:          return operator(0, 0)

    def __lt__(self, other):
        return self.cmp(other, operator.lt)
        while self and other:
            if self.quals < other.quals: return True
            self  = self.next
            other = other.next
        return not self and other

    def __gt__(self, other):
        return self.cmp(other, operator.gt)
        if self.quals > other.quals: return True
        if self.next and other.next: return self.next > other.next
        return False

    def __eq__(self, other):
        return self.cmp(other, operator.eq)
        while self and other:
            if self.quals != other.quals:           return False
            if type(self.node) != type(other.node): return False
            self, other = self.next, other.next
        return True

    def __ne__(self, other):
        return not(self.__eq__(self, other))

class Normalizer():
    def __init__(self, meta):
        self.meta = meta
        self.result = Result(None, [])
        self.last = self.result
        self.quals = set()

    def run(self, ast):
        self.visit(ast)
        return self.result.next

    def visit(self, node):
        T = type(node)
        if T is c_ast.Decl:
            pass
        elif T in (c_ast.Typedef, c_ast.TypeDecl):
            self.quals.update(node.quals)
        elif T is c_ast.PtrDecl:
            self.quals.update(node.quals)
            self.last.next = Result(node, self.quals)
            self.last = self.last.next
            self.quals = set()
        elif T is c_ast.IdentifierType:
            n = self.meta.resolve_identifier(node.names[0])
            if n:
                self.visit(n)
            else:
                self.last.next = Result(node, self.quals)
                self.last = self.last.next
                self.quals = set()
            return  #XXX
        elif T in (c_ast.Struct, c_ast.Enum, c_ast.FuncDecl):
            self.last.next = Result(node, self.quals)
            self.last = self.last.next
            self.quals = set()
            return  #XXX
        else:
            print(node)
            raise

        self.visit(node.type)


def FuncDecl_get_name(node): # TODO: rename
    typ = type(node)
    if   typ is c_ast.TypeDecl: return node.declname
    elif typ is c_ast.FuncDecl: return FuncDecl_get_name(node.type)
    elif typ is c_ast.PtrDecl:  return FuncDecl_get_name(node.type)
    raise

def get_funcs(ast):
    class FuncDefVisitor(c_ast.NodeVisitor):
        def __init__(self, ast):
            self.xml_funcs = []
            self.free_funcs = []
            self.visit(ast)

        def visit_FuncDecl(self, node):
            name = FuncDecl_get_name(node)
            if name and name.startswith('xml'):
                if 'free' in name.lower():
                    self.free_funcs.append(node)
                else:
                    self.xml_funcs.append(node)

    x = FuncDefVisitor(ast)
    return x.xml_funcs, x.free_funcs

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

print(unpack_id(make_id(['long','long'])))
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
    parser = c_parser.CParser()
    ast = parse_file(filename, use_cpp=True,
        cpp_path='gcc',
        cpp_args=[
        '-E',
        '-D__attribute__(x)=',
#       '-nostdinc',
       '-I.',
       '-Ifake_libc_include',
        '-I/usr/include/libxml2',
#        '-undef',
#        '-I/usr/include',
    ], parser=parser)

    xml_funcs, free_funcs = get_funcs(ast)
    #v = FuncDefVisitor()
    #v.visit(ast)
    meta = Meta(ast)

    for node in free_funcs:
        nparams = FuncDecl_param_count(node)
        if nparams == 1:
            f = 'template<> void xmlGenericFree<{TYPE}>({TYPE} {NAME}) {{ {FUNC}({NAME}); }}'.format(
                FUNC = FuncDecl_get_name(node),
                TYPE = Decl_type(node.args.params[0].type),
                NAME = Decl_name(node.args.params[0])
            )

            print(f)#, node.args.params[0].type)

            #print(g.visit(node.args))
            #for a in node.args:
            #    print(a)

    #xml_funcs.sort(key=FuncDecl_get_name)
    #xml_funcs.sort(key=lambda n: Decl_type(n.args.params[0].type).replace('const', ''))

    #for node in xml_funcs:
    #    print(
    #        Decl_type(node.args.params[0].type).replace('const', ''), '  ',
    #        FuncDecl_get_name(node), '(', g.visit(node.args), ')', sep='')

    #print('%s at %s' % (node.decl.name, node.decl.coord))
    #print('%s at %s' % (node.name, node.coord))
    #print(node.args)

    #print(type_defs['xmlBuffer'])
    #print(type_defs['xmlBufferPtr'])
    #print(xml_funcs[0].args.params[1])
    #print(struct_defs['_xmlBuffer'])

    ##  a = parser.parse('''
    ##      typedef int* int_p;
    ##      const int_p p;
    ##      int* const p3;
    ##      const int* p2;
    ##      const int* const p4;
    ##      const int LOL;
    ##      int const LOL2;''').ext
    ##  meta = Meta(a)
    ##  #print(a[1])
    ##  print(Normalizer(meta).run(a[1]))
    ##  print(Normalizer(meta).run(a[2]))
    ##  #print(a[3])
    ##  print(Normalizer(meta).run(a[3]))
    ##  print(Normalizer(meta).run(a[4]))
    ##  #print(a[5])
    ##  #print(a[6])
    ##  #raise

    #def is_same_type(a, b):
    #    a = resolve(a)
    #    b = resolve(b)
    #    typ_a = type(a)
    #    typ_b = type(b)
    #    if typ_a == typ_b:
    #        if typ_a is c_ast.PtrDecl:
    #            return a.quals == b.quals and is_same_type(a.type, b.type)
    #        elif typ_a is c_ast.Struct:
    #            return a.name == b.name

    #    return False
    #    #print(a)
    #    #print(b)
    #    #a = resolve(a.type)
    #    #b = resolve(b.type)
    #    #print(a)
    #    #print(b)

    #print( is_same_type(type_defs['xmlBufferPtr'], xml_funcs[0].args.params[1]))

    norm = Normalizer(meta)
    xml_funcs.sort(key=lambda f: norm.run(f.args.params[0].type))
    for node in xml_funcs:
        print(
            Decl_type(node.args.params[0].type).replace('const', ''), '  ',
            FuncDecl_get_name(node), '(', g.visit(node.args), ')', sep='')

    xmlStrcat = next(filter(lambda n: FuncDecl_get_name(n) == 'xmlStrcat', xml_funcs))
    def is_same_type(a,b):
        return norm.run(a) == norm.run(b)
    print(is_same_type(xmlStrcat.args.params[0], xmlStrcat.args.params[1]))
    #print(next(filter(lambda n: FuncDecl_get_name(n) == 'xmlGetGlobalState', xml_funcs)))
    #print(parser.parse('unsigned signed int * p;').ext[0])
    #print(parser.parse('const int * p;').ext[0])
    #print(a[0], a[1], a[2])
    #print(parser.parse('unsigned int p;'))

if __name__ == "__main__":
    for filename in sys.argv[1:]:
        show_func_defs(filename)

