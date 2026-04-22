#ifndef INCLUDED_COM_SUN_STAR_TEXT_TEXTPOSITION_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_TEXTPOSITION_HPP

#include "sal/config.h"

#include "com/sun/star/text/TextPosition.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace text {

inline TextPosition::TextPosition()
    : Paragraph(0)
    , PositionInParagraph(0)
{
}

inline TextPosition::TextPosition(const ::sal_Int32& Paragraph_, const ::sal_Int32& PositionInParagraph_)
    : Paragraph(Paragraph_)
    , PositionInParagraph(PositionInParagraph_)
{
}


inline bool operator==(const TextPosition& the_lhs, const TextPosition& the_rhs)
{
    return the_lhs.Paragraph == the_rhs.Paragraph
        && the_lhs.PositionInParagraph == the_rhs.PositionInParagraph;
}

inline bool operator!=(const TextPosition& the_lhs, const TextPosition& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::TextPosition const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.text.TextPosition", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::text::TextPosition const *) {
    return ::cppu::UnoType< ::css::text::TextPosition >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_TEXTPOSITION_HPP
