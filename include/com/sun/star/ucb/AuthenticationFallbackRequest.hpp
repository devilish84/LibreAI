#ifndef INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONFALLBACKREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONFALLBACKREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/AuthenticationFallbackRequest.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline AuthenticationFallbackRequest::AuthenticationFallbackRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , instructions()
    , url()
{ }

inline AuthenticationFallbackRequest::AuthenticationFallbackRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& instructions_, const ::rtl::OUString& url_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , instructions(instructions_)
    , url(url_)
{ }

#if !defined LIBO_INTERNAL_ONLY
AuthenticationFallbackRequest::AuthenticationFallbackRequest(AuthenticationFallbackRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), instructions(the_other.instructions), url(the_other.url) {}

AuthenticationFallbackRequest::~AuthenticationFallbackRequest() {}

AuthenticationFallbackRequest & AuthenticationFallbackRequest::operator =(AuthenticationFallbackRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    instructions = the_other.instructions;
    url = the_other.url;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::AuthenticationFallbackRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[2];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.ucb.AuthenticationFallbackRequest", rBaseType.getTypeLibType(), 2,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::AuthenticationFallbackRequest const *) {
    return ::cppu::UnoType< ::css::ucb::AuthenticationFallbackRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONFALLBACKREQUEST_HPP
