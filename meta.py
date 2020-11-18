#!/usr/bin/python3

from pycparser import c_parser, c_ast, c_generator, parse_file

# =============================================================================
# AST Stuff ===================================================================
# =============================================================================

class Meta(c_ast.NodeVisitor):
    def __init__(self, ast):
        self.typedefs = {}
        self.structs  = {}
        self.unions   = {}
        self.visit(ast)

    def visit_Struct(self, node):
        self.structs[node.name] = node

    def visit_Union(self, node):
        self.unions[node.name] = node

    def visit_Typedef(self, node):
        self.typedefs[node.name] = node

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


if __name__ == '__main__':
    #print(NormalizedIdentifier(['unsigned','char']))
    assert NormalizedIdentifier(['char'])            == NormalizedIdentifier(['char'])
    assert NormalizedIdentifier(['unsigned','char']) != NormalizedIdentifier(['char'])
    assert NormalizedIdentifier(['signed',  'char']) != NormalizedIdentifier(['char'])
    assert NormalizedIdentifier(['short',   'int'])  == NormalizedIdentifier(['short'])
    assert NormalizedIdentifier(['long',    'int'])  == NormalizedIdentifier(['long'])
    assert NormalizedIdentifier(['signed'])          == NormalizedIdentifier(['int'])
    assert NormalizedIdentifier(['unsigned'])        == NormalizedIdentifier(['unsigned', 'int'])

