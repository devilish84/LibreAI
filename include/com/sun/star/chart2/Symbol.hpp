#ifndef INCLUDED_COM_SUN_STAR_CHART2_SYMBOL_HPP
#define INCLUDED_COM_SUN_STAR_CHART2_SYMBOL_HPP

#include "sal/config.h"

#include "com/sun/star/chart2/Symbol.hdl"

#include "com/sun/star/awt/Size.hpp"
#include "com/sun/star/chart2/SymbolStyle.hpp"
#include "com/sun/star/drawing/PolyPolygonBezierCoords.hpp"
#include "com/sun/star/graphic/XGraphic.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace chart2 {

inline Symbol::Symbol()
    : Style(::css::chart2::SymbolStyle_NONE)
    , PolygonCoords()
    , StandardSymbol(0)
    , Graphic()
    , Size()
    , BorderColor(0)
    , FillColor(0)
{
}

inline Symbol::Symbol(const ::css::chart2::SymbolStyle& Style_, const ::css::drawing::PolyPolygonBezierCoords& PolygonCoords_, const ::sal_Int32& StandardSymbol_, const ::css::uno::Reference< ::css::graphic::XGraphic >& Graphic_, const ::css::awt::Size& Size_, const ::sal_Int32& BorderColor_, const ::sal_Int32& FillColor_)
    : Style(Style_)
    , PolygonCoords(PolygonCoords_)
    , StandardSymbol(StandardSymbol_)
    , Graphic(Graphic_)
    , Size(Size_)
    , BorderColor(BorderColor_)
    , FillColor(FillColor_)
{
}


inline bool operator==(const Symbol& the_lhs, const Symbol& the_rhs)
{
    return the_lhs.Style == the_rhs.Style
        && the_lhs.PolygonCoords == the_rhs.PolygonCoords
        && the_lhs.StandardSymbol == the_rhs.StandardSymbol
        && the_lhs.Graphic == the_rhs.Graphic
        && the_lhs.Size == the_rhs.Size
        && the_lhs.BorderColor == the_rhs.BorderColor
        && the_lhs.FillColor == the_rhs.FillColor;
}

inline bool operator!=(const Symbol& the_lhs, const Symbol& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace chart2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::chart2::Symbol const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::chart2::SymbolStyle >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::PolyPolygonBezierCoords >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::graphic::XGraphic > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::Size >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.chart2.Symbol", 0, 7, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::chart2::Symbol const *) {
    return ::cppu::UnoType< ::css::chart2::Symbol >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CHART2_SYMBOL_HPP
