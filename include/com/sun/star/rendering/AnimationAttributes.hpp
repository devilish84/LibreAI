#ifndef INCLUDED_COM_SUN_STAR_RENDERING_ANIMATIONATTRIBUTES_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_ANIMATIONATTRIBUTES_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/AnimationAttributes.hdl"

#include "com/sun/star/geometry/RealSize2D.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline AnimationAttributes::AnimationAttributes()
    : Duration(0)
    , RepeatMode(0)
    , UntransformedSize()
{
}

inline AnimationAttributes::AnimationAttributes(const double& Duration_, const ::sal_Int8& RepeatMode_, const ::css::geometry::RealSize2D& UntransformedSize_)
    : Duration(Duration_)
    , RepeatMode(RepeatMode_)
    , UntransformedSize(UntransformedSize_)
{
}


inline bool operator==(const AnimationAttributes& the_lhs, const AnimationAttributes& the_rhs)
{
    return the_lhs.Duration == the_rhs.Duration
        && the_lhs.RepeatMode == the_rhs.RepeatMode
        && the_lhs.UntransformedSize == the_rhs.UntransformedSize;
}

inline bool operator!=(const AnimationAttributes& the_lhs, const AnimationAttributes& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::AnimationAttributes const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::geometry::RealSize2D >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.AnimationAttributes", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::AnimationAttributes const *) {
    return ::cppu::UnoType< ::css::rendering::AnimationAttributes >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_ANIMATIONATTRIBUTES_HPP
