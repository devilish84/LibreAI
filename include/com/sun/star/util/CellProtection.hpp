#ifndef INCLUDED_COM_SUN_STAR_UTIL_CELLPROTECTION_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_CELLPROTECTION_HPP

#include "sal/config.h"

#include "com/sun/star/util/CellProtection.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline CellProtection::CellProtection()
    : IsLocked(false)
    , IsFormulaHidden(false)
    , IsHidden(false)
    , IsPrintHidden(false)
{
}

inline CellProtection::CellProtection(const ::sal_Bool& IsLocked_, const ::sal_Bool& IsFormulaHidden_, const ::sal_Bool& IsHidden_, const ::sal_Bool& IsPrintHidden_)
    : IsLocked(IsLocked_)
    , IsFormulaHidden(IsFormulaHidden_)
    , IsHidden(IsHidden_)
    , IsPrintHidden(IsPrintHidden_)
{
}


inline bool operator==(const CellProtection& the_lhs, const CellProtection& the_rhs)
{
    return the_lhs.IsLocked == the_rhs.IsLocked
        && the_lhs.IsFormulaHidden == the_rhs.IsFormulaHidden
        && the_lhs.IsHidden == the_rhs.IsHidden
        && the_lhs.IsPrintHidden == the_rhs.IsPrintHidden;
}

inline bool operator!=(const CellProtection& the_lhs, const CellProtection& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::CellProtection const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.CellProtection", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::CellProtection const *) {
    return ::cppu::UnoType< ::css::util::CellProtection >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_CELLPROTECTION_HPP
