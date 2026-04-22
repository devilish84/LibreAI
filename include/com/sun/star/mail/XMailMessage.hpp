#ifndef INCLUDED_COM_SUN_STAR_MAIL_XMAILMESSAGE_HPP
#define INCLUDED_COM_SUN_STAR_MAIL_XMAILMESSAGE_HPP

#include "sal/config.h"

#include "com/sun/star/mail/XMailMessage.hdl"

#include "com/sun/star/datatransfer/XTransferable.hpp"
#include "com/sun/star/mail/MailAttachment.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace mail {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::mail::XMailMessage const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.mail.XMailMessage", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::mail::XMailMessage > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::mail::XMailMessage > >::get();
}

::css::uno::Type const & ::css::mail::XMailMessage::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::mail::XMailMessage >::get();
}

#endif // INCLUDED_COM_SUN_STAR_MAIL_XMAILMESSAGE_HPP
