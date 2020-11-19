#include <utility>

// LibXML2 Includes
$XML_INCLUDES

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

namespace LibXML_impl {
$XML_CLASS_FORWARD_DECLARATIONS
$XML_CLASS_DEFINITIONS
} // namespace LibXML_impl

namespace Xml {
$XML_USING_DECLARATIONS
} // namespace Xml
