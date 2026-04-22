#ifndef INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPEPARAMETERPAIR_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPEPARAMETERPAIR_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/EnhancedCustomShapeParameterPair.hdl"

#include "com/sun/star/drawing/EnhancedCustomShapeParameter.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline EnhancedCustomShapeParameterPair::EnhancedCustomShapeParameterPair()
    : First()
    , Second()
{
}

inline EnhancedCustomShapeParameterPair::EnhancedCustomShapeParameterPair(const ::css::drawing::EnhancedCustomShapeParameter& First_, const ::css::drawing::EnhancedCustomShapeParameter& Second_)
    : First(First_)
    , Second(Second_)
{
}


inline bool operator==(const EnhancedCustomShapeParameterPair& the_lhs, const EnhancedCustomShapeParameterPair& the_rhs)
{
    return the_lhs.First == the_rhs.First
        && the_lhs.Second == the_rhs.Second;
}

inline bool operator!=(const EnhancedCustomShapeParameterPair& the_lhs, const EnhancedCustomShapeParameterPair& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeParameterPair const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::drawing::EnhancedCustomShapeParameter >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::drawing::EnhancedCustomShapeParameter >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.EnhancedCustomShapeParameterPair", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeParameterPair const *) {
    return ::cppu::UnoType< ::css::drawing::EnhancedCustomShapeParameterPair >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPEPARAMETERPAIR_HPP
