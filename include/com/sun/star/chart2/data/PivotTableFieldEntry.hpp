#ifndef INCLUDED_COM_SUN_STAR_CHART2_DATA_PIVOTTABLEFIELDENTRY_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_DATA_PIVOTTABLEFIELDENTRY_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/data/PivotTableFieldEntry.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 { namespace data {

inline PivotTableFieldEntry::PivotTableFieldEntry()
    : Name()
    , DimensionIndex(0)
    , DimensionPositionIndex(0)
    , HasHiddenMembers(false)
{
}

inline PivotTableFieldEntry::PivotTableFieldEntry(const ::rtl::OUString& Name_, const ::sal_Int32& DimensionIndex_, const ::sal_Int32& DimensionPositionIndex_, const ::sal_Bool& HasHiddenMembers_)
    : Name(Name_)
    , DimensionIndex(DimensionIndex_)
    , DimensionPositionIndex(DimensionPositionIndex_)
    , HasHiddenMembers(HasHiddenMembers_)
{
}


inline bool operator==(const PivotTableFieldEntry& the_lhs, const PivotTableFieldEntry& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.DimensionIndex == the_rhs.DimensionIndex
        && the_lhs.DimensionPositionIndex == the_rhs.DimensionPositionIndex
        && the_lhs.HasHiddenMembers == the_rhs.HasHiddenMembers;
}

inline bool operator!=(const PivotTableFieldEntry& the_lhs, const PivotTableFieldEntry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace chart2 { namespace data {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::data::PivotTableFieldEntry const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.data.PivotTableFieldEntry", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::data::PivotTableFieldEntry const *) {
    return ::cppu::UnoType< ::css::chart2::data::PivotTableFieldEntry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_DATA_PIVOTTABLEFIELDENTRY_HPP
