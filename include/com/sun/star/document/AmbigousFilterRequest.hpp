#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_AMBIGOUSFILTERREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_AMBIGOUSFILTERREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/document/AmbigousFilterRequest.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace document {

inline AmbigousFilterRequest::AmbigousFilterRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , URL()
    , SelectedFilter()
    , DetectedFilter()
{ }

inline AmbigousFilterRequest::AmbigousFilterRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& URL_, const ::rtl::OUString& SelectedFilter_, const ::rtl::OUString& DetectedFilter_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , URL(URL_)
    , SelectedFilter(SelectedFilter_)
    , DetectedFilter(DetectedFilter_)
{ }

#if !defined LIBO_INTERNAL_ONLY
AmbigousFilterRequest::AmbigousFilterRequest(AmbigousFilterRequest const & the_other): ::css::uno::Exception(the_other), URL(the_other.URL), SelectedFilter(the_other.SelectedFilter), DetectedFilter(the_other.DetectedFilter) {}

AmbigousFilterRequest::~AmbigousFilterRequest() {}

AmbigousFilterRequest & AmbigousFilterRequest::operator =(AmbigousFilterRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    URL = the_other.URL;
    SelectedFilter = the_other.SelectedFilter;
    DetectedFilter = the_other.DetectedFilter;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::AmbigousFilterRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_string = ::cppu::UnoType< ::rtl::OUString >::get();
        aMemberRefs[0] = rMemberType_string.getTypeLibType();
        aMemberRefs[1] = rMemberType_string.getTypeLibType();
        aMemberRefs[2] = rMemberType_string.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.document.AmbigousFilterRequest", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::document::AmbigousFilterRequest const *) {
    return ::cppu::UnoType< ::css::document::AmbigousFilterRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_AMBIGOUSFILTERREQUEST_HPP
