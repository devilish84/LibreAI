#ifndef INCLUDED_COM_SUN_STAR_DRAWING_GLUEPOINT_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_GLUEPOINT_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/GluePoint.hdl"

#include "com/sun/star/awt/Point.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline GluePoint::GluePoint()
    : Position()
    , EscapeDirection(0)
    , PositionAbsolute(false)
    , Alignment(0)
{
}

inline GluePoint::GluePoint(const ::css::awt::Point& Position_, const ::sal_Int16& EscapeDirection_, const ::sal_Bool& PositionAbsolute_, const ::sal_Int16& Alignment_)
    : Position(Position_)
    , EscapeDirection(EscapeDirection_)
    , PositionAbsolute(PositionAbsolute_)
    , Alignment(Alignment_)
{
}


inline bool operator==(const GluePoint& the_lhs, const GluePoint& the_rhs)
{
    return the_lhs.Position == the_rhs.Position
        && the_lhs.EscapeDirection == the_rhs.EscapeDirection
        && the_lhs.PositionAbsolute == the_rhs.PositionAbsolute
        && the_lhs.Alignment == the_rhs.Alignment;
}

inline bool operator!=(const GluePoint& the_lhs, const GluePoint& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::GluePoint const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::awt::Point >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.GluePoint", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::GluePoint const *) {
    return ::cppu::UnoType< ::css::drawing::GluePoint >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_GLUEPOINT_HPP
