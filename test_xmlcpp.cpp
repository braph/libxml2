#include "xmlcpp.h"
#include <iostream>
using namespace std;

const char* d = "<r> <node attr='value' /> </r>";
const char* e = "//node";

int main() {
  auto doc   = Xml::Doc<0>::readDoc(BAD_CAST d, NULL, NULL, 0);
  auto xpath = doc.xPathNewContext();
  auto expr  = Xml::XPathCompExpr<0>::compile(BAD_CAST e);
  auto resu  = expr.compiledEval(xpath);

#if FOO
  // C++ API wrapper
  auto doc    = Xml::Doc::readDoc(d, NULL, NULL, 0);
  auto xpath  = doc.XPathNewContext();
  auto expr   = Xml::XPathCompExpr::compile(e);
  auto result = expr.CompiledEval(xpath);

  // Original C API
  auto doc    = xmlReadDoc(d, NULL, NULL, 0);
  auto xpath  = xmlXPathNewContext(doc);
  auto expr   = xmlXPathCompile(e);
  auto result = xmlXPathCompiledEval(expr, xpath);
  xmlFreeDoc(doc);
  xmlXPathFreeContext(xpath);
  xmlXPathFreeCompExpr(expr);
  xmlXPathFreeObject(result);
#endif
}
