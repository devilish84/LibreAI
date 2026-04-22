#ifndef INCLUDED_COM_SUN_STAR_XML_SAX_SAXINVALIDCHARACTEREXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_XML_SAX_SAXINVALIDCHARACTEREXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/xml/sax/SAXInvalidCharacterException.hdl"

#include "com/sun/star/xml/sax/SAXException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline SAXInvalidCharacterException::SAXInvalidCharacterException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::xml::sax::SAXException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline SAXInvalidCharacterException::SAXInvalidCharacterException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& WrappedException_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::xml::sax::SAXException(Message_, Context_, WrappedException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
SAXInvalidCharacterException::SAXInvalidCharacterException(SAXInvalidCharacterException const & the_other): ::css::xml::sax::SAXException(the_other) {}

SAXInvalidCharacterException::~SAXInvalidCharacterException() {}

SAXInvalidCharacterException & SAXInvalidCharacterException::operator =(SAXInvalidCharacterException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::xml::sax::SAXException::operator =(the_other);
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::sax::SAXInvalidCharacterException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::xml::sax::SAXException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.xml.sax.SAXInvalidCharacterException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::sax::SAXInvalidCharacterException const *) {
    return ::cppu::UnoType< ::css::xml::sax::SAXInvalidCharacterException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_SAX_SAXINVALIDCHARACTEREXCEPTION_HPP
