#ifndef INCLUDED_COM_SUN_STAR_I18N_CURRENCY2_HPP
#define INCLUDED_COM_SUN_STAR_I18N_CURRENCY2_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/Currency2.hdl"

#include "com/sun/star/i18n/Currency.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline Currency2::Currency2()
    : ::css::i18n::Currency()
    , LegacyOnly(false)
{
}

inline Currency2::Currency2(const ::rtl::OUString& ID_, const ::rtl::OUString& Symbol_, const ::rtl::OUString& BankSymbol_, const ::rtl::OUString& Name_, const ::sal_Bool& Default_, const ::sal_Bool& UsedInCompatibleFormatCodes_, const ::sal_Int16& DecimalPlaces_, const ::sal_Bool& LegacyOnly_)
    : ::css::i18n::Currency(ID_, Symbol_, BankSymbol_, Name_, Default_, UsedInCompatibleFormatCodes_, DecimalPlaces_)
    , LegacyOnly(LegacyOnly_)
{
}


inline bool operator==(const Currency2& the_lhs, const Currency2& the_rhs)
{
    return operator==( static_cast< ::css::i18n::Currency>(the_lhs), static_cast< ::css::i18n::Currency>(the_rhs) )

        && the_lhs.LegacyOnly == the_rhs.LegacyOnly;
}

inline bool operator!=(const Currency2& the_lhs, const Currency2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::Currency2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.Currency2", ::cppu::UnoType< ::css::i18n::Currency >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::Currency2 const *) {
    return ::cppu::UnoType< ::css::i18n::Currency2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_CURRENCY2_HPP
