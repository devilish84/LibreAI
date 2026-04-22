#ifndef INCLUDED_COM_SUN_STAR_DRAWING_CAMERAGEOMETRY_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_CAMERAGEOMETRY_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/CameraGeometry.hdl"

#include "com/sun/star/drawing/Direction3D.hpp"
#include "com/sun/star/drawing/Position3D.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline CameraGeometry::CameraGeometry()
    : vrp()
    , vpn()
    , vup()
{
}

inline CameraGeometry::CameraGeometry(const ::css::drawing::Position3D& vrp_, const ::css::drawing::Direction3D& vpn_, const ::css::drawing::Direction3D& vup_)
    : vrp(vrp_)
    , vpn(vpn_)
    , vup(vup_)
{
}


inline bool operator==(const CameraGeometry& the_lhs, const CameraGeometry& the_rhs)
{
    return the_lhs.vrp == the_rhs.vrp
        && the_lhs.vpn == the_rhs.vpn
        && the_lhs.vup == the_rhs.vup;
}

inline bool operator!=(const CameraGeometry& the_lhs, const CameraGeometry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::CameraGeometry const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::drawing::Position3D >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::Direction3D >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::Direction3D >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.CameraGeometry", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::CameraGeometry const *) {
    return ::cppu::UnoType< ::css::drawing::CameraGeometry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_CAMERAGEOMETRY_HPP
