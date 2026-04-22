#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_MODULEINFO_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_MODULEINFO_HPP

#include "sal/config.h"

#include "com/sun/star/script/ModuleInfo.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace script {

inline ModuleInfo::ModuleInfo()
    : ModuleObject()
    , ModuleType(0)
{
}

inline ModuleInfo::ModuleInfo(const ::css::uno::Reference< ::css::uno::XInterface >& ModuleObject_, const ::sal_Int32& ModuleType_)
    : ModuleObject(ModuleObject_)
    , ModuleType(ModuleType_)
{
}


inline bool operator==(const ModuleInfo& the_lhs, const ModuleInfo& the_rhs)
{
    return the_lhs.ModuleObject == the_rhs.ModuleObject
        && the_lhs.ModuleType == the_rhs.ModuleType;
}

inline bool operator!=(const ModuleInfo& the_lhs, const ModuleInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::ModuleInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.script.ModuleInfo", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::ModuleInfo const *) {
    return ::cppu::UnoType< ::css::script::ModuleInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_MODULEINFO_HPP
