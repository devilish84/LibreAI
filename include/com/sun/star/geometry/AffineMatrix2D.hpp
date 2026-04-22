#ifndef INCLUDED_COM_SUN_STAR_GEOMETRY_AFFINEMATRIX2D_HPP
#define INCLUDED_COM_SUN_STAR_GEOMETRY_AFFINEMATRIX2D_HPP

#include "sal/config.h"

#include "com/sun/star/geometry/AffineMatrix2D.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace geometry {

inline AffineMatrix2D::AffineMatrix2D()
    : m00(0)
    , m01(0)
    , m02(0)
    , m10(0)
    , m11(0)
    , m12(0)
{
}

inline AffineMatrix2D::AffineMatrix2D(const double& m00_, const double& m01_, const double& m02_, const double& m10_, const double& m11_, const double& m12_)
    : m00(m00_)
    , m01(m01_)
    , m02(m02_)
    , m10(m10_)
    , m11(m11_)
    , m12(m12_)
{
}


inline bool operator==(const AffineMatrix2D& the_lhs, const AffineMatrix2D& the_rhs)
{
    return the_lhs.m00 == the_rhs.m00
        && the_lhs.m01 == the_rhs.m01
        && the_lhs.m02 == the_rhs.m02
        && the_lhs.m10 == the_rhs.m10
        && the_lhs.m11 == the_rhs.m11
        && the_lhs.m12 == the_rhs.m12;
}

inline bool operator!=(const AffineMatrix2D& the_lhs, const AffineMatrix2D& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace geometry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::geometry::AffineMatrix2D const *) {
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
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.geometry.AffineMatrix2D", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::geometry::AffineMatrix2D const *) {
    return ::cppu::UnoType< ::css::geometry::AffineMatrix2D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_GEOMETRY_AFFINEMATRIX2D_HPP
