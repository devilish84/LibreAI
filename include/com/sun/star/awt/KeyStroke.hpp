#ifndef INCLUDED_COM_SUN_STAR_AWT_KEYSTROKE_HPP
#define INCLUDED_COM_SUN_STAR_AWT_KEYSTROKE_HPP

#include "sal/config.h"

#include "com/sun/star/awt/KeyStroke.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline KeyStroke::KeyStroke()
    : Modifiers(0)
    , KeyCode(0)
    , KeyChar(0)
    , KeyFunc(0)
{
}

inline KeyStroke::KeyStroke(const ::sal_Int16& Modifiers_, const ::sal_Int16& KeyCode_, const ::sal_Unicode& KeyChar_, const ::sal_Int16& KeyFunc_)
    : Modifiers(Modifiers_)
    , KeyCode(KeyCode_)
    , KeyChar(KeyChar_)
    , KeyFunc(KeyFunc_)
{
}


inline bool operator==(const KeyStroke& the_lhs, const KeyStroke& the_rhs)
{
    return the_lhs.Modifiers == the_rhs.Modifiers
        && the_lhs.KeyCode == the_rhs.KeyCode
        && the_lhs.KeyChar == the_rhs.KeyChar
        && the_lhs.KeyFunc == the_rhs.KeyFunc;
}

inline bool operator!=(const KeyStroke& the_lhs, const KeyStroke& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::KeyStroke const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoCharType >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.KeyStroke", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::KeyStroke const *) {
    return ::cppu::UnoType< ::css::awt::KeyStroke >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_KEYSTROKE_HPP
