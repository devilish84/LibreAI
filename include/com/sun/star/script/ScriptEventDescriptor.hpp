#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_SCRIPTEVENTDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_SCRIPTEVENTDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/script/ScriptEventDescriptor.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace script {

inline ScriptEventDescriptor::ScriptEventDescriptor()
    : ListenerType()
    , EventMethod()
    , AddListenerParam()
    , ScriptType()
    , ScriptCode()
{
}

inline ScriptEventDescriptor::ScriptEventDescriptor(const ::rtl::OUString& ListenerType_, const ::rtl::OUString& EventMethod_, const ::rtl::OUString& AddListenerParam_, const ::rtl::OUString& ScriptType_, const ::rtl::OUString& ScriptCode_)
    : ListenerType(ListenerType_)
    , EventMethod(EventMethod_)
    , AddListenerParam(AddListenerParam_)
    , ScriptType(ScriptType_)
    , ScriptCode(ScriptCode_)
{
}


inline bool operator==(const ScriptEventDescriptor& the_lhs, const ScriptEventDescriptor& the_rhs)
{
    return the_lhs.ListenerType == the_rhs.ListenerType
        && the_lhs.EventMethod == the_rhs.EventMethod
        && the_lhs.AddListenerParam == the_rhs.AddListenerParam
        && the_lhs.ScriptType == the_rhs.ScriptType
        && the_lhs.ScriptCode == the_rhs.ScriptCode;
}

inline bool operator!=(const ScriptEventDescriptor& the_lhs, const ScriptEventDescriptor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::ScriptEventDescriptor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.script.ScriptEventDescriptor", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::ScriptEventDescriptor const *) {
    return ::cppu::UnoType< ::css::script::ScriptEventDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_SCRIPTEVENTDESCRIPTOR_HPP
