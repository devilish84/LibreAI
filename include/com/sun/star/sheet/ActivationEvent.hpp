#ifndef INCLUDED_COM_SUN_STAR_SHEET_ACTIVATIONEVENT_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_ACTIVATIONEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/ActivationEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/sheet/XSpreadsheet.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline ActivationEvent::ActivationEvent()
    : ::css::lang::EventObject()
    , ActiveSheet()
{
}

inline ActivationEvent::ActivationEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Reference< ::css::sheet::XSpreadsheet >& ActiveSheet_)
    : ::css::lang::EventObject(Source_)
    , ActiveSheet(ActiveSheet_)
{
}


inline bool operator==(const ActivationEvent& the_lhs, const ActivationEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.ActiveSheet == the_rhs.ActiveSheet;
}

inline bool operator!=(const ActivationEvent& the_lhs, const ActivationEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::ActivationEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::sheet::XSpreadsheet > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.ActivationEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::ActivationEvent const *) {
    return ::cppu::UnoType< ::css::sheet::ActivationEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_ACTIVATIONEVENT_HPP
