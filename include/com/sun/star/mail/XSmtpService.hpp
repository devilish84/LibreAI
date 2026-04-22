#ifndef INCLUDED_COM_SUN_STAR_MAIL_XSMTPSERVICE_HPP
#define INCLUDED_COM_SUN_STAR_MAIL_XSMTPSERVICE_HPP

#include "sal/config.h"

#include "com/sun/star/mail/XSmtpService.hdl"

#include "com/sun/star/mail/XMailMessage.hpp"
#include "com/sun/star/mail/XMailService.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace mail {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::mail::XSmtpService const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::mail::XMailService > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.mail.XSmtpService", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::mail::XSmtpService > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::mail::XSmtpService > >::get();
}

::css::uno::Type const & ::css::mail::XSmtpService::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::mail::XSmtpService >::get();
}

#endif // INCLUDED_COM_SUN_STAR_MAIL_XSMTPSERVICE_HPP
