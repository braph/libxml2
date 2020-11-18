#!/usr/bin/python3

from lxml import etree

''' LibXML2 API Documentation Data Classes '''

class API_Doc():
    def __init__(self):
        self.header_files = []
        self.exports      = {}
        self.typedefs     = {}
        self.functions    = {}
        self.structs      = {}

    def read_xml(self, file):
        for section in etree.parse(file).getroot():
            if section.tag == 'symbols':
                for symbol in section:
                    if symbol.tag == 'function':
                        self.functions[symbol.attrib['name']] = Function.from_xmlnode(symbol)
                    elif symbol.tag == 'struct':
                        self.structs[symbol.attrib['name']] = Struct.from_xmlnode(symbol)
                    elif symbol.tag == 'typedef':
                        self.typedefs[symbol.attrib['name']] = Typedef.from_xmlnode(symbol)
            elif section.tag == 'files':
                for file in section:
                    self.header_files.append(file.attrib['name'])
                    for node in file:
                        if node.tag == 'exports':
                            self.exports[node.attrib['symbol']] = node.attrib['type']

        # <struct name='xmlAttributeTable' type='struct _xmlHashTable'/>
        # This create a typedef "xmlAttributeTable -> struct _xmlHashTable"
        for struct in self.structs.values():
            self.typedefs[struct.name] = Typedef(
                name = struct.name, 
                type = struct.type, 
                file = struct.file)

        new = {}
        for struct in self.structs.values():
            struct.name = struct.type.replace('struct','').strip()
            new[struct.name] = struct
        self.structs = new

        # As the relation of struct.name and struct.type is more like a typedef
        # we have to flip those.
        #for name, struct in list(self.structs.values()):


        return

        #type = symbol.attrib['type']
        #struct = Struct.from_xmlnode(symbol)
        #if struct.fields and type not in self.structs:
        #    self.structs[type] = struct

        #self.typedefs[symbol] = Typedef(
        #    name = struct.name, 
        #    type = struct.type, 
        #    file = struct.file)

        for symbol, type in self.exports.items():
            if type == 'typedef':
                struct = self.structs.get(symbol, None)
                if struct:
                    print('erm:', symbol, type, struct)
                    self.typedefs[symbol] = Typedef(
                        name = struct.name, 
                        type = struct.type, 
                        file = struct.file)

                    self.structs.pop(symbol)

class Function():
    __slots__ = ('name', 'file', 'module', 'cond', 'info', 'returns', 'args')

    def __init__(self, **kw):
        for k, v in kw.items():
            setattr(self, k, v)

    def __repr__(self):
        return "%s %s %s" % (self.returns, self.name, self.args)

    @staticmethod
    def from_xmlnode(node):
        r = Function(
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
            elif n.tag == 'arg':    r.args.append(Arg.from_xmlnode(n))
            elif n.tag == 'return': r.returns = Return.from_xmlnode(n)
        return r

class Arg():
    __slots__ = ('name', 'type', 'info')

    def __init__(self, **kw):
        for k, v in kw.items():
            setattr(self, k, v)

    def __repr__(self):
        return "%s %s" % (self.type, self.name)

    @staticmethod
    def from_xmlnode(node):
        return Arg(
            name=node.attrib['name'],
            type=node.attrib['type'],
            info=node.attrib['info'])

class Return():
    __slots__ = ('type', 'info')

    def __init__(self, **kw):
        for k, v in kw.items():
            setattr(self, k, v)

    def __repr__(self):
        return self.type

    @staticmethod
    def from_xmlnode(node):
        return Return(
            type=node.attrib.get('type'),
            info=node.attrib.get('info',''))

class Struct():
    __slots__ = ('name', 'file', 'type', 'fields')

    def __init__(self, **kw):
        self.fields = []
        for k, v in kw.items():
            setattr(self, k, v)

    def __repr__(self):
        return '%s %s' % (self.name, self.fields)

    @staticmethod
    def from_xmlnode(node):
        r = Struct(
            name   = node.attrib['name'],
            file   = node.attrib['file'],
            type   = node.attrib['type'],
            fields = [])

        for n in node:
            if n.tag == 'field': r.fields.append(Field.from_xmlnode(n))
        return r

class Field():
    __slots__ = ('name', 'type', 'info')

    def __init__(self, **kw):
        for k, v in kw.items():
            setattr(self, k, v)

    def __repr__(self):
        return '%s %s' % (self.type, self.name)

    @staticmethod
    def from_xmlnode(node):
        return Field(
            name = node.attrib['name'],
            type = node.attrib['type'],
            info = node.attrib.get('info', ''))

class Typedef():
    __slots__ = ('name', 'file', 'type')

    def __init__(self, **kw):
        for k, v in kw.items():
            setattr(self, k, v)

    def __repr__(self):
        return '%s = %s' % (self.name, self.type)

    @staticmethod
    def from_xmlnode(node):
        return Typedef(
            name = node.attrib['name'],
            file = node.attrib['file'],
            type = node.attrib['type'])


if __name__ == "__main__":
    d = API_Doc()
    d.read_xml('doc/libxml2-api.xml')
    #print(d.funcs)
    # <exports symbol='xmlAttributeTable' type='typedef'/>
    # <exports symbol='xmlAttributeTablePtr' type='typedef'/>
    #print(d.structs)
    print(d.typedefs)
