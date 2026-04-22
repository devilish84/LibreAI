#ifndef INCLUDED_COM_SUN_STAR_GEOMETRY_REALBEZIERSEGMENT2D_HPP
#define INCLUDED_COM_SUN_STAR_GEOMETRY_REALBEZIERSEGMENT2D_HPP

#include "sal/config.h"

#include "com/sun/star/geometry/RealBezierSegment2D.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace geometry {

inline RealBezierSegment2D::RealBezierSegment2D()
    : Px(0)
    , Py(0)
    , C1x(0)
    , C1y(0)
    , C2x(0)
    , C2y(0)
{
}

inline RealBezierSegment2D::RealBezierSegment2D(const double& Px_, const double& Py_, const double& C1x_, const double& C1y_, const double& C2x_, const double& C2y_)
    : Px(Px_)
    , Py(Py_)
    , C1x(C1x_)
    , C1y(C1y_)
    , C2x(C2x_)
    , C2y(C2y_)
{
}


inline bool operator==(const RealBezierSegment2D& the_lhs, const RealBezierSegment2D& the_rhs)
{
    return the_lhs.Px == the_rhs.Px
        && the_lhs.Py == the_rhs.Py
        && the_lhs.C1x == the_rhs.C1x
        && the_lhs.C1y == the_rhs.C1y
        && the_lhs.C2x == the_rhs.C2x
        && the_lhs.C2y == the_rhs.C2y;
}

inline bool operator!=(const RealBezierSegment2D& the_lhs, const RealBezierSegment2D& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace geometry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::geometry::RealBezierSegment2D const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.geometry.RealBezierSegment2D", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::geometry::RealBezierSegment2D const *) {
    return ::cppu::UnoType< ::css::geometry::RealBezierSegment2D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_GEOMETRY_REALBEZIERSEGMENT2D_HPP
