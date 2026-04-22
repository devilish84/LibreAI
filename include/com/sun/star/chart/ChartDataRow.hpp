#ifndef INCLUDED_COM_SUN_STAR_CHART_CHARTDATAROW_HPP
#define INCLUDED_COM_SUN_STAR_CHART_CHARTDATAROW_HPP

#include "sal/config.h"

#include "com/sun/star/chart/ChartDataRow.hdl"

#include "com/sun/star/chart/ChartDataValue.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart {

inline ChartDataRow::ChartDataRow()
    : Name()
    , Points()
{
}

inline ChartDataRow::ChartDataRow(const ::rtl::OUString& Name_, const ::css::uno::Sequence< ::css::uno::Sequence< ::css::chart::ChartDataValue > >& Points_)
    : Name(Name_)
    , Points(Points_)
{
}


inline bool operator==(const ChartDataRow& the_lhs, const ChartDataRow& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Points == the_rhs.Points;
}

inline bool operator!=(const ChartDataRow& the_lhs, const ChartDataRow& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::ChartDataRow const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::cppu::UnoSequenceType< ::css::chart::ChartDataValue > > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart.ChartDataRow", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart::ChartDataRow const *) {
    return ::cppu::UnoType< ::css::chart::ChartDataRow >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_CHARTDATAROW_HPP
