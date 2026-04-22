#ifndef INCLUDED_COM_SUN_STAR_TASK_UNSUPPORTEDOVERWRITEREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_TASK_UNSUPPORTEDOVERWRITEREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/task/UnsupportedOverwriteRequest.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace task {

inline UnsupportedOverwriteRequest::UnsupportedOverwriteRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Name()
{ }

inline UnsupportedOverwriteRequest::UnsupportedOverwriteRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& Name_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Name(Name_)
{ }

#if !defined LIBO_INTERNAL_ONLY
UnsupportedOverwriteRequest::UnsupportedOverwriteRequest(UnsupportedOverwriteRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), Name(the_other.Name) {}

UnsupportedOverwriteRequest::~UnsupportedOverwriteRequest() {}

UnsupportedOverwriteRequest & UnsupportedOverwriteRequest::operator =(UnsupportedOverwriteRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    Name = the_other.Name;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::UnsupportedOverwriteRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::task::ClassifiedInteractionRequest >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.task.UnsupportedOverwriteRequest", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::task::UnsupportedOverwriteRequest const *) {
    return ::cppu::UnoType< ::css::task::UnsupportedOverwriteRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_UNSUPPORTEDOVERWRITEREQUEST_HPP
