#ifndef INCLUDED_COM_SUN_STAR_XML_CRYPTO_SECURITYOPERATIONSTATUS_HPP
#define INCLUDED_COM_SUN_STAR_XML_CRYPTO_SECURITYOPERATIONSTATUS_HPP

#include "sal/config.h"

#include "com/sun/star/xml/crypto/SecurityOperationStatus.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xml { namespace crypto {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::crypto::SecurityOperationStatus const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.xml.crypto.SecurityOperationStatus",
                                       ::css::xml::crypto::SecurityOperationStatus_UNKNOWN );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::crypto::SecurityOperationStatus const *) {
    return ::cppu::UnoType< ::css::xml::crypto::SecurityOperationStatus >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_CRYPTO_SECURITYOPERATIONSTATUS_HPP
