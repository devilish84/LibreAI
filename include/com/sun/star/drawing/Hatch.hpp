#ifndef INCLUDED_COM_SUN_STAR_DRAWING_HATCH_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_HATCH_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/Hatch.hdl"

#include "com/sun/star/drawing/HatchStyle.hpp"
#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline Hatch::Hatch()
    : Style(::css::drawing::HatchStyle_SINGLE)
    , Color(0)
    , Distance(0)
    , Angle(0)
{
}

inline Hatch::Hatch(const ::css::drawing::HatchStyle& Style_, const ::sal_Int32& Color_, const ::sal_Int32& Distance_, const ::sal_Int32& Angle_)
    : Style(Style_)
    , Color(Color_)
    , Distance(Distance_)
    , Angle(Angle_)
{
}


inline bool operator==(const Hatch& the_lhs, const Hatch& the_rhs)
{
    return the_lhs.Style == the_rhs.Style
        && the_lhs.Color == the_rhs.Color
        && the_lhs.Distance == the_rhs.Distance
        && the_lhs.Angle == the_rhs.Angle;
}

inline bool operator!=(const Hatch& the_lhs, const Hatch& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::Hatch const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::drawing::HatchStyle >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.Hatch", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::Hatch const *) {
    return ::cppu::UnoType< ::css::drawing::Hatch >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_HATCH_HPP
