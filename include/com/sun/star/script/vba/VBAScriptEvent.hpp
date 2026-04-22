#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_VBA_VBASCRIPTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_VBA_VBASCRIPTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/script/vba/VBAScriptEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace script { namespace vba {

inline VBAScriptEvent::VBAScriptEvent()
    : ::css::lang::EventObject()
    , Identifier(0)
    , ModuleName()
{
}

inline VBAScriptEvent::VBAScriptEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& Identifier_, const ::rtl::OUString& ModuleName_)
    : ::css::lang::EventObject(Source_)
    , Identifier(Identifier_)
    , ModuleName(ModuleName_)
{
}


inline bool operator==(const VBAScriptEvent& the_lhs, const VBAScriptEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Identifier == the_rhs.Identifier
        && the_lhs.ModuleName == the_rhs.ModuleName;
}

inline bool operator!=(const VBAScriptEvent& the_lhs, const VBAScriptEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace script { namespace vba {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::vba::VBAScriptEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.script.vba.VBAScriptEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::vba::VBAScriptEvent const *) {
    return ::cppu::UnoType< ::css::script::vba::VBAScriptEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_VBA_VBASCRIPTEVENT_HPP
