#ifndef INCLUDED_COM_SUN_STAR_TASK_MASTERPASSWORDREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_TASK_MASTERPASSWORDREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/task/MasterPasswordRequest.hdl"

#include "com/sun/star/task/PasswordRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace task {

inline MasterPasswordRequest::MasterPasswordRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::PasswordRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline MasterPasswordRequest::MasterPasswordRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::css::task::PasswordRequestMode& Mode_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::PasswordRequest(Message_, Context_, Classification_, Mode_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
MasterPasswordRequest::MasterPasswordRequest(MasterPasswordRequest const & the_other): ::css::task::PasswordRequest(the_other) {}

MasterPasswordRequest::~MasterPasswordRequest() {}

MasterPasswordRequest & MasterPasswordRequest::operator =(MasterPasswordRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::PasswordRequest::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::MasterPasswordRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::PasswordRequest >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.task.MasterPasswordRequest", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::task::MasterPasswordRequest const *) {
    return ::cppu::UnoType< ::css::task::MasterPasswordRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_MASTERPASSWORDREQUEST_HPP
