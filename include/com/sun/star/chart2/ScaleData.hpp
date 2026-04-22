#ifndef INCLUDED_COM_SUN_STAR_CHART2_SCALEDATA_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_SCALEDATA_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/ScaleData.hdl"

#include "com/sun/star/chart/TimeIncrement.hpp"
#include "com/sun/star/chart2/AxisOrientation.hpp"
#include "com/sun/star/chart2/IncrementData.hpp"
#include "com/sun/star/chart2/XScaling.hpp"
#include "com/sun/star/chart2/data/XLabeledDataSequence.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline ScaleData::ScaleData()
    : Minimum()
    , Maximum()
    , Origin()
    , Orientation(::css::chart2::AxisOrientation_MATHEMATICAL)
    , Scaling()
    , Categories()
    , AxisType(0)
    , AutoDateAxis(false)
    , ShiftedCategoryPosition(false)
    , IncrementData()
    , TimeIncrement()
{
}

inline ScaleData::ScaleData(const ::css::uno::Any& Minimum_, const ::css::uno::Any& Maximum_, const ::css::uno::Any& Origin_, const ::css::chart2::AxisOrientation& Orientation_, const ::css::uno::Reference< ::css::chart2::XScaling >& Scaling_, const ::css::uno::Reference< ::css::chart2::data::XLabeledDataSequence >& Categories_, const ::sal_Int32& AxisType_, const ::sal_Bool& AutoDateAxis_, const ::sal_Bool& ShiftedCategoryPosition_, const ::css::chart2::IncrementData& IncrementData_, const ::css::chart::TimeIncrement& TimeIncrement_)
    : Minimum(Minimum_)
    , Maximum(Maximum_)
    , Origin(Origin_)
    , Orientation(Orientation_)
    , Scaling(Scaling_)
    , Categories(Categories_)
    , AxisType(AxisType_)
    , AutoDateAxis(AutoDateAxis_)
    , ShiftedCategoryPosition(ShiftedCategoryPosition_)
    , IncrementData(IncrementData_)
    , TimeIncrement(TimeIncrement_)
{
}


inline bool operator==(const ScaleData& the_lhs, const ScaleData& the_rhs)
{
    return the_lhs.Minimum == the_rhs.Minimum
        && the_lhs.Maximum == the_rhs.Maximum
        && the_lhs.Origin == the_rhs.Origin
        && the_lhs.Orientation == the_rhs.Orientation
        && the_lhs.Scaling == the_rhs.Scaling
        && the_lhs.Categories == the_rhs.Categories
        && the_lhs.AxisType == the_rhs.AxisType
        && the_lhs.AutoDateAxis == the_rhs.AutoDateAxis
        && the_lhs.ShiftedCategoryPosition == the_rhs.ShiftedCategoryPosition
        && the_lhs.IncrementData == the_rhs.IncrementData
        && the_lhs.TimeIncrement == the_rhs.TimeIncrement;
}

inline bool operator!=(const ScaleData& the_lhs, const ScaleData& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::ScaleData const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::chart2::AxisOrientation >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::chart2::XScaling > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::chart2::data::XLabeledDataSequence > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::chart2::IncrementData >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::chart::TimeIncrement >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.ScaleData", 0, 11, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::ScaleData const *) {
    return ::cppu::UnoType< ::css::chart2::ScaleData >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_SCALEDATA_HPP
