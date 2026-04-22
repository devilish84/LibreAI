#ifndef INCLUDED_COM_SUN_STAR_CHART2_RELATIVEPOSITION_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_RELATIVEPOSITION_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/RelativePosition.hdl"

#include "com/sun/star/drawing/Alignment.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline RelativePosition::RelativePosition()
    : Primary(0)
    , Secondary(0)
    , Anchor(::css::drawing::Alignment_TOP_LEFT)
{
}

inline RelativePosition::RelativePosition(const double& Primary_, const double& Secondary_, const ::css::drawing::Alignment& Anchor_)
    : Primary(Primary_)
    , Secondary(Secondary_)
    , Anchor(Anchor_)
{
}


inline bool operator==(const RelativePosition& the_lhs, const RelativePosition& the_rhs)
{
    return the_lhs.Primary == the_rhs.Primary
        && the_lhs.Secondary == the_rhs.Secondary
        && the_lhs.Anchor == the_rhs.Anchor;
}

inline bool operator!=(const RelativePosition& the_lhs, const RelativePosition& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::RelativePosition const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::Alignment >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.RelativePosition", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::RelativePosition const *) {
    return ::cppu::UnoType< ::css::chart2::RelativePosition >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_RELATIVEPOSITION_HPP
