#ifndef INCLUDED_COM_SUN_STAR_MOZILLA_MENUSINGLECHANGE_HPP
#define INCLUDED_COM_SUN_STAR_MOZILLA_MENUSINGLECHANGE_HPP

#include "sal/config.h"

#include "com/sun/star/mozilla/MenuSingleChange.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace mozilla {

inline MenuSingleChange::MenuSingleChange()
    : ID(0)
    , ChangeID(0)
    , Change()
{
}

inline MenuSingleChange::MenuSingleChange(const ::sal_Int16& ID_, const ::sal_Int16& ChangeID_, const ::css::uno::Any& Change_)
    : ID(ID_)
    , ChangeID(ChangeID_)
    , Change(Change_)
{
}


inline bool operator==(const MenuSingleChange& the_lhs, const MenuSingleChange& the_rhs)
{
    return the_lhs.ID == the_rhs.ID
        && the_lhs.ChangeID == the_rhs.ChangeID
        && the_lhs.Change == the_rhs.Change;
}

inline bool operator!=(const MenuSingleChange& the_lhs, const MenuSingleChange& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace mozilla {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::mozilla::MenuSingleChange const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.mozilla.MenuSingleChange", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::mozilla::MenuSingleChange const *) {
    return ::cppu::UnoType< ::css::mozilla::MenuSingleChange >::get();
}

#endif // INCLUDED_COM_SUN_STAR_MOZILLA_MENUSINGLECHANGE_HPP
