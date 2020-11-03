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
