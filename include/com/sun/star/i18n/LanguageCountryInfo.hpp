#ifndef INCLUDED_COM_SUN_STAR_I18N_LANGUAGECOUNTRYINFO_HPP
#define INCLUDED_COM_SUN_STAR_I18N_LANGUAGECOUNTRYINFO_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/LanguageCountryInfo.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline LanguageCountryInfo::LanguageCountryInfo()
    : Language()
    , LanguageDefaultName()
    , Country()
    , CountryDefaultName()
    , Variant()
{
}

inline LanguageCountryInfo::LanguageCountryInfo(const ::rtl::OUString& Language_, const ::rtl::OUString& LanguageDefaultName_, const ::rtl::OUString& Country_, const ::rtl::OUString& CountryDefaultName_, const ::rtl::OUString& Variant_)
    : Language(Language_)
    , LanguageDefaultName(LanguageDefaultName_)
    , Country(Country_)
    , CountryDefaultName(CountryDefaultName_)
    , Variant(Variant_)
{
}


inline bool operator==(const LanguageCountryInfo& the_lhs, const LanguageCountryInfo& the_rhs)
{
    return the_lhs.Language == the_rhs.Language
        && the_lhs.LanguageDefaultName == the_rhs.LanguageDefaultName
        && the_lhs.Country == the_rhs.Country
        && the_lhs.CountryDefaultName == the_rhs.CountryDefaultName
        && the_lhs.Variant == the_rhs.Variant;
}

inline bool operator!=(const LanguageCountryInfo& the_lhs, const LanguageCountryInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::LanguageCountryInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.LanguageCountryInfo", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::LanguageCountryInfo const *) {
    return ::cppu::UnoType< ::css::i18n::LanguageCountryInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_LANGUAGECOUNTRYINFO_HPP
