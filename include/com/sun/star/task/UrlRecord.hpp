#ifndef INCLUDED_COM_SUN_STAR_TASK_URLRECORD_HPP
#define INCLUDED_COM_SUN_STAR_TASK_URLRECORD_HPP

#include "sal/config.h"

#include "com/sun/star/task/UrlRecord.hdl"

#include "com/sun/star/task/UserRecord.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace task {

inline UrlRecord::UrlRecord()
    : Url()
    , UserList()
{
}

inline UrlRecord::UrlRecord(const ::rtl::OUString& Url_, const ::css::uno::Sequence< ::css::task::UserRecord >& UserList_)
    : Url(Url_)
    , UserList(UserList_)
{
}


inline bool operator==(const UrlRecord& the_lhs, const UrlRecord& the_rhs)
{
    return the_lhs.Url == the_rhs.Url
        && the_lhs.UserList == the_rhs.UserList;
}

inline bool operator!=(const UrlRecord& the_lhs, const UrlRecord& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::UrlRecord const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::task::UserRecord > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.task.UrlRecord", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::task::UrlRecord const *) {
    return ::cppu::UnoType< ::css::task::UrlRecord >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_URLRECORD_HPP
