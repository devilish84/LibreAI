#ifndef INCLUDED_COM_SUN_STAR_UCB_LISTACTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_LISTACTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ListAction.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ListAction::ListAction()
    : Position(0)
    , Count(0)
    , ListActionType(0)
    , ActionInfo()
{
}

inline ListAction::ListAction(const ::sal_Int32& Position_, const ::sal_Int32& Count_, const ::sal_Int32& ListActionType_, const ::css::uno::Any& ActionInfo_)
    : Position(Position_)
    , Count(Count_)
    , ListActionType(ListActionType_)
    , ActionInfo(ActionInfo_)
{
}


inline bool operator==(const ListAction& the_lhs, const ListAction& the_rhs)
{
    return the_lhs.Position == the_rhs.Position
        && the_lhs.Count == the_rhs.Count
        && the_lhs.ListActionType == the_rhs.ListActionType
        && the_lhs.ActionInfo == the_rhs.ActionInfo;
}

inline bool operator!=(const ListAction& the_lhs, const ListAction& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ListAction const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.ListAction", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ListAction const *) {
    return ::cppu::UnoType< ::css::ucb::ListAction >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_LISTACTION_HPP
