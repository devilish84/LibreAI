#ifndef INCLUDED_COM_SUN_STAR_TEXT_INVALIDTEXTCONTENTEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_INVALIDTEXTCONTENTEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/text/InvalidTextContentException.hdl"

#include "com/sun/star/text/XTextContent.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace text {

inline InvalidTextContentException::InvalidTextContentException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , TextContent()
{ }

inline InvalidTextContentException::InvalidTextContentException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Reference< ::css::text::XTextContent >& TextContent_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , TextContent(TextContent_)
{ }

#if !defined LIBO_INTERNAL_ONLY
InvalidTextContentException::InvalidTextContentException(InvalidTextContentException const & the_other): ::css::uno::Exception(the_other), TextContent(the_other.TextContent) {}

InvalidTextContentException::~InvalidTextContentException() {}

InvalidTextContentException & InvalidTextContentException::operator =(InvalidTextContentException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    TextContent = the_other.TextContent;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::InvalidTextContentException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_com_sun_star_text_XTextContent = ::cppu::UnoType< ::css::uno::Reference< ::css::text::XTextContent > >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_text_XTextContent.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.text.InvalidTextContentException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::text::InvalidTextContentException const *) {
    return ::cppu::UnoType< ::css::text::InvalidTextContentException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_INVALIDTEXTCONTENTEXCEPTION_HPP
