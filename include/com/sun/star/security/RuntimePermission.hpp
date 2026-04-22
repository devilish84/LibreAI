#ifndef INCLUDED_COM_SUN_STAR_SECURITY_RUNTIMEPERMISSION_HPP
#define INCLUDED_COM_SUN_STAR_SECURITY_RUNTIMEPERMISSION_HPP

#include "sal/config.h"

#include "com/sun/star/security/RuntimePermission.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace security {

inline RuntimePermission::RuntimePermission()
    : Name()
{
}

inline RuntimePermission::RuntimePermission(const ::rtl::OUString& Name_)
    : Name(Name_)
{
}


inline bool operator==(const RuntimePermission& the_lhs, const RuntimePermission& the_rhs)
{
    return the_lhs.Name == the_rhs.Name;
}

inline bool operator!=(const RuntimePermission& the_lhs, const RuntimePermission& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace security { namespace detail {

struct theRuntimePermissionType : public rtl::StaticWithInit< ::css::uno::Type *, theRuntimePermissionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.security.RuntimePermission" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Name" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace security {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::security::RuntimePermission const *) {
    return *detail::theRuntimePermissionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::security::RuntimePermission const *) {
    return ::cppu::UnoType< ::css::security::RuntimePermission >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SECURITY_RUNTIMEPERMISSION_HPP
