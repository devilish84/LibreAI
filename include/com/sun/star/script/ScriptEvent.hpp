#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_SCRIPTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_SCRIPTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/script/ScriptEvent.hdl"

#include "com/sun/star/script/AllEventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace script {

inline ScriptEvent::ScriptEvent()
    : ::css::script::AllEventObject()
    , ScriptType()
    , ScriptCode()
{
}

inline ScriptEvent::ScriptEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Any& Helper_, const ::css::uno::Type& ListenerType_, const ::rtl::OUString& MethodName_, const ::css::uno::Sequence< ::css::uno::Any >& Arguments_, const ::rtl::OUString& ScriptType_, const ::rtl::OUString& ScriptCode_)
    : ::css::script::AllEventObject(Source_, Helper_, ListenerType_, MethodName_, Arguments_)
    , ScriptType(ScriptType_)
    , ScriptCode(ScriptCode_)
{
}


inline bool operator==(const ScriptEvent& the_lhs, const ScriptEvent& the_rhs)
{
    return operator==( static_cast< ::css::script::AllEventObject>(the_lhs), static_cast< ::css::script::AllEventObject>(the_rhs) )

        && the_lhs.ScriptType == the_rhs.ScriptType
        && the_lhs.ScriptCode == the_rhs.ScriptCode;
}

inline bool operator!=(const ScriptEvent& the_lhs, const ScriptEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::ScriptEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.script.ScriptEvent", ::cppu::UnoType< ::css::script::AllEventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::ScriptEvent const *) {
    return ::cppu::UnoType< ::css::script::ScriptEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_SCRIPTEVENT_HPP
