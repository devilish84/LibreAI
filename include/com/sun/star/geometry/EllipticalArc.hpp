#ifndef INCLUDED_COM_SUN_STAR_GEOMETRY_ELLIPTICALARC_HPP
#define INCLUDED_COM_SUN_STAR_GEOMETRY_ELLIPTICALARC_HPP

#include "sal/config.h"

#include "com/sun/star/geometry/EllipticalArc.hdl"

#include "com/sun/star/geometry/RealPoint2D.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace geometry {

inline EllipticalArc::EllipticalArc()
    : StartPosition()
    , EndPosition()
    , RadiusX(0)
    , RadiusY(0)
    , XAxisRotation(0)
    , IsLargeArc(false)
    , IsClockwiseSweep(false)
{
}

inline EllipticalArc::EllipticalArc(const ::css::geometry::RealPoint2D& StartPosition_, const ::css::geometry::RealPoint2D& EndPosition_, const double& RadiusX_, const double& RadiusY_, const double& XAxisRotation_, const ::sal_Bool& IsLargeArc_, const ::sal_Bool& IsClockwiseSweep_)
    : StartPosition(StartPosition_)
    , EndPosition(EndPosition_)
    , RadiusX(RadiusX_)
    , RadiusY(RadiusY_)
    , XAxisRotation(XAxisRotation_)
    , IsLargeArc(IsLargeArc_)
    , IsClockwiseSweep(IsClockwiseSweep_)
{
}


inline bool operator==(const EllipticalArc& the_lhs, const EllipticalArc& the_rhs)
{
    return the_lhs.StartPosition == the_rhs.StartPosition
        && the_lhs.EndPosition == the_rhs.EndPosition
        && the_lhs.RadiusX == the_rhs.RadiusX
        && the_lhs.RadiusY == the_rhs.RadiusY
        && the_lhs.XAxisRotation == the_rhs.XAxisRotation
        && the_lhs.IsLargeArc == the_rhs.IsLargeArc
        && the_lhs.IsClockwiseSweep == the_rhs.IsClockwiseSweep;
}

inline bool operator!=(const EllipticalArc& the_lhs, const EllipticalArc& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace geometry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::geometry::EllipticalArc const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::geometry::RealPoint2D >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::geometry::RealPoint2D >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.geometry.EllipticalArc", 0, 7, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::geometry::EllipticalArc const *) {
    return ::cppu::UnoType< ::css::geometry::EllipticalArc >::get();
}

#endif // INCLUDED_COM_SUN_STAR_GEOMETRY_ELLIPTICALARC_HPP
