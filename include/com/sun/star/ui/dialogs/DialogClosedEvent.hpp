#ifndef INCLUDED_COM_SUN_STAR_UI_DIALOGS_DIALOGCLOSEDEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UI_DIALOGS_DIALOGCLOSEDEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/ui/dialogs/DialogClosedEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ui { namespace dialogs {

inline DialogClosedEvent::DialogClosedEvent()
    : ::css::lang::EventObject()
    , DialogResult(0)
{
}

inline DialogClosedEvent::DialogClosedEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int16& DialogResult_)
    : ::css::lang::EventObject(Source_)
    , DialogResult(DialogResult_)
{
}


inline bool operator==(const DialogClosedEvent& the_lhs, const DialogClosedEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.DialogResult == the_rhs.DialogResult;
}

inline bool operator!=(const DialogClosedEvent& the_lhs, const DialogClosedEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace ui { namespace dialogs {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::dialogs::DialogClosedEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ui.dialogs.DialogClosedEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ui::dialogs::DialogClosedEvent const *) {
    return ::cppu::UnoType< ::css::ui::dialogs::DialogClosedEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_DIALOGS_DIALOGCLOSEDEVENT_HPP
