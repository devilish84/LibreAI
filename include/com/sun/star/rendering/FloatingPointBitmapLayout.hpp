#ifndef INCLUDED_COM_SUN_STAR_RENDERING_FLOATINGPOINTBITMAPLAYOUT_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_FLOATINGPOINTBITMAPLAYOUT_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/FloatingPointBitmapLayout.hdl"

#include "com/sun/star/rendering/XColorSpace.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline FloatingPointBitmapLayout::FloatingPointBitmapLayout()
    : ScanLines(0)
    , ScanLineBytes(0)
    , ScanLineStride(0)
    , PlaneStride(0)
    , ColorSpace()
    , NumComponents(0)
    , Endianness(0)
    , Format(0)
{
}

inline FloatingPointBitmapLayout::FloatingPointBitmapLayout(const ::sal_Int32& ScanLines_, const ::sal_Int32& ScanLineBytes_, const ::sal_Int32& ScanLineStride_, const ::sal_Int32& PlaneStride_, const ::css::uno::Reference< ::css::rendering::XColorSpace >& ColorSpace_, const ::sal_Int32& NumComponents_, const ::sal_Int8& Endianness_, const ::sal_Int8& Format_)
    : ScanLines(ScanLines_)
    , ScanLineBytes(ScanLineBytes_)
    , ScanLineStride(ScanLineStride_)
    , PlaneStride(PlaneStride_)
    , ColorSpace(ColorSpace_)
    , NumComponents(NumComponents_)
    , Endianness(Endianness_)
    , Format(Format_)
{
}


inline bool operator==(const FloatingPointBitmapLayout& the_lhs, const FloatingPointBitmapLayout& the_rhs)
{
    return the_lhs.ScanLines == the_rhs.ScanLines
        && the_lhs.ScanLineBytes == the_rhs.ScanLineBytes
        && the_lhs.ScanLineStride == the_rhs.ScanLineStride
        && the_lhs.PlaneStride == the_rhs.PlaneStride
        && the_lhs.ColorSpace == the_rhs.ColorSpace
        && the_lhs.NumComponents == the_rhs.NumComponents
        && the_lhs.Endianness == the_rhs.Endianness
        && the_lhs.Format == the_rhs.Format;
}

inline bool operator!=(const FloatingPointBitmapLayout& the_lhs, const FloatingPointBitmapLayout& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::FloatingPointBitmapLayout const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::rendering::XColorSpace > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.FloatingPointBitmapLayout", 0, 8, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::FloatingPointBitmapLayout const *) {
    return ::cppu::UnoType< ::css::rendering::FloatingPointBitmapLayout >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_FLOATINGPOINTBITMAPLAYOUT_HPP
