#ifndef INCLUDED_COM_SUN_STAR_I18N_CURRENCY_HPP
#define INCLUDED_COM_SUN_STAR_I18N_CURRENCY_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/Currency.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline Currency::Currency()
    : ID()
    , Symbol()
    , BankSymbol()
    , Name()
    , Default(false)
    , UsedInCompatibleFormatCodes(false)
    , DecimalPlaces(0)
{
}

inline Currency::Currency(const ::rtl::OUString& ID_, const ::rtl::OUString& Symbol_, const ::rtl::OUString& BankSymbol_, const ::rtl::OUString& Name_, const ::sal_Bool& Default_, const ::sal_Bool& UsedInCompatibleFormatCodes_, const ::sal_Int16& DecimalPlaces_)
    : ID(ID_)
    , Symbol(Symbol_)
    , BankSymbol(BankSymbol_)
    , Name(Name_)
    , Default(Default_)
    , UsedInCompatibleFormatCodes(UsedInCompatibleFormatCodes_)
    , DecimalPlaces(DecimalPlaces_)
{
}


inline bool operator==(const Currency& the_lhs, const Currency& the_rhs)
{
    return the_lhs.ID == the_rhs.ID
        && the_lhs.Symbol == the_rhs.Symbol
        && the_lhs.BankSymbol == the_rhs.BankSymbol
        && the_lhs.Name == the_rhs.Name
        && the_lhs.Default == the_rhs.Default
        && the_lhs.UsedInCompatibleFormatCodes == the_rhs.UsedInCompatibleFormatCodes
        && the_lhs.DecimalPlaces == the_rhs.DecimalPlaces;
}

inline bool operator!=(const Currency& the_lhs, const Currency& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::Currency const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.Currency", 0, 7, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::Currency const *) {
    return ::cppu::UnoType< ::css::i18n::Currency >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_CURRENCY_HPP
