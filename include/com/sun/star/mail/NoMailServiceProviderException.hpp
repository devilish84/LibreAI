#ifndef INCLUDED_COM_SUN_STAR_MAIL_NOMAILSERVICEPROVIDEREXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_MAIL_NOMAILSERVICEPROVIDEREXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/mail/NoMailServiceProviderException.hdl"

#include "com/sun/star/mail/MailException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace mail {

inline NoMailServiceProviderException::NoMailServiceProviderException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::mail::MailException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline NoMailServiceProviderException::NoMailServiceProviderException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::mail::MailException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
NoMailServiceProviderException::NoMailServiceProviderException(NoMailServiceProviderException const & the_other): ::css::mail::MailException(the_other) {}

NoMailServiceProviderException::~NoMailServiceProviderException() {}

NoMailServiceProviderException & NoMailServiceProviderException::operator =(NoMailServiceProviderException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::mail::MailException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace mail {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::mail::NoMailServiceProviderException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::mail::MailException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.mail.NoMailServiceProviderException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::mail::NoMailServiceProviderException const *) {
    return ::cppu::UnoType< ::css::mail::NoMailServiceProviderException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_MAIL_NOMAILSERVICEPROVIDEREXCEPTION_HPP
