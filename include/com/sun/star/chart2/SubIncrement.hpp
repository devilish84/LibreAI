#ifndef INCLUDED_COM_SUN_STAR_CHART2_SUBINCREMENT_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_SUBINCREMENT_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/SubIncrement.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline SubIncrement::SubIncrement()
    : IntervalCount()
    , PostEquidistant()
{
}

inline SubIncrement::SubIncrement(const ::css::uno::Any& IntervalCount_, const ::css::uno::Any& PostEquidistant_)
    : IntervalCount(IntervalCount_)
    , PostEquidistant(PostEquidistant_)
{
}


inline bool operator==(const SubIncrement& the_lhs, const SubIncrement& the_rhs)
{
    return the_lhs.IntervalCount == the_rhs.IntervalCount
        && the_lhs.PostEquidistant == the_rhs.PostEquidistant;
}

inline bool operator!=(const SubIncrement& the_lhs, const SubIncrement& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::SubIncrement const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.SubIncrement", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::SubIncrement const *) {
    return ::cppu::UnoType< ::css::chart2::SubIncrement >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_SUBINCREMENT_HPP
