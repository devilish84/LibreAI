#ifndef INCLUDED_COM_SUN_STAR_TASK_DOCUMENTMSPASSWORDREQUEST2_HPP
#define INCLUDED_COM_SUN_STAR_TASK_DOCUMENTMSPASSWORDREQUEST2_HPP

#include "sal/config.h"

#include "com/sun/star/task/DocumentMSPasswordRequest2.hdl"

#include "com/sun/star/task/DocumentMSPasswordRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace task {

inline DocumentMSPasswordRequest2::DocumentMSPasswordRequest2(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::DocumentMSPasswordRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , IsRequestPasswordToModify(false)
{ }

inline DocumentMSPasswordRequest2::DocumentMSPasswordRequest2(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::css::task::PasswordRequestMode& Mode_, const ::rtl::OUString& Name_, const ::sal_Bool& IsRequestPasswordToModify_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::DocumentMSPasswordRequest(Message_, Context_, Classification_, Mode_, Name_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , IsRequestPasswordToModify(IsRequestPasswordToModify_)
{ }

#if !defined LIBO_INTERNAL_ONLY
DocumentMSPasswordRequest2::DocumentMSPasswordRequest2(DocumentMSPasswordRequest2 const & the_other): ::css::task::DocumentMSPasswordRequest(the_other), IsRequestPasswordToModify(the_other.IsRequestPasswordToModify) {}

DocumentMSPasswordRequest2::~DocumentMSPasswordRequest2() {}

DocumentMSPasswordRequest2 & DocumentMSPasswordRequest2::operator =(DocumentMSPasswordRequest2 const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::DocumentMSPasswordRequest::operator =(the_other);
    IsRequestPasswordToModify = the_other.IsRequestPasswordToModify;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::DocumentMSPasswordRequest2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::DocumentMSPasswordRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_boolean = ::cppu::UnoType< ::sal_Bool >::get();
        aMemberRefs[0] = rMemberType_boolean.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.task.DocumentMSPasswordRequest2", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::task::DocumentMSPasswordRequest2 const *) {
    return ::cppu::UnoType< ::css::task::DocumentMSPasswordRequest2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_DOCUMENTMSPASSWORDREQUEST2_HPP
