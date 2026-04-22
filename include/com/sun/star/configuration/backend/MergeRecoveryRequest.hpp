#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_MERGERECOVERYREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_MERGERECOVERYREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/backend/MergeRecoveryRequest.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline MergeRecoveryRequest::MergeRecoveryRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ErrorDetails()
    , ErrorLayerId()
    , IsRemovalRequest(false)
{ }

inline MergeRecoveryRequest::MergeRecoveryRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& ErrorDetails_, const ::rtl::OUString& ErrorLayerId_, const ::sal_Bool& IsRemovalRequest_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ErrorDetails(ErrorDetails_)
    , ErrorLayerId(ErrorLayerId_)
    , IsRemovalRequest(IsRemovalRequest_)
{ }

#if !defined LIBO_INTERNAL_ONLY
MergeRecoveryRequest::MergeRecoveryRequest(MergeRecoveryRequest const & the_other): ::css::uno::Exception(the_other), ErrorDetails(the_other.ErrorDetails), ErrorLayerId(the_other.ErrorLayerId), IsRemovalRequest(the_other.IsRemovalRequest) {}

MergeRecoveryRequest::~MergeRecoveryRequest() {}

MergeRecoveryRequest & MergeRecoveryRequest::operator =(MergeRecoveryRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    ErrorDetails = the_other.ErrorDetails;
    ErrorLayerId = the_other.ErrorLayerId;
    IsRemovalRequest = the_other.IsRemovalRequest;
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::backend::MergeRecoveryRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_any = ::cppu::UnoType< ::css::uno::Any >::get();
        aMemberRefs[0] = rMemberType_any.getTypeLibType();
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();
        const ::css::uno::Type& rMemberType_boolean = ::cppu::UnoType< ::sal_Bool >::get();
        aMemberRefs[2] = rMemberType_boolean.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.configuration.backend.MergeRecoveryRequest", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::backend::MergeRecoveryRequest const *) {
    return ::cppu::UnoType< ::css::configuration::backend::MergeRecoveryRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_MERGERECOVERYREQUEST_HPP
