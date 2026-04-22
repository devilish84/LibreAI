#ifndef INCLUDED_COM_SUN_STAR_DRAWING_DIRECTION3D_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_DIRECTION3D_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/Direction3D.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline Direction3D::Direction3D()
    : DirectionX(0)
    , DirectionY(0)
    , DirectionZ(0)
{
}

inline Direction3D::Direction3D(const double& DirectionX_, const double& DirectionY_, const double& DirectionZ_)
    : DirectionX(DirectionX_)
    , DirectionY(DirectionY_)
    , DirectionZ(DirectionZ_)
{
}


inline bool operator==(const Direction3D& the_lhs, const Direction3D& the_rhs)
{
    return the_lhs.DirectionX == the_rhs.DirectionX
        && the_lhs.DirectionY == the_rhs.DirectionY
        && the_lhs.DirectionZ == the_rhs.DirectionZ;
}

inline bool operator!=(const Direction3D& the_lhs, const Direction3D& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::Direction3D const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.Direction3D", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::Direction3D const *) {
    return ::cppu::UnoType< ::css::drawing::Direction3D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_DIRECTION3D_HPP
