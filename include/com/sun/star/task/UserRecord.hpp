#ifndef INCLUDED_COM_SUN_STAR_TASK_USERRECORD_HPP
#define INCLUDED_COM_SUN_STAR_TASK_USERRECORD_HPP

#include "sal/config.h"

#include "com/sun/star/task/UserRecord.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace task {

inline UserRecord::UserRecord()
    : UserName()
    , Passwords()
{
}

inline UserRecord::UserRecord(const ::rtl::OUString& UserName_, const ::css::uno::Sequence< ::rtl::OUString >& Passwords_)
    : UserName(UserName_)
    , Passwords(Passwords_)
{
}


inline bool operator==(const UserRecord& the_lhs, const UserRecord& the_rhs)
{
    return the_lhs.UserName == the_rhs.UserName
        && the_lhs.Passwords == the_rhs.Passwords;
}

inline bool operator!=(const UserRecord& the_lhs, const UserRecord& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::UserRecord const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.task.UserRecord", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::task::UserRecord const *) {
    return ::cppu::UnoType< ::css::task::UserRecord >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_USERRECORD_HPP
