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
    //xmlXPathObjectPtr _ = ::xmlXPathCompiledEval(expr, m_xpathcontext);

//: doc(Html::readDoc(source, NULL, NULL,
//    HTML_PARSE_RECOVER|HTML_PARSE_NOERROR|HTML_PARSE_NOWARNING|HTML_PARSE_COMPACT|HTML_PARSE_NOBLANKS))

}
