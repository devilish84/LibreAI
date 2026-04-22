#ifndef INCLUDED_COM_SUN_STAR_CHART2_FILLBITMAP_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_FILLBITMAP_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/FillBitmap.hdl"

#include "com/sun/star/awt/Point.hpp"
#include "com/sun/star/awt/Size.hpp"
#include "com/sun/star/drawing/BitmapMode.hpp"
#include "com/sun/star/drawing/RectanglePoint.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline FillBitmap::FillBitmap()
    : aURL()
    , aOffset()
    , aPositionOffset()
    , aRectanglePoint(::css::drawing::RectanglePoint_LEFT_TOP)
    , bLogicalSize(false)
    , aSize()
    , aBitmapMode(::css::drawing::BitmapMode_REPEAT)
{
}

inline FillBitmap::FillBitmap(const ::rtl::OUString& aURL_, const ::css::awt::Point& aOffset_, const ::css::awt::Point& aPositionOffset_, const ::css::drawing::RectanglePoint& aRectanglePoint_, const ::sal_Bool& bLogicalSize_, const ::css::awt::Size& aSize_, const ::css::drawing::BitmapMode& aBitmapMode_)
    : aURL(aURL_)
    , aOffset(aOffset_)
    , aPositionOffset(aPositionOffset_)
    , aRectanglePoint(aRectanglePoint_)
    , bLogicalSize(bLogicalSize_)
    , aSize(aSize_)
    , aBitmapMode(aBitmapMode_)
{
}


inline bool operator==(const FillBitmap& the_lhs, const FillBitmap& the_rhs)
{
    return the_lhs.aURL == the_rhs.aURL
        && the_lhs.aOffset == the_rhs.aOffset
        && the_lhs.aPositionOffset == the_rhs.aPositionOffset
        && the_lhs.aRectanglePoint == the_rhs.aRectanglePoint
        && the_lhs.bLogicalSize == the_rhs.bLogicalSize
        && the_lhs.aSize == the_rhs.aSize
        && the_lhs.aBitmapMode == the_rhs.aBitmapMode;
}

inline bool operator!=(const FillBitmap& the_lhs, const FillBitmap& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::FillBitmap const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::Point >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::Point >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::RectanglePoint >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::Size >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::BitmapMode >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.FillBitmap", 0, 7, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::FillBitmap const *) {
    return ::cppu::UnoType< ::css::chart2::FillBitmap >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_FILLBITMAP_HPP
