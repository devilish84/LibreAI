#ifndef INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPETEXTFRAME_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPETEXTFRAME_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/EnhancedCustomShapeTextFrame.hdl"

#include "com/sun/star/drawing/EnhancedCustomShapeParameterPair.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline EnhancedCustomShapeTextFrame::EnhancedCustomShapeTextFrame()
    : TopLeft()
    , BottomRight()
{
}

inline EnhancedCustomShapeTextFrame::EnhancedCustomShapeTextFrame(const ::css::drawing::EnhancedCustomShapeParameterPair& TopLeft_, const ::css::drawing::EnhancedCustomShapeParameterPair& BottomRight_)
    : TopLeft(TopLeft_)
    , BottomRight(BottomRight_)
{
}


inline bool operator==(const EnhancedCustomShapeTextFrame& the_lhs, const EnhancedCustomShapeTextFrame& the_rhs)
{
    return the_lhs.TopLeft == the_rhs.TopLeft
        && the_lhs.BottomRight == the_rhs.BottomRight;
}

inline bool operator!=(const EnhancedCustomShapeTextFrame& the_lhs, const EnhancedCustomShapeTextFrame& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeTextFrame const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::drawing::EnhancedCustomShapeParameterPair >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::EnhancedCustomShapeParameterPair >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.EnhancedCustomShapeTextFrame", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeTextFrame const *) {
    return ::cppu::UnoType< ::css::drawing::EnhancedCustomShapeTextFrame >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPETEXTFRAME_HPP
