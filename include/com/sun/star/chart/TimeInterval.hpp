#ifndef INCLUDED_COM_SUN_STAR_CHART_TIMEINTERVAL_HPP
#define INCLUDED_COM_SUN_STAR_CHART_TIMEINTERVAL_HPP

#include "sal/config.h"

#include "com/sun/star/chart/TimeInterval.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart {

inline TimeInterval::TimeInterval()
    : Number(0)
    , TimeUnit(0)
{
}

inline TimeInterval::TimeInterval(const ::sal_Int32& Number_, const ::sal_Int32& TimeUnit_)
    : Number(Number_)
    , TimeUnit(TimeUnit_)
{
}


inline bool operator==(const TimeInterval& the_lhs, const TimeInterval& the_rhs)
{
    return the_lhs.Number == the_rhs.Number
        && the_lhs.TimeUnit == the_rhs.TimeUnit;
}

inline bool operator!=(const TimeInterval& the_lhs, const TimeInterval& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart::TimeInterval const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart.TimeInterval", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart::TimeInterval const *) {
    return ::cppu::UnoType< ::css::chart::TimeInterval >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART_TIMEINTERVAL_HPP
