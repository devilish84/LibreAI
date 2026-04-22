#ifndef INCLUDED_COM_SUN_STAR_CHART2_INCREMENTDATA_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_INCREMENTDATA_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/IncrementData.hdl"

#include "com/sun/star/chart2/SubIncrement.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline IncrementData::IncrementData()
    : Distance()
    , PostEquidistant()
    , BaseValue()
    , SubIncrements()
{
}

inline IncrementData::IncrementData(const ::css::uno::Any& Distance_, const ::css::uno::Any& PostEquidistant_, const ::css::uno::Any& BaseValue_, const ::css::uno::Sequence< ::css::chart2::SubIncrement >& SubIncrements_)
    : Distance(Distance_)
    , PostEquidistant(PostEquidistant_)
    , BaseValue(BaseValue_)
    , SubIncrements(SubIncrements_)
{
}


inline bool operator==(const IncrementData& the_lhs, const IncrementData& the_rhs)
{
    return the_lhs.Distance == the_rhs.Distance
        && the_lhs.PostEquidistant == the_rhs.PostEquidistant
        && the_lhs.BaseValue == the_rhs.BaseValue
        && the_lhs.SubIncrements == the_rhs.SubIncrements;
}

inline bool operator!=(const IncrementData& the_lhs, const IncrementData& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::IncrementData const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::chart2::SubIncrement > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.IncrementData", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::IncrementData const *) {
    return ::cppu::UnoType< ::css::chart2::IncrementData >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_INCREMENTDATA_HPP
