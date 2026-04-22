#ifndef INCLUDED_COM_SUN_STAR_CHART2_DATA_HIGHLIGHTEDRANGE_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_DATA_HIGHLIGHTEDRANGE_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/data/HighlightedRange.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 { namespace data {

inline HighlightedRange::HighlightedRange()
    : RangeRepresentation()
    , Index(0)
    , PreferredColor(0)
    , AllowMerginigWithOtherRanges(false)
{
}

inline HighlightedRange::HighlightedRange(const ::rtl::OUString& RangeRepresentation_, const ::sal_Int32& Index_, const ::sal_Int32& PreferredColor_, const ::sal_Bool& AllowMerginigWithOtherRanges_)
    : RangeRepresentation(RangeRepresentation_)
    , Index(Index_)
    , PreferredColor(PreferredColor_)
    , AllowMerginigWithOtherRanges(AllowMerginigWithOtherRanges_)
{
}


inline bool operator==(const HighlightedRange& the_lhs, const HighlightedRange& the_rhs)
{
    return the_lhs.RangeRepresentation == the_rhs.RangeRepresentation
        && the_lhs.Index == the_rhs.Index
        && the_lhs.PreferredColor == the_rhs.PreferredColor
        && the_lhs.AllowMerginigWithOtherRanges == the_rhs.AllowMerginigWithOtherRanges;
}

inline bool operator!=(const HighlightedRange& the_lhs, const HighlightedRange& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace chart2 { namespace data {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::data::HighlightedRange const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.data.HighlightedRange", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::data::HighlightedRange const *) {
    return ::cppu::UnoType< ::css::chart2::data::HighlightedRange >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_DATA_HIGHLIGHTEDRANGE_HPP
