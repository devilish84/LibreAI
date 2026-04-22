#ifndef INCLUDED_COM_SUN_STAR_ACCESSIBILITY_ACCESSIBLEEVENTOBJECT_HPP
#define INCLUDED_COM_SUN_STAR_ACCESSIBILITY_ACCESSIBLEEVENTOBJECT_HPP

#include "sal/config.h"

#include "com/sun/star/accessibility/AccessibleEventObject.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace accessibility {

inline AccessibleEventObject::AccessibleEventObject()
    : ::css::lang::EventObject()
    , EventId(0)
    , NewValue()
    , OldValue()
{
}

inline AccessibleEventObject::AccessibleEventObject(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int16& EventId_, const ::css::uno::Any& NewValue_, const ::css::uno::Any& OldValue_)
    : ::css::lang::EventObject(Source_)
    , EventId(EventId_)
    , NewValue(NewValue_)
    , OldValue(OldValue_)
{
}


inline bool operator==(const AccessibleEventObject& the_lhs, const AccessibleEventObject& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.EventId == the_rhs.EventId
        && the_lhs.NewValue == the_rhs.NewValue
        && the_lhs.OldValue == the_rhs.OldValue;
}

inline bool operator!=(const AccessibleEventObject& the_lhs, const AccessibleEventObject& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace accessibility {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::accessibility::AccessibleEventObject const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.accessibility.AccessibleEventObject", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::accessibility::AccessibleEventObject const *) {
    return ::cppu::UnoType< ::css::accessibility::AccessibleEventObject >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ACCESSIBILITY_ACCESSIBLEEVENTOBJECT_HPP
