#ifndef INCLUDED_COM_SUN_STAR_DRAWING_GLUEPOINT2_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_GLUEPOINT2_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/GluePoint2.hdl"

#include "com/sun/star/awt/Point.hpp"
#include "com/sun/star/drawing/Alignment.hpp"
#include "com/sun/star/drawing/EscapeDirection.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline GluePoint2::GluePoint2()
    : Position()
    , IsRelative(false)
    , PositionAlignment(::css::drawing::Alignment_TOP_LEFT)
    , Escape(::css::drawing::EscapeDirection_SMART)
    , IsUserDefined(false)
{
}

inline GluePoint2::GluePoint2(const ::css::awt::Point& Position_, const ::sal_Bool& IsRelative_, const ::css::drawing::Alignment& PositionAlignment_, const ::css::drawing::EscapeDirection& Escape_, const ::sal_Bool& IsUserDefined_)
    : Position(Position_)
    , IsRelative(IsRelative_)
    , PositionAlignment(PositionAlignment_)
    , Escape(Escape_)
    , IsUserDefined(IsUserDefined_)
{
}


inline bool operator==(const GluePoint2& the_lhs, const GluePoint2& the_rhs)
{
    return the_lhs.Position == the_rhs.Position
        && the_lhs.IsRelative == the_rhs.IsRelative
        && the_lhs.PositionAlignment == the_rhs.PositionAlignment
        && the_lhs.Escape == the_rhs.Escape
        && the_lhs.IsUserDefined == the_rhs.IsUserDefined;
}

inline bool operator!=(const GluePoint2& the_lhs, const GluePoint2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::GluePoint2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::awt::Point >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::Alignment >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::EscapeDirection >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.GluePoint2", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::GluePoint2 const *) {
    return ::cppu::UnoType< ::css::drawing::GluePoint2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_GLUEPOINT2_HPP
