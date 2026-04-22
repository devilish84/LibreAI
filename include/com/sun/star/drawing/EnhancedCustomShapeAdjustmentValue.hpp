#ifndef INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPEADJUSTMENTVALUE_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPEADJUSTMENTVALUE_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/EnhancedCustomShapeAdjustmentValue.hdl"

#include "com/sun/star/beans/PropertyState.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing {

inline EnhancedCustomShapeAdjustmentValue::EnhancedCustomShapeAdjustmentValue()
    : Value()
    , State(::css::beans::PropertyState_DIRECT_VALUE)
    , Name()
{
}

inline EnhancedCustomShapeAdjustmentValue::EnhancedCustomShapeAdjustmentValue(const ::css::uno::Any& Value_, const ::css::beans::PropertyState& State_, const ::rtl::OUString& Name_)
    : Value(Value_)
    , State(State_)
    , Name(Name_)
{
}


inline bool operator==(const EnhancedCustomShapeAdjustmentValue& the_lhs, const EnhancedCustomShapeAdjustmentValue& the_rhs)
{
    return the_lhs.Value == the_rhs.Value
        && the_lhs.State == the_rhs.State
        && the_lhs.Name == the_rhs.Name;
}

inline bool operator!=(const EnhancedCustomShapeAdjustmentValue& the_lhs, const EnhancedCustomShapeAdjustmentValue& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace drawing {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeAdjustmentValue const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::beans::PropertyState >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.EnhancedCustomShapeAdjustmentValue", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::EnhancedCustomShapeAdjustmentValue const *) {
    return ::cppu::UnoType< ::css::drawing::EnhancedCustomShapeAdjustmentValue >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_ENHANCEDCUSTOMSHAPEADJUSTMENTVALUE_HPP
