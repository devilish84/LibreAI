#ifndef INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/AuthenticationRequest.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline AuthenticationRequest::AuthenticationRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ServerName()
    , Diagnostic()
    , HasRealm(false)
    , Realm()
    , HasUserName(false)
    , UserName()
    , HasPassword(false)
    , Password()
    , HasAccount(false)
    , Account()
{ }

inline AuthenticationRequest::AuthenticationRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& ServerName_, const ::rtl::OUString& Diagnostic_, const ::sal_Bool& HasRealm_, const ::rtl::OUString& Realm_, const ::sal_Bool& HasUserName_, const ::rtl::OUString& UserName_, const ::sal_Bool& HasPassword_, const ::rtl::OUString& Password_, const ::sal_Bool& HasAccount_, const ::rtl::OUString& Account_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ServerName(ServerName_)
    , Diagnostic(Diagnostic_)
    , HasRealm(HasRealm_)
    , Realm(Realm_)
    , HasUserName(HasUserName_)
    , UserName(UserName_)
    , HasPassword(HasPassword_)
    , Password(Password_)
    , HasAccount(HasAccount_)
    , Account(Account_)
{ }

#if !defined LIBO_INTERNAL_ONLY
AuthenticationRequest::AuthenticationRequest(AuthenticationRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), ServerName(the_other.ServerName), Diagnostic(the_other.Diagnostic), HasRealm(the_other.HasRealm), Realm(the_other.Realm), HasUserName(the_other.HasUserName), UserName(the_other.UserName), HasPassword(the_other.HasPassword), Password(the_other.Password), HasAccount(the_other.HasAccount), Account(the_other.Account) {}

AuthenticationRequest::~AuthenticationRequest() {}

AuthenticationRequest & AuthenticationRequest::operator =(AuthenticationRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    ServerName = the_other.ServerName;
    Diagnostic = the_other.Diagnostic;
    HasRealm = the_other.HasRealm;
    Realm = the_other.Realm;
    HasUserName = the_other.HasUserName;
    UserName = the_other.UserName;
    HasPassword = the_other.HasPassword;
    Password = the_other.Password;
    HasAccount = the_other.HasAccount;
    Account = the_other.Account;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::AuthenticationRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[10];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();
        const ::css::uno::Type& rMemberType_boolean = ::cppu::UnoType< ::sal_Bool >::get();
        aMemberRefs[2] = rMemberType_boolean.getTypeLibType();
        aMemberRefs[3] = rMemberType_string.getTypeLibType();
        aMemberRefs[4] = rMemberType_boolean.getTypeLibType();
        aMemberRefs[5] = rMemberType_string.getTypeLibType();
        aMemberRefs[6] = rMemberType_boolean.getTypeLibType();
        aMemberRefs[7] = rMemberType_string.getTypeLibType();
        aMemberRefs[8] = rMemberType_boolean.getTypeLibType();
        aMemberRefs[9] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.AuthenticationRequest", rBaseType.getTypeLibType(), 10,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::AuthenticationRequest const *) {
    return ::cppu::UnoType< ::css::ucb::AuthenticationRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONREQUEST_HPP
