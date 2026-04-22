#ifndef INCLUDED_COM_SUN_STAR_XML_SAX_SAXEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_XML_SAX_SAXEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/xml/sax/SAXException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline SAXException::SAXException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , WrappedException()
{ }

inline SAXException::SAXException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& WrappedException_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , WrappedException(WrappedException_)
{ }

#if !defined LIBO_INTERNAL_ONLY
SAXException::SAXException(SAXException const & the_other): ::css::uno::Exception(the_other), WrappedException(the_other.WrappedException) {}

SAXException::~SAXException() {}

SAXException & SAXException::operator =(SAXException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    WrappedException = the_other.WrappedException;
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::sax::SAXException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_any = ::cppu::UnoType< ::css::uno::Any >::get();
        aMemberRefs[0] = rMemberType_any.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.xml.sax.SAXException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::sax::SAXException const *) {
    return ::cppu::UnoType< ::css::xml::sax::SAXException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_SAX_SAXEXCEPTION_HPP
