#ifndef INCLUDED_COM_SUN_STAR_UCB_FOLDERLISTENTRY_HPP
#define INCLUDED_COM_SUN_STAR_UCB_FOLDERLISTENTRY_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/FolderListEntry.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline FolderListEntry::FolderListEntry()
    : Title()
    , ID()
    , Subscribed(false)
    , New(false)
    , Removed(false)
    , Purge(false)
{
}

inline FolderListEntry::FolderListEntry(const ::rtl::OUString& Title_, const ::rtl::OUString& ID_, const ::sal_Bool& Subscribed_, const ::sal_Bool& New_, const ::sal_Bool& Removed_, const ::sal_Bool& Purge_)
    : Title(Title_)
    , ID(ID_)
    , Subscribed(Subscribed_)
    , New(New_)
    , Removed(Removed_)
    , Purge(Purge_)
{
}


inline bool operator==(const FolderListEntry& the_lhs, const FolderListEntry& the_rhs)
{
    return the_lhs.Title == the_rhs.Title
        && the_lhs.ID == the_rhs.ID
        && the_lhs.Subscribed == the_rhs.Subscribed
        && the_lhs.New == the_rhs.New
        && the_lhs.Removed == the_rhs.Removed
        && the_lhs.Purge == the_rhs.Purge;
}

inline bool operator!=(const FolderListEntry& the_lhs, const FolderListEntry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::FolderListEntry const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.FolderListEntry", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::FolderListEntry const *) {
    return ::cppu::UnoType< ::css::ucb::FolderListEntry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_FOLDERLISTENTRY_HPP
