#ifndef INCLUDED_COM_SUN_STAR_XML_CRYPTO_XMLSIGNATUREEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_XML_CRYPTO_XMLSIGNATUREEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/xml/crypto/XMLSignatureException.hdl"

#include "com/sun/star/security/SignatureException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace crypto {

inline XMLSignatureException::XMLSignatureException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::security::SignatureException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline XMLSignatureException::XMLSignatureException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::security::SignatureException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
XMLSignatureException::XMLSignatureException(XMLSignatureException const & the_other): ::css::security::SignatureException(the_other) {}

XMLSignatureException::~XMLSignatureException() {}

XMLSignatureException & XMLSignatureException::operator =(XMLSignatureException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::security::SignatureException::operator =(the_other);
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace crypto {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::crypto::XMLSignatureException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::security::SignatureException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.xml.crypto.XMLSignatureException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::crypto::XMLSignatureException const *) {
    return ::cppu::UnoType< ::css::xml::crypto::XMLSignatureException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_CRYPTO_XMLSIGNATUREEXCEPTION_HPP
