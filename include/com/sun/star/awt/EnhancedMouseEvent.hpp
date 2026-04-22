#ifndef INCLUDED_COM_SUN_STAR_AWT_ENHANCEDMOUSEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_ENHANCEDMOUSEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/EnhancedMouseEvent.hdl"

#include "com/sun/star/awt/MouseEvent.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline EnhancedMouseEvent::EnhancedMouseEvent()
    : ::css::awt::MouseEvent()
    , Target()
{
}

inline EnhancedMouseEvent::EnhancedMouseEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int16& Modifiers_, const ::sal_Int16& Buttons_, const ::sal_Int32& X_, const ::sal_Int32& Y_, const ::sal_Int32& ClickCount_, const ::sal_Bool& PopupTrigger_, const ::css::uno::Reference< ::css::uno::XInterface >& Target_)
    : ::css::awt::MouseEvent(Source_, Modifiers_, Buttons_, X_, Y_, ClickCount_, PopupTrigger_)
    , Target(Target_)
{
}


inline bool operator==(const EnhancedMouseEvent& the_lhs, const EnhancedMouseEvent& the_rhs)
{
    return operator==( static_cast< ::css::awt::MouseEvent>(the_lhs), static_cast< ::css::awt::MouseEvent>(the_rhs) )

        && the_lhs.Target == the_rhs.Target;
}

inline bool operator!=(const EnhancedMouseEvent& the_lhs, const EnhancedMouseEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::EnhancedMouseEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.EnhancedMouseEvent", ::cppu::UnoType< ::css::awt::MouseEvent >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::EnhancedMouseEvent const *) {
    return ::cppu::UnoType< ::css::awt::EnhancedMouseEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_ENHANCEDMOUSEEVENT_HPP
