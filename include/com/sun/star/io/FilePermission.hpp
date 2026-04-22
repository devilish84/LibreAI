#ifndef INCLUDED_COM_SUN_STAR_IO_FILEPERMISSION_HPP
#define INCLUDED_COM_SUN_STAR_IO_FILEPERMISSION_HPP

#include "sal/config.h"

#include "com/sun/star/io/FilePermission.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace io {

inline FilePermission::FilePermission()
    : URL()
    , Actions()
{
}

inline FilePermission::FilePermission(const ::rtl::OUString& URL_, const ::rtl::OUString& Actions_)
    : URL(URL_)
    , Actions(Actions_)
{
}


inline bool operator==(const FilePermission& the_lhs, const FilePermission& the_rhs)
{
    return the_lhs.URL == the_rhs.URL
        && the_lhs.Actions == the_rhs.Actions;
}

inline bool operator!=(const FilePermission& the_lhs, const FilePermission& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace io { namespace detail {

struct theFilePermissionType : public rtl::StaticWithInit< ::css::uno::Type *, theFilePermissionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.io.FilePermission" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "URL" );
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

namespace com { namespace sun { namespace star { namespace io {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::FilePermission const *) {
    return *detail::theFilePermissionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::io::FilePermission const *) {
    return ::cppu::UnoType< ::css::io::FilePermission >::get();
}

#endif // INCLUDED_COM_SUN_STAR_IO_FILEPERMISSION_HPP
