#ifndef INCLUDED_COM_SUN_STAR_AWT_FOCUSEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_FOCUSEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/FocusEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline FocusEvent::FocusEvent()
    : ::css::lang::EventObject()
    , FocusFlags(0)
    , NextFocus()
    , Temporary(false)
{
}

inline FocusEvent::FocusEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int16& FocusFlags_, const ::css::uno::Reference< ::css::uno::XInterface >& NextFocus_, const ::sal_Bool& Temporary_)
    : ::css::lang::EventObject(Source_)
    , FocusFlags(FocusFlags_)
    , NextFocus(NextFocus_)
    , Temporary(Temporary_)
{
}


inline bool operator==(const FocusEvent& the_lhs, const FocusEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.FocusFlags == the_rhs.FocusFlags
        && the_lhs.NextFocus == the_rhs.NextFocus
        && the_lhs.Temporary == the_rhs.Temporary;
}

inline bool operator!=(const FocusEvent& the_lhs, const FocusEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::FocusEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.FocusEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::FocusEvent const *) {
    return ::cppu::UnoType< ::css::awt::FocusEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_FOCUSEVENT_HPP
