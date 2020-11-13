#include <libxml/DOCBparser.h>
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>
#include <libxml/SAX.h>
#include <libxml/SAX2.h>
#include <libxml/c14n.h>
#include <libxml/catalog.h>
#include <libxml/chvalid.h>
#include <libxml/debugXML.h>
#include <libxml/dict.h>
#include <libxml/encoding.h>
#include <libxml/entities.h>
#include <libxml/globals.h>
#include <libxml/hash.h>
#include <libxml/list.h>
#include <libxml/nanoftp.h>
#include <libxml/nanohttp.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/pattern.h>
#include <libxml/relaxng.h>
#include <libxml/schemasInternals.h>
#include <libxml/schematron.h>
#include <libxml/threads.h>
#include <libxml/tree.h>
#include <libxml/uri.h>
#include <libxml/valid.h>
#include <libxml/xinclude.h>
#include <libxml/xlink.h>
#include <libxml/xmlIO.h>
#include <libxml/xmlautomata.h>
#include <libxml/xmlerror.h>
#include <libxml/xmlexports.h>
#include <libxml/xmlmemory.h>
#include <libxml/xmlmodule.h>
#include <libxml/xmlreader.h>
#include <libxml/xmlregexp.h>
#include <libxml/xmlsave.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <libxml/xmlstring.h>
#include <libxml/xmlunicode.h>
#include <libxml/xmlversion.h>
#include <libxml/xmlwriter.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/xpointer.h>
namespace Xml {
template<bool> class ElemDesc;
template<bool> class SAXHandlerV1;
template<bool> class XlinkHandler;
template<bool> class Catalog;
template<bool> class Buf;
template<bool> class Enumeration;
template<bool> class Error;
template<bool> class URI;
template<bool> class Dict;
template<bool> class GlobalState;
template<bool> class Link;
template<bool> class Module;
template<bool> class Mutex;
template<bool> class RMutex;
template<bool> class RegExecCtxt;
template<bool> class SchemaVal;
template<bool> class SchemaSAXPlug;
template<bool> class StreamCtxt;
template<bool> class ParserInputBuffer;
template<bool> class ParserNodeInfoSeq;
template<bool> class HashTable;
template<bool> class ElementContent;
template<bool> class Ns;
template<bool> class Attr;
template<bool> class List;
template<bool> class TextWriter;
template<bool> class ParserInput;
template<bool> class Regexp;
template<bool> class RelaxNG;
template<bool> class Schema;
template<bool> class SchematronParserCtxt;
template<bool> class Schematron;
template<bool> class ShellCtxt;
template<bool> class XIncludeCtxt;
template<bool> class LocationSet;
template<bool> class CharEncodingHandler;
template<bool> class Automata;
template<bool> class DOMWrapCtxt;
template<bool> class OutputBuffer;
template<bool> class Pattern;
template<bool> class RelaxNGParserCtxt;
template<bool> class SaveCtxt;
template<bool> class SchemaParserCtxt;
template<bool> class SchematronValidCtxt;
template<bool> class XPathCompExpr;
template<bool> class XPathParserContext;
template<bool> class Dtd;
template<bool> class RelaxNGValidCtxt;
template<bool> class SchemaFacet;
template<bool> class SchemaType;
template<bool> class XPathObject;
template<bool> class NodeSet;
template<bool> class XPathContext;
template<bool> class SAXHandler;
template<bool> class SchemaValidCtxt;
template<bool> class TextReader;
template<bool> class Node;
template<bool> class ParserCtxt;
template<bool> class Buffer;
template<bool> class ValidCtxt;
template<bool> class Doc;
template<bool> class AutomataState;
template<bool> class Attribute;
template<bool> class Element;
template<bool> class Notation;
template<bool> class Entity;
template<bool> class ParserNodeInfo;
template<bool> class ID;
template<bool> class Ref;
template<bool Owning = 0>
class ElemDesc {
 _htmlElemDesc *cobj;
public:
 inline ~ElemDesc() { if (Owning) free(cobj), cobj = NULL; }
 inline ElemDesc(_htmlElemDesc *ptr) : cobj(ptr) {}
 inline ElemDesc(const ElemDesc<0> &o) : cobj(o.cobj) {}
 inline ElemDesc(const ElemDesc<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _htmlElemDesc*() { return cobj; }
 inline ElemDesc<0> release() { }
};

template<bool Owning = 0>
class SAXHandlerV1 {
 _xmlSAXHandlerV1 *cobj;
public:
 inline ~SAXHandlerV1() { if (Owning) free(cobj), cobj = NULL; }
 inline SAXHandlerV1(_xmlSAXHandlerV1 *ptr) : cobj(ptr) {}
 inline SAXHandlerV1(const SAXHandlerV1<0> &o) : cobj(o.cobj) {}
 inline SAXHandlerV1(const SAXHandlerV1<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSAXHandlerV1*() { return cobj; }
 inline SAXHandlerV1<0> release() { }
};

template<bool Owning = 0>
class XlinkHandler {
 _xlinkHandler *cobj;
public:
 inline ~XlinkHandler() { if (Owning) free(cobj), cobj = NULL; }
 inline XlinkHandler(_xlinkHandler *ptr) : cobj(ptr) {}
 inline XlinkHandler(const XlinkHandler<0> &o) : cobj(o.cobj) {}
 inline XlinkHandler(const XlinkHandler<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xlinkHandler*() { return cobj; }
 inline XlinkHandler<0> release() { }
};

template<bool Owning = 0>
class Catalog {
 _xmlCatalog *cobj;
public:
 inline ~Catalog() { if (Owning) free(cobj), cobj = NULL; }
 inline Catalog(_xmlCatalog *ptr) : cobj(ptr) {}
 inline Catalog(const Catalog<0> &o) : cobj(o.cobj) {}
 inline Catalog(const Catalog<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlCatalog*() { return cobj; }
 inline Catalog<0> release() { }
#if defined(LIBXML_CATALOG_ENABLED)
  inline int aCatalogAdd(const xmlChar * type, const xmlChar * orig, const xmlChar * replace) { return xmlACatalogAdd(cobj, type, orig, replace); }
  inline int aCatalogRemove(const xmlChar * value) { return xmlACatalogRemove(cobj, value); }
  inline xmlChar*  aCatalogResolve(const xmlChar * pubID, const xmlChar * sysID) { return xmlACatalogResolve(cobj, pubID, sysID); }
  inline xmlChar*  aCatalogResolvePublic(const xmlChar * pubID) { return xmlACatalogResolvePublic(cobj, pubID); }
  inline xmlChar*  aCatalogResolveSystem(const xmlChar * sysID) { return xmlACatalogResolveSystem(cobj, sysID); }
  inline xmlChar*  aCatalogResolveURI(const xmlChar * URI) { return xmlACatalogResolveURI(cobj, URI); }
  inline int isEmpty() { return xmlCatalogIsEmpty(cobj); }
  inline int convertSGMLCatalog() { return xmlConvertSGMLCatalog(cobj); }
  inline static Catalog<1-Owning*0> newCatalog(int sgml) { return xmlNewCatalog(sgml); }
#endif
#if defined(LIBXML_CATALOG_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
  inline void aCatalogDump(FILE * out) { xmlACatalogDump(cobj, out); }
#endif
};

template<bool Owning = 0>
class Buf {
 _xmlBuf *cobj;
public:
 inline ~Buf() { if (Owning) free(cobj), cobj = NULL; }
 inline Buf(_xmlBuf *ptr) : cobj(ptr) {}
 inline Buf(const Buf<0> &o) : cobj(o.cobj) {}
 inline Buf(const Buf<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlBuf*() { return cobj; }
 inline Buf<0> release() { }
 inline xmlChar*  content() const { return xmlBufContent(cobj); }
 inline xmlChar*  end() { return xmlBufEnd(cobj); }
 inline size_t shrink(size_t len) { return xmlBufShrink(cobj, len); }
 inline size_t use() { return xmlBufUse(cobj); }
};

template<bool Owning = 0>
class Enumeration {
 _xmlEnumeration *cobj;
public:
 inline ~Enumeration() { if (Owning) free(cobj), cobj = NULL; }
 inline Enumeration(_xmlEnumeration *ptr) : cobj(ptr) {}
 inline Enumeration(const Enumeration<0> &o) : cobj(o.cobj) {}
 inline Enumeration(const Enumeration<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlEnumeration*() { return cobj; }
 inline Enumeration<0> release() { }
 inline static Enumeration<1-Owning*0> createEnumeration(const xmlChar * name) { return xmlCreateEnumeration(name); }
#if defined(LIBXML_TREE_ENABLED)
  inline Enumeration<1-Owning*0> copyEnumeration() { return xmlCopyEnumeration(cobj); }
#endif
};

template<bool Owning = 0>
class Error {
 _xmlError *cobj;
public:
 inline ~Error() { if (Owning) free(cobj), cobj = NULL; }
 inline Error(_xmlError *ptr) : cobj(ptr) {}
 inline Error(const Error<0> &o) : cobj(o.cobj) {}
 inline Error(const Error<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlError*() { return cobj; }
 inline Error<0> release() { }
 inline int copyError(xmlErrorPtr to) { return xmlCopyError(cobj, to); }
 inline void resetError() { xmlResetError(cobj); }
};

template<bool Owning = 0>
class URI {
 _xmlURI *cobj;
public:
 inline ~URI() { if (Owning) free(cobj), cobj = NULL; }
 inline URI(_xmlURI *ptr) : cobj(ptr) {}
 inline URI(const URI<0> &o) : cobj(o.cobj) {}
 inline URI(const URI<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlURI*() { return cobj; }
 inline URI<0> release() { }
 inline static URI<1-Owning*0> createURI() { return xmlCreateURI(); }
 inline static URI<1-Owning*0> parseURI(const char * str) { return xmlParseURI(str); }
 inline static URI<1-Owning*0> parseURIRaw(const char * str, int raw) { return xmlParseURIRaw(str, raw); }
 inline int parseURIReference(const char * str) { return xmlParseURIReference(cobj, str); }
 inline xmlChar*  saveUri() { return xmlSaveUri(cobj); }
};

template<bool Owning = 0>
class Dict {
 _xmlDict *cobj;
public:
 inline ~Dict() { if (Owning) free(cobj), cobj = NULL; }
 inline Dict(_xmlDict *ptr) : cobj(ptr) {}
 inline Dict(const Dict<0> &o) : cobj(o.cobj) {}
 inline Dict(const Dict<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlDict*() { return cobj; }
 inline Dict<0> release() { }
 inline static Dict<1-Owning*0> create() { return xmlDictCreate(); }
 inline Dict<1-Owning*0> createSub() { return xmlDictCreateSub(cobj); }
 inline xmlChar*  exists(const xmlChar * name, int len) { return xmlDictExists(cobj, name, len); }
 inline size_t getUsage() { return xmlDictGetUsage(cobj); }
 inline xmlChar*  lookup(const xmlChar * name, int len) { return xmlDictLookup(cobj, name, len); }
 inline int owns(const xmlChar * str) { return xmlDictOwns(cobj, str); }
 inline xmlChar*  qLookup(const xmlChar * prefix, const xmlChar * name) { return xmlDictQLookup(cobj, prefix, name); }
 inline int reference() { return xmlDictReference(cobj); }
 inline size_t setLimit(size_t limit) { return xmlDictSetLimit(cobj, limit); }
 inline int size() { return xmlDictSize(cobj); }
};

template<bool Owning = 0>
class GlobalState {
 _xmlGlobalState *cobj;
public:
 inline ~GlobalState() { if (Owning) free(cobj), cobj = NULL; }
 inline GlobalState(_xmlGlobalState *ptr) : cobj(ptr) {}
 inline GlobalState(const GlobalState<0> &o) : cobj(o.cobj) {}
 inline GlobalState(const GlobalState<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlGlobalState*() { return cobj; }
 inline GlobalState<0> release() { }
 inline void initializeGlobalState() { xmlInitializeGlobalState(cobj); }
};

template<bool Owning = 0>
class Link {
 _xmlLink *cobj;
public:
 inline ~Link() { if (Owning) free(cobj), cobj = NULL; }
 inline Link(_xmlLink *ptr) : cobj(ptr) {}
 inline Link(const Link<0> &o) : cobj(o.cobj) {}
 inline Link(const Link<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlLink*() { return cobj; }
 inline Link<0> release() { }
 inline void * getData() { return xmlLinkGetData(cobj); }
};

template<bool Owning = 0>
class Module {
 _xmlModule *cobj;
public:
 inline ~Module() { if (Owning) free(cobj), cobj = NULL; }
 inline Module(_xmlModule *ptr) : cobj(ptr) {}
 inline Module(const Module<0> &o) : cobj(o.cobj) {}
 inline Module(const Module<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlModule*() { return cobj; }
 inline Module<0> release() { }
#if defined(LIBXML_MODULES_ENABLED)
  inline int close() { return xmlModuleClose(cobj); }
  inline int symbol(const char * name, void ** symbol) { return xmlModuleSymbol(cobj, name, symbol); }
#endif
};

template<bool Owning = 0>
class Mutex {
 _xmlMutex *cobj;
public:
 inline ~Mutex() { if (Owning) free(cobj), cobj = NULL; }
 inline Mutex(_xmlMutex *ptr) : cobj(ptr) {}
 inline Mutex(const Mutex<0> &o) : cobj(o.cobj) {}
 inline Mutex(const Mutex<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlMutex*() { return cobj; }
 inline Mutex<0> release() { }
 inline void lock() { xmlMutexLock(cobj); }
 inline void unlock() { xmlMutexUnlock(cobj); }
 inline static Mutex<1-Owning*0> newMutex() { return xmlNewMutex(); }
};

template<bool Owning = 0>
class RMutex {
 _xmlRMutex *cobj;
public:
 inline ~RMutex() { if (Owning) free(cobj), cobj = NULL; }
 inline RMutex(_xmlRMutex *ptr) : cobj(ptr) {}
 inline RMutex(const RMutex<0> &o) : cobj(o.cobj) {}
 inline RMutex(const RMutex<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlRMutex*() { return cobj; }
 inline RMutex<0> release() { }
 inline static RMutex<1-Owning*0> newRMutex() { return xmlNewRMutex(); }
 inline void lock() { xmlRMutexLock(cobj); }
 inline void unlock() { xmlRMutexUnlock(cobj); }
};

template<bool Owning = 0>
class RegExecCtxt {
 _xmlRegExecCtxt *cobj;
public:
 inline ~RegExecCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline RegExecCtxt(_xmlRegExecCtxt *ptr) : cobj(ptr) {}
 inline RegExecCtxt(const RegExecCtxt<0> &o) : cobj(o.cobj) {}
 inline RegExecCtxt(const RegExecCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlRegExecCtxt*() { return cobj; }
 inline RegExecCtxt<0> release() { }
#if defined(LIBXML_REGEXP_ENABLED)
  inline int errInfo(const xmlChar ** string, int * nbval, int * nbneg, xmlChar ** values, int * terminal) { return xmlRegExecErrInfo(cobj, string, nbval, nbneg, values, terminal); }
  inline int nextValues(int * nbval, int * nbneg, xmlChar ** values, int * terminal) { return xmlRegExecNextValues(cobj, nbval, nbneg, values, terminal); }
  inline int pushString(const xmlChar * value, void * data) { return xmlRegExecPushString(cobj, value, data); }
  inline int pushString2(const xmlChar * value, const xmlChar * value2, void * data) { return xmlRegExecPushString2(cobj, value, value2, data); }
#endif
};

template<bool Owning = 0>
class SchemaVal {
 _xmlSchemaVal *cobj;
public:
 inline ~SchemaVal() { if (Owning) free(cobj), cobj = NULL; }
 inline SchemaVal(_xmlSchemaVal *ptr) : cobj(ptr) {}
 inline SchemaVal(const SchemaVal<0> &o) : cobj(o.cobj) {}
 inline SchemaVal(const SchemaVal<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchemaVal*() { return cobj; }
 inline SchemaVal<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline int compareValues(xmlSchemaValPtr y) { return xmlSchemaCompareValues(cobj, y); }
  inline int compareValuesWhtsp(xmlSchemaWhitespaceValueType xws, xmlSchemaValPtr y, xmlSchemaWhitespaceValueType yws) { return xmlSchemaCompareValuesWhtsp(cobj, xws, y, yws); }
  inline SchemaVal<1-Owning*0> copyValue() { return xmlSchemaCopyValue(cobj); }
  inline int getCanonValue(const xmlChar ** retValue) { return xmlSchemaGetCanonValue(cobj, retValue); }
  inline int getCanonValueWhtsp(const xmlChar ** retValue, xmlSchemaWhitespaceValueType ws) { return xmlSchemaGetCanonValueWhtsp(cobj, retValue, ws); }
  inline xmlSchemaValType getValType() { return xmlSchemaGetValType(cobj); }
  inline static SchemaVal<1-Owning*0> newNOTATIONValue(const xmlChar * name, const xmlChar * ns) { return xmlSchemaNewNOTATIONValue(name, ns); }
  inline static SchemaVal<1-Owning*0> newQNameValue(const xmlChar * namespaceName, const xmlChar * localName) { return xmlSchemaNewQNameValue(namespaceName, localName); }
  inline static SchemaVal<1-Owning*0> newStringValue(xmlSchemaValType type, const xmlChar * value) { return xmlSchemaNewStringValue(type, value); }
  inline int valueAppend(xmlSchemaValPtr prev) { return xmlSchemaValueAppend(prev, cobj); }
  inline int valueGetAsBoolean() { return xmlSchemaValueGetAsBoolean(cobj); }
  inline xmlChar*  valueGetAsString() { return xmlSchemaValueGetAsString(cobj); }
  inline SchemaVal<0-Owning*0> valueGetNext() { return xmlSchemaValueGetNext(cobj); }
#endif
};

template<bool Owning = 0>
class SchemaSAXPlug {
 _xmlSchemaSAXPlug *cobj;
public:
 inline ~SchemaSAXPlug() { if (Owning) free(cobj), cobj = NULL; }
 inline SchemaSAXPlug(_xmlSchemaSAXPlug *ptr) : cobj(ptr) {}
 inline SchemaSAXPlug(const SchemaSAXPlug<0> &o) : cobj(o.cobj) {}
 inline SchemaSAXPlug(const SchemaSAXPlug<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchemaSAXPlug*() { return cobj; }
 inline SchemaSAXPlug<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline int unplug() { return xmlSchemaSAXUnplug(cobj); }
#endif
};

template<bool Owning = 0>
class StreamCtxt {
 _xmlStreamCtxt *cobj;
public:
 inline ~StreamCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline StreamCtxt(_xmlStreamCtxt *ptr) : cobj(ptr) {}
 inline StreamCtxt(const StreamCtxt<0> &o) : cobj(o.cobj) {}
 inline StreamCtxt(const StreamCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlStreamCtxt*() { return cobj; }
 inline StreamCtxt<0> release() { }
#if defined(LIBXML_PATTERN_ENABLED)
  inline int pop() { return xmlStreamPop(cobj); }
  inline int push(const xmlChar * name, const xmlChar * ns) { return xmlStreamPush(cobj, name, ns); }
  inline int pushAttr(const xmlChar * name, const xmlChar * ns) { return xmlStreamPushAttr(cobj, name, ns); }
  inline int pushNode(const xmlChar * name, const xmlChar * ns, int nodeType) { return xmlStreamPushNode(cobj, name, ns, nodeType); }
  inline int wantsAnyNode() { return xmlStreamWantsAnyNode(cobj); }
#endif
};

template<bool Owning = 0>
class ParserInputBuffer {
 _xmlParserInputBuffer *cobj;
public:
 inline ~ParserInputBuffer() { if (Owning) free(cobj), cobj = NULL; }
 inline ParserInputBuffer(_xmlParserInputBuffer *ptr) : cobj(ptr) {}
 inline ParserInputBuffer(const ParserInputBuffer<0> &o) : cobj(o.cobj) {}
 inline ParserInputBuffer(const ParserInputBuffer<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlParserInputBuffer*() { return cobj; }
 inline ParserInputBuffer<0> release() { }
 inline static ParserInputBuffer<1-Owning*0> allocParserInputBuffer(xmlCharEncoding enc) { return xmlAllocParserInputBuffer(enc); }
 inline static ParserInputBuffer<1-Owning*0> createFd(int fd, xmlCharEncoding enc) { return xmlParserInputBufferCreateFd(fd, enc); }
 inline static ParserInputBuffer<1-Owning*0> createFile(FILE * file, xmlCharEncoding enc) { return xmlParserInputBufferCreateFile(file, enc); }
 inline static ParserInputBuffer<1-Owning*0> createFilename(const char * URI, xmlCharEncoding enc) { return xmlParserInputBufferCreateFilename(URI, enc); }
 inline static ParserInputBuffer<1-Owning*0> createIO(xmlInputReadCallback ioread, xmlInputCloseCallback ioclose, void * ioctx, xmlCharEncoding enc) { return xmlParserInputBufferCreateIO(ioread, ioclose, ioctx, enc); }
 inline static ParserInputBuffer<1-Owning*0> createMem(const char * mem, int size, xmlCharEncoding enc) { return xmlParserInputBufferCreateMem(mem, size, enc); }
 inline static ParserInputBuffer<1-Owning*0> createStatic(const char * mem, int size, xmlCharEncoding enc) { return xmlParserInputBufferCreateStatic(mem, size, enc); }
 inline int grow(int len) { return xmlParserInputBufferGrow(cobj, len); }
 inline int push(int len, const char * buf) { return xmlParserInputBufferPush(cobj, len, buf); }
 inline int read(int len) { return xmlParserInputBufferRead(cobj, len); }
#if defined(LIBXML_READER_ENABLED)
  inline TextReader<1-Owning*0> newTextReader(const char * URI) { return xmlNewTextReader(cobj, URI); }
#endif
};

template<bool Owning = 0>
class ParserNodeInfoSeq {
 _xmlParserNodeInfoSeq *cobj;
public:
 inline ~ParserNodeInfoSeq() { if (Owning) free(cobj), cobj = NULL; }
 inline ParserNodeInfoSeq(_xmlParserNodeInfoSeq *ptr) : cobj(ptr) {}
 inline ParserNodeInfoSeq(const ParserNodeInfoSeq<0> &o) : cobj(o.cobj) {}
 inline ParserNodeInfoSeq(const ParserNodeInfoSeq<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlParserNodeInfoSeq*() { return cobj; }
 inline ParserNodeInfoSeq<0> release() { }
 inline void clearNodeInfoSeq() { xmlClearNodeInfoSeq(cobj); }
 inline void initNodeInfoSeq() { xmlInitNodeInfoSeq(cobj); }
 inline unsigned long findNodeInfoIndex(const xmlNodePtr node) { return xmlParserFindNodeInfoIndex(cobj, node); }
};

template<bool Owning = 0>
class HashTable {
 _xmlHashTable *cobj;
public:
 inline ~HashTable() { if (Owning) free(cobj), cobj = NULL; }
 inline HashTable(_xmlHashTable *ptr) : cobj(ptr) {}
 inline HashTable(const HashTable<0> &o) : cobj(o.cobj) {}
 inline HashTable(const HashTable<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlHashTable*() { return cobj; }
 inline HashTable<0> release() { }
 inline static HashTable<1-Owning*0> createEntitiesTable() { return xmlCreateEntitiesTable(); }
 inline int addEntry(const xmlChar * name, void * userdata) { return xmlHashAddEntry(cobj, name, userdata); }
 inline int addEntry2(const xmlChar * name, const xmlChar * name2, void * userdata) { return xmlHashAddEntry2(cobj, name, name2, userdata); }
 inline int addEntry3(const xmlChar * name, const xmlChar * name2, const xmlChar * name3, void * userdata) { return xmlHashAddEntry3(cobj, name, name2, name3, userdata); }
 inline HashTable<1-Owning*0> copy(xmlHashCopier f) { return xmlHashCopy(cobj, f); }
 inline static HashTable<1-Owning*0> create(int size) { return xmlHashCreate(size); }
 inline static HashTable<1-Owning*0> createDict(int size, xmlDictPtr dict) { return xmlHashCreateDict(size, dict); }
 inline void free(xmlHashDeallocator f) { xmlHashFree(cobj, f); }
 inline void * lookup(const xmlChar * name) { return xmlHashLookup(cobj, name); }
 inline void * lookup2(const xmlChar * name, const xmlChar * name2) { return xmlHashLookup2(cobj, name, name2); }
 inline void * lookup3(const xmlChar * name, const xmlChar * name2, const xmlChar * name3) { return xmlHashLookup3(cobj, name, name2, name3); }
 inline void * qLookup(const xmlChar * prefix, const xmlChar * name) { return xmlHashQLookup(cobj, prefix, name); }
 inline void * qLookup2(const xmlChar * prefix, const xmlChar * name, const xmlChar * prefix2, const xmlChar * name2) { return xmlHashQLookup2(cobj, prefix, name, prefix2, name2); }
 inline void * qLookup3(const xmlChar * prefix, const xmlChar * name, const xmlChar * prefix2, const xmlChar * name2, const xmlChar * prefix3, const xmlChar * name3) { return xmlHashQLookup3(cobj, prefix, name, prefix2, name2, prefix3, name3); }
 inline int removeEntry(const xmlChar * name, xmlHashDeallocator f) { return xmlHashRemoveEntry(cobj, name, f); }
 inline int removeEntry2(const xmlChar * name, const xmlChar * name2, xmlHashDeallocator f) { return xmlHashRemoveEntry2(cobj, name, name2, f); }
 inline int removeEntry3(const xmlChar * name, const xmlChar * name2, const xmlChar * name3, xmlHashDeallocator f) { return xmlHashRemoveEntry3(cobj, name, name2, name3, f); }
 inline void scan(xmlHashScanner f, void * data) { xmlHashScan(cobj, f, data); }
 inline void scan3(const xmlChar * name, const xmlChar * name2, const xmlChar * name3, xmlHashScanner f, void * data) { xmlHashScan3(cobj, name, name2, name3, f, data); }
 inline void scanFull(xmlHashScannerFull f, void * data) { xmlHashScanFull(cobj, f, data); }
 inline void scanFull3(const xmlChar * name, const xmlChar * name2, const xmlChar * name3, xmlHashScannerFull f, void * data) { xmlHashScanFull3(cobj, name, name2, name3, f, data); }
 inline int size() { return xmlHashSize(cobj); }
 inline int updateEntry(const xmlChar * name, void * userdata, xmlHashDeallocator f) { return xmlHashUpdateEntry(cobj, name, userdata, f); }
 inline int updateEntry2(const xmlChar * name, const xmlChar * name2, void * userdata, xmlHashDeallocator f) { return xmlHashUpdateEntry2(cobj, name, name2, userdata, f); }
 inline int updateEntry3(const xmlChar * name, const xmlChar * name2, const xmlChar * name3, void * userdata, xmlHashDeallocator f) { return xmlHashUpdateEntry3(cobj, name, name2, name3, userdata, f); }
#if defined(LIBXML_TREE_ENABLED)
  inline HashTable<1-Owning*0> copyAttributeTable() { return xmlCopyAttributeTable(cobj); }
  inline HashTable<1-Owning*0> copyElementTable() { return xmlCopyElementTable(cobj); }
  inline HashTable<1-Owning*0> copyEntitiesTable() { return xmlCopyEntitiesTable(cobj); }
  inline HashTable<1-Owning*0> copyNotationTable() { return xmlCopyNotationTable(cobj); }
#endif
};

template<bool Owning = 0>
class ElementContent {
 _xmlElementContent *cobj;
public:
 inline ~ElementContent() { if (Owning) free(cobj), cobj = NULL; }
 inline ElementContent(_xmlElementContent *ptr) : cobj(ptr) {}
 inline ElementContent(const ElementContent<0> &o) : cobj(o.cobj) {}
 inline ElementContent(const ElementContent<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlElementContent*() { return cobj; }
 inline ElementContent<0> release() { }
 inline ElementContent<1-Owning*0> copyElementContent() { return xmlCopyElementContent(cobj); }
 inline void freeDocElementContent(xmlDocPtr doc) { xmlFreeDocElementContent(doc, cobj); }
 inline static ElementContent<1-Owning*0> newElementContent(const xmlChar * name, xmlElementContentType type) { return xmlNewElementContent(name, type); }
#if defined(LIBXML_VALID_ENABLED)
  inline int validGetPotentialChildren(const xmlChar ** names, int * len, int max) { return xmlValidGetPotentialChildren(cobj, names, len, max); }
#endif
};

template<bool Owning = 0>
class Ns {
 _xmlNs *cobj;
public:
 inline ~Ns() { if (Owning) free(cobj), cobj = NULL; }
 inline Ns(_xmlNs *ptr) : cobj(ptr) {}
 inline Ns(const Ns<0> &o) : cobj(o.cobj) {}
 inline Ns(const Ns<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlNs*() { return cobj; }
 inline Ns<0> release() { }
 inline Ns<1-Owning*0> copyNamespace() { return xmlCopyNamespace(cobj); }
 inline Ns<1-Owning*0> copyNamespaceList() { return xmlCopyNamespaceList(cobj); }
 inline Node<1-Owning*0> newNode(const xmlChar * name) { return xmlNewNode(cobj, name); }
 inline Node<1-Owning*0> newNodeEatName(xmlChar * name) { return xmlNewNodeEatName(cobj, name); }
};

template<bool Owning = 0>
class Attr {
 _xmlAttr *cobj;
public:
 inline ~Attr() { if (Owning) free(cobj), cobj = NULL; }
 inline Attr(_xmlAttr *ptr) : cobj(ptr) {}
 inline Attr(const Attr<0> &o) : cobj(o.cobj) {}
 inline Attr(const Attr<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlAttr*() { return cobj; }
 inline Attr<0> release() { }
 inline Attr<1-Owning*0> copyProp(xmlNodePtr target) { return xmlCopyProp(target, cobj); }
 inline Attr<1-Owning*0> copyPropList(xmlNodePtr target) { return xmlCopyPropList(target, cobj); }
 inline int removeProp() { return xmlRemoveProp(cobj); }
};

template<bool Owning = 0>
class List {
 _xmlList *cobj;
public:
 inline ~List() { if (Owning) free(cobj), cobj = NULL; }
 inline List(_xmlList *ptr) : cobj(ptr) {}
 inline List(const List<0> &o) : cobj(o.cobj) {}
 inline List(const List<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlList*() { return cobj; }
 inline List<0> release() { }
 inline int append(void * data) { return xmlListAppend(cobj, data); }
 inline void clear() { xmlListClear(cobj); }
 inline int copy(const xmlListPtr old) { return xmlListCopy(cobj, old); }
 inline static List<1-Owning*0> create(xmlListDeallocator deallocator, xmlListDataCompare compare) { return xmlListCreate(deallocator, compare); }
 inline void Delete() { xmlListDelete(cobj); }
 inline List<1-Owning*0> dup() { return xmlListDup(cobj); }
 inline int empty() { return xmlListEmpty(cobj); }
 inline Link<0-Owning*0> end() { return xmlListEnd(cobj); }
 inline Link<0-Owning*0> front() { return xmlListFront(cobj); }
 inline int insert(void * data) { return xmlListInsert(cobj, data); }
 inline void merge(xmlListPtr l2) { xmlListMerge(cobj, l2); }
 inline void popBack() { xmlListPopBack(cobj); }
 inline void popFront() { xmlListPopFront(cobj); }
 inline int pushBack(void * data) { return xmlListPushBack(cobj, data); }
 inline int pushFront(void * data) { return xmlListPushFront(cobj, data); }
 inline int removeAll(void * data) { return xmlListRemoveAll(cobj, data); }
 inline int removeFirst(void * data) { return xmlListRemoveFirst(cobj, data); }
 inline int removeLast(void * data) { return xmlListRemoveLast(cobj, data); }
 inline void reverse() { xmlListReverse(cobj); }
 inline void * reverseSearch(void * data) { return xmlListReverseSearch(cobj, data); }
 inline void reverseWalk(xmlListWalker walker, void * user) { xmlListReverseWalk(cobj, walker, user); }
 inline void * search(void * data) { return xmlListSearch(cobj, data); }
 inline int size() { return xmlListSize(cobj); }
 inline void sort() { xmlListSort(cobj); }
 inline void walk(xmlListWalker walker, void * user) { xmlListWalk(cobj, walker, user); }
};

template<bool Owning = 0>
class TextWriter {
 _xmlTextWriter *cobj;
public:
 inline ~TextWriter() { if (Owning) free(cobj), cobj = NULL; }
 inline TextWriter(_xmlTextWriter *ptr) : cobj(ptr) {}
 inline TextWriter(const TextWriter<0> &o) : cobj(o.cobj) {}
 inline TextWriter(const TextWriter<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlTextWriter*() { return cobj; }
 inline TextWriter<0> release() { }
#if defined(LIBXML_WRITER_ENABLED)
  inline static TextWriter<1-Owning*0> newTextWriterDoc(xmlDocPtr * doc, int compression) { return xmlNewTextWriterDoc(doc, compression); }
  inline static TextWriter<1-Owning*0> newTextWriterFilename(const char * uri, int compression) { return xmlNewTextWriterFilename(uri, compression); }
  inline int endAttribute() { return xmlTextWriterEndAttribute(cobj); }
  inline int endCDATA() { return xmlTextWriterEndCDATA(cobj); }
  inline int endComment() { return xmlTextWriterEndComment(cobj); }
  inline int endDTD() { return xmlTextWriterEndDTD(cobj); }
  inline int endDTDAttlist() { return xmlTextWriterEndDTDAttlist(cobj); }
  inline int endDTDElement() { return xmlTextWriterEndDTDElement(cobj); }
  inline int endDTDEntity() { return xmlTextWriterEndDTDEntity(cobj); }
  inline int endDocument() { return xmlTextWriterEndDocument(cobj); }
  inline int endElement() { return xmlTextWriterEndElement(cobj); }
  inline int endPI() { return xmlTextWriterEndPI(cobj); }
  inline int flush() { return xmlTextWriterFlush(cobj); }
  inline int fullEndElement() { return xmlTextWriterFullEndElement(cobj); }
  inline int setIndent(int indent) { return xmlTextWriterSetIndent(cobj, indent); }
  inline int setIndentString(const xmlChar * str) { return xmlTextWriterSetIndentString(cobj, str); }
  inline int setQuoteChar(xmlChar quotechar) { return xmlTextWriterSetQuoteChar(cobj, quotechar); }
  inline int startAttribute(const xmlChar * name) { return xmlTextWriterStartAttribute(cobj, name); }
  inline int startAttributeNS(const xmlChar * prefix, const xmlChar * name, const xmlChar * namespaceURI) { return xmlTextWriterStartAttributeNS(cobj, prefix, name, namespaceURI); }
  inline int startCDATA() { return xmlTextWriterStartCDATA(cobj); }
  inline int startComment() { return xmlTextWriterStartComment(cobj); }
  inline int startDTD(const xmlChar * name, const xmlChar * pubid, const xmlChar * sysid) { return xmlTextWriterStartDTD(cobj, name, pubid, sysid); }
  inline int startDTDAttlist(const xmlChar * name) { return xmlTextWriterStartDTDAttlist(cobj, name); }
  inline int startDTDElement(const xmlChar * name) { return xmlTextWriterStartDTDElement(cobj, name); }
  inline int startDTDEntity(int pe, const xmlChar * name) { return xmlTextWriterStartDTDEntity(cobj, pe, name); }
  inline int startDocument(const char * version, const char * encoding, const char * standalone) { return xmlTextWriterStartDocument(cobj, version, encoding, standalone); }
  inline int startElement(const xmlChar * name) { return xmlTextWriterStartElement(cobj, name); }
  inline int startElementNS(const xmlChar * prefix, const xmlChar * name, const xmlChar * namespaceURI) { return xmlTextWriterStartElementNS(cobj, prefix, name, namespaceURI); }
  inline int startPI(const xmlChar * target) { return xmlTextWriterStartPI(cobj, target); }
  inline int writeAttribute(const xmlChar * name, const xmlChar * content) { return xmlTextWriterWriteAttribute(cobj, name, content); }
  inline int writeAttributeNS(const xmlChar * prefix, const xmlChar * name, const xmlChar * namespaceURI, const xmlChar * content) { return xmlTextWriterWriteAttributeNS(cobj, prefix, name, namespaceURI, content); }
  inline int writeBase64(const char * data, int start, int len) { return xmlTextWriterWriteBase64(cobj, data, start, len); }
  inline int writeBinHex(const char * data, int start, int len) { return xmlTextWriterWriteBinHex(cobj, data, start, len); }
  inline int writeCDATA(const xmlChar * content) { return xmlTextWriterWriteCDATA(cobj, content); }
  inline int writeComment(const xmlChar * content) { return xmlTextWriterWriteComment(cobj, content); }
  inline int writeDTD(const xmlChar * name, const xmlChar * pubid, const xmlChar * sysid, const xmlChar * subset) { return xmlTextWriterWriteDTD(cobj, name, pubid, sysid, subset); }
  inline int writeDTDAttlist(const xmlChar * name, const xmlChar * content) { return xmlTextWriterWriteDTDAttlist(cobj, name, content); }
  inline int writeDTDElement(const xmlChar * name, const xmlChar * content) { return xmlTextWriterWriteDTDElement(cobj, name, content); }
  inline int writeDTDEntity(int pe, const xmlChar * name, const xmlChar * pubid, const xmlChar * sysid, const xmlChar * ndataid, const xmlChar * content) { return xmlTextWriterWriteDTDEntity(cobj, pe, name, pubid, sysid, ndataid, content); }
  inline int writeDTDExternalEntity(int pe, const xmlChar * name, const xmlChar * pubid, const xmlChar * sysid, const xmlChar * ndataid) { return xmlTextWriterWriteDTDExternalEntity(cobj, pe, name, pubid, sysid, ndataid); }
  inline int writeDTDExternalEntityContents(const xmlChar * pubid, const xmlChar * sysid, const xmlChar * ndataid) { return xmlTextWriterWriteDTDExternalEntityContents(cobj, pubid, sysid, ndataid); }
  inline int writeDTDInternalEntity(int pe, const xmlChar * name, const xmlChar * content) { return xmlTextWriterWriteDTDInternalEntity(cobj, pe, name, content); }
  inline int writeDTDNotation(const xmlChar * name, const xmlChar * pubid, const xmlChar * sysid) { return xmlTextWriterWriteDTDNotation(cobj, name, pubid, sysid); }
  inline int writeElement(const xmlChar * name, const xmlChar * content) { return xmlTextWriterWriteElement(cobj, name, content); }
  inline int writeElementNS(const xmlChar * prefix, const xmlChar * name, const xmlChar * namespaceURI, const xmlChar * content) { return xmlTextWriterWriteElementNS(cobj, prefix, name, namespaceURI, content); }
  
  
  
  
  
  
  
  
  
  
  
  
  
  inline int writePI(const xmlChar * target, const xmlChar * content) { return xmlTextWriterWritePI(cobj, target, content); }
  inline int writeRaw(const xmlChar * content) { return xmlTextWriterWriteRaw(cobj, content); }
  inline int writeRawLen(const xmlChar * content, int len) { return xmlTextWriterWriteRawLen(cobj, content, len); }
  inline int writeString(const xmlChar * content) { return xmlTextWriterWriteString(cobj, content); }
  inline int writeVFormatAttribute(const xmlChar * name, const char * format, va_list argptr) { return xmlTextWriterWriteVFormatAttribute(cobj, name, format, argptr); }
  inline int writeVFormatAttributeNS(const xmlChar * prefix, const xmlChar * name, const xmlChar * namespaceURI, const char * format, va_list argptr) { return xmlTextWriterWriteVFormatAttributeNS(cobj, prefix, name, namespaceURI, format, argptr); }
  inline int writeVFormatCDATA(const char * format, va_list argptr) { return xmlTextWriterWriteVFormatCDATA(cobj, format, argptr); }
  inline int writeVFormatComment(const char * format, va_list argptr) { return xmlTextWriterWriteVFormatComment(cobj, format, argptr); }
  inline int writeVFormatDTD(const xmlChar * name, const xmlChar * pubid, const xmlChar * sysid, const char * format, va_list argptr) { return xmlTextWriterWriteVFormatDTD(cobj, name, pubid, sysid, format, argptr); }
  inline int writeVFormatDTDAttlist(const xmlChar * name, const char * format, va_list argptr) { return xmlTextWriterWriteVFormatDTDAttlist(cobj, name, format, argptr); }
  inline int writeVFormatDTDElement(const xmlChar * name, const char * format, va_list argptr) { return xmlTextWriterWriteVFormatDTDElement(cobj, name, format, argptr); }
  inline int writeVFormatDTDInternalEntity(int pe, const xmlChar * name, const char * format, va_list argptr) { return xmlTextWriterWriteVFormatDTDInternalEntity(cobj, pe, name, format, argptr); }
  inline int writeVFormatElement(const xmlChar * name, const char * format, va_list argptr) { return xmlTextWriterWriteVFormatElement(cobj, name, format, argptr); }
  inline int writeVFormatElementNS(const xmlChar * prefix, const xmlChar * name, const xmlChar * namespaceURI, const char * format, va_list argptr) { return xmlTextWriterWriteVFormatElementNS(cobj, prefix, name, namespaceURI, format, argptr); }
  inline int writeVFormatPI(const xmlChar * target, const char * format, va_list argptr) { return xmlTextWriterWriteVFormatPI(cobj, target, format, argptr); }
  inline int writeVFormatRaw(const char * format, va_list argptr) { return xmlTextWriterWriteVFormatRaw(cobj, format, argptr); }
  inline int writeVFormatString(const char * format, va_list argptr) { return xmlTextWriterWriteVFormatString(cobj, format, argptr); }
#endif
};

template<bool Owning = 0>
class ParserInput {
 _xmlParserInput *cobj;
public:
 inline ~ParserInput() { if (Owning) free(cobj), cobj = NULL; }
 inline ParserInput(_xmlParserInput *ptr) : cobj(ptr) {}
 inline ParserInput(const ParserInput<0> &o) : cobj(o.cobj) {}
 inline ParserInput(const ParserInput<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlParserInput*() { return cobj; }
 inline ParserInput<0> release() { }
 inline static ParserInput<1-Owning*0> noNetExternalEntityLoader(const char * URL, const char * ID, xmlParserCtxtPtr ctxt) { return xmlNoNetExternalEntityLoader(URL, ID, ctxt); }
 inline int grow(int len) { return xmlParserInputGrow(cobj, len); }
 inline int read(int len) { return xmlParserInputRead(cobj, len); }
 inline void shrink() { xmlParserInputShrink(cobj); }
 inline void printFileContext() { xmlParserPrintFileContext(cobj); }
 inline void printFileInfo() { xmlParserPrintFileInfo(cobj); }
};

template<bool Owning = 0>
class Regexp {
 _xmlRegexp *cobj;
public:
 inline ~Regexp() { if (Owning) free(cobj), cobj = NULL; }
 inline Regexp(_xmlRegexp *ptr) : cobj(ptr) {}
 inline Regexp(const Regexp<0> &o) : cobj(o.cobj) {}
 inline Regexp(const Regexp<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlRegexp*() { return cobj; }
 inline Regexp<0> release() { }
#if defined(LIBXML_REGEXP_ENABLED)
  inline RegExecCtxt<1-Owning*0> regNewExecCtxt(xmlRegExecCallbacks callback, void * data) { return xmlRegNewExecCtxt(cobj, callback, data); }
  inline int exec(const xmlChar * content) { return xmlRegexpExec(cobj, content); }
  inline int isDeterminist() { return xmlRegexpIsDeterminist(cobj); }
#endif
};

template<bool Owning = 0>
class RelaxNG {
 _xmlRelaxNG *cobj;
public:
 inline ~RelaxNG() { if (Owning) free(cobj), cobj = NULL; }
 inline RelaxNG(_xmlRelaxNG *ptr) : cobj(ptr) {}
 inline RelaxNG(const RelaxNG<0> &o) : cobj(o.cobj) {}
 inline RelaxNG(const RelaxNG<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlRelaxNG*() { return cobj; }
 inline RelaxNG<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline RelaxNGValidCtxt<1-Owning*0> newValidCtxt() { return xmlRelaxNGNewValidCtxt(cobj); }
#endif
};

template<bool Owning = 0>
class Schema {
 _xmlSchema *cobj;
public:
 inline ~Schema() { if (Owning) free(cobj), cobj = NULL; }
 inline Schema(_xmlSchema *ptr) : cobj(ptr) {}
 inline Schema(const Schema<0> &o) : cobj(o.cobj) {}
 inline Schema(const Schema<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchema*() { return cobj; }
 inline Schema<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline SchemaValidCtxt<1-Owning*0> newValidCtxt() { return xmlSchemaNewValidCtxt(cobj); }
#endif
};

template<bool Owning = 0>
class SchematronParserCtxt {
 _xmlSchematronParserCtxt *cobj;
public:
 inline ~SchematronParserCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline SchematronParserCtxt(_xmlSchematronParserCtxt *ptr) : cobj(ptr) {}
 inline SchematronParserCtxt(const SchematronParserCtxt<0> &o) : cobj(o.cobj) {}
 inline SchematronParserCtxt(const SchematronParserCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchematronParserCtxt*() { return cobj; }
 inline SchematronParserCtxt<0> release() { }
#if defined(LIBXML_SCHEMATRON_ENABLED)
  inline static SchematronParserCtxt<1-Owning*0> newMemParserCtxt(const char * buffer, int size) { return xmlSchematronNewMemParserCtxt(buffer, size); }
  inline static SchematronParserCtxt<1-Owning*0> newParserCtxt(const char * URL) { return xmlSchematronNewParserCtxt(URL); }
  inline Schematron<0-Owning*0> parse() { return xmlSchematronParse(cobj); }
#endif
};

template<bool Owning = 0>
class Schematron {
 _xmlSchematron *cobj;
public:
 inline ~Schematron() { if (Owning) free(cobj), cobj = NULL; }
 inline Schematron(_xmlSchematron *ptr) : cobj(ptr) {}
 inline Schematron(const Schematron<0> &o) : cobj(o.cobj) {}
 inline Schematron(const Schematron<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchematron*() { return cobj; }
 inline Schematron<0> release() { }
#if defined(LIBXML_SCHEMATRON_ENABLED)
  inline SchematronValidCtxt<1-Owning*0> newValidCtxt(int options) { return xmlSchematronNewValidCtxt(cobj, options); }
#endif
};

template<bool Owning = 0>
class ShellCtxt {
 _xmlShellCtxt *cobj;
public:
 inline ~ShellCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline ShellCtxt(_xmlShellCtxt *ptr) : cobj(ptr) {}
 inline ShellCtxt(const ShellCtxt<0> &o) : cobj(o.cobj) {}
 inline ShellCtxt(const ShellCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlShellCtxt*() { return cobj; }
 inline ShellCtxt<0> release() { }
#if defined(LIBXML_DEBUG_ENABLED) && defined(LIBXML_XPATH_ENABLED)
  inline int base(char * arg, xmlNodePtr node, xmlNodePtr node2) { return xmlShellBase(cobj, arg, node, node2); }
  inline int dir(char * arg, xmlNodePtr node, xmlNodePtr node2) { return xmlShellDir(cobj, arg, node, node2); }
  inline int du(char * arg, xmlNodePtr tree, xmlNodePtr node2) { return xmlShellDu(cobj, arg, tree, node2); }
  inline int list(char * arg, xmlNodePtr node, xmlNodePtr node2) { return xmlShellList(cobj, arg, node, node2); }
  inline int load(char * filename, xmlNodePtr node, xmlNodePtr node2) { return xmlShellLoad(cobj, filename, node, node2); }
  inline int pwd(char * buffer, xmlNodePtr node, xmlNodePtr node2) { return xmlShellPwd(cobj, buffer, node, node2); }
#endif
#if defined(LIBXML_DEBUG_ENABLED) && defined(LIBXML_XPATH_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
  inline int cat(char * arg, xmlNodePtr node, xmlNodePtr node2) { return xmlShellCat(cobj, arg, node, node2); }
  inline int save(char * filename, xmlNodePtr node, xmlNodePtr node2) { return xmlShellSave(cobj, filename, node, node2); }
  inline int write(char * filename, xmlNodePtr node, xmlNodePtr node2) { return xmlShellWrite(cobj, filename, node, node2); }
#endif
#if defined(LIBXML_DEBUG_ENABLED) && defined(LIBXML_XPATH_ENABLED) && defined(LIBXML_VALID_ENABLED)
  inline int validate(char * dtd, xmlNodePtr node, xmlNodePtr node2) { return xmlShellValidate(cobj, dtd, node, node2); }
#endif
};

template<bool Owning = 0>
class XIncludeCtxt {
 _xmlXIncludeCtxt *cobj;
public:
 inline ~XIncludeCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline XIncludeCtxt(_xmlXIncludeCtxt *ptr) : cobj(ptr) {}
 inline XIncludeCtxt(const XIncludeCtxt<0> &o) : cobj(o.cobj) {}
 inline XIncludeCtxt(const XIncludeCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlXIncludeCtxt*() { return cobj; }
 inline XIncludeCtxt<0> release() { }
#if defined(LIBXML_XINCLUDE_ENABLED)
  inline int processNode(xmlNodePtr node) { return xmlXIncludeProcessNode(cobj, node); }
  inline int setFlags(int flags) { return xmlXIncludeSetFlags(cobj, flags); }
#endif
};

template<bool Owning = 0>
class LocationSet {
 _xmlLocationSet *cobj;
public:
 inline ~LocationSet() { if (Owning) free(cobj), cobj = NULL; }
 inline LocationSet(_xmlLocationSet *ptr) : cobj(ptr) {}
 inline LocationSet(const LocationSet<0> &o) : cobj(o.cobj) {}
 inline LocationSet(const LocationSet<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlLocationSet*() { return cobj; }
 inline LocationSet<0> release() { }
#if defined(LIBXML_XPTR_ENABLED)
  inline void xPtrLocationSetAdd(xmlXPathObjectPtr val) { xmlXPtrLocationSetAdd(cobj, val); }
  inline void xPtrLocationSetDel(xmlXPathObjectPtr val) { xmlXPtrLocationSetDel(cobj, val); }
  inline LocationSet<0-Owning*0> xPtrLocationSetMerge(xmlLocationSetPtr val2) { return xmlXPtrLocationSetMerge(cobj, val2); }
  inline void xPtrLocationSetRemove(int val) { xmlXPtrLocationSetRemove(cobj, val); }
  inline XPathObject<1-Owning*0> xPtrWrapLocationSet() { return xmlXPtrWrapLocationSet(cobj); }
#endif
};

template<bool Owning = 0>
class CharEncodingHandler {
 _xmlCharEncodingHandler *cobj;
public:
 inline ~CharEncodingHandler() { if (Owning) free(cobj), cobj = NULL; }
 inline CharEncodingHandler(_xmlCharEncodingHandler *ptr) : cobj(ptr) {}
 inline CharEncodingHandler(const CharEncodingHandler<0> &o) : cobj(o.cobj) {}
 inline CharEncodingHandler(const CharEncodingHandler<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlCharEncodingHandler*() { return cobj; }
 inline CharEncodingHandler<0> release() { }
 inline int encCloseFunc() { return xmlCharEncCloseFunc(cobj); }
 inline int encFirstLine(xmlBufferPtr out, xmlBufferPtr in) { return xmlCharEncFirstLine(cobj, out, in); }
 inline int encInFunc(xmlBufferPtr out, xmlBufferPtr in) { return xmlCharEncInFunc(cobj, out, in); }
 inline int encOutFunc(xmlBufferPtr out, xmlBufferPtr in) { return xmlCharEncOutFunc(cobj, out, in); }
 inline static CharEncodingHandler<1-Owning*0> newCharEncodingHandler(const char * name, xmlCharEncodingInputFunc input, xmlCharEncodingOutputFunc output) { return xmlNewCharEncodingHandler(name, input, output); }
 inline void registerCharEncodingHandler() { xmlRegisterCharEncodingHandler(cobj); }
#if defined(LIBXML_OUTPUT_ENABLED)
  inline OutputBuffer<1-Owning*0> allocOutputBuffer() { return xmlAllocOutputBuffer(cobj); }
#endif
};

template<bool Owning = 0>
class Automata {
 _xmlAutomata *cobj;
public:
 inline ~Automata() { if (Owning) free(cobj), cobj = NULL; }
 inline Automata(_xmlAutomata *ptr) : cobj(ptr) {}
 inline Automata(const Automata<0> &o) : cobj(o.cobj) {}
 inline Automata(const Automata<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlAutomata*() { return cobj; }
 inline Automata<0> release() { }
#if defined(LIBXML_REGEXP_ENABLED) && defined(LIBXML_AUTOMATA_ENABLED)
  inline Regexp<0-Owning*0> compile() { return xmlAutomataCompile(cobj); }
  inline AutomataState<0-Owning*0> getInitState() { return xmlAutomataGetInitState(cobj); }
  inline int isDeterminist() { return xmlAutomataIsDeterminist(cobj); }
  inline AutomataState<1-Owning*0> newAllTrans(xmlAutomataStatePtr from, xmlAutomataStatePtr to, int lax) { return xmlAutomataNewAllTrans(cobj, from, to, lax); }
  inline AutomataState<1-Owning*0> newCountTrans(xmlAutomataStatePtr from, xmlAutomataStatePtr to, const xmlChar * token, int min, int max, void * data) { return xmlAutomataNewCountTrans(cobj, from, to, token, min, max, data); }
  inline AutomataState<1-Owning*0> newCountTrans2(xmlAutomataStatePtr from, xmlAutomataStatePtr to, const xmlChar * token, const xmlChar * token2, int min, int max, void * data) { return xmlAutomataNewCountTrans2(cobj, from, to, token, token2, min, max, data); }
  inline AutomataState<1-Owning*0> newCountedTrans(xmlAutomataStatePtr from, xmlAutomataStatePtr to, int counter) { return xmlAutomataNewCountedTrans(cobj, from, to, counter); }
  inline int newCounter(int min, int max) { return xmlAutomataNewCounter(cobj, min, max); }
  inline AutomataState<1-Owning*0> newCounterTrans(xmlAutomataStatePtr from, xmlAutomataStatePtr to, int counter) { return xmlAutomataNewCounterTrans(cobj, from, to, counter); }
  inline AutomataState<1-Owning*0> newEpsilon(xmlAutomataStatePtr from, xmlAutomataStatePtr to) { return xmlAutomataNewEpsilon(cobj, from, to); }
  inline AutomataState<1-Owning*0> newNegTrans(xmlAutomataStatePtr from, xmlAutomataStatePtr to, const xmlChar * token, const xmlChar * token2, void * data) { return xmlAutomataNewNegTrans(cobj, from, to, token, token2, data); }
  inline AutomataState<1-Owning*0> newOnceTrans(xmlAutomataStatePtr from, xmlAutomataStatePtr to, const xmlChar * token, int min, int max, void * data) { return xmlAutomataNewOnceTrans(cobj, from, to, token, min, max, data); }
  inline AutomataState<1-Owning*0> newOnceTrans2(xmlAutomataStatePtr from, xmlAutomataStatePtr to, const xmlChar * token, const xmlChar * token2, int min, int max, void * data) { return xmlAutomataNewOnceTrans2(cobj, from, to, token, token2, min, max, data); }
  inline AutomataState<1-Owning*0> newState() { return xmlAutomataNewState(cobj); }
  inline AutomataState<1-Owning*0> newTransition(xmlAutomataStatePtr from, xmlAutomataStatePtr to, const xmlChar * token, void * data) { return xmlAutomataNewTransition(cobj, from, to, token, data); }
  inline AutomataState<1-Owning*0> newTransition2(xmlAutomataStatePtr from, xmlAutomataStatePtr to, const xmlChar * token, const xmlChar * token2, void * data) { return xmlAutomataNewTransition2(cobj, from, to, token, token2, data); }
  inline int setFinalState(xmlAutomataStatePtr state) { return xmlAutomataSetFinalState(cobj, state); }
  inline static Automata<1-Owning*0> newAutomata() { return xmlNewAutomata(); }
#endif
};

template<bool Owning = 0>
class DOMWrapCtxt {
 _xmlDOMWrapCtxt *cobj;
public:
 inline ~DOMWrapCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline DOMWrapCtxt(_xmlDOMWrapCtxt *ptr) : cobj(ptr) {}
 inline DOMWrapCtxt(const DOMWrapCtxt<0> &o) : cobj(o.cobj) {}
 inline DOMWrapCtxt(const DOMWrapCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlDOMWrapCtxt*() { return cobj; }
 inline DOMWrapCtxt<0> release() { }
 inline int adoptNode(xmlDocPtr sourceDoc, xmlNodePtr node, xmlDocPtr destDoc, xmlNodePtr destParent, int options) { return xmlDOMWrapAdoptNode(cobj, sourceDoc, node, destDoc, destParent, options); }
 inline int cloneNode(xmlDocPtr sourceDoc, xmlNodePtr node, xmlNodePtr * resNode, xmlDocPtr destDoc, xmlNodePtr destParent, int deep, int options) { return xmlDOMWrapCloneNode(cobj, sourceDoc, node, resNode, destDoc, destParent, deep, options); }
 inline static DOMWrapCtxt<1-Owning*0> newCtxt() { return xmlDOMWrapNewCtxt(); }
 inline int reconcileNamespaces(xmlNodePtr elem, int options) { return xmlDOMWrapReconcileNamespaces(cobj, elem, options); }
 inline int removeNode(xmlDocPtr doc, xmlNodePtr node, int options) { return xmlDOMWrapRemoveNode(cobj, doc, node, options); }
};

template<bool Owning = 0>
class OutputBuffer {
 _xmlOutputBuffer *cobj;
public:
 inline ~OutputBuffer() { if (Owning) free(cobj), cobj = NULL; }
 inline OutputBuffer(_xmlOutputBuffer *ptr) : cobj(ptr) {}
 inline OutputBuffer(const OutputBuffer<0> &o) : cobj(o.cobj) {}
 inline OutputBuffer(const OutputBuffer<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlOutputBuffer*() { return cobj; }
 inline OutputBuffer<0> release() { }
#if defined(LIBXML_WRITER_ENABLED)
  inline TextWriter<1-Owning*0> newTextWriter() { return xmlNewTextWriter(cobj); }
#endif
#if defined(LIBXML_OUTPUT_ENABLED)
  inline int close() { return xmlOutputBufferClose(cobj); }
  inline static OutputBuffer<1-Owning*0> createFd(int fd, xmlCharEncodingHandlerPtr encoder) { return xmlOutputBufferCreateFd(fd, encoder); }
  inline static OutputBuffer<1-Owning*0> createFile(FILE * file, xmlCharEncodingHandlerPtr encoder) { return xmlOutputBufferCreateFile(file, encoder); }
  inline static OutputBuffer<1-Owning*0> createFilename(const char * URI, xmlCharEncodingHandlerPtr encoder, int compression) { return xmlOutputBufferCreateFilename(URI, encoder, compression); }
  inline static OutputBuffer<1-Owning*0> createIO(xmlOutputWriteCallback iowrite, xmlOutputCloseCallback ioclose, void * ioctx, xmlCharEncodingHandlerPtr encoder) { return xmlOutputBufferCreateIO(iowrite, ioclose, ioctx, encoder); }
  inline int flush() { return xmlOutputBufferFlush(cobj); }
  inline xmlChar*  getContent() { return xmlOutputBufferGetContent(cobj); }
  inline size_t getSize() { return xmlOutputBufferGetSize(cobj); }
  inline int write(int len, const char * buf) { return xmlOutputBufferWrite(cobj, len, buf); }
  inline int writeEscape(const xmlChar * str, xmlCharEncodingOutputFunc escaping) { return xmlOutputBufferWriteEscape(cobj, str, escaping); }
  inline int writeString(const char * str) { return xmlOutputBufferWriteString(cobj, str); }
#endif
};

template<bool Owning = 0>
class Pattern {
 _xmlPattern *cobj;
public:
 inline ~Pattern() { if (Owning) free(cobj), cobj = NULL; }
 inline Pattern(_xmlPattern *ptr) : cobj(ptr) {}
 inline Pattern(const Pattern<0> &o) : cobj(o.cobj) {}
 inline Pattern(const Pattern<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlPattern*() { return cobj; }
 inline Pattern<0> release() { }
#if defined(LIBXML_PATTERN_ENABLED)
  inline int fromRoot() { return xmlPatternFromRoot(cobj); }
  inline StreamCtxt<0-Owning*0> getStreamCtxt() { return xmlPatternGetStreamCtxt(cobj); }
  inline int match(xmlNodePtr node) { return xmlPatternMatch(cobj, node); }
  inline int maxDepth() { return xmlPatternMaxDepth(cobj); }
  inline int minDepth() { return xmlPatternMinDepth(cobj); }
  inline int streamable() { return xmlPatternStreamable(cobj); }
#endif
};

template<bool Owning = 0>
class RelaxNGParserCtxt {
 _xmlRelaxNGParserCtxt *cobj;
public:
 inline ~RelaxNGParserCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline RelaxNGParserCtxt(_xmlRelaxNGParserCtxt *ptr) : cobj(ptr) {}
 inline RelaxNGParserCtxt(const RelaxNGParserCtxt<0> &o) : cobj(o.cobj) {}
 inline RelaxNGParserCtxt(const RelaxNGParserCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlRelaxNGParserCtxt*() { return cobj; }
 inline RelaxNGParserCtxt<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline int getParserErrors(xmlRelaxNGValidityErrorFunc * err, xmlRelaxNGValidityWarningFunc * warn, void ** ctx) { return xmlRelaxNGGetParserErrors(cobj, err, warn, ctx); }
  inline static RelaxNGParserCtxt<1-Owning*0> newMemParserCtxt(const char * buffer, int size) { return xmlRelaxNGNewMemParserCtxt(buffer, size); }
  inline static RelaxNGParserCtxt<1-Owning*0> newParserCtxt(const char * URL) { return xmlRelaxNGNewParserCtxt(URL); }
  inline RelaxNG<0-Owning*0> parse() { return xmlRelaxNGParse(cobj); }
  inline void setParserErrors(xmlRelaxNGValidityErrorFunc err, xmlRelaxNGValidityWarningFunc warn, void * ctx) { xmlRelaxNGSetParserErrors(cobj, err, warn, ctx); }
  inline void setParserStructuredErrors(xmlStructuredErrorFunc serror, void * ctx) { xmlRelaxNGSetParserStructuredErrors(cobj, serror, ctx); }
  inline int setFlag(int flags) { return xmlRelaxParserSetFlag(cobj, flags); }
#endif
};

template<bool Owning = 0>
class SaveCtxt {
 _xmlSaveCtxt *cobj;
public:
 inline ~SaveCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline SaveCtxt(_xmlSaveCtxt *ptr) : cobj(ptr) {}
 inline SaveCtxt(const SaveCtxt<0> &o) : cobj(o.cobj) {}
 inline SaveCtxt(const SaveCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSaveCtxt*() { return cobj; }
 inline SaveCtxt<0> release() { }
#if defined(LIBXML_OUTPUT_ENABLED)
  inline int close() { return xmlSaveClose(cobj); }
  inline long doc(xmlDocPtr doc) { return xmlSaveDoc(cobj, doc); }
  inline int flush() { return xmlSaveFlush(cobj); }
  inline int setAttrEscape(xmlCharEncodingOutputFunc escape) { return xmlSaveSetAttrEscape(cobj, escape); }
  inline int setEscape(xmlCharEncodingOutputFunc escape) { return xmlSaveSetEscape(cobj, escape); }
  inline static SaveCtxt<1-Owning*0> toFd(int fd, const char * encoding, int options) { return xmlSaveToFd(fd, encoding, options); }
  inline static SaveCtxt<1-Owning*0> toFilename(const char * filename, const char * encoding, int options) { return xmlSaveToFilename(filename, encoding, options); }
  inline static SaveCtxt<1-Owning*0> toIO(xmlOutputWriteCallback iowrite, xmlOutputCloseCallback ioclose, void * ioctx, const char * encoding, int options) { return xmlSaveToIO(iowrite, ioclose, ioctx, encoding, options); }
  inline long tree(xmlNodePtr node) { return xmlSaveTree(cobj, node); }
#endif
};

template<bool Owning = 0>
class SchemaParserCtxt {
 _xmlSchemaParserCtxt *cobj;
public:
 inline ~SchemaParserCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline SchemaParserCtxt(_xmlSchemaParserCtxt *ptr) : cobj(ptr) {}
 inline SchemaParserCtxt(const SchemaParserCtxt<0> &o) : cobj(o.cobj) {}
 inline SchemaParserCtxt(const SchemaParserCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchemaParserCtxt*() { return cobj; }
 inline SchemaParserCtxt<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline int getParserErrors(xmlSchemaValidityErrorFunc * err, xmlSchemaValidityWarningFunc * warn, void ** ctx) { return xmlSchemaGetParserErrors(cobj, err, warn, ctx); }
  inline static SchemaParserCtxt<1-Owning*0> newMemParserCtxt(const char * buffer, int size) { return xmlSchemaNewMemParserCtxt(buffer, size); }
  inline static SchemaParserCtxt<1-Owning*0> newParserCtxt(const char * URL) { return xmlSchemaNewParserCtxt(URL); }
  inline Schema<0-Owning*0> parse() { return xmlSchemaParse(cobj); }
  inline void setParserErrors(xmlSchemaValidityErrorFunc err, xmlSchemaValidityWarningFunc warn, void * ctx) { xmlSchemaSetParserErrors(cobj, err, warn, ctx); }
  inline void setParserStructuredErrors(xmlStructuredErrorFunc serror, void * ctx) { xmlSchemaSetParserStructuredErrors(cobj, serror, ctx); }
#endif
};

template<bool Owning = 0>
class SchematronValidCtxt {
 _xmlSchematronValidCtxt *cobj;
public:
 inline ~SchematronValidCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline SchematronValidCtxt(_xmlSchematronValidCtxt *ptr) : cobj(ptr) {}
 inline SchematronValidCtxt(const SchematronValidCtxt<0> &o) : cobj(o.cobj) {}
 inline SchematronValidCtxt(const SchematronValidCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchematronValidCtxt*() { return cobj; }
 inline SchematronValidCtxt<0> release() { }
#if defined(LIBXML_SCHEMATRON_ENABLED)
  inline void setValidStructuredErrors(xmlStructuredErrorFunc serror, void * ctx) { xmlSchematronSetValidStructuredErrors(cobj, serror, ctx); }
  inline int validateDoc(xmlDocPtr instance) { return xmlSchematronValidateDoc(cobj, instance); }
#endif
};

template<bool Owning = 0>
class XPathCompExpr {
 _xmlXPathCompExpr *cobj;
public:
 inline ~XPathCompExpr() { if (Owning) free(cobj), cobj = NULL; }
 inline XPathCompExpr(_xmlXPathCompExpr *ptr) : cobj(ptr) {}
 inline XPathCompExpr(const XPathCompExpr<0> &o) : cobj(o.cobj) {}
 inline XPathCompExpr(const XPathCompExpr<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlXPathCompExpr*() { return cobj; }
 inline XPathCompExpr<0> release() { }
#if defined(LIBXML_XPATH_ENABLED)
  inline static XPathCompExpr<1-Owning*0> compile(const xmlChar * str) { return xmlXPathCompile(str); }
  inline XPathObject<1-Owning*0> compiledEval(xmlXPathContextPtr ctx) { return xmlXPathCompiledEval(cobj, ctx); }
  inline int compiledEvalToBoolean(xmlXPathContextPtr ctxt) { return xmlXPathCompiledEvalToBoolean(cobj, ctxt); }
#endif
};

template<bool Owning = 0>
class XPathParserContext {
 _xmlXPathParserContext *cobj;
public:
 inline ~XPathParserContext() { if (Owning) free(cobj), cobj = NULL; }
 inline XPathParserContext(_xmlXPathParserContext *ptr) : cobj(ptr) {}
 inline XPathParserContext(const XPathParserContext<0> &o) : cobj(o.cobj) {}
 inline XPathParserContext(const XPathParserContext<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlXPathParserContext*() { return cobj; }
 inline XPathParserContext<0> release() { }
#if defined(LIBXML_XPATH_ENABLED)
  inline void addValues() { xmlXPathAddValues(cobj); }
  inline void booleanFunction(int nargs) { xmlXPathBooleanFunction(cobj, nargs); }
  inline void ceilingFunction(int nargs) { xmlXPathCeilingFunction(cobj, nargs); }
  inline int compareValues(int inf, int strict) { return xmlXPathCompareValues(cobj, inf, strict); }
  inline void concatFunction(int nargs) { xmlXPathConcatFunction(cobj, nargs); }
  inline void containsFunction(int nargs) { xmlXPathContainsFunction(cobj, nargs); }
  inline void countFunction(int nargs) { xmlXPathCountFunction(cobj, nargs); }
  inline void divValues() { xmlXPathDivValues(cobj); }
  inline int equalValues() { return xmlXPathEqualValues(cobj); }
  inline void err(int error) { xmlXPathErr(cobj, error); }
  inline void evalExpr() { xmlXPathEvalExpr(cobj); }
  inline int evaluatePredicateResult(xmlXPathObjectPtr res) { return xmlXPathEvaluatePredicateResult(cobj, res); }
  inline void falseFunction(int nargs) { xmlXPathFalseFunction(cobj, nargs); }
  inline void floorFunction(int nargs) { xmlXPathFloorFunction(cobj, nargs); }
  inline void idFunction(int nargs) { xmlXPathIdFunction(cobj, nargs); }
  inline void langFunction(int nargs) { xmlXPathLangFunction(cobj, nargs); }
  inline void lastFunction(int nargs) { xmlXPathLastFunction(cobj, nargs); }
  inline void localNameFunction(int nargs) { xmlXPathLocalNameFunction(cobj, nargs); }
  inline void modValues() { xmlXPathModValues(cobj); }
  inline void multValues() { xmlXPathMultValues(cobj); }
  inline void namespaceURIFunction(int nargs) { xmlXPathNamespaceURIFunction(cobj, nargs); }
  inline static XPathParserContext<1-Owning*0> newParserContext(const xmlChar * str, xmlXPathContextPtr ctxt) { return xmlXPathNewParserContext(str, ctxt); }
  inline void normalizeFunction(int nargs) { xmlXPathNormalizeFunction(cobj, nargs); }
  inline int notEqualValues() { return xmlXPathNotEqualValues(cobj); }
  inline void notFunction(int nargs) { xmlXPathNotFunction(cobj, nargs); }
  inline void numberFunction(int nargs) { xmlXPathNumberFunction(cobj, nargs); }
  inline xmlChar*  parseNCName() { return xmlXPathParseNCName(cobj); }
  inline xmlChar*  parseName() { return xmlXPathParseName(cobj); }
  inline int popBoolean() { return xmlXPathPopBoolean(cobj); }
  inline void * popExternal() { return xmlXPathPopExternal(cobj); }
  inline NodeSet<0-Owning*0> popNodeSet() { return xmlXPathPopNodeSet(cobj); }
  inline double popNumber() { return xmlXPathPopNumber(cobj); }
  inline xmlChar*  popString() { return xmlXPathPopString(cobj); }
  inline void positionFunction(int nargs) { xmlXPathPositionFunction(cobj, nargs); }
  inline void root() { xmlXPathRoot(cobj); }
  inline void roundFunction(int nargs) { xmlXPathRoundFunction(cobj, nargs); }
  inline void startsWithFunction(int nargs) { xmlXPathStartsWithFunction(cobj, nargs); }
  inline void stringFunction(int nargs) { xmlXPathStringFunction(cobj, nargs); }
  inline void stringLengthFunction(int nargs) { xmlXPathStringLengthFunction(cobj, nargs); }
  inline void subValues() { xmlXPathSubValues(cobj); }
  inline void substringAfterFunction(int nargs) { xmlXPathSubstringAfterFunction(cobj, nargs); }
  inline void substringBeforeFunction(int nargs) { xmlXPathSubstringBeforeFunction(cobj, nargs); }
  inline void substringFunction(int nargs) { xmlXPathSubstringFunction(cobj, nargs); }
  inline void sumFunction(int nargs) { xmlXPathSumFunction(cobj, nargs); }
  inline void translateFunction(int nargs) { xmlXPathTranslateFunction(cobj, nargs); }
  inline void trueFunction(int nargs) { xmlXPathTrueFunction(cobj, nargs); }
  inline void valueFlipSign() { xmlXPathValueFlipSign(cobj); }
  inline void patherror(const char * file, int line, int no) { xmlXPatherror(cobj, file, line, no); }
#endif
#if defined(LIBXML_XPTR_ENABLED)
  inline void ptrEvalRangePredicate() { xmlXPtrEvalRangePredicate(cobj); }
  inline void ptrRangeToFunction(int nargs) { xmlXPtrRangeToFunction(cobj, nargs); }
#endif
};

template<bool Owning = 0>
class Dtd {
 _xmlDtd *cobj;
public:
 inline ~Dtd() { if (Owning) free(cobj), cobj = NULL; }
 inline Dtd(_xmlDtd *ptr) : cobj(ptr) {}
 inline Dtd(const Dtd<0> &o) : cobj(o.cobj) {}
 inline Dtd(const Dtd<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlDtd*() { return cobj; }
 inline Dtd<0> release() { }
 inline Attribute<0-Owning*0> getDtdAttrDesc(const xmlChar * elem, const xmlChar * name) { return xmlGetDtdAttrDesc(cobj, elem, name); }
 inline Element<0-Owning*0> getDtdElementDesc(const xmlChar * name) { return xmlGetDtdElementDesc(cobj, name); }
 inline Notation<0-Owning*0> getDtdNotationDesc(const xmlChar * name) { return xmlGetDtdNotationDesc(cobj, name); }
 inline Attribute<0-Owning*0> getDtdQAttrDesc(const xmlChar * elem, const xmlChar * name, const xmlChar * prefix) { return xmlGetDtdQAttrDesc(cobj, elem, name, prefix); }
 inline Element<0-Owning*0> getDtdQElementDesc(const xmlChar * name, const xmlChar * prefix) { return xmlGetDtdQElementDesc(cobj, name, prefix); }
#if defined(LIBXML_TREE_ENABLED)
  inline Dtd<1-Owning*0> copyDtd() { return xmlCopyDtd(cobj); }
#endif
};

template<bool Owning = 0>
class RelaxNGValidCtxt {
 _xmlRelaxNGValidCtxt *cobj;
public:
 inline ~RelaxNGValidCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline RelaxNGValidCtxt(_xmlRelaxNGValidCtxt *ptr) : cobj(ptr) {}
 inline RelaxNGValidCtxt(const RelaxNGValidCtxt<0> &o) : cobj(o.cobj) {}
 inline RelaxNGValidCtxt(const RelaxNGValidCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlRelaxNGValidCtxt*() { return cobj; }
 inline RelaxNGValidCtxt<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline int getValidErrors(xmlRelaxNGValidityErrorFunc * err, xmlRelaxNGValidityWarningFunc * warn, void ** ctx) { return xmlRelaxNGGetValidErrors(cobj, err, warn, ctx); }
  inline void setValidErrors(xmlRelaxNGValidityErrorFunc err, xmlRelaxNGValidityWarningFunc warn, void * ctx) { xmlRelaxNGSetValidErrors(cobj, err, warn, ctx); }
  inline void setValidStructuredErrors(xmlStructuredErrorFunc serror, void * ctx) { xmlRelaxNGSetValidStructuredErrors(cobj, serror, ctx); }
  inline int validateDoc(xmlDocPtr doc) { return xmlRelaxNGValidateDoc(cobj, doc); }
  inline int validateFullElement(xmlDocPtr doc, xmlNodePtr elem) { return xmlRelaxNGValidateFullElement(cobj, doc, elem); }
  inline int validatePopElement(xmlDocPtr doc, xmlNodePtr elem) { return xmlRelaxNGValidatePopElement(cobj, doc, elem); }
  inline int validatePushCData(const xmlChar * data, int len) { return xmlRelaxNGValidatePushCData(cobj, data, len); }
  inline int validatePushElement(xmlDocPtr doc, xmlNodePtr elem) { return xmlRelaxNGValidatePushElement(cobj, doc, elem); }
#endif
};

template<bool Owning = 0>
class SchemaFacet {
 _xmlSchemaFacet *cobj;
public:
 inline ~SchemaFacet() { if (Owning) free(cobj), cobj = NULL; }
 inline SchemaFacet(_xmlSchemaFacet *ptr) : cobj(ptr) {}
 inline SchemaFacet(const SchemaFacet<0> &o) : cobj(o.cobj) {}
 inline SchemaFacet(const SchemaFacet<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchemaFacet*() { return cobj; }
 inline SchemaFacet<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline int checkFacet(xmlSchemaTypePtr typeDecl, xmlSchemaParserCtxtPtr pctxt, const xmlChar * name) { return xmlSchemaCheckFacet(cobj, typeDecl, pctxt, name); }
  inline unsigned long getFacetValueAsULong() { return xmlSchemaGetFacetValueAsULong(cobj); }
  inline static SchemaFacet<1-Owning*0> newFacet() { return xmlSchemaNewFacet(); }
  inline int validateFacetWhtsp(xmlSchemaWhitespaceValueType fws, xmlSchemaValType valType, const xmlChar * value, xmlSchemaValPtr val, xmlSchemaWhitespaceValueType ws) { return xmlSchemaValidateFacetWhtsp(cobj, fws, valType, value, val, ws); }
  inline int validateLengthFacetWhtsp(xmlSchemaValType valType, const xmlChar * value, xmlSchemaValPtr val, unsigned long * length, xmlSchemaWhitespaceValueType ws) { return xmlSchemaValidateLengthFacetWhtsp(cobj, valType, value, val, length, ws); }
  inline int validateListSimpleTypeFacet(const xmlChar * value, unsigned long actualLen, unsigned long * expectedLen) { return xmlSchemaValidateListSimpleTypeFacet(cobj, value, actualLen, expectedLen); }
#endif
};

template<bool Owning = 0>
class SchemaType {
 _xmlSchemaType *cobj;
public:
 inline ~SchemaType() { if (Owning) free(cobj), cobj = NULL; }
 inline SchemaType(_xmlSchemaType *ptr) : cobj(ptr) {}
 inline SchemaType(const SchemaType<0> &o) : cobj(o.cobj) {}
 inline SchemaType(const SchemaType<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchemaType*() { return cobj; }
 inline SchemaType<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline SchemaType<0-Owning*0> getBuiltInListSimpleTypeItemType() { return xmlSchemaGetBuiltInListSimpleTypeItemType(cobj); }
  inline int isBuiltInTypeFacet(int facetType) { return xmlSchemaIsBuiltInTypeFacet(cobj, facetType); }
  inline int valPredefTypeNode(const xmlChar * value, xmlSchemaValPtr * val, xmlNodePtr node) { return xmlSchemaValPredefTypeNode(cobj, value, val, node); }
  inline int valPredefTypeNodeNoNorm(const xmlChar * value, xmlSchemaValPtr * val, xmlNodePtr node) { return xmlSchemaValPredefTypeNodeNoNorm(cobj, value, val, node); }
  inline int validateFacet(xmlSchemaFacetPtr facet, const xmlChar * value, xmlSchemaValPtr val) { return xmlSchemaValidateFacet(cobj, facet, value, val); }
  inline int validateLengthFacet(xmlSchemaFacetPtr facet, const xmlChar * value, xmlSchemaValPtr val, unsigned long * length) { return xmlSchemaValidateLengthFacet(cobj, facet, value, val, length); }
  inline int validatePredefinedType(const xmlChar * value, xmlSchemaValPtr * val) { return xmlSchemaValidatePredefinedType(cobj, value, val); }
#endif
};

template<bool Owning = 0>
class XPathObject {
 _xmlXPathObject *cobj;
public:
 inline ~XPathObject() { if (Owning) free(cobj), cobj = NULL; }
 inline XPathObject(_xmlXPathObject *ptr) : cobj(ptr) {}
 inline XPathObject(const XPathObject<0> &o) : cobj(o.cobj) {}
 inline XPathObject(const XPathObject<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlXPathObject*() { return cobj; }
 inline XPathObject<0> release() { }
#if defined(LIBXML_DEBUG_ENABLED) && defined(LIBXML_XPATH_ENABLED)
  inline void shellPrintXPathResult() { xmlShellPrintXPathResult(cobj); }
#endif
#if defined(LIBXML_XPATH_ENABLED)
  inline int castToBoolean() { return xmlXPathCastToBoolean(cobj); }
  inline double castToNumber() { return xmlXPathCastToNumber(cobj); }
  inline xmlChar*  castToString() { return xmlXPathCastToString(cobj); }
  inline XPathObject<1-Owning*0> convertBoolean() { return xmlXPathConvertBoolean(cobj); }
  inline XPathObject<1-Owning*0> convertNumber() { return xmlXPathConvertNumber(cobj); }
  inline XPathObject<1-Owning*0> convertString() { return xmlXPathConvertString(cobj); }
  inline static XPathObject<1-Owning*0> eval(const xmlChar * str, xmlXPathContextPtr ctx) { return xmlXPathEval(str, ctx); }
  inline static XPathObject<1-Owning*0> evalExpression(const xmlChar * str, xmlXPathContextPtr ctxt) { return xmlXPathEvalExpression(str, ctxt); }
  inline static XPathObject<1-Owning*0> newBoolean(int val) { return xmlXPathNewBoolean(val); }
  inline static XPathObject<1-Owning*0> newCString(const char * val) { return xmlXPathNewCString(val); }
  inline static XPathObject<1-Owning*0> newFloat(double val) { return xmlXPathNewFloat(val); }
  inline static XPathObject<1-Owning*0> newString(const xmlChar * val) { return xmlXPathNewString(val); }
  inline XPathObject<1-Owning*0> copy() { return xmlXPathObjectCopy(cobj); }
  inline static XPathObject<1-Owning*0> wrapCString(char * val) { return xmlXPathWrapCString(val); }
  inline static XPathObject<1-Owning*0> wrapExternal(void * val) { return xmlXPathWrapExternal(val); }
  inline static XPathObject<1-Owning*0> wrapString(xmlChar * val) { return xmlXPathWrapString(val); }
#endif
#if defined(LIBXML_XPATH_ENABLED) && defined(LIBXML_DEBUG_ENABLED)
  inline void debugDumpObject(FILE * output, int depth) { xmlXPathDebugDumpObject(output, cobj, depth); }
#endif
#if defined(LIBXML_XPTR_ENABLED)
  inline Node<0-Owning*0> ptrBuildNodeList() { return xmlXPtrBuildNodeList(cobj); }
  inline static XPathObject<1-Owning*0> ptrEval(const xmlChar * str, xmlXPathContextPtr ctx) { return xmlXPtrEval(str, ctx); }
  inline LocationSet<1-Owning*0> ptrLocationSetCreate() { return xmlXPtrLocationSetCreate(cobj); }
  inline XPathObject<1-Owning*0> ptrNewRangePointNode(xmlNodePtr end) { return xmlXPtrNewRangePointNode(cobj, end); }
  inline XPathObject<1-Owning*0> ptrNewRangePoints(xmlXPathObjectPtr end) { return xmlXPtrNewRangePoints(cobj, end); }
#endif
};

template<bool Owning = 0>
class NodeSet {
 _xmlNodeSet *cobj;
public:
 inline ~NodeSet() { if (Owning) free(cobj), cobj = NULL; }
 inline NodeSet(_xmlNodeSet *ptr) : cobj(ptr) {}
 inline NodeSet(const NodeSet<0> &o) : cobj(o.cobj) {}
 inline NodeSet(const NodeSet<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlNodeSet*() { return cobj; }
 inline NodeSet<0> release() { }
#if defined(LIBXML_XPATH_ENABLED)
  inline int xPathCastNodeSetToBoolean() { return xmlXPathCastNodeSetToBoolean(cobj); }
  inline double xPathCastNodeSetToNumber() { return xmlXPathCastNodeSetToNumber(cobj); }
  inline xmlChar*  xPathCastNodeSetToString() { return xmlXPathCastNodeSetToString(cobj); }
  inline NodeSet<0-Owning*0> xPathDifference(xmlNodeSetPtr nodes2) { return xmlXPathDifference(cobj, nodes2); }
  inline NodeSet<0-Owning*0> xPathDistinct() { return xmlXPathDistinct(cobj); }
  inline NodeSet<0-Owning*0> xPathDistinctSorted() { return xmlXPathDistinctSorted(cobj); }
  inline int xPathHasSameNodes(xmlNodeSetPtr nodes2) { return xmlXPathHasSameNodes(cobj, nodes2); }
  inline NodeSet<0-Owning*0> xPathIntersection(xmlNodeSetPtr nodes2) { return xmlXPathIntersection(cobj, nodes2); }
  inline NodeSet<0-Owning*0> xPathLeading(xmlNodeSetPtr nodes2) { return xmlXPathLeading(cobj, nodes2); }
  inline NodeSet<0-Owning*0> xPathLeadingSorted(xmlNodeSetPtr nodes2) { return xmlXPathLeadingSorted(cobj, nodes2); }
  inline XPathObject<1-Owning*0> xPathNewNodeSetList() { return xmlXPathNewNodeSetList(cobj); }
  inline NodeSet<0-Owning*0> xPathNodeLeading(xmlNodePtr node) { return xmlXPathNodeLeading(cobj, node); }
  inline NodeSet<0-Owning*0> xPathNodeLeadingSorted(xmlNodePtr node) { return xmlXPathNodeLeadingSorted(cobj, node); }
  inline int xPathNodeSetAdd(xmlNodePtr val) { return xmlXPathNodeSetAdd(cobj, val); }
  inline int xPathNodeSetAddNs(xmlNodePtr node, xmlNsPtr ns) { return xmlXPathNodeSetAddNs(cobj, node, ns); }
  inline int xPathNodeSetAddUnique(xmlNodePtr val) { return xmlXPathNodeSetAddUnique(cobj, val); }
  inline int xPathNodeSetContains(xmlNodePtr val) { return xmlXPathNodeSetContains(cobj, val); }
  inline void xPathNodeSetDel(xmlNodePtr val) { xmlXPathNodeSetDel(cobj, val); }
  inline NodeSet<0-Owning*0> xPathNodeSetMerge(xmlNodeSetPtr val2) { return xmlXPathNodeSetMerge(cobj, val2); }
  inline void xPathNodeSetRemove(int val) { xmlXPathNodeSetRemove(cobj, val); }
  inline void xPathNodeSetSort() { xmlXPathNodeSetSort(cobj); }
  inline NodeSet<0-Owning*0> xPathNodeTrailing(xmlNodePtr node) { return xmlXPathNodeTrailing(cobj, node); }
  inline NodeSet<0-Owning*0> xPathNodeTrailingSorted(xmlNodePtr node) { return xmlXPathNodeTrailingSorted(cobj, node); }
  inline NodeSet<0-Owning*0> xPathTrailing(xmlNodeSetPtr nodes2) { return xmlXPathTrailing(cobj, nodes2); }
  inline NodeSet<0-Owning*0> xPathTrailingSorted(xmlNodeSetPtr nodes2) { return xmlXPathTrailingSorted(cobj, nodes2); }
  inline XPathObject<1-Owning*0> xPathWrapNodeSet() { return xmlXPathWrapNodeSet(cobj); }
#endif
#if defined(LIBXML_XPTR_ENABLED)
  inline XPathObject<1-Owning*0> xPtrNewLocationSetNodeSet() { return xmlXPtrNewLocationSetNodeSet(cobj); }
#endif
};

template<bool Owning = 0>
class XPathContext {
 _xmlXPathContext *cobj;
public:
 inline ~XPathContext() { if (Owning) free(cobj), cobj = NULL; }
 inline XPathContext(_xmlXPathContext *ptr) : cobj(ptr) {}
 inline XPathContext(const XPathContext<0> &o) : cobj(o.cobj) {}
 inline XPathContext(const XPathContext<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlXPathContext*() { return cobj; }
 inline XPathContext<0> release() { }
#if defined(LIBXML_XPATH_ENABLED)
  inline int setCache(int active, int value, int options) { return xmlXPathContextSetCache(cobj, active, value, options); }
  inline XPathCompExpr<1-Owning*0> ctxtCompile(const xmlChar * str) { return xmlXPathCtxtCompile(cobj, str); }
  inline int evalPredicate(xmlXPathObjectPtr res) { return xmlXPathEvalPredicate(cobj, res); }
  inline xmlXPathFunction functionLookup(const xmlChar * name) { return xmlXPathFunctionLookup(cobj, name); }
  inline xmlXPathFunction functionLookupNS(const xmlChar * name, const xmlChar * ns_uri) { return xmlXPathFunctionLookupNS(cobj, name, ns_uri); }
  inline xmlChar*  nsLookup(const xmlChar * prefix) { return xmlXPathNsLookup(cobj, prefix); }
  inline void registerAllFunctions() { xmlXPathRegisterAllFunctions(cobj); }
  inline int registerFunc(const xmlChar * name, xmlXPathFunction f) { return xmlXPathRegisterFunc(cobj, name, f); }
  inline void registerFuncLookup(xmlXPathFuncLookupFunc f, void * funcCtxt) { xmlXPathRegisterFuncLookup(cobj, f, funcCtxt); }
  inline int registerFuncNS(const xmlChar * name, const xmlChar * ns_uri, xmlXPathFunction f) { return xmlXPathRegisterFuncNS(cobj, name, ns_uri, f); }
  inline int registerNs(const xmlChar * prefix, const xmlChar * ns_uri) { return xmlXPathRegisterNs(cobj, prefix, ns_uri); }
  inline int registerVariable(const xmlChar * name, xmlXPathObjectPtr value) { return xmlXPathRegisterVariable(cobj, name, value); }
  inline void registerVariableLookup(xmlXPathVariableLookupFunc f, void * data) { xmlXPathRegisterVariableLookup(cobj, f, data); }
  inline int registerVariableNS(const xmlChar * name, const xmlChar * ns_uri, xmlXPathObjectPtr value) { return xmlXPathRegisterVariableNS(cobj, name, ns_uri, value); }
  inline void registeredFuncsCleanup() { xmlXPathRegisteredFuncsCleanup(cobj); }
  inline void registeredNsCleanup() { xmlXPathRegisteredNsCleanup(cobj); }
  inline void registeredVariablesCleanup() { xmlXPathRegisteredVariablesCleanup(cobj); }
  inline XPathObject<0-Owning*0> variableLookup(const xmlChar * name) { return xmlXPathVariableLookup(cobj, name); }
  inline XPathObject<0-Owning*0> variableLookupNS(const xmlChar * name, const xmlChar * ns_uri) { return xmlXPathVariableLookupNS(cobj, name, ns_uri); }
#endif
};

template<bool Owning = 0>
class SAXHandler {
 _xmlSAXHandler *cobj;
public:
 inline ~SAXHandler() { if (Owning) free(cobj), cobj = NULL; }
 inline SAXHandler(_xmlSAXHandler *ptr) : cobj(ptr) {}
 inline SAXHandler(const SAXHandler<0> &o) : cobj(o.cobj) {}
 inline SAXHandler(const SAXHandler<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSAXHandler*() { return cobj; }
 inline SAXHandler<0> release() { }
 inline ParserCtxt<1-Owning*0> createIOParserCtxt(void * user_data, xmlInputReadCallback ioread, xmlInputCloseCallback ioclose, void * ioctx, xmlCharEncoding enc) { return xmlCreateIOParserCtxt(cobj, user_data, ioread, ioclose, ioctx, enc); }
 inline void x2InitDefaultSAXHandler(int warning) { xmlSAX2InitDefaultSAXHandler(cobj, warning); }
 inline int version(int version) { return xmlSAXVersion(cobj, version); }
#if defined(LIBXML_PUSH_ENABLED)
  inline ParserCtxt<1-Owning*0> createPushParserCtxt(void * user_data, const char * chunk, int size, const char * filename) { return xmlCreatePushParserCtxt(cobj, user_data, chunk, size, filename); }
#endif
#if defined(LIBXML_VALID_ENABLED)
  inline Dtd<0-Owning*0> iOParseDTD(xmlParserInputBufferPtr input, xmlCharEncoding enc) { return xmlIOParseDTD(cobj, input, enc); }
  inline Dtd<0-Owning*0> parseDTD(const xmlChar * ExternalID, const xmlChar * SystemID) { return xmlSAXParseDTD(cobj, ExternalID, SystemID); }
#endif
#if defined(LIBXML_DOCB_ENABLED)
  inline void x2InitDocbDefaultSAXHandler() { xmlSAX2InitDocbDefaultSAXHandler(cobj); }
#endif
#if defined(LIBXML_HTML_ENABLED)
  inline void x2InitHtmlDefaultSAXHandler() { xmlSAX2InitHtmlDefaultSAXHandler(cobj); }
#endif
#if defined(LIBXML_SAX1_ENABLED)
  inline Doc<1-Owning*0> parseDoc(const xmlChar * cur, int recovery) { return xmlSAXParseDoc(cobj, cur, recovery); }
  inline Doc<1-Owning*0> parseEntity(const char * filename) { return xmlSAXParseEntity(cobj, filename); }
  inline Doc<1-Owning*0> parseFile(const char * filename, int recovery) { return xmlSAXParseFile(cobj, filename, recovery); }
  inline Doc<1-Owning*0> parseFileWithData(const char * filename, int recovery, void * data) { return xmlSAXParseFileWithData(cobj, filename, recovery, data); }
  inline Doc<1-Owning*0> parseMemory(const char * buffer, int size, int recovery) { return xmlSAXParseMemory(cobj, buffer, size, recovery); }
  inline Doc<1-Owning*0> parseMemoryWithData(const char * buffer, int size, int recovery, void * data) { return xmlSAXParseMemoryWithData(cobj, buffer, size, recovery, data); }
  inline int userParseFile(void * user_data, const char * filename) { return xmlSAXUserParseFile(cobj, user_data, filename); }
  inline int userParseMemory(void * user_data, const char * buffer, int size) { return xmlSAXUserParseMemory(cobj, user_data, buffer, size); }
#endif
};

template<bool Owning = 0>
class SchemaValidCtxt {
 _xmlSchemaValidCtxt *cobj;
public:
 inline ~SchemaValidCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline SchemaValidCtxt(_xmlSchemaValidCtxt *ptr) : cobj(ptr) {}
 inline SchemaValidCtxt(const SchemaValidCtxt<0> &o) : cobj(o.cobj) {}
 inline SchemaValidCtxt(const SchemaValidCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlSchemaValidCtxt*() { return cobj; }
 inline SchemaValidCtxt<0> release() { }
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline int getValidErrors(xmlSchemaValidityErrorFunc * err, xmlSchemaValidityWarningFunc * warn, void ** ctx) { return xmlSchemaGetValidErrors(cobj, err, warn, ctx); }
  inline int isValid() { return xmlSchemaIsValid(cobj); }
  inline SchemaSAXPlug<0-Owning*0> sAXPlug(xmlSAXHandlerPtr * sax, void ** user_data) { return xmlSchemaSAXPlug(cobj, sax, user_data); }
  inline void setValidErrors(xmlSchemaValidityErrorFunc err, xmlSchemaValidityWarningFunc warn, void * ctx) { xmlSchemaSetValidErrors(cobj, err, warn, ctx); }
  inline int setValidOptions(int options) { return xmlSchemaSetValidOptions(cobj, options); }
  inline void setValidStructuredErrors(xmlStructuredErrorFunc serror, void * ctx) { xmlSchemaSetValidStructuredErrors(cobj, serror, ctx); }
  inline int getOptions() { return xmlSchemaValidCtxtGetOptions(cobj); }
  inline ParserCtxt<0-Owning*0> getParserCtxt() { return xmlSchemaValidCtxtGetParserCtxt(cobj); }
  inline int validateDoc(xmlDocPtr doc) { return xmlSchemaValidateDoc(cobj, doc); }
  inline int validateFile(const char * filename, int options) { return xmlSchemaValidateFile(cobj, filename, options); }
  inline int validateOneElement(xmlNodePtr elem) { return xmlSchemaValidateOneElement(cobj, elem); }
  inline void validateSetFilename(const char * filename) { xmlSchemaValidateSetFilename(cobj, filename); }
  inline void validateSetLocator(xmlSchemaValidityLocatorFunc f, void * ctxt) { xmlSchemaValidateSetLocator(cobj, f, ctxt); }
  inline int validateStream(xmlParserInputBufferPtr input, xmlCharEncoding enc, xmlSAXHandlerPtr sax, void * user_data) { return xmlSchemaValidateStream(cobj, input, enc, sax, user_data); }
#endif
};

template<bool Owning = 0>
class TextReader {
 _xmlTextReader *cobj;
public:
 inline ~TextReader() { if (Owning) free(cobj), cobj = NULL; }
 inline TextReader(_xmlTextReader *ptr) : cobj(ptr) {}
 inline TextReader(const TextReader<0> &o) : cobj(o.cobj) {}
 inline TextReader(const TextReader<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlTextReader*() { return cobj; }
 inline TextReader<0> release() { }
#if defined(LIBXML_READER_ENABLED)
  inline static TextReader<1-Owning*0> newTextReaderFilename(const char * URI) { return xmlNewTextReaderFilename(URI); }
  inline static TextReader<1-Owning*0> forDoc(const xmlChar * cur, const char * URL, const char * encoding, int options) { return xmlReaderForDoc(cur, URL, encoding, options); }
  inline static TextReader<1-Owning*0> forFd(int fd, const char * URL, const char * encoding, int options) { return xmlReaderForFd(fd, URL, encoding, options); }
  inline static TextReader<1-Owning*0> forFile(const char * filename, const char * encoding, int options) { return xmlReaderForFile(filename, encoding, options); }
  inline static TextReader<1-Owning*0> forIO(xmlInputReadCallback ioread, xmlInputCloseCallback ioclose, void * ioctx, const char * URL, const char * encoding, int options) { return xmlReaderForIO(ioread, ioclose, ioctx, URL, encoding, options); }
  inline static TextReader<1-Owning*0> forMemory(const char * buffer, int size, const char * URL, const char * encoding, int options) { return xmlReaderForMemory(buffer, size, URL, encoding, options); }
  inline int newDoc(const xmlChar * cur, const char * URL, const char * encoding, int options) { return xmlReaderNewDoc(cobj, cur, URL, encoding, options); }
  inline int newFd(int fd, const char * URL, const char * encoding, int options) { return xmlReaderNewFd(cobj, fd, URL, encoding, options); }
  inline int newFile(const char * filename, const char * encoding, int options) { return xmlReaderNewFile(cobj, filename, encoding, options); }
  inline int newIO(xmlInputReadCallback ioread, xmlInputCloseCallback ioclose, void * ioctx, const char * URL, const char * encoding, int options) { return xmlReaderNewIO(cobj, ioread, ioclose, ioctx, URL, encoding, options); }
  inline int newMemory(const char * buffer, int size, const char * URL, const char * encoding, int options) { return xmlReaderNewMemory(cobj, buffer, size, URL, encoding, options); }
  inline int newWalker(xmlDocPtr doc) { return xmlReaderNewWalker(cobj, doc); }
  inline int attributeCount() { return xmlTextReaderAttributeCount(cobj); }
  inline xmlChar*  baseUri() { return xmlTextReaderBaseUri(cobj); }
  inline long byteConsumed() { return xmlTextReaderByteConsumed(cobj); }
  inline int close() { return xmlTextReaderClose(cobj); }
  inline xmlChar*  constBaseUri() { return xmlTextReaderConstBaseUri(cobj); }
  inline xmlChar*  constEncoding() { return xmlTextReaderConstEncoding(cobj); }
  inline xmlChar*  constLocalName() { return xmlTextReaderConstLocalName(cobj); }
  inline xmlChar*  constName() { return xmlTextReaderConstName(cobj); }
  inline xmlChar*  constNamespaceUri() { return xmlTextReaderConstNamespaceUri(cobj); }
  inline xmlChar*  constPrefix() { return xmlTextReaderConstPrefix(cobj); }
  inline xmlChar*  constString(const xmlChar * str) { return xmlTextReaderConstString(cobj, str); }
  inline xmlChar*  constValue() { return xmlTextReaderConstValue(cobj); }
  inline xmlChar*  constXmlLang() { return xmlTextReaderConstXmlLang(cobj); }
  inline xmlChar*  constXmlVersion() { return xmlTextReaderConstXmlVersion(cobj); }
  inline Doc<0-Owning*0> currentDoc() { return xmlTextReaderCurrentDoc(cobj); }
  inline Node<0-Owning*0> currentNode() { return xmlTextReaderCurrentNode(cobj); }
  inline int depth() { return xmlTextReaderDepth(cobj); }
  inline Node<0-Owning*0> expand() { return xmlTextReaderExpand(cobj); }
  inline xmlChar*  getAttribute(const xmlChar * name) { return xmlTextReaderGetAttribute(cobj, name); }
  inline xmlChar*  getAttributeNo(int no) { return xmlTextReaderGetAttributeNo(cobj, no); }
  inline xmlChar*  getAttributeNs(const xmlChar * localName, const xmlChar * namespaceURI) { return xmlTextReaderGetAttributeNs(cobj, localName, namespaceURI); }
  inline void getErrorHandler(xmlTextReaderErrorFunc * f, void ** arg) { xmlTextReaderGetErrorHandler(cobj, f, arg); }
  inline int getParserColumnNumber() { return xmlTextReaderGetParserColumnNumber(cobj); }
  inline int getParserLineNumber() { return xmlTextReaderGetParserLineNumber(cobj); }
  inline int getParserProp(int prop) { return xmlTextReaderGetParserProp(cobj, prop); }
  inline ParserInputBuffer<0-Owning*0> getRemainder() { return xmlTextReaderGetRemainder(cobj); }
  inline int hasAttributes() { return xmlTextReaderHasAttributes(cobj); }
  inline int hasValue() { return xmlTextReaderHasValue(cobj); }
  inline int isDefault() { return xmlTextReaderIsDefault(cobj); }
  inline int isEmptyElement() { return xmlTextReaderIsEmptyElement(cobj); }
  inline int isNamespaceDecl() { return xmlTextReaderIsNamespaceDecl(cobj); }
  inline int isValid() { return xmlTextReaderIsValid(cobj); }
  inline xmlChar*  localName() { return xmlTextReaderLocalName(cobj); }
  inline xmlChar*  lookupNamespace(const xmlChar * prefix) { return xmlTextReaderLookupNamespace(cobj, prefix); }
  inline int moveToAttribute(const xmlChar * name) { return xmlTextReaderMoveToAttribute(cobj, name); }
  inline int moveToAttributeNo(int no) { return xmlTextReaderMoveToAttributeNo(cobj, no); }
  inline int moveToAttributeNs(const xmlChar * localName, const xmlChar * namespaceURI) { return xmlTextReaderMoveToAttributeNs(cobj, localName, namespaceURI); }
  inline int moveToElement() { return xmlTextReaderMoveToElement(cobj); }
  inline int moveToFirstAttribute() { return xmlTextReaderMoveToFirstAttribute(cobj); }
  inline int moveToNextAttribute() { return xmlTextReaderMoveToNextAttribute(cobj); }
  inline xmlChar*  name() { return xmlTextReaderName(cobj); }
  inline xmlChar*  namespaceUri() { return xmlTextReaderNamespaceUri(cobj); }
  inline int next() { return xmlTextReaderNext(cobj); }
  inline int nextSibling() { return xmlTextReaderNextSibling(cobj); }
  inline int nodeType() { return xmlTextReaderNodeType(cobj); }
  inline int normalization() { return xmlTextReaderNormalization(cobj); }
  inline xmlChar*  prefix() { return xmlTextReaderPrefix(cobj); }
  inline Node<0-Owning*0> preserve() { return xmlTextReaderPreserve(cobj); }
  inline int quoteChar() { return xmlTextReaderQuoteChar(cobj); }
  inline int read() { return xmlTextReaderRead(cobj); }
  inline int readAttributeValue() { return xmlTextReaderReadAttributeValue(cobj); }
  inline int readState() { return xmlTextReaderReadState(cobj); }
  inline xmlChar*  readString() { return xmlTextReaderReadString(cobj); }
  inline void setErrorHandler(xmlTextReaderErrorFunc f, void * arg) { xmlTextReaderSetErrorHandler(cobj, f, arg); }
  inline int setParserProp(int prop, int value) { return xmlTextReaderSetParserProp(cobj, prop, value); }
  inline void setStructuredErrorHandler(xmlStructuredErrorFunc f, void * arg) { xmlTextReaderSetStructuredErrorHandler(cobj, f, arg); }
  inline int setup(xmlParserInputBufferPtr input, const char * URL, const char * encoding, int options) { return xmlTextReaderSetup(cobj, input, URL, encoding, options); }
  inline int standalone() { return xmlTextReaderStandalone(cobj); }
  inline xmlChar*  value() { return xmlTextReaderValue(cobj); }
  inline xmlChar*  xmlLang() { return xmlTextReaderXmlLang(cobj); }
#endif
#if defined(LIBXML_READER_ENABLED) && defined(LIBXML_PATTERN_ENABLED)
  inline int preservePattern(const xmlChar * pattern, const xmlChar ** namespaces) { return xmlTextReaderPreservePattern(cobj, pattern, namespaces); }
#endif
#if defined(LIBXML_READER_ENABLED) && defined(LIBXML_WRITER_ENABLED)
  inline xmlChar*  readInnerXml() { return xmlTextReaderReadInnerXml(cobj); }
  inline xmlChar*  readOuterXml() { return xmlTextReaderReadOuterXml(cobj); }
#endif
#if defined(LIBXML_READER_ENABLED) && defined(LIBXML_SCHEMAS_ENABLED)
  inline int relaxNGSetSchema(xmlRelaxNGPtr schema) { return xmlTextReaderRelaxNGSetSchema(cobj, schema); }
  inline int relaxNGValidate(const char * rng) { return xmlTextReaderRelaxNGValidate(cobj, rng); }
  inline int relaxNGValidateCtxt(xmlRelaxNGValidCtxtPtr ctxt, int options) { return xmlTextReaderRelaxNGValidateCtxt(cobj, ctxt, options); }
  inline int schemaValidate(const char * xsd) { return xmlTextReaderSchemaValidate(cobj, xsd); }
  inline int schemaValidateCtxt(xmlSchemaValidCtxtPtr ctxt, int options) { return xmlTextReaderSchemaValidateCtxt(cobj, ctxt, options); }
  inline int setSchema(xmlSchemaPtr schema) { return xmlTextReaderSetSchema(cobj, schema); }
#endif
};

template<bool Owning = 0>
class Node {
 _xmlNode *cobj;
public:
 inline ~Node() { if (Owning) free(cobj), cobj = NULL; }
 inline Node(_xmlNode *ptr) : cobj(ptr) {}
 inline Node(const Node<0> &o) : cobj(o.cobj) {}
 inline Node(const Node<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlNode*() { return cobj; }
 inline Node<0> release() { }
 inline Node<0-Owning*0> addChild(xmlNodePtr parent) { return xmlAddChild(parent, cobj); }
 inline Node<0-Owning*0> addChildList(xmlNodePtr parent) { return xmlAddChildList(parent, cobj); }
 inline Node<1-Owning*0> addNextSibling(xmlNodePtr elem) { return xmlAddNextSibling(cobj, elem); }
 inline Node<1-Owning*0> addSibling(xmlNodePtr elem) { return xmlAddSibling(cobj, elem); }
 inline int bufGetNodeContent(xmlBufPtr buf) const { return xmlBufGetNodeContent(buf, cobj); }
 inline Node<1-Owning*0> copyNode(int extended) { return xmlCopyNode(cobj, extended); }
 inline Node<1-Owning*0> copyNodeList() { return xmlCopyNodeList(cobj); }
 inline Node<1-Owning*0> docCopyNode(xmlDocPtr doc, int extended) { return xmlDocCopyNode(cobj, doc, extended); }
 inline Node<0-Owning*0> getLastChild() const { return xmlGetLastChild(cobj); }
 inline long getLineNo() const { return xmlGetLineNo(cobj); }
 inline xmlChar*  getNoNsProp(const xmlChar * name) const { return xmlGetNoNsProp(cobj, name); }
 inline xmlChar*  getNsProp(const xmlChar * name, const xmlChar * nameSpace) const { return xmlGetNsProp(cobj, name, nameSpace); }
 inline xmlChar*  getProp(const xmlChar * name) const { return xmlGetProp(cobj, name); }
 inline Attr<0-Owning*0> hasNsProp(const xmlChar * name, const xmlChar * nameSpace) const { return xmlHasNsProp(cobj, name, nameSpace); }
 inline Attr<0-Owning*0> hasProp(const xmlChar * name) const { return xmlHasProp(cobj, name); }
 inline int isBlankNode() const { return xmlIsBlankNode(cobj); }
 inline static Node<1-Owning*0> newComment(const xmlChar * content) { return xmlNewComment(content); }
 inline Ns<1-Owning*0> newNs(const xmlChar * href, const xmlChar * prefix) { return xmlNewNs(cobj, href, prefix); }
 inline Attr<1-Owning*0> newNsProp(xmlNsPtr ns, const xmlChar * name, const xmlChar * value) { return xmlNewNsProp(cobj, ns, name, value); }
 inline Attr<1-Owning*0> newNsPropEatName(xmlNsPtr ns, xmlChar * name, const xmlChar * value) { return xmlNewNsPropEatName(cobj, ns, name, value); }
 inline static Node<1-Owning*0> newPI(const xmlChar * name, const xmlChar * content) { return xmlNewPI(name, content); }
 inline static Node<1-Owning*0> newText(const xmlChar * content) { return xmlNewText(content); }
 inline static Node<1-Owning*0> newTextLen(const xmlChar * content, int len) { return xmlNewTextLen(content, len); }
 inline void addContent(const xmlChar * content) { xmlNodeAddContent(cobj, content); }
 inline void addContentLen(const xmlChar * content, int len) { xmlNodeAddContentLen(cobj, content, len); }
 inline int bufGetContent(xmlBufferPtr buffer) const { return xmlNodeBufGetContent(buffer, cobj); }
 inline xmlChar*  getBase(const xmlDoc * doc) const { return xmlNodeGetBase(doc, cobj); }
 inline xmlChar*  getContent() const { return xmlNodeGetContent(cobj); }
 inline xmlChar*  getLang() const { return xmlNodeGetLang(cobj); }
 inline int getSpacePreserve() const { return xmlNodeGetSpacePreserve(cobj); }
 inline int isText() const { return xmlNodeIsText(cobj); }
 inline void setContent(const xmlChar * content) { xmlNodeSetContent(cobj, content); }
 inline xmlParserErrors parseInNodeContext(const char * data, int datalen, int options, xmlNodePtr * lst) { return xmlParseInNodeContext(cobj, data, datalen, options, lst); }
 inline void setListDoc(xmlDocPtr doc) { xmlSetListDoc(cobj, doc); }
 inline void setNs(xmlNsPtr ns) { xmlSetNs(cobj, ns); }
 inline void setTreeDoc(xmlDocPtr doc) { xmlSetTreeDoc(cobj, doc); }
 inline int textConcat(const xmlChar * content, int len) { return xmlTextConcat(cobj, content, len); }
 inline Node<0-Owning*0> textMerge(xmlNodePtr second) { return xmlTextMerge(cobj, second); }
 inline void unlinkNode() { xmlUnlinkNode(cobj); }
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_HTML_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED) || defined(LIBXML_XINCLUDE_ENABLED)
  inline Node<1-Owning*0> addPrevSibling(xmlNodePtr elem) { return xmlAddPrevSibling(cobj, elem); }
#endif
#if defined(LIBXML_OUTPUT_ENABLED)
  inline size_t bufNodeDump(xmlBufPtr buf, xmlDocPtr doc, int level, int format) { return xmlBufNodeDump(buf, doc, cobj, level, format); }
  inline void elemDump(FILE * f, xmlDocPtr doc) { xmlElemDump(f, doc, cobj); }
  inline int dump(xmlBufferPtr buf, xmlDocPtr doc, int level, int format) { return xmlNodeDump(buf, doc, cobj, level, format); }
  inline void dumpOutput(xmlOutputBufferPtr buf, xmlDocPtr doc, int level, int format, const char * encoding) { xmlNodeDumpOutput(buf, doc, cobj, level, format, encoding); }
#endif
#if defined(LIBXML_TREE_ENABLED)
  inline unsigned long childElementCount() { return xmlChildElementCount(cobj); }
  inline Node<0-Owning*0> firstElementChild() { return xmlFirstElementChild(cobj); }
  inline Node<0-Owning*0> lastElementChild() { return xmlLastElementChild(cobj); }
  inline Node<1-Owning*0> newTextChild(xmlNsPtr ns, const xmlChar * name, const xmlChar * content) { return xmlNewTextChild(cobj, ns, name, content); }
  inline Node<0-Owning*0> nextElementSibling() { return xmlNextElementSibling(cobj); }
  inline void setContentLen(const xmlChar * content, int len) { xmlNodeSetContentLen(cobj, content, len); }
  inline void setLang(const xmlChar * lang) { xmlNodeSetLang(cobj, lang); }
  inline void setName(const xmlChar * name) { xmlNodeSetName(cobj, name); }
  inline void setSpacePreserve(int val) { xmlNodeSetSpacePreserve(cobj, val); }
  inline Node<0-Owning*0> previousElementSibling() { return xmlPreviousElementSibling(cobj); }
#endif
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_DEBUG_ENABLED)
  inline xmlChar*  getNodePath() const { return xmlGetNodePath(cobj); }
#endif
#if defined(LIBXML_DEBUG_ENABLED)
  inline int lsCountNode() { return xmlLsCountNode(cobj); }
#endif
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
  inline Node<1-Owning*0> newChild(xmlNsPtr ns, const xmlChar * name, const xmlChar * content) { return xmlNewChild(cobj, ns, name, content); }
  inline int unsetNsProp(xmlNsPtr ns, const xmlChar * name) { return xmlUnsetNsProp(cobj, ns, name); }
  inline int unsetProp(const xmlChar * name) { return xmlUnsetProp(cobj, name); }
#endif
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_HTML_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
  inline Attr<1-Owning*0> newProp(const xmlChar * name, const xmlChar * value) { return xmlNewProp(cobj, name, value); }
#endif
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_XINCLUDE_ENABLED)
  inline void setBase(const xmlChar * uri) { xmlNodeSetBase(cobj, uri); }
#endif
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_WRITER_ENABLED)
  inline Node<0-Owning*0> replaceNode(xmlNodePtr old) { return xmlReplaceNode(old, cobj); }
#endif
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_XINCLUDE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED) || defined(LIBXML_HTML_ENABLED)
  inline Attr<0-Owning*0> setNsProp(xmlNsPtr ns, const xmlChar * name, const xmlChar * value) { return xmlSetNsProp(cobj, ns, name, value); }
  inline Attr<0-Owning*0> setProp(const xmlChar * name, const xmlChar * value) { return xmlSetProp(cobj, name, value); }
#endif
#if defined(LIBXML_DEBUG_ENABLED) && defined(LIBXML_XPATH_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
  inline void shellPrintNode() { xmlShellPrintNode(cobj); }
#endif
#if defined(LIBXML_VALID_ENABLED)
  inline int validGetValidElements(xmlNode * next, const xmlChar ** names, int max) { return xmlValidGetValidElements(cobj, next, names, max); }
#endif
#if defined(LIBXML_XINCLUDE_ENABLED)
  inline int xIncludeProcessTree() { return xmlXIncludeProcessTree(cobj); }
  inline int xIncludeProcessTreeFlags(int flags) { return xmlXIncludeProcessTreeFlags(cobj, flags); }
  inline int xIncludeProcessTreeFlagsData(int flags, void * data) { return xmlXIncludeProcessTreeFlagsData(cobj, flags, data); }
#endif
#if defined(LIBXML_XPATH_ENABLED)
  inline double xPathCastNodeToNumber() { return xmlXPathCastNodeToNumber(cobj); }
  inline xmlChar*  xPathCastNodeToString() { return xmlXPathCastNodeToString(cobj); }
  inline int xPathCmpNodes(xmlNodePtr node2) { return xmlXPathCmpNodes(cobj, node2); }
  inline XPathObject<1-Owning*0> xPathNewNodeSet() { return xmlXPathNewNodeSet(cobj); }
  inline XPathObject<1-Owning*0> xPathNewValueTree() { return xmlXPathNewValueTree(cobj); }
  inline Node<0-Owning*0> xPathNextAncestor(xmlXPathParserContextPtr ctxt) { return xmlXPathNextAncestor(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextAncestorOrSelf(xmlXPathParserContextPtr ctxt) { return xmlXPathNextAncestorOrSelf(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextAttribute(xmlXPathParserContextPtr ctxt) { return xmlXPathNextAttribute(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextChild(xmlXPathParserContextPtr ctxt) { return xmlXPathNextChild(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextDescendant(xmlXPathParserContextPtr ctxt) { return xmlXPathNextDescendant(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextDescendantOrSelf(xmlXPathParserContextPtr ctxt) { return xmlXPathNextDescendantOrSelf(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextFollowing(xmlXPathParserContextPtr ctxt) { return xmlXPathNextFollowing(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextFollowingSibling(xmlXPathParserContextPtr ctxt) { return xmlXPathNextFollowingSibling(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextNamespace(xmlXPathParserContextPtr ctxt) { return xmlXPathNextNamespace(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextParent(xmlXPathParserContextPtr ctxt) { return xmlXPathNextParent(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextPreceding(xmlXPathParserContextPtr ctxt) { return xmlXPathNextPreceding(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextPrecedingSibling(xmlXPathParserContextPtr ctxt) { return xmlXPathNextPrecedingSibling(ctxt, cobj); }
  inline Node<0-Owning*0> xPathNextSelf(xmlXPathParserContextPtr ctxt) { return xmlXPathNextSelf(ctxt, cobj); }
  inline XPathObject<1-Owning*0> xPathNodeEval(const xmlChar * str, xmlXPathContextPtr ctx) { return xmlXPathNodeEval(cobj, str, ctx); }
  inline NodeSet<1-Owning*0> xPathNodeSetCreate() { return xmlXPathNodeSetCreate(cobj); }
  inline int xPathSetContextNode(xmlXPathContextPtr ctx) { return xmlXPathSetContextNode(cobj, ctx); }
#endif
#if defined(LIBXML_XPTR_ENABLED)
  inline XPathObject<1-Owning*0> xPtrNewCollapsedRange() { return xmlXPtrNewCollapsedRange(cobj); }
  inline XPathObject<1-Owning*0> xPtrNewLocationSetNodes(xmlNodePtr end) { return xmlXPtrNewLocationSetNodes(cobj, end); }
  inline XPathObject<1-Owning*0> xPtrNewRange(int startindex, xmlNodePtr end, int endindex) { return xmlXPtrNewRange(cobj, startindex, end, endindex); }
  inline XPathObject<1-Owning*0> xPtrNewRangeNodeObject(xmlXPathObjectPtr end) { return xmlXPtrNewRangeNodeObject(cobj, end); }
  inline XPathObject<1-Owning*0> xPtrNewRangeNodePoint(xmlXPathObjectPtr end) { return xmlXPtrNewRangeNodePoint(cobj, end); }
  inline XPathObject<1-Owning*0> xPtrNewRangeNodes(xmlNodePtr end) { return xmlXPtrNewRangeNodes(cobj, end); }
#endif
};

template<bool Owning = 0>
class ParserCtxt {
 _xmlParserCtxt *cobj;
public:
 inline ~ParserCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline ParserCtxt(_xmlParserCtxt *ptr) : cobj(ptr) {}
 inline ParserCtxt(const ParserCtxt<0> &o) : cobj(o.cobj) {}
 inline ParserCtxt(const ParserCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlParserCtxt*() { return cobj; }
 inline ParserCtxt<0> release() { }
 inline long byteConsumed() { return xmlByteConsumed(cobj); }
 inline ParserInput<0-Owning*0> checkHTTPInput(xmlParserInputPtr ret) { return xmlCheckHTTPInput(cobj, ret); }
 inline void clearParserCtxt() { xmlClearParserCtxt(cobj); }
 inline static ParserCtxt<1-Owning*0> createDocParserCtxt(const xmlChar * cur) { return xmlCreateDocParserCtxt(cur); }
 inline static ParserCtxt<1-Owning*0> createEntityParserCtxt(const xmlChar * URL, const xmlChar * ID, const xmlChar * base) { return xmlCreateEntityParserCtxt(URL, ID, base); }
 inline static ParserCtxt<1-Owning*0> createFileParserCtxt(const char * filename) { return xmlCreateFileParserCtxt(filename); }
 inline static ParserCtxt<1-Owning*0> createMemoryParserCtxt(const char * buffer, int size) { return xmlCreateMemoryParserCtxt(buffer, size); }
 inline static ParserCtxt<1-Owning*0> createURLParserCtxt(const char * filename, int options) { return xmlCreateURLParserCtxt(filename, options); }
 inline Doc<1-Owning*0> readDoc(const xmlChar * cur, const char * URL, const char * encoding, int options) { return xmlCtxtReadDoc(cobj, cur, URL, encoding, options); }
 inline Doc<1-Owning*0> readFd(int fd, const char * URL, const char * encoding, int options) { return xmlCtxtReadFd(cobj, fd, URL, encoding, options); }
 inline Doc<1-Owning*0> readFile(const char * filename, const char * encoding, int options) { return xmlCtxtReadFile(cobj, filename, encoding, options); }
 inline Doc<1-Owning*0> readIO(xmlInputReadCallback ioread, xmlInputCloseCallback ioclose, void * ioctx, const char * URL, const char * encoding, int options) { return xmlCtxtReadIO(cobj, ioread, ioclose, ioctx, URL, encoding, options); }
 inline Doc<1-Owning*0> readMemory(const char * buffer, int size, const char * URL, const char * encoding, int options) { return xmlCtxtReadMemory(cobj, buffer, size, URL, encoding, options); }
 inline void reset() { xmlCtxtReset(cobj); }
 inline int resetPush(const char * chunk, int size, const char * filename, const char * encoding) { return xmlCtxtResetPush(cobj, chunk, size, filename, encoding); }
 inline int useOptions(int options) { return xmlCtxtUseOptions(cobj, options); }
 inline int currentChar(int * len) { return xmlCurrentChar(cobj, len); }
 inline int initParserCtxt() { return xmlInitParserCtxt(cobj); }
 inline ParserInput<1-Owning*0> newEntityInputStream(xmlEntityPtr entity) { return xmlNewEntityInputStream(cobj, entity); }
 inline ParserInput<1-Owning*0> newIOInputStream(xmlParserInputBufferPtr input, xmlCharEncoding enc) { return xmlNewIOInputStream(cobj, input, enc); }
 inline ParserInput<1-Owning*0> newInputFromFile(const char * filename) { return xmlNewInputFromFile(cobj, filename); }
 inline ParserInput<1-Owning*0> newInputStream() { return xmlNewInputStream(cobj); }
 inline static ParserCtxt<1-Owning*0> newParserCtxt() { return xmlNewParserCtxt(); }
 inline ParserInput<1-Owning*0> newStringInputStream(const xmlChar * buffer) { return xmlNewStringInputStream(cobj, buffer); }
 inline void nextChar() { xmlNextChar(cobj); }
 inline xmlChar*  parseAttValue() { return xmlParseAttValue(cobj); }
 inline void parseAttributeListDecl() { xmlParseAttributeListDecl(cobj); }
 inline int parseAttributeType(xmlEnumerationPtr * tree) { return xmlParseAttributeType(cobj, tree); }
 inline void parseCDSect() { xmlParseCDSect(cobj); }
 inline void parseCharData(int cdata) { xmlParseCharData(cobj, cdata); }
 inline int parseCharRef() { return xmlParseCharRef(cobj); }
 inline void parseComment() { xmlParseComment(cobj); }
 inline void parseContent() { xmlParseContent(cobj); }
 inline int parseCtxtExternalEntity(const xmlChar * URL, const xmlChar * ID, xmlNodePtr * lst) { return xmlParseCtxtExternalEntity(cobj, URL, ID, lst); }
 inline int parseDefaultDecl(xmlChar ** value) { return xmlParseDefaultDecl(cobj, value); }
 inline void parseDocTypeDecl() { xmlParseDocTypeDecl(cobj); }
 inline int parseDocument() { return xmlParseDocument(cobj); }
 inline void parseElement() { xmlParseElement(cobj); }
 inline ElementContent<0-Owning*0> parseElementChildrenContentDecl(int inputchk) { return xmlParseElementChildrenContentDecl(cobj, inputchk); }
 inline int parseElementContentDecl(const xmlChar * name, xmlElementContentPtr * result) { return xmlParseElementContentDecl(cobj, name, result); }
 inline int parseElementDecl() { return xmlParseElementDecl(cobj); }
 inline ElementContent<0-Owning*0> parseElementMixedContentDecl(int inputchk) { return xmlParseElementMixedContentDecl(cobj, inputchk); }
 inline xmlChar*  parseEncName() { return xmlParseEncName(cobj); }
 inline xmlChar*  parseEncodingDecl() { return xmlParseEncodingDecl(cobj); }
 inline void parseEntityDecl() { xmlParseEntityDecl(cobj); }
 inline Entity<0-Owning*0> parseEntityRef() { return xmlParseEntityRef(cobj); }
 inline xmlChar*  parseEntityValue(xmlChar ** orig) { return xmlParseEntityValue(cobj, orig); }
 inline int parseEnumeratedType(xmlEnumerationPtr * tree) { return xmlParseEnumeratedType(cobj, tree); }
 inline Enumeration<0-Owning*0> parseEnumerationType() { return xmlParseEnumerationType(cobj); }
 inline int parseExtParsedEnt() { return xmlParseExtParsedEnt(cobj); }
 inline xmlChar*  parseExternalID(xmlChar ** publicID, int strict) { return xmlParseExternalID(cobj, publicID, strict); }
 inline void parseExternalSubset(const xmlChar * ExternalID, const xmlChar * SystemID) { xmlParseExternalSubset(cobj, ExternalID, SystemID); }
 inline void parseMarkupDecl() { xmlParseMarkupDecl(cobj); }
 inline void parseMisc() { xmlParseMisc(cobj); }
 inline xmlChar*  parseName() { return xmlParseName(cobj); }
 inline xmlChar*  parseNmtoken() { return xmlParseNmtoken(cobj); }
 inline void parseNotationDecl() { xmlParseNotationDecl(cobj); }
 inline Enumeration<0-Owning*0> parseNotationType() { return xmlParseNotationType(cobj); }
 inline void parsePEReference() { xmlParsePEReference(cobj); }
 inline void parsePI() { xmlParsePI(cobj); }
 inline xmlChar*  parsePITarget() { return xmlParsePITarget(cobj); }
 inline xmlChar*  parsePubidLiteral() { return xmlParsePubidLiteral(cobj); }
 inline void parseReference() { xmlParseReference(cobj); }
 inline int parseSDDecl() { return xmlParseSDDecl(cobj); }
 inline xmlChar*  parseSystemLiteral() { return xmlParseSystemLiteral(cobj); }
 inline void parseTextDecl() { xmlParseTextDecl(cobj); }
 inline xmlChar*  parseVersionInfo() { return xmlParseVersionInfo(cobj); }
 inline xmlChar*  parseVersionNum() { return xmlParseVersionNum(cobj); }
 inline void parseXMLDecl() { xmlParseXMLDecl(cobj); }
 inline void addNodeInfo(const xmlParserNodeInfoPtr info) { xmlParserAddNodeInfo(cobj, info); }
 inline ParserNodeInfo<0-Owning*0> findNodeInfo(const xmlNodePtr node) { return xmlParserFindNodeInfo(cobj, node); }
 inline void handlePEReference() { xmlParserHandlePEReference(cobj); }
 inline xmlChar  popInput() { return xmlPopInput(cobj); }
 inline int pushInput(xmlParserInputPtr input) { return xmlPushInput(cobj, input); }
 inline int skipBlankChars() { return xmlSkipBlankChars(cobj); }
 inline xmlChar*  splitQName(const xmlChar * name, xmlChar ** prefix) { return xmlSplitQName(cobj, name, prefix); }
 inline void stopParser() { xmlStopParser(cobj); }
 inline int stringCurrentChar(const xmlChar * cur, int * len) { return xmlStringCurrentChar(cobj, cur, len); }
 inline xmlChar*  stringDecodeEntities(const xmlChar * str, int what, xmlChar end, xmlChar end2, xmlChar end3) { return xmlStringDecodeEntities(cobj, str, what, end, end2, end3); }
 inline xmlChar*  stringLenDecodeEntities(const xmlChar * str, int len, int what, xmlChar end, xmlChar end2, xmlChar end3) { return xmlStringLenDecodeEntities(cobj, str, len, what, end, end2, end3); }
 inline int switchEncoding(xmlCharEncoding enc) { return xmlSwitchEncoding(cobj, enc); }
 inline int switchInputEncoding(xmlParserInputPtr input, xmlCharEncodingHandlerPtr handler) { return xmlSwitchInputEncoding(cobj, input, handler); }
 inline int switchToEncoding(xmlCharEncodingHandlerPtr handler) { return xmlSwitchToEncoding(cobj, handler); }
#if defined(LIBXML_LEGACY_ENABLED)
  inline xmlChar*  decodeEntities(int len, int what, xmlChar end, xmlChar end2, xmlChar end3) { return xmlDecodeEntities(cobj, len, what, end, end2, end3); }
  inline int getFeature(const char * name, void * result) { return xmlGetFeature(cobj, name, result); }
  inline void handleEntity(xmlEntityPtr entity) { xmlHandleEntity(cobj, entity); }
  inline xmlChar*  namespaceParseNCName() { return xmlNamespaceParseNCName(cobj); }
  inline xmlChar*  namespaceParseNSDef() { return xmlNamespaceParseNSDef(cobj); }
  inline xmlChar*  namespaceParseQName(xmlChar ** prefix) { return xmlNamespaceParseQName(cobj, prefix); }
  inline void parseNamespace() { xmlParseNamespace(cobj); }
  inline xmlChar*  parseQuotedString() { return xmlParseQuotedString(cobj); }
  inline void handleReference() { xmlParserHandleReference(cobj); }
  inline xmlChar*  scanName() { return xmlScanName(cobj); }
  inline int setFeature(const char * name, void * value) { return xmlSetFeature(cobj, name, value); }
#endif
#if defined(LIBXML_WRITER_ENABLED)
  inline TextWriter<1-Owning*0> newTextWriterPushParser(int compression) { return xmlNewTextWriterPushParser(cobj, compression); }
#endif
#if defined(LIBXML_SAX1_ENABLED)
  inline xmlChar*  parseAttribute(xmlChar ** value) { return xmlParseAttribute(cobj, value); }
  inline void parseEndTag() { xmlParseEndTag(cobj); }
  inline xmlChar*  parseStartTag() { return xmlParseStartTag(cobj); }
  inline void setupParserForBuffer(const xmlChar * buffer, const char * filename) { xmlSetupParserForBuffer(cobj, buffer, filename); }
#endif
#if defined(LIBXML_PUSH_ENABLED)
  inline int parseChunk(const char * chunk, int size, int terminate) { return xmlParseChunk(cobj, chunk, size, terminate); }
#endif
};

template<bool Owning = 0>
class Buffer {
 _xmlBuffer *cobj;
public:
 inline ~Buffer() { if (Owning) free(cobj), cobj = NULL; }
 inline Buffer(_xmlBuffer *ptr) : cobj(ptr) {}
 inline Buffer(const Buffer<0> &o) : cobj(o.cobj) {}
 inline Buffer(const Buffer<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlBuffer*() { return cobj; }
 inline Buffer<0> release() { }
 inline int add(const xmlChar * str, int len) { return xmlBufferAdd(cobj, str, len); }
 inline int addHead(const xmlChar * str, int len) { return xmlBufferAddHead(cobj, str, len); }
 inline int cCat(const char * str) { return xmlBufferCCat(cobj, str); }
 inline int cat(const xmlChar * str) { return xmlBufferCat(cobj, str); }
 inline xmlChar*  content() const { return xmlBufferContent(cobj); }
 inline static Buffer<1-Owning*0> create() { return xmlBufferCreate(); }
 inline static Buffer<1-Owning*0> createSize(size_t size) { return xmlBufferCreateSize(size); }
 inline static Buffer<1-Owning*0> createStatic(void * mem, size_t size) { return xmlBufferCreateStatic(mem, size); }
 inline xmlChar*  detach() { return xmlBufferDetach(cobj); }
 inline void empty() { xmlBufferEmpty(cobj); }
 inline int grow(unsigned int len) { return xmlBufferGrow(cobj, len); }
 inline int length() const { return xmlBufferLength(cobj); }
 inline int resize(unsigned int size) { return xmlBufferResize(cobj, size); }
 inline void setAllocationScheme(xmlBufferAllocationScheme scheme) { xmlBufferSetAllocationScheme(cobj, scheme); }
 inline int shrink(unsigned int len) { return xmlBufferShrink(cobj, len); }
 inline void writeCHAR(const xmlChar * string) { xmlBufferWriteCHAR(cobj, string); }
 inline void writeChar(const char * string) { xmlBufferWriteChar(cobj, string); }
 inline void writeQuotedString(const xmlChar * string) { xmlBufferWriteQuotedString(cobj, string); }
#if defined(LIBXML_OUTPUT_ENABLED)
  inline void attrSerializeTxtContent(xmlDocPtr doc, xmlAttrPtr attr, const xmlChar * string) { xmlAttrSerializeTxtContent(cobj, doc, attr, string); }
  inline void dumpAttributeDecl(xmlAttributePtr attr) { xmlDumpAttributeDecl(cobj, attr); }
  inline void dumpAttributeTable(xmlAttributeTablePtr table) { xmlDumpAttributeTable(cobj, table); }
  inline void dumpElementDecl(xmlElementPtr elem) { xmlDumpElementDecl(cobj, elem); }
  inline void dumpElementTable(xmlElementTablePtr table) { xmlDumpElementTable(cobj, table); }
  inline void dumpEntitiesTable(xmlEntitiesTablePtr table) { xmlDumpEntitiesTable(cobj, table); }
  inline void dumpEntityDecl(xmlEntityPtr ent) { xmlDumpEntityDecl(cobj, ent); }
  inline void dumpNotationDecl(xmlNotationPtr nota) { xmlDumpNotationDecl(cobj, nota); }
  inline void dumpNotationTable(xmlNotationTablePtr table) { xmlDumpNotationTable(cobj, table); }
  inline OutputBuffer<1-Owning*0> outputBufferCreateBuffer(xmlCharEncodingHandlerPtr encoder) { return xmlOutputBufferCreateBuffer(cobj, encoder); }
  inline SaveCtxt<1-Owning*0> saveToBuffer(const char * encoding, int options) { return xmlSaveToBuffer(cobj, encoding, options); }
#endif
#if defined(LIBXML_WRITER_ENABLED)
  inline TextWriter<1-Owning*0> newTextWriterMemory(int compression) { return xmlNewTextWriterMemory(cobj, compression); }
#endif
};

template<bool Owning = 0>
class ValidCtxt {
 _xmlValidCtxt *cobj;
public:
 inline ~ValidCtxt() { if (Owning) free(cobj), cobj = NULL; }
 inline ValidCtxt(_xmlValidCtxt *ptr) : cobj(ptr) {}
 inline ValidCtxt(const ValidCtxt<0> &o) : cobj(o.cobj) {}
 inline ValidCtxt(const ValidCtxt<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlValidCtxt*() { return cobj; }
 inline ValidCtxt<0> release() { }
 inline Attribute<0-Owning*0> addAttributeDecl(xmlDtdPtr dtd, const xmlChar * elem, const xmlChar * name, const xmlChar * ns, xmlAttributeType type, xmlAttributeDefault def, const xmlChar * defaultValue, xmlEnumerationPtr tree) { return xmlAddAttributeDecl(cobj, dtd, elem, name, ns, type, def, defaultValue, tree); }
 inline Element<0-Owning*0> addElementDecl(xmlDtdPtr dtd, const xmlChar * name, xmlElementTypeVal type, xmlElementContentPtr content) { return xmlAddElementDecl(cobj, dtd, name, type, content); }
 inline ID<1-Owning*0> addID(xmlDocPtr doc, const xmlChar * value, xmlAttrPtr attr) { return xmlAddID(cobj, doc, value, attr); }
 inline Notation<0-Owning*0> addNotationDecl(xmlDtdPtr dtd, const xmlChar * name, const xmlChar * PublicID, const xmlChar * SystemID) { return xmlAddNotationDecl(cobj, dtd, name, PublicID, SystemID); }
 inline Ref<1-Owning*0> addRef(xmlDocPtr doc, const xmlChar * value, xmlAttrPtr attr) { return xmlAddRef(cobj, doc, value, attr); }
#if defined(LIBXML_VALID_ENABLED)
  inline static ValidCtxt<1-Owning*0> newValidCtxt() { return xmlNewValidCtxt(); }
  inline xmlChar*  normalizeAttributeValue(xmlDocPtr doc, xmlNodePtr elem, const xmlChar * name, const xmlChar * value) { return xmlValidCtxtNormalizeAttributeValue(cobj, doc, elem, name, value); }
  inline int validateAttributeDecl(xmlDocPtr doc, xmlAttributePtr attr) { return xmlValidateAttributeDecl(cobj, doc, attr); }
  inline int validateDocument(xmlDocPtr doc) { return xmlValidateDocument(cobj, doc); }
  inline int validateDocumentFinal(xmlDocPtr doc) { return xmlValidateDocumentFinal(cobj, doc); }
  inline int validateDtd(xmlDocPtr doc, xmlDtdPtr dtd) { return xmlValidateDtd(cobj, doc, dtd); }
  inline int validateDtdFinal(xmlDocPtr doc) { return xmlValidateDtdFinal(cobj, doc); }
  inline int validateElement(xmlDocPtr doc, xmlNodePtr elem) { return xmlValidateElement(cobj, doc, elem); }
  inline int validateElementDecl(xmlDocPtr doc, xmlElementPtr elem) { return xmlValidateElementDecl(cobj, doc, elem); }
  inline int validateNotationDecl(xmlDocPtr doc, xmlNotationPtr nota) { return xmlValidateNotationDecl(cobj, doc, nota); }
  inline int validateOneAttribute(xmlDocPtr doc, xmlNodePtr elem, xmlAttrPtr attr, const xmlChar * value) { return xmlValidateOneAttribute(cobj, doc, elem, attr, value); }
  inline int validateOneElement(xmlDocPtr doc, xmlNodePtr elem) { return xmlValidateOneElement(cobj, doc, elem); }
  inline int validateOneNamespace(xmlDocPtr doc, xmlNodePtr elem, const xmlChar * prefix, xmlNsPtr ns, const xmlChar * value) { return xmlValidateOneNamespace(cobj, doc, elem, prefix, ns, value); }
  inline int validateRoot(xmlDocPtr doc) { return xmlValidateRoot(cobj, doc); }
#endif
#if defined(LIBXML_VALID_ENABLED) && defined(LIBXML_REGEXP_ENABLED)
  inline int buildContentModel(xmlElementPtr elem) { return xmlValidBuildContentModel(cobj, elem); }
  inline int validatePopElement(xmlDocPtr doc, xmlNodePtr elem, const xmlChar * qname) { return xmlValidatePopElement(cobj, doc, elem, qname); }
  inline int validatePushCData(const xmlChar * data, int len) { return xmlValidatePushCData(cobj, data, len); }
  inline int validatePushElement(xmlDocPtr doc, xmlNodePtr elem, const xmlChar * qname) { return xmlValidatePushElement(cobj, doc, elem, qname); }
#endif
#if defined(LIBXML_VALID_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
  inline int validateNotationUse(xmlDocPtr doc, const xmlChar * notationName) { return xmlValidateNotationUse(cobj, doc, notationName); }
#endif
};

template<bool Owning = 0>
class Doc {
 _xmlDoc *cobj;
public:
 inline ~Doc() { if (Owning) free(cobj), cobj = NULL; }
 inline Doc(_xmlDoc *ptr) : cobj(ptr) {}
 inline Doc(const Doc<0> &o) : cobj(o.cobj) {}
 inline Doc(const Doc<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlDoc*() { return cobj; }
 inline Doc<0> release() { }
 inline Entity<0-Owning*0> addDocEntity(const xmlChar * name, int type, const xmlChar * ExternalID, const xmlChar * SystemID, const xmlChar * content) { return xmlAddDocEntity(cobj, name, type, ExternalID, SystemID, content); }
 inline Entity<0-Owning*0> addDtdEntity(const xmlChar * name, int type, const xmlChar * ExternalID, const xmlChar * SystemID, const xmlChar * content) { return xmlAddDtdEntity(cobj, name, type, ExternalID, SystemID, content); }
 inline ElementContent<1-Owning*0> copyDocElementContent(xmlElementContentPtr cur) { return xmlCopyDocElementContent(cobj, cur); }
 inline Dtd<1-Owning*0> createIntSubset(const xmlChar * name, const xmlChar * ExternalID, const xmlChar * SystemID) { return xmlCreateIntSubset(cobj, name, ExternalID, SystemID); }
 inline Node<1-Owning*0> copyNodeList(xmlNodePtr node) { return xmlDocCopyNodeList(cobj, node); }
 inline Node<0-Owning*0> getRootElement() const { return xmlDocGetRootElement(cobj); }
 inline xmlChar*  encodeEntitiesReentrant(const xmlChar * input) { return xmlEncodeEntitiesReentrant(cobj, input); }
 inline xmlChar*  encodeSpecialChars(const xmlChar * input) const { return xmlEncodeSpecialChars(cobj, input); }
 inline int getDocCompressMode() const { return xmlGetDocCompressMode(cobj); }
 inline Entity<0-Owning*0> getDocEntity(const xmlChar * name) const { return xmlGetDocEntity(cobj, name); }
 inline Entity<0-Owning*0> getDtdEntity(const xmlChar * name) { return xmlGetDtdEntity(cobj, name); }
 inline Attr<0-Owning*0> getID(const xmlChar * ID) { return xmlGetID(cobj, ID); }
 inline Dtd<0-Owning*0> getIntSubset() const { return xmlGetIntSubset(cobj); }
 inline Entity<0-Owning*0> getParameterEntity(const xmlChar * name) { return xmlGetParameterEntity(cobj, name); }
 inline List<0-Owning*0> getRefs(const xmlChar * ID) { return xmlGetRefs(cobj, ID); }
 inline int isID(xmlNodePtr elem, xmlAttrPtr attr) { return xmlIsID(cobj, elem, attr); }
 inline int isMixedElement(const xmlChar * name) { return xmlIsMixedElement(cobj, name); }
 inline int isRef(xmlNodePtr elem, xmlAttrPtr attr) { return xmlIsRef(cobj, elem, attr); }
 inline Node<1-Owning*0> newCDataBlock(const xmlChar * content, int len) { return xmlNewCDataBlock(cobj, content, len); }
 inline Node<1-Owning*0> newCharRef(const xmlChar * name) { return xmlNewCharRef(cobj, name); }
 inline static Doc<1-Owning*0> newDoc(const xmlChar * version) { return xmlNewDoc(version); }
 inline Node<1-Owning*0> newDocComment(const xmlChar * content) { return xmlNewDocComment(cobj, content); }
 inline ElementContent<1-Owning*0> newDocElementContent(const xmlChar * name, xmlElementContentType type) { return xmlNewDocElementContent(cobj, name, type); }
 inline Node<1-Owning*0> newDocNode(xmlNsPtr ns, const xmlChar * name, const xmlChar * content) { return xmlNewDocNode(cobj, ns, name, content); }
 inline Node<1-Owning*0> newDocNodeEatName(xmlNsPtr ns, xmlChar * name, const xmlChar * content) { return xmlNewDocNodeEatName(cobj, ns, name, content); }
 inline Node<1-Owning*0> newDocPI(const xmlChar * name, const xmlChar * content) { return xmlNewDocPI(cobj, name, content); }
 inline Attr<1-Owning*0> newDocProp(const xmlChar * name, const xmlChar * value) { return xmlNewDocProp(cobj, name, value); }
 inline Node<1-Owning*0> newDocText(const xmlChar * content) const { return xmlNewDocText(cobj, content); }
 inline Node<1-Owning*0> newDocTextLen(const xmlChar * content, int len) { return xmlNewDocTextLen(cobj, content, len); }
 inline Dtd<1-Owning*0> newDtd(const xmlChar * name, const xmlChar * ExternalID, const xmlChar * SystemID) { return xmlNewDtd(cobj, name, ExternalID, SystemID); }
 inline Entity<1-Owning*0> newEntity(const xmlChar * name, int type, const xmlChar * ExternalID, const xmlChar * SystemID, const xmlChar * content) { return xmlNewEntity(cobj, name, type, ExternalID, SystemID, content); }
 inline Node<1-Owning*0> newReference(const xmlChar * name) const { return xmlNewReference(cobj, name); }
 inline xmlChar*  nodeListGetString(const xmlNode * list, int inLine) { return xmlNodeListGetString(cobj, list, inLine); }
 inline static Doc<1-Owning*0> readDoc(const xmlChar * cur, const char * URL, const char * encoding, int options) { return xmlReadDoc(cur, URL, encoding, options); }
 inline static Doc<1-Owning*0> readFd(int fd, const char * URL, const char * encoding, int options) { return xmlReadFd(fd, URL, encoding, options); }
 inline static Doc<1-Owning*0> readFile(const char * filename, const char * encoding, int options) { return xmlReadFile(filename, encoding, options); }
 inline static Doc<1-Owning*0> readIO(xmlInputReadCallback ioread, xmlInputCloseCallback ioclose, void * ioctx, const char * URL, const char * encoding, int options) { return xmlReadIO(ioread, ioclose, ioctx, URL, encoding, options); }
 inline static Doc<1-Owning*0> readMemory(const char * buffer, int size, const char * URL, const char * encoding, int options) { return xmlReadMemory(buffer, size, URL, encoding, options); }
 inline int removeID(xmlAttrPtr attr) { return xmlRemoveID(cobj, attr); }
 inline int removeRef(xmlAttrPtr attr) { return xmlRemoveRef(cobj, attr); }
 inline Ns<0-Owning*0> searchNs(xmlNodePtr node, const xmlChar * nameSpace) { return xmlSearchNs(cobj, node, nameSpace); }
 inline Ns<0-Owning*0> searchNsByHref(xmlNodePtr node, const xmlChar * href) { return xmlSearchNsByHref(cobj, node, href); }
 inline void setDocCompressMode(int mode) { xmlSetDocCompressMode(cobj, mode); }
 inline Node<0-Owning*0> stringGetNodeList(const xmlChar * value) const { return xmlStringGetNodeList(cobj, value); }
 inline Node<0-Owning*0> stringLenGetNodeList(const xmlChar * value, int len) const { return xmlStringLenGetNodeList(cobj, value, len); }
#if defined(LIBXML_C14N_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
  inline int c14NDocDumpMemory(xmlNodeSetPtr nodes, int mode, xmlChar ** inclusive_ns_prefixes, int with_comments, xmlChar ** doc_txt_ptr) { return xmlC14NDocDumpMemory(cobj, nodes, mode, inclusive_ns_prefixes, with_comments, doc_txt_ptr); }
  inline int c14NDocSave(xmlNodeSetPtr nodes, int mode, xmlChar ** inclusive_ns_prefixes, int with_comments, const char * filename, int compression) { return xmlC14NDocSave(cobj, nodes, mode, inclusive_ns_prefixes, with_comments, filename, compression); }
  inline int c14NDocSaveTo(xmlNodeSetPtr nodes, int mode, xmlChar ** inclusive_ns_prefixes, int with_comments, xmlOutputBufferPtr buf) { return xmlC14NDocSaveTo(cobj, nodes, mode, inclusive_ns_prefixes, with_comments, buf); }
  inline int c14NExecute(xmlC14NIsVisibleCallback is_visible_callback, void * user_data, int mode, xmlChar ** inclusive_ns_prefixes, int with_comments, xmlOutputBufferPtr buf) { return xmlC14NExecute(cobj, is_visible_callback, user_data, mode, inclusive_ns_prefixes, with_comments, buf); }
#endif
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
  inline Doc<1-Owning*0> copyDoc(int recursive) { return xmlCopyDoc(cobj, recursive); }
#endif
#if defined(LIBXML_OUTPUT_ENABLED)
  inline int dump(FILE * f) { return xmlDocDump(f, cobj); }
  inline void dumpFormatMemory(xmlChar ** mem, int * size, int format) { xmlDocDumpFormatMemory(cobj, mem, size, format); }
  inline void dumpFormatMemoryEnc(xmlChar ** doc_txt_ptr, int * doc_txt_len, const char * txt_encoding, int format) { xmlDocDumpFormatMemoryEnc(cobj, doc_txt_ptr, doc_txt_len, txt_encoding, format); }
  inline void dumpMemory(xmlChar ** mem, int * size) { xmlDocDumpMemory(cobj, mem, size); }
  inline void dumpMemoryEnc(xmlChar ** doc_txt_ptr, int * doc_txt_len, const char * txt_encoding) { xmlDocDumpMemoryEnc(cobj, doc_txt_ptr, doc_txt_len, txt_encoding); }
  inline int formatDump(FILE * f, int format) { return xmlDocFormatDump(f, cobj, format); }
  inline int saveFile(const char * filename) { return xmlSaveFile(filename, cobj); }
  inline int saveFileEnc(const char * filename, const char * encoding) { return xmlSaveFileEnc(filename, cobj, encoding); }
  inline int saveFileTo(xmlOutputBufferPtr buf, const char * encoding) { return xmlSaveFileTo(buf, cobj, encoding); }
  inline int saveFormatFile(const char * filename, int format) { return xmlSaveFormatFile(filename, cobj, format); }
  inline int saveFormatFileEnc(const char * filename, const char * encoding, int format) { return xmlSaveFormatFileEnc(filename, cobj, encoding, format); }
  inline int saveFormatFileTo(xmlOutputBufferPtr buf, const char * encoding, int format) { return xmlSaveFormatFileTo(buf, cobj, encoding, format); }
#endif
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_WRITER_ENABLED)
  inline Node<0-Owning*0> setRootElement(xmlNodePtr root) { return xmlDocSetRootElement(cobj, root); }
#endif
#if defined(LIBXML_LEGACY_ENABLED)
  inline xmlChar*  encodeEntities(const xmlChar * input) { return xmlEncodeEntities(cobj, input); }
  inline Ns<1-Owning*0> newGlobalNs(const xmlChar * href, const xmlChar * prefix) { return xmlNewGlobalNs(cobj, href, prefix); }
#endif
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_XPATH_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
  inline xmlNsPtr * getNsList(const xmlNode * node) const { return xmlGetNsList(cobj, node); }
#endif
#if defined(LIBXML_TREE_ENABLED)
  inline Node<1-Owning*0> newDocFragment() { return xmlNewDocFragment(cobj); }
  inline Node<1-Owning*0> newDocRawNode(xmlNsPtr ns, const xmlChar * name, const xmlChar * content) { return xmlNewDocRawNode(cobj, ns, name, content); }
  inline xmlChar*  nodeListGetRawString(const xmlNode * list, int inLine) const { return xmlNodeListGetRawString(cobj, list, inLine); }
  inline int reconciliateNs(xmlNodePtr tree) { return xmlReconciliateNs(cobj, tree); }
#endif
#if defined(LIBXML_WRITER_ENABLED)
  inline TextWriter<1-Owning*0> newTextWriterTree(xmlNodePtr node, int compression) { return xmlNewTextWriterTree(cobj, node, compression); }
#endif
#if defined(LIBXML_SAX1_ENABLED)
  inline int parseBalancedChunkMemory(xmlSAXHandlerPtr sax, void * user_data, int depth, const xmlChar * string, xmlNodePtr * lst) { return xmlParseBalancedChunkMemory(cobj, sax, user_data, depth, string, lst); }
  inline int parseBalancedChunkMemoryRecover(xmlSAXHandlerPtr sax, void * user_data, int depth, const xmlChar * string, xmlNodePtr * lst, int recover) { return xmlParseBalancedChunkMemoryRecover(cobj, sax, user_data, depth, string, lst, recover); }
  inline static Doc<1-Owning*0> parseDoc(const xmlChar * cur) { return xmlParseDoc(cur); }
  inline static Doc<1-Owning*0> parseEntity(const char * filename) { return xmlParseEntity(filename); }
  inline int parseExternalEntity(xmlSAXHandlerPtr sax, void * user_data, int depth, const xmlChar * URL, const xmlChar * ID, xmlNodePtr * lst) { return xmlParseExternalEntity(cobj, sax, user_data, depth, URL, ID, lst); }
  inline static Doc<1-Owning*0> parseFile(const char * filename) { return xmlParseFile(filename); }
  inline static Doc<1-Owning*0> parseMemory(const char * buffer, int size) { return xmlParseMemory(buffer, size); }
  inline static Doc<1-Owning*0> recoverDoc(const xmlChar * cur) { return xmlRecoverDoc(cur); }
  inline static Doc<1-Owning*0> recoverFile(const char * filename) { return xmlRecoverFile(filename); }
  inline static Doc<1-Owning*0> recoverMemory(const char * buffer, int size) { return xmlRecoverMemory(buffer, size); }
#endif
#if defined(LIBXML_CATALOG_ENABLED)
  inline static Doc<1-Owning*0> parseCatalogFile(const char * filename) { return xmlParseCatalogFile(filename); }
#endif
#if defined(LIBXML_READER_ENABLED)
  inline TextReader<1-Owning*0> readerWalker() { return xmlReaderWalker(cobj); }
#endif
#if defined(LIBXML_SCHEMAS_ENABLED)
  inline RelaxNGParserCtxt<1-Owning*0> relaxNGNewDocParserCtxt() { return xmlRelaxNGNewDocParserCtxt(cobj); }
  inline SchemaParserCtxt<1-Owning*0> schemaNewDocParserCtxt() { return xmlSchemaNewDocParserCtxt(cobj); }
#endif
#if defined(LIBXML_SCHEMATRON_ENABLED)
  inline SchematronParserCtxt<1-Owning*0> schematronNewDocParserCtxt() { return xmlSchematronNewDocParserCtxt(cobj); }
#endif
#if defined(LIBXML_DEBUG_ENABLED) && defined(LIBXML_XPATH_ENABLED)
  inline void shell(char * filename, xmlShellReadlineFunc input, FILE * output) { xmlShell(cobj, filename, input, output); }
#endif
#if defined(LIBXML_VALID_ENABLED)
  inline xmlChar*  validNormalizeAttributeValue(xmlNodePtr elem, const xmlChar * name, const xmlChar * value) { return xmlValidNormalizeAttributeValue(cobj, elem, name, value); }
#endif
#if defined(LIBXML_XINCLUDE_ENABLED)
  inline XIncludeCtxt<1-Owning*0> xIncludeNewContext() { return xmlXIncludeNewContext(cobj); }
  inline int xIncludeProcess() { return xmlXIncludeProcess(cobj); }
  inline int xIncludeProcessFlags(int flags) { return xmlXIncludeProcessFlags(cobj, flags); }
  inline int xIncludeProcessFlagsData(int flags, void * data) { return xmlXIncludeProcessFlagsData(cobj, flags, data); }
#endif
#if defined(LIBXML_XPATH_ENABLED)
  inline XPathContext<1-Owning*0> xPathNewContext() { return xmlXPathNewContext(cobj); }
  inline long xPathOrderDocElems() { return xmlXPathOrderDocElems(cobj); }
#endif
#if defined(LIBXML_XPTR_ENABLED)
  inline XPathContext<1-Owning*0> xPtrNewContext(xmlNodePtr here, xmlNodePtr origin) { return xmlXPtrNewContext(cobj, here, origin); }
#endif
};

template<bool Owning = 0>
class AutomataState {
 _xmlAutomataState *cobj;
public:
 inline ~AutomataState() { if (Owning) free(cobj), cobj = NULL; }
 inline AutomataState(_xmlAutomataState *ptr) : cobj(ptr) {}
 inline AutomataState(const AutomataState<0> &o) : cobj(o.cobj) {}
 inline AutomataState(const AutomataState<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlAutomataState*() { return cobj; }
 inline AutomataState<0> release() { }
};

template<bool Owning = 0>
class Attribute {
 _xmlAttribute *cobj;
public:
 inline ~Attribute() { if (Owning) free(cobj), cobj = NULL; }
 inline Attribute(_xmlAttribute *ptr) : cobj(ptr) {}
 inline Attribute(const Attribute<0> &o) : cobj(o.cobj) {}
 inline Attribute(const Attribute<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlAttribute*() { return cobj; }
 inline Attribute<0> release() { }
};

template<bool Owning = 0>
class Element {
 _xmlElement *cobj;
public:
 inline ~Element() { if (Owning) free(cobj), cobj = NULL; }
 inline Element(_xmlElement *ptr) : cobj(ptr) {}
 inline Element(const Element<0> &o) : cobj(o.cobj) {}
 inline Element(const Element<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlElement*() { return cobj; }
 inline Element<0> release() { }
};

template<bool Owning = 0>
class Notation {
 _xmlNotation *cobj;
public:
 inline ~Notation() { if (Owning) free(cobj), cobj = NULL; }
 inline Notation(_xmlNotation *ptr) : cobj(ptr) {}
 inline Notation(const Notation<0> &o) : cobj(o.cobj) {}
 inline Notation(const Notation<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlNotation*() { return cobj; }
 inline Notation<0> release() { }
};

template<bool Owning = 0>
class Entity {
 _xmlEntity *cobj;
public:
 inline ~Entity() { if (Owning) free(cobj), cobj = NULL; }
 inline Entity(_xmlEntity *ptr) : cobj(ptr) {}
 inline Entity(const Entity<0> &o) : cobj(o.cobj) {}
 inline Entity(const Entity<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlEntity*() { return cobj; }
 inline Entity<0> release() { }
};

template<bool Owning = 0>
class ParserNodeInfo {
 _xmlParserNodeInfo *cobj;
public:
 inline ~ParserNodeInfo() { if (Owning) free(cobj), cobj = NULL; }
 inline ParserNodeInfo(_xmlParserNodeInfo *ptr) : cobj(ptr) {}
 inline ParserNodeInfo(const ParserNodeInfo<0> &o) : cobj(o.cobj) {}
 inline ParserNodeInfo(const ParserNodeInfo<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlParserNodeInfo*() { return cobj; }
 inline ParserNodeInfo<0> release() { }
};

template<bool Owning = 0>
class ID {
 _xmlID *cobj;
public:
 inline ~ID() { if (Owning) free(cobj), cobj = NULL; }
 inline ID(_xmlID *ptr) : cobj(ptr) {}
 inline ID(const ID<0> &o) : cobj(o.cobj) {}
 inline ID(const ID<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlID*() { return cobj; }
 inline ID<0> release() { }
};

template<bool Owning = 0>
class Ref {
 _xmlRef *cobj;
public:
 inline ~Ref() { if (Owning) free(cobj), cobj = NULL; }
 inline Ref(_xmlRef *ptr) : cobj(ptr) {}
 inline Ref(const Ref<0> &o) : cobj(o.cobj) {}
 inline Ref(const Ref<1> &o) : cobj(o.cobj) { if (Owning) {} }
 inline operator _xmlRef*() { return cobj; }
 inline Ref<0> release() { }
};

}
