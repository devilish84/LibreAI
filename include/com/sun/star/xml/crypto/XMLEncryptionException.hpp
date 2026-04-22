#ifndef INCLUDED_COM_SUN_STAR_XML_CRYPTO_XMLENCRYPTIONEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_XML_CRYPTO_XMLENCRYPTIONEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/xml/crypto/XMLEncryptionException.hdl"

#include "com/sun/star/security/EncryptionException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace crypto {

inline XMLEncryptionException::XMLEncryptionException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::security::EncryptionException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline XMLEncryptionException::XMLEncryptionException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::security::EncryptionException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
XMLEncryptionException::XMLEncryptionException(XMLEncryptionException const & the_other): ::css::security::EncryptionException(the_other) {}

XMLEncryptionException::~XMLEncryptionException() {}

XMLEncryptionException & XMLEncryptionException::operator =(XMLEncryptionException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::security::EncryptionException::operator =(the_other);
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace crypto {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::crypto::XMLEncryptionException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::security::EncryptionException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.xml.crypto.XMLEncryptionException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::crypto::XMLEncryptionException const *) {
    return ::cppu::UnoType< ::css::xml::crypto::XMLEncryptionException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_CRYPTO_XMLENCRYPTIONEXCEPTION_HPP
