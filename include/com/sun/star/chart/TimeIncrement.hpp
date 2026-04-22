#ifndef INCLUDED_COM_SUN_STAR_CHART_TIMEINCREMENT_HPP
#define INCLUDED_COM_SUN_STAR_CHART_TIMEINCREMENT_HPP

#include "sal/config.h"

#include "com/sun/star/chart/TimeIncrement.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart {

inline TimeIncrement::TimeIncrement()
    : MajorTimeInterval()
    , MinorTimeInterval()
    , TimeResolution()
{
}

inline TimeIncrement::TimeIncrement(const ::css::uno::Any& MajorTimeInterval_, const ::css::uno::Any& MinorTimeInterval_, const ::css::uno::Any& TimeResolution_)
    : MajorTimeInterval(MajorTimeInterval_)
    , MinorTimeInterval(MinorTimeInterval_)
    , TimeResolution(TimeResolution_)
{
}


inline bool operator==(const TimeIncrement& the_lhs, const TimeIncrement& the_rhs)
{
    return the_lhs.MajorTimeInterval == the_rhs.MajorTimeInterval
        && the_lhs.MinorTimeInterval == the_rhs.MinorTimeInterval
        && the_lhs.TimeResolution == the_rhs.TimeResolution;
}

inline bool operator!=(const TimeIncrement& the_lhs, const TimeIncrement& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::TimeIncrement const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart.TimeIncrement", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart::TimeIncrement const *) {
    return ::cppu::UnoType< ::css::chart::TimeIncrement >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_TIMEINCREMENT_HPP
