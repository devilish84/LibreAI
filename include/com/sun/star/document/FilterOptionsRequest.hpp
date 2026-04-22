#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_FILTEROPTIONSREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_FILTEROPTIONSREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/document/FilterOptionsRequest.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/frame/XModel.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace document {

inline FilterOptionsRequest::FilterOptionsRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , rModel()
    , rProperties()
{ }

inline FilterOptionsRequest::FilterOptionsRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Reference< ::css::frame::XModel >& rModel_, const ::css::uno::Sequence< ::css::beans::PropertyValue >& rProperties_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , rModel(rModel_)
    , rProperties(rProperties_)
{ }

#if !defined LIBO_INTERNAL_ONLY
FilterOptionsRequest::FilterOptionsRequest(FilterOptionsRequest const & the_other): ::css::uno::Exception(the_other), rModel(the_other.rModel), rProperties(the_other.rProperties) {}

FilterOptionsRequest::~FilterOptionsRequest() {}

FilterOptionsRequest & FilterOptionsRequest::operator =(FilterOptionsRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    rModel = the_other.rModel;
    rProperties = the_other.rProperties;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::FilterOptionsRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[2];
        const ::css::uno::Type& rMemberType_com_sun_star_frame_XModel = ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XModel > >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_frame_XModel.getTypeLibType();
        const ::css::uno::Type& rMemberType_seq_com_sun_star_beans_PropertyValue = ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::PropertyValue > >::get();
        aMemberRefs[1] = rMemberType_seq_com_sun_star_beans_PropertyValue.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.document.FilterOptionsRequest", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 2,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::document::FilterOptionsRequest const *) {
    return ::cppu::UnoType< ::css::document::FilterOptionsRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_FILTEROPTIONSREQUEST_HPP
