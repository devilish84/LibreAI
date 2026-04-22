#ifndef INCLUDED_COM_SUN_STAR_DRAWING_GRAPHICFILTERREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_GRAPHICFILTERREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/GraphicFilterRequest.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline GraphicFilterRequest::GraphicFilterRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ErrCode(0)
{ }

inline GraphicFilterRequest::GraphicFilterRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int32& ErrCode_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ErrCode(ErrCode_)
{ }

#if !defined LIBO_INTERNAL_ONLY
GraphicFilterRequest::GraphicFilterRequest(GraphicFilterRequest const & the_other): ::css::uno::Exception(the_other), ErrCode(the_other.ErrCode) {}

GraphicFilterRequest::~GraphicFilterRequest() {}

GraphicFilterRequest & GraphicFilterRequest::operator =(GraphicFilterRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    ErrCode = the_other.ErrCode;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::GraphicFilterRequest const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[0] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.drawing.GraphicFilterRequest", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::GraphicFilterRequest const *) {
    return ::cppu::UnoType< ::css::drawing::GraphicFilterRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_GRAPHICFILTERREQUEST_HPP
