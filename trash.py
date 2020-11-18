        if result is None:
            result = Result(None, [])

        typ = type(node)
        if typ in (c_ast.Typedef, c_ast.Decl, c_ast.TypeDecl, c_ast.PtrDecl):
            r = Result(node, list(node.quals))
            result.next = r
            self.normalize(node.type, r)

        elif typ is c_ast.IdentifierType:
            n = self.resolve_identifier(node.names[0])
            if n:
                self.normalize(n, result)
            else:
                result.next = Result(node, [])

        return self.kuerze(result)


    def kuerze_working(self, result):
        typ = type(current)
        DECL_TYPES = (c_ast.Decl, c_ast.TypeDecl, c_ast.Typedef, type(None))
        if typ in DECL_TYPES:
            if not result.quals:
                result.drop()

    def kuerze(self, result):
        if result is not None:
            parent = result
            child  = result.next
            if child:
                typ = type(child)
                DECL_TYPES = (c_ast.Decl, c_ast.TypeDecl, c_ast.Typedef, type(None))
                if typ in DECL_TYPES:
                    raise
                    if not child.quals:
                        parent.drop(child)

            self.kuerze(parent.next)
        return result

    def kuerze_old(self, a, b=None):
        if not b:
            b = a.next
        if not b:
            return a

        typ_a, typ_b = type(a.node), type(b.node)
        DECL_TYPES = (c_ast.Decl, c_ast.TypeDecl, c_ast.Typedef, type(None))

        if typ_a in DECL_TYPES:# and typ_b in DECL_TYPES:
            b.quals = a.quals
            return self.kuerze(b, b.next)

        a.next = self.kuerze(b, b.next)
        return a

    def kuerze_lol(self, result):
        node = result
        while node.next:
            typ = type(node.next.node)

            if typ in (c_ast.Decl, c_ast.TypeDecl, c_ast.Typedef, type(None)):
                node.next.quals = node.quals
                node.next = node.next.next

            elif typ in (c_ast.PtrDecl,):
                if type(node.node) in (c_ast.Decl, c_ast.TypeDecl, c_ast.Typedef):
                    pass

            node = node.next
                    
        return result

    #def kuerze(self, result):
    #    typ = type(result.node)
    #    if typ != c_ast.PtrDecl:
    #        if not result.quals:
    #            return self.kuerze(result.next)
    #    else:
    #        result.next = self.kuerze(result.next)

    #    return result


    #    self.kuerze(result.next)

    #    if result.next:
    #        typ = type(result.node)
    #        next_typ = type(result.next.node)

    #        if typ in (c_ast.Decl, c_ast.TypeDecl):
    #            if next_typ in (c_ast.Decl, c_ast.TypeDecl):
    #                if result.quals == result.next.quals:
    #                    result.next = result.next.next
    #                    self.kuerze(result)

class Normalizer2(c_ast.NodeVisitor):
    def __init__(self, meta):
        self.meta = meta
        self.result = Result(None, [])
        self.last = self.result

    def run(self, ast):
        self.visit(ast)
        return self.result

    def visit_Struct(self, node):
        raise

    def visit_Union(self, node):
        raise

    def visit_Typedef(self, node):
        if not node.quals:
            pass
        elif type(node.type) in (c_ast.Decl, c_ast.TypeDecl, c_ast.Typedef) and node.quals == node.type.quals:
            pass
        elif type(node.type) in (c_ast.PtrDecl,):
            self.last.next = Result(node.type, node.type.quals + node.quals)
            self.last = self.last.next
            self.visit(node.type.type)
            return
        else:
            self.last.next = Result(node, list(node.quals))
            self.last = self.last.next
        self.visit(node.type)

    def visit_Decl(self, node):
        self.visit_Typedef(node)

    def visit_TypeDecl(self, node):
        self.visit_Typedef(node)

    def visit_PtrDecl(self, node):
        self.last.next = Result(node, list(node.quals))
        self.last = self.last.next
        self.visit(node.type)

    def visit_IdentifierType(self, node):
        n = self.meta.resolve_identifier(node.names[0])
        if n:
            self.visit(n)
        else:
            self.last.next = Result(node, [])
            self.last = self.last.next


# def make_id(names):
#     if len(names) == 1:
#         if name == 'float':    return 4
#         if name == 'double':   return 6
#         if name == 'void':     return 2
# 
#     ID = SIGNED = UNSIGNED = 0
#     for name in names:
#         if   name == 'signed'  : SIGNED   = 1
#         elif name == 'unsigned': UNSIGNED = 1
#         elif name == 'int':      INT += 1
#         elif name == 'char':     CHAR += 1
#         elif name == 'short':    SHORT += 1
#         elif name == 'long':     LONG += 1
#         else: return names
# 
#     ID = 0
#     for name in names:
#         if   name == 'signed'  : SIGNED   = 1
#         elif name == 'unsigned': UNSIGNED = 1
#         else:
#             id = ['char', 'short', 'int', 'long'].index(name) + 1
# 
#         if name == 'char':
#             if ID raise
#         if name == 'short':
# 
# 
# 
#         if   name == 'int':      
#         elif name == 'char':     if ID: return names else ID = 8 #  ID += 1 << 4
#         elif name == 'short':    if ID and ID != 10: return names else ID = 12 # += 1 << 8
#         elif name == 'long':     ID += 1 << 16
#         else: return names
# 
#     if (SIGNED and UNSIGNED) or \
#         char > 1 or short > 1 or int > 1 or long > 2:
#             return names
# 
#     if char:
#         if not _int+_short+_long:
#             return char|UNSIGNED
#     else:
#         if short == 1 and not long:      return short|UNSIGNED
#         if long == 1  and not short:     return long|UNSIGNED
#         if long == 2  and not short:     return long|long|UNSIGNED
#         return int|UNSIGNED
# 
# 


    def resolve(node):
        typ = type(node)

        if typ is c_ast.Typedef:
            if not node.quals:
                return resolve(node.type)

        elif typ is c_ast.Decl:
            if not node.quals:
                return resolve(node.type)

        elif typ is c_ast.TypeDecl:
            if not node.quals:
                return resolve(node.type)

        elif typ is c_ast.IdentifierType:
            n = meta.resolve_identifier(node.names[0])
            if n:
                return resolve(n)

        return node
        #elif typ is c_ast.PtrDecl: return node
        #elif typ is c_ast.Struct: return node

    from functools import cmp_to_key
    def predicate_to_cmp(predicate):
        def cmp(a, b):
            if predicate(a, b):
                return 1
            elif a == b:
                return 0
            else:
                return -1
        return cmp
    key = cmp_to_key(predicate_to_cmp(is_same_first_param))
    def is_same_first_param(a,b):
        a = norm.run(a.args.params[0].type)
        b = norm.run(b.args.params[0].type)
        return a == b


def make_id(names):
    ID = 0
    for name in names:
        if   name == 'int':      pass
        elif name == 'signed'  : pass
        elif name == 'unsigned': ID |= 1
        elif name == 'char':     ID += 1 << 4
        elif name == 'short':    ID += 1 << 8
        elif name == 'long':     ID += 1 << 16
        elif name == 'float':    ID += 1 << 20
        elif name == 'double':   ID += 1 << 24
        elif name == 'void':     ID += 1 << 28
        else: return names
    return ID

def compare_identifier(names_a, names_b):
    id_a = make_id(names_a)
    id_b = make_id(names_b)
    return id_a == id_b

print(bin(make_id(['unsigned', 'char', 'char', 'char'])))
print(bin(make_id(['unsigned', 'char' ])))
raise







# =====================================================================================================

    #for node in free_funcs:
    #    nparams = FuncDecl_param_count(node)
    #    if nparams == 1:
    #        f = 'template<> void xmlGenericFree<{TYPE}>({TYPE} {NAME}) {{ {FUNC}({NAME}); }}'.format(
    #            FUNC = FuncDecl_get_name(node),
    #            TYPE = Decl_type(node.args.params[0].type),
    #            NAME = Decl_name(node.args.params[0])
    #        )

    #        print(f)#, node.args.params[0].type)

    #        #print(g.visit(node.args))
    #        #for a in node.args:
    #        #    print(a)

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

    ##  parser = c_parser.CParser()
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







class Normalizer():
    def __init__(self, meta):
        self.meta   = meta
        self.result = Result(None, [])
        self.last   = self.result
        self.quals  = set()

    @staticmethod
    def normalize(meta, ast):
        n = Normalizer(meta)
        n.visit(ast)
        return n.result.next

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



        #try: f.this = list(filter(lambda a: contains(a.type, 'Ptr', '*'), f.doc.args))[0]
        #try: f.this = [i for i, arg in f.doc.args if contains(arg.type, 'Ptr', '*')[0]
        #except: pass
#for o in rst:
























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
        print(node)
        raise
    return result


#    if 'Ptr' in o.returns.type:
#        print(o)
#        print(o.returns.info)
#
#raise













# ===================== new blah>?

class Normalized_Result:
    def __init__(self, quals):
        self.quals = quals
        self.next  = None

class Normalized_PtrDecl():
    def __init__(self, quals):
        self.quals = quals
        self.next  = None

class Normalized_IdentifierType():
    def __init__(self, quals, identifier):
        self.quals = quals
        self.identifier = identifier
        self.next = None

class Normalized_Struct():
    def __init__(self, quals, name):
        self.quals = quals
        self.name = name
        self.next = None


def normalize(node, meta):
    return normalize_impl(node, meta, Normalized_Result([]), set()).next

def normalize_impl(node, meta, result, quals):
    T = type(node)
    if T is c_ast.Decl:
        normalize_impl(node.type, meta, result, quals)
    elif T in (c_ast.Typedef, c_ast.TypeDecl, c_ast.Typename):
        normalize_impl(node.type, meta, result, quals | set(node.quals))
    elif T is c_ast.PtrDecl:
        result.next = Normalized_PtrDecl(quals | set(node.quals))
        normalize_impl(node.type, meta, result.next, set())
    elif T is c_ast.IdentifierType:
        n = meta.resolve_identifier(node.names[0])
        if n: normalize_impl(n, meta, result, quals)
        else: result.next = Normalized_IdentifierType(quals, node.names)
    elif T in (c_ast.Struct, c_ast.Enum, c_ast.FuncDecl):
        result.next = Normalized_Struct(quals, node.name)
    else:
        print(node)
        raise
    return result



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

def Decl_type(node):
    if type(node) == c_ast.PtrDecl:
        return Decl_type(node.type) + '*'
    elif type(node) == c_ast.TypeDecl:
        return node.type.names[0]
    else:
        raise
        return node
        return "?"

    # TODO: common prefix only on camel case...
    common_prefix_len = 0
    for c1, c2 in zip(f, struct_type):
        if c1 != c2: break
        common_prefix_len += 1

    if common_prefix_len < 2:
        common_prefix_len = 0

    #print('<<<<<<<<<<<', f, struct_type, common_prefix)

    return f[common_prefix_len:]
    return re.sub('^[a-z]+[A-Z][a-z]+', '', s)

    if function.doc.name == 'xmlXPathNewContext': raise






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
    s += ' noexcept'
    s += ' { '
    if function.doc.returns.type != 'void':
        s += 'return '
    s += function.doc.name
    s += '('
    s += ', '.join(['cobj' if i == function.this else arg.name for i, arg in enumerate(function.doc.args)])
    s += '); '
    s += '}'
    return s

