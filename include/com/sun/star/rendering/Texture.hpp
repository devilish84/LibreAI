#ifndef INCLUDED_COM_SUN_STAR_RENDERING_TEXTURE_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_TEXTURE_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/Texture.hdl"

#include "com/sun/star/geometry/AffineMatrix2D.hpp"
#include "com/sun/star/rendering/StrokeAttributes.hpp"
#include "com/sun/star/rendering/XBitmap.hpp"
#include "com/sun/star/rendering/XParametricPolyPolygon2D.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline Texture::Texture()
    : AffineTransform()
    , Alpha(0)
    , NumberOfHatchPolygons(0)
    , Bitmap()
    , Gradient()
    , Hatching()
    , HatchAttributes()
    , RepeatModeX(0)
    , RepeatModeY(0)
{
}

inline Texture::Texture(const ::css::geometry::AffineMatrix2D& AffineTransform_, const double& Alpha_, const ::sal_Int32& NumberOfHatchPolygons_, const ::css::uno::Reference< ::css::rendering::XBitmap >& Bitmap_, const ::css::uno::Reference< ::css::rendering::XParametricPolyPolygon2D >& Gradient_, const ::css::uno::Reference< ::css::rendering::XParametricPolyPolygon2D >& Hatching_, const ::css::rendering::StrokeAttributes& HatchAttributes_, const ::sal_Int8& RepeatModeX_, const ::sal_Int8& RepeatModeY_)
    : AffineTransform(AffineTransform_)
    , Alpha(Alpha_)
    , NumberOfHatchPolygons(NumberOfHatchPolygons_)
    , Bitmap(Bitmap_)
    , Gradient(Gradient_)
    , Hatching(Hatching_)
    , HatchAttributes(HatchAttributes_)
    , RepeatModeX(RepeatModeX_)
    , RepeatModeY(RepeatModeY_)
{
}


inline bool operator==(const Texture& the_lhs, const Texture& the_rhs)
{
    return the_lhs.AffineTransform == the_rhs.AffineTransform
        && the_lhs.Alpha == the_rhs.Alpha
        && the_lhs.NumberOfHatchPolygons == the_rhs.NumberOfHatchPolygons
        && the_lhs.Bitmap == the_rhs.Bitmap
        && the_lhs.Gradient == the_rhs.Gradient
        && the_lhs.Hatching == the_rhs.Hatching
        && the_lhs.HatchAttributes == the_rhs.HatchAttributes
        && the_lhs.RepeatModeX == the_rhs.RepeatModeX
        && the_lhs.RepeatModeY == the_rhs.RepeatModeY;
}

inline bool operator!=(const Texture& the_lhs, const Texture& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::Texture const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::geometry::AffineMatrix2D >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XBitmap > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XParametricPolyPolygon2D > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XParametricPolyPolygon2D > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::rendering::StrokeAttributes >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.Texture", 0, 9, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::Texture const *) {
    return ::cppu::UnoType< ::css::rendering::Texture >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_TEXTURE_HPP
