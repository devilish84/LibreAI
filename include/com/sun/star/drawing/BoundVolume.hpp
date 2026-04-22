#ifndef INCLUDED_COM_SUN_STAR_DRAWING_BOUNDVOLUME_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_BOUNDVOLUME_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/BoundVolume.hdl"

#include "com/sun/star/drawing/Position3D.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline BoundVolume::BoundVolume()
    : min()
    , max()
{
}

inline BoundVolume::BoundVolume(const ::css::drawing::Position3D& min_, const ::css::drawing::Position3D& max_)
    : min(min_)
    , max(max_)
{
}


inline bool operator==(const BoundVolume& the_lhs, const BoundVolume& the_rhs)
{
    return the_lhs.min == the_rhs.min
        && the_lhs.max == the_rhs.max;
}

inline bool operator!=(const BoundVolume& the_lhs, const BoundVolume& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::BoundVolume const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::drawing::Position3D >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::Position3D >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.BoundVolume", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::BoundVolume const *) {
    return ::cppu::UnoType< ::css::drawing::BoundVolume >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_BOUNDVOLUME_HPP
