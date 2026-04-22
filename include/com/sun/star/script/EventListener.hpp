#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_EVENTLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_EVENTLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/script/EventListener.hdl"

#include "com/sun/star/script/XAllListener.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace script {

inline EventListener::EventListener()
    : AllListener()
    , Helper()
    , ListenerType()
    , AddListenerParam()
    , EventMethod()
{
}

inline EventListener::EventListener(const ::css::uno::Reference< ::css::script::XAllListener >& AllListener_, const ::css::uno::Any& Helper_, const ::rtl::OUString& ListenerType_, const ::rtl::OUString& AddListenerParam_, const ::rtl::OUString& EventMethod_)
    : AllListener(AllListener_)
    , Helper(Helper_)
    , ListenerType(ListenerType_)
    , AddListenerParam(AddListenerParam_)
    , EventMethod(EventMethod_)
{
}


inline bool operator==(const EventListener& the_lhs, const EventListener& the_rhs)
{
    return the_lhs.AllListener == the_rhs.AllListener
        && the_lhs.Helper == the_rhs.Helper
        && the_lhs.ListenerType == the_rhs.ListenerType
        && the_lhs.AddListenerParam == the_rhs.AddListenerParam
        && the_lhs.EventMethod == the_rhs.EventMethod;
}

inline bool operator!=(const EventListener& the_lhs, const EventListener& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::EventListener const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::script::XAllListener > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.script.EventListener", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::EventListener const *) {
    return ::cppu::UnoType< ::css::script::EventListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_EVENTLISTENER_HPP
