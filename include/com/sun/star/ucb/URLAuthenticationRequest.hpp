#ifndef INCLUDED_COM_SUN_STAR_UCB_URLAUTHENTICATIONREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_URLAUTHENTICATIONREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/URLAuthenticationRequest.hdl"

#include "com/sun/star/ucb/AuthenticationRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline URLAuthenticationRequest::URLAuthenticationRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::ucb::AuthenticationRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , URL()
{ }

inline URLAuthenticationRequest::URLAuthenticationRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& ServerName_, const ::rtl::OUString& Diagnostic_, const ::sal_Bool& HasRealm_, const ::rtl::OUString& Realm_, const ::sal_Bool& HasUserName_, const ::rtl::OUString& UserName_, const ::sal_Bool& HasPassword_, const ::rtl::OUString& Password_, const ::sal_Bool& HasAccount_, const ::rtl::OUString& Account_, const ::rtl::OUString& URL_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::ucb::AuthenticationRequest(Message_, Context_, Classification_, ServerName_, Diagnostic_, HasRealm_, Realm_, HasUserName_, UserName_, HasPassword_, Password_, HasAccount_, Account_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , URL(URL_)
{ }

#if !defined LIBO_INTERNAL_ONLY
URLAuthenticationRequest::URLAuthenticationRequest(URLAuthenticationRequest const & the_other): ::css::ucb::AuthenticationRequest(the_other), URL(the_other.URL) {}

URLAuthenticationRequest::~URLAuthenticationRequest() {}

URLAuthenticationRequest & URLAuthenticationRequest::operator =(URLAuthenticationRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::AuthenticationRequest::operator =(the_other);
    URL = the_other.URL;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::URLAuthenticationRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::ucb::AuthenticationRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.URLAuthenticationRequest", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::URLAuthenticationRequest const *) {
    return ::cppu::UnoType< ::css::ucb::URLAuthenticationRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_URLAUTHENTICATIONREQUEST_HPP
