#ifndef INCLUDED_COM_SUN_STAR_TASK_PASSWORDREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_TASK_PASSWORDREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/task/PasswordRequest.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/task/PasswordRequestMode.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace task {

inline PasswordRequest::PasswordRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Mode(::css::task::PasswordRequestMode_PASSWORD_CREATE)
{ }

inline PasswordRequest::PasswordRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::css::task::PasswordRequestMode& Mode_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Mode(Mode_)
{ }

#if !defined LIBO_INTERNAL_ONLY
PasswordRequest::PasswordRequest(PasswordRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), Mode(the_other.Mode) {}

PasswordRequest::~PasswordRequest() {}

PasswordRequest & PasswordRequest::operator =(PasswordRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    Mode = the_other.Mode;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::PasswordRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_com_sun_star_task_PasswordRequestMode = ::cppu::UnoType< ::css::task::PasswordRequestMode >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_task_PasswordRequestMode.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.task.PasswordRequest", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::task::PasswordRequest const *) {
    return ::cppu::UnoType< ::css::task::PasswordRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_PASSWORDREQUEST_HPP
