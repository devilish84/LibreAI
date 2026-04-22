#ifndef INCLUDED_COM_SUN_STAR_CONNECTION_SOCKETPERMISSION_HPP
#define INCLUDED_COM_SUN_STAR_CONNECTION_SOCKETPERMISSION_HPP

#include "sal/config.h"

#include "com/sun/star/connection/SocketPermission.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace connection {

inline SocketPermission::SocketPermission()
    : Host()
    , Actions()
{
}

inline SocketPermission::SocketPermission(const ::rtl::OUString& Host_, const ::rtl::OUString& Actions_)
    : Host(Host_)
    , Actions(Actions_)
{
}


inline bool operator==(const SocketPermission& the_lhs, const SocketPermission& the_rhs)
{
    return the_lhs.Host == the_rhs.Host
        && the_lhs.Actions == the_rhs.Actions;
}

inline bool operator!=(const SocketPermission& the_lhs, const SocketPermission& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace connection { namespace detail {

struct theSocketPermissionType : public rtl::StaticWithInit< ::css::uno::Type *, theSocketPermissionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.connection.SocketPermission" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Host" );
        ::rtl::OUString the_name1( "Actions" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace connection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::connection::SocketPermission const *) {
    return *detail::theSocketPermissionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::connection::SocketPermission const *) {
    return ::cppu::UnoType< ::css::connection::SocketPermission >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONNECTION_SOCKETPERMISSION_HPP
