#ifndef INCLUDED_COM_SUN_STAR_DRAWING_POSITION3D_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_POSITION3D_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/Position3D.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline Position3D::Position3D()
    : PositionX(0)
    , PositionY(0)
    , PositionZ(0)
{
}

inline Position3D::Position3D(const double& PositionX_, const double& PositionY_, const double& PositionZ_)
    : PositionX(PositionX_)
    , PositionY(PositionY_)
    , PositionZ(PositionZ_)
{
}


inline bool operator==(const Position3D& the_lhs, const Position3D& the_rhs)
{
    return the_lhs.PositionX == the_rhs.PositionX
        && the_lhs.PositionY == the_rhs.PositionY
        && the_lhs.PositionZ == the_rhs.PositionZ;
}

inline bool operator!=(const Position3D& the_lhs, const Position3D& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::Position3D const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.Position3D", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::Position3D const *) {
    return ::cppu::UnoType< ::css::drawing::Position3D >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_POSITION3D_HPP
