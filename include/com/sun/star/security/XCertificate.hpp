#ifndef INCLUDED_COM_SUN_STAR_SECURITY_XCERTIFICATE_HPP
#define INCLUDED_COM_SUN_STAR_SECURITY_XCERTIFICATE_HPP

#include "sal/config.h"

#include "com/sun/star/security/XCertificate.hdl"

#include "com/sun/star/security/CertificateKind.hpp"
#include "com/sun/star/security/XCertificateExtension.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace security {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::security::XCertificate const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.security.XCertificate", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::security::XCertificate > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::security::XCertificate > >::get();
}

::css::uno::Type const & ::css::security::XCertificate::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::security::XCertificate >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SECURITY_XCERTIFICATE_HPP
