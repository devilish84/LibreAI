#ifndef INCLUDED_COM_SUN_STAR_GEOMETRY_REALRECTANGLE3D_HPP
#define INCLUDED_COM_SUN_STAR_GEOMETRY_REALRECTANGLE3D_HPP

#include "sal/config.h"

#include "com/sun/star/geometry/RealRectangle3D.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace geometry {

inline RealRectangle3D::RealRectangle3D()
    : X1(0)
    , Y1(0)
    , Z1(0)
    , X2(0)
    , Y2(0)
    , Z2(0)
{
}

inline RealRectangle3D::RealRectangle3D(const double& X1_, const double& Y1_, const double& Z1_, const double& X2_, const double& Y2_, const double& Z2_)
    : X1(X1_)
    , Y1(Y1_)
    , Z1(Z1_)
    , X2(X2_)
    , Y2(Y2_)
    , Z2(Z2_)
{
}


inline bool operator==(const RealRectangle3D& the_lhs, const RealRectangle3D& the_rhs)
{
    return the_lhs.X1 == the_rhs.X1
        && the_lhs.Y1 == the_rhs.Y1
        && the_lhs.Z1 == the_rhs.Z1
        && the_lhs.X2 == the_rhs.X2
        && the_lhs.Y2 == the_rhs.Y2
        && the_lhs.Z2 == the_rhs.Z2;
}

inline bool operator!=(const RealRectangle3D& the_lhs, const RealRectangle3D& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace geometry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::geometry::RealRectangle3D const *) {
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
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.geometry.RealRectangle3D", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::geometry::RealRectangle3D const *) {
    return ::cppu::UnoType< ::css::geometry::RealRectangle3D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_GEOMETRY_REALRECTANGLE3D_HPP
