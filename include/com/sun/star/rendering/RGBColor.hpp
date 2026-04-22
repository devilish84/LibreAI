#ifndef INCLUDED_COM_SUN_STAR_RENDERING_RGBCOLOR_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_RGBCOLOR_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/RGBColor.hdl"

#include "com/sun/star/rendering/ColorComponent.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline RGBColor::RGBColor()
    : Red(0)
    , Green(0)
    , Blue(0)
{
}

inline RGBColor::RGBColor(const double& Red_, const double& Green_, const double& Blue_)
    : Red(Red_)
    , Green(Green_)
    , Blue(Blue_)
{
}


inline bool operator==(const RGBColor& the_lhs, const RGBColor& the_rhs)
{
    return the_lhs.Red == the_rhs.Red
        && the_lhs.Green == the_rhs.Green
        && the_lhs.Blue == the_rhs.Blue;
}

inline bool operator!=(const RGBColor& the_lhs, const RGBColor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::RGBColor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.RGBColor", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::RGBColor const *) {
    return ::cppu::UnoType< ::css::rendering::RGBColor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_RGBCOLOR_HPP
