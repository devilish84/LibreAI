#ifndef INCLUDED_COM_SUN_STAR_UCB_FOLDERLIST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_FOLDERLIST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/FolderList.hdl"

#include "com/sun/star/ucb/FolderListCommand.hpp"
#include "com/sun/star/ucb/FolderListEntry.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline FolderList::FolderList()
    : Command(::css::ucb::FolderListCommand_GET)
    , List()
{
}

inline FolderList::FolderList(const ::css::ucb::FolderListCommand& Command_, const ::css::uno::Sequence< ::css::ucb::FolderListEntry >& List_)
    : Command(Command_)
    , List(List_)
{
}


inline bool operator==(const FolderList& the_lhs, const FolderList& the_rhs)
{
    return the_lhs.Command == the_rhs.Command
        && the_lhs.List == the_rhs.List;
}

inline bool operator!=(const FolderList& the_lhs, const FolderList& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::FolderList const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::ucb::FolderListCommand >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::FolderListEntry > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.FolderList", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::FolderList const *) {
    return ::cppu::UnoType< ::css::ucb::FolderList >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_FOLDERLIST_HPP
