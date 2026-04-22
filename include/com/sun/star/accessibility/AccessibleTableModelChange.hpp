#ifndef INCLUDED_COM_SUN_STAR_ACCESSIBILITY_ACCESSIBLETABLEMODELCHANGE_HPP
#define INCLUDED_COM_SUN_STAR_ACCESSIBILITY_ACCESSIBLETABLEMODELCHANGE_HPP

#include "sal/config.h"

#include "com/sun/star/accessibility/AccessibleTableModelChange.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace accessibility {

inline AccessibleTableModelChange::AccessibleTableModelChange()
    : Type(0)
    , FirstRow(0)
    , LastRow(0)
    , FirstColumn(0)
    , LastColumn(0)
{
}

inline AccessibleTableModelChange::AccessibleTableModelChange(const ::sal_Int16& Type_, const ::sal_Int32& FirstRow_, const ::sal_Int32& LastRow_, const ::sal_Int32& FirstColumn_, const ::sal_Int32& LastColumn_)
    : Type(Type_)
    , FirstRow(FirstRow_)
    , LastRow(LastRow_)
    , FirstColumn(FirstColumn_)
    , LastColumn(LastColumn_)
{
}


inline bool operator==(const AccessibleTableModelChange& the_lhs, const AccessibleTableModelChange& the_rhs)
{
    return the_lhs.Type == the_rhs.Type
        && the_lhs.FirstRow == the_rhs.FirstRow
        && the_lhs.LastRow == the_rhs.LastRow
        && the_lhs.FirstColumn == the_rhs.FirstColumn
        && the_lhs.LastColumn == the_rhs.LastColumn;
}

inline bool operator!=(const AccessibleTableModelChange& the_lhs, const AccessibleTableModelChange& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace accessibility {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::accessibility::AccessibleTableModelChange const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.accessibility.AccessibleTableModelChange", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::accessibility::AccessibleTableModelChange const *) {
    return ::cppu::UnoType< ::css::accessibility::AccessibleTableModelChange >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ACCESSIBILITY_ACCESSIBLETABLEMODELCHANGE_HPP
