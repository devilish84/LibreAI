#ifndef INCLUDED_COM_SUN_STAR_XML_DOM_DOMEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_XML_DOM_DOMEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/xml/dom/DOMException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/xml/dom/DOMExceptionType.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace dom {

inline DOMException::DOMException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Code(::css::xml::dom::DOMExceptionType_DOMSTRING_SIZE_ERR)
{ }

inline DOMException::DOMException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::xml::dom::DOMExceptionType& Code_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Code(Code_)
{ }

#if !defined LIBO_INTERNAL_ONLY
DOMException::DOMException(DOMException const & the_other): ::css::uno::Exception(the_other), Code(the_other.Code) {}

DOMException::~DOMException() {}

DOMException & DOMException::operator =(DOMException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    Code = the_other.Code;
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace dom {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::dom::DOMException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_com_sun_star_xml_dom_DOMExceptionType = ::cppu::UnoType< ::css::xml::dom::DOMExceptionType >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_xml_dom_DOMExceptionType.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.xml.dom.DOMException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::dom::DOMException const *) {
    return ::cppu::UnoType< ::css::xml::dom::DOMException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_DOM_DOMEXCEPTION_HPP
