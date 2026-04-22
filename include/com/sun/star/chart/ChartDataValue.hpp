#ifndef INCLUDED_COM_SUN_STAR_CHART_CHARTDATAVALUE_HPP
#define INCLUDED_COM_SUN_STAR_CHART_CHARTDATAVALUE_HPP

#include "sal/config.h"

#include "com/sun/star/chart/ChartDataValue.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart {

inline ChartDataValue::ChartDataValue()
    : Value(0)
    , HighError(0)
    , LowError(0)
{
}

inline ChartDataValue::ChartDataValue(const double& Value_, const double& HighError_, const double& LowError_)
    : Value(Value_)
    , HighError(HighError_)
    , LowError(LowError_)
{
}


inline bool operator==(const ChartDataValue& the_lhs, const ChartDataValue& the_rhs)
{
    return the_lhs.Value == the_rhs.Value
        && the_lhs.HighError == the_rhs.HighError
        && the_lhs.LowError == the_rhs.LowError;
}

inline bool operator!=(const ChartDataValue& the_lhs, const ChartDataValue& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::ChartDataValue const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart.ChartDataValue", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart::ChartDataValue const *) {
    return ::cppu::UnoType< ::css::chart::ChartDataValue >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_CHARTDATAVALUE_HPP
