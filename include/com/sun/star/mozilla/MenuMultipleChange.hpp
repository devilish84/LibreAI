#ifndef INCLUDED_COM_SUN_STAR_MOZILLA_MENUMULTIPLECHANGE_HPP
#define INCLUDED_COM_SUN_STAR_MOZILLA_MENUMULTIPLECHANGE_HPP

#include "sal/config.h"

#include "com/sun/star/mozilla/MenuMultipleChange.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace mozilla {

inline MenuMultipleChange::MenuMultipleChange()
    : ID(0)
    , GroupID(0)
    , PreItemID(0)
    , ItemText()
    , IsVisible(false)
    , IsActive(false)
    , IsCheckable(false)
    , IsChecked(false)
    , Image()
{
}

inline MenuMultipleChange::MenuMultipleChange(const ::sal_Int16& ID_, const ::sal_Int16& GroupID_, const ::sal_Int16& PreItemID_, const ::rtl::OUString& ItemText_, const ::sal_Bool& IsVisible_, const ::sal_Bool& IsActive_, const ::sal_Bool& IsCheckable_, const ::sal_Bool& IsChecked_, const ::css::uno::Sequence< ::sal_Int8 >& Image_)
    : ID(ID_)
    , GroupID(GroupID_)
    , PreItemID(PreItemID_)
    , ItemText(ItemText_)
    , IsVisible(IsVisible_)
    , IsActive(IsActive_)
    , IsCheckable(IsCheckable_)
    , IsChecked(IsChecked_)
    , Image(Image_)
{
}


inline bool operator==(const MenuMultipleChange& the_lhs, const MenuMultipleChange& the_rhs)
{
    return the_lhs.ID == the_rhs.ID
        && the_lhs.GroupID == the_rhs.GroupID
        && the_lhs.PreItemID == the_rhs.PreItemID
        && the_lhs.ItemText == the_rhs.ItemText
        && the_lhs.IsVisible == the_rhs.IsVisible
        && the_lhs.IsActive == the_rhs.IsActive
        && the_lhs.IsCheckable == the_rhs.IsCheckable
        && the_lhs.IsChecked == the_rhs.IsChecked
        && the_lhs.Image == the_rhs.Image;
}

inline bool operator!=(const MenuMultipleChange& the_lhs, const MenuMultipleChange& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace mozilla {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::mozilla::MenuMultipleChange const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int8 > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.mozilla.MenuMultipleChange", 0, 9, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::mozilla::MenuMultipleChange const *) {
    return ::cppu::UnoType< ::css::mozilla::MenuMultipleChange >::get();
}

#endif // INCLUDED_COM_SUN_STAR_MOZILLA_MENUMULTIPLECHANGE_HPP
