#ifndef INCLUDED_COM_SUN_STAR_TABLE_TABLEBORDER2_HPP
#define INCLUDED_COM_SUN_STAR_TABLE_TABLEBORDER2_HPP

#include "sal/config.h"

#include "com/sun/star/table/TableBorder2.hdl"

#include "com/sun/star/table/BorderLine2.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace table {

inline TableBorder2::TableBorder2()
    : TopLine()
    , IsTopLineValid(false)
    , BottomLine()
    , IsBottomLineValid(false)
    , LeftLine()
    , IsLeftLineValid(false)
    , RightLine()
    , IsRightLineValid(false)
    , HorizontalLine()
    , IsHorizontalLineValid(false)
    , VerticalLine()
    , IsVerticalLineValid(false)
    , Distance(0)
    , IsDistanceValid(false)
{
}

inline TableBorder2::TableBorder2(const ::css::table::BorderLine2& TopLine_, const ::sal_Bool& IsTopLineValid_, const ::css::table::BorderLine2& BottomLine_, const ::sal_Bool& IsBottomLineValid_, const ::css::table::BorderLine2& LeftLine_, const ::sal_Bool& IsLeftLineValid_, const ::css::table::BorderLine2& RightLine_, const ::sal_Bool& IsRightLineValid_, const ::css::table::BorderLine2& HorizontalLine_, const ::sal_Bool& IsHorizontalLineValid_, const ::css::table::BorderLine2& VerticalLine_, const ::sal_Bool& IsVerticalLineValid_, const ::sal_Int16& Distance_, const ::sal_Bool& IsDistanceValid_)
    : TopLine(TopLine_)
    , IsTopLineValid(IsTopLineValid_)
    , BottomLine(BottomLine_)
    , IsBottomLineValid(IsBottomLineValid_)
    , LeftLine(LeftLine_)
    , IsLeftLineValid(IsLeftLineValid_)
    , RightLine(RightLine_)
    , IsRightLineValid(IsRightLineValid_)
    , HorizontalLine(HorizontalLine_)
    , IsHorizontalLineValid(IsHorizontalLineValid_)
    , VerticalLine(VerticalLine_)
    , IsVerticalLineValid(IsVerticalLineValid_)
    , Distance(Distance_)
    , IsDistanceValid(IsDistanceValid_)
{
}


inline bool operator==(const TableBorder2& the_lhs, const TableBorder2& the_rhs)
{
    return the_lhs.TopLine == the_rhs.TopLine
        && the_lhs.IsTopLineValid == the_rhs.IsTopLineValid
        && the_lhs.BottomLine == the_rhs.BottomLine
        && the_lhs.IsBottomLineValid == the_rhs.IsBottomLineValid
        && the_lhs.LeftLine == the_rhs.LeftLine
        && the_lhs.IsLeftLineValid == the_rhs.IsLeftLineValid
        && the_lhs.RightLine == the_rhs.RightLine
        && the_lhs.IsRightLineValid == the_rhs.IsRightLineValid
        && the_lhs.HorizontalLine == the_rhs.HorizontalLine
        && the_lhs.IsHorizontalLineValid == the_rhs.IsHorizontalLineValid
        && the_lhs.VerticalLine == the_rhs.VerticalLine
        && the_lhs.IsVerticalLineValid == the_rhs.IsVerticalLineValid
        && the_lhs.Distance == the_rhs.Distance
        && the_lhs.IsDistanceValid == the_rhs.IsDistanceValid;
}

inline bool operator!=(const TableBorder2& the_lhs, const TableBorder2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace table {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::table::TableBorder2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::table::BorderLine2 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::table::BorderLine2 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::table::BorderLine2 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::table::BorderLine2 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::table::BorderLine2 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::table::BorderLine2 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.table.TableBorder2", 0, 14, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::table::TableBorder2 const *) {
    return ::cppu::UnoType< ::css::table::TableBorder2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TABLE_TABLEBORDER2_HPP
