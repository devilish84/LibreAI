#ifndef INCLUDED_COM_SUN_STAR_GEOMETRY_INTEGERPOINT2D_HPP
#define INCLUDED_COM_SUN_STAR_GEOMETRY_INTEGERPOINT2D_HPP

#include "sal/config.h"

#include "com/sun/star/geometry/IntegerPoint2D.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace geometry {

inline IntegerPoint2D::IntegerPoint2D()
    : X(0)
    , Y(0)
{
}

inline IntegerPoint2D::IntegerPoint2D(const ::sal_Int32& X_, const ::sal_Int32& Y_)
    : X(X_)
    , Y(Y_)
{
}


inline bool operator==(const IntegerPoint2D& the_lhs, const IntegerPoint2D& the_rhs)
{
    return the_lhs.X == the_rhs.X
        && the_lhs.Y == the_rhs.Y;
}

inline bool operator!=(const IntegerPoint2D& the_lhs, const IntegerPoint2D& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace geometry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::geometry::IntegerPoint2D const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.geometry.IntegerPoint2D", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::geometry::IntegerPoint2D const *) {
    return ::cppu::UnoType< ::css::geometry::IntegerPoint2D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_GEOMETRY_INTEGERPOINT2D_HPP
