#ifndef INCLUDED_COM_SUN_STAR_RENDERING_RENDERSTATE_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_RENDERSTATE_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/RenderState.hdl"

#include "com/sun/star/geometry/AffineMatrix2D.hpp"
#include "com/sun/star/rendering/ColorComponent.hpp"
#include "com/sun/star/rendering/XPolyPolygon2D.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline RenderState::RenderState()
    : AffineTransform()
    , Clip()
    , DeviceColor()
    , CompositeOperation(0)
{
}

inline RenderState::RenderState(const ::css::geometry::AffineMatrix2D& AffineTransform_, const ::css::uno::Reference< ::css::rendering::XPolyPolygon2D >& Clip_, const ::css::uno::Sequence< double >& DeviceColor_, const ::sal_Int8& CompositeOperation_)
    : AffineTransform(AffineTransform_)
    , Clip(Clip_)
    , DeviceColor(DeviceColor_)
    , CompositeOperation(CompositeOperation_)
{
}


inline bool operator==(const RenderState& the_lhs, const RenderState& the_rhs)
{
    return the_lhs.AffineTransform == the_rhs.AffineTransform
        && the_lhs.Clip == the_rhs.Clip
        && the_lhs.DeviceColor == the_rhs.DeviceColor
        && the_lhs.CompositeOperation == the_rhs.CompositeOperation;
}

inline bool operator!=(const RenderState& the_lhs, const RenderState& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::RenderState const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::geometry::AffineMatrix2D >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XPolyPolygon2D > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< double > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.RenderState", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::RenderState const *) {
    return ::cppu::UnoType< ::css::rendering::RenderState >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_RENDERSTATE_HPP
