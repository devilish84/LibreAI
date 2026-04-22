#ifndef INCLUDED_COM_SUN_STAR_STYLE_TABSTOP_HPP
#define INCLUDED_COM_SUN_STAR_STYLE_TABSTOP_HPP

#include "sal/config.h"

#include "com/sun/star/style/TabStop.hdl"

#include "com/sun/star/style/TabAlign.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace style {

inline TabStop::TabStop()
    : Position(0)
    , Alignment(::css::style::TabAlign_LEFT)
    , DecimalChar(0)
    , FillChar(0)
{
}

inline TabStop::TabStop(const ::sal_Int32& Position_, const ::css::style::TabAlign& Alignment_, const ::sal_Unicode& DecimalChar_, const ::sal_Unicode& FillChar_)
    : Position(Position_)
    , Alignment(Alignment_)
    , DecimalChar(DecimalChar_)
    , FillChar(FillChar_)
{
}


inline bool operator==(const TabStop& the_lhs, const TabStop& the_rhs)
{
    return the_lhs.Position == the_rhs.Position
        && the_lhs.Alignment == the_rhs.Alignment
        && the_lhs.DecimalChar == the_rhs.DecimalChar
        && the_lhs.FillChar == the_rhs.FillChar;
}

inline bool operator!=(const TabStop& the_lhs, const TabStop& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace style {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::style::TabStop const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::style::TabAlign >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoCharType >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoCharType >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.style.TabStop", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::style::TabStop const *) {
    return ::cppu::UnoType< ::css::style::TabStop >::get();
}

#endif // INCLUDED_COM_SUN_STAR_STYLE_TABSTOP_HPP
