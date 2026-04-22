#ifndef INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPEPARAMETER_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPEPARAMETER_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/EnhancedCustomShapeParameter.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline EnhancedCustomShapeParameter::EnhancedCustomShapeParameter()
    : Value()
    , Type(0)
{
}

inline EnhancedCustomShapeParameter::EnhancedCustomShapeParameter(const ::css::uno::Any& Value_, const ::sal_Int16& Type_)
    : Value(Value_)
    , Type(Type_)
{
}


inline bool operator==(const EnhancedCustomShapeParameter& the_lhs, const EnhancedCustomShapeParameter& the_rhs)
{
    return the_lhs.Value == the_rhs.Value
        && the_lhs.Type == the_rhs.Type;
}

inline bool operator!=(const EnhancedCustomShapeParameter& the_lhs, const EnhancedCustomShapeParameter& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeParameter const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.EnhancedCustomShapeParameter", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeParameter const *) {
    return ::cppu::UnoType< ::css::drawing::EnhancedCustomShapeParameter >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPEPARAMETER_HPP
