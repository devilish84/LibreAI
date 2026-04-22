#ifndef INCLUDED_COM_SUN_STAR_TASK_CLASSIFIEDINTERACTIONREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_TASK_CLASSIFIEDINTERACTIONREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/task/ClassifiedInteractionRequest.hdl"

#include "com/sun/star/task/InteractionClassification.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace task {

inline ClassifiedInteractionRequest::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Classification(::css::task::InteractionClassification_ERROR)
{ }

inline ClassifiedInteractionRequest::ClassifiedInteractionRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Classification(Classification_)
{ }

#if !defined LIBO_INTERNAL_ONLY
ClassifiedInteractionRequest::ClassifiedInteractionRequest(ClassifiedInteractionRequest const & the_other): ::css::uno::Exception(the_other), Classification(the_other.Classification) {}

ClassifiedInteractionRequest::~ClassifiedInteractionRequest() {}

ClassifiedInteractionRequest & ClassifiedInteractionRequest::operator =(ClassifiedInteractionRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    Classification = the_other.Classification;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::ClassifiedInteractionRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_com_sun_star_task_InteractionClassification = ::cppu::UnoType< ::css::task::InteractionClassification >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_task_InteractionClassification.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.task.ClassifiedInteractionRequest", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::task::ClassifiedInteractionRequest const *) {
    return ::cppu::UnoType< ::css::task::ClassifiedInteractionRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_CLASSIFIEDINTERACTIONREQUEST_HPP
