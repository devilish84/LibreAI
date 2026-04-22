#ifndef INCLUDED_COM_SUN_STAR_SECURITY_XSANEXTENSION_HPP
#define INCLUDED_COM_SUN_STAR_SECURITY_XSANEXTENSION_HPP

#include "sal/config.h"

#include "com/sun/star/security/XSanExtension.hdl"

#include "com/sun/star/security/CertAltNameEntry.hpp"
#include "com/sun/star/security/XCertificateExtension.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace security {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::security::XSanExtension const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::security::XCertificateExtension > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.security.XSanExtension", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::security::XSanExtension > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::security::XSanExtension > >::get();
}

::css::uno::Type const & ::css::security::XSanExtension::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::security::XSanExtension >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SECURITY_XSANEXTENSION_HPP
