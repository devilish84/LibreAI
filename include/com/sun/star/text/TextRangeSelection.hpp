#ifndef INCLUDED_COM_SUN_STAR_TEXT_TEXTRANGESELECTION_HPP
#define INCLUDED_COM_SUN_STAR_TEXT_TEXTRANGESELECTION_HPP

#include "sal/config.h"

#include "com/sun/star/text/TextRangeSelection.hdl"

#include "com/sun/star/text/TextPosition.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace text {

inline TextRangeSelection::TextRangeSelection()
    : Start()
    , End()
{
}

inline TextRangeSelection::TextRangeSelection(const ::css::text::TextPosition& Start_, const ::css::text::TextPosition& End_)
    : Start(Start_)
    , End(End_)
{
}


inline bool operator==(const TextRangeSelection& the_lhs, const TextRangeSelection& the_rhs)
{
    return the_lhs.Start == the_rhs.Start
        && the_lhs.End == the_rhs.End;
}

inline bool operator!=(const TextRangeSelection& the_lhs, const TextRangeSelection& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace text {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::text::TextRangeSelection const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::text::TextPosition >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::text::TextPosition >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.text.TextRangeSelection", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::text::TextRangeSelection const *) {
    return ::cppu::UnoType< ::css::text::TextRangeSelection >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TEXT_TEXTRANGESELECTION_HPP
