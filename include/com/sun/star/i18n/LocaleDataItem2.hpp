#ifndef INCLUDED_COM_SUN_STAR_I18N_LOCALEDATAITEM2_HPP
#define INCLUDED_COM_SUN_STAR_I18N_LOCALEDATAITEM2_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/LocaleDataItem2.hdl"

#include "com/sun/star/i18n/LocaleDataItem.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline LocaleDataItem2::LocaleDataItem2()
    : ::css::i18n::LocaleDataItem()
    , decimalSeparatorAlternative()
{
}

inline LocaleDataItem2::LocaleDataItem2(const ::rtl::OUString& unoID_, const ::rtl::OUString& dateSeparator_, const ::rtl::OUString& thousandSeparator_, const ::rtl::OUString& decimalSeparator_, const ::rtl::OUString& timeSeparator_, const ::rtl::OUString& time100SecSeparator_, const ::rtl::OUString& listSeparator_, const ::rtl::OUString& quotationStart_, const ::rtl::OUString& quotationEnd_, const ::rtl::OUString& doubleQuotationStart_, const ::rtl::OUString& doubleQuotationEnd_, const ::rtl::OUString& timeAM_, const ::rtl::OUString& timePM_, const ::rtl::OUString& measurementSystem_, const ::rtl::OUString& LongDateDayOfWeekSeparator_, const ::rtl::OUString& LongDateDaySeparator_, const ::rtl::OUString& LongDateMonthSeparator_, const ::rtl::OUString& LongDateYearSeparator_, const ::rtl::OUString& decimalSeparatorAlternative_)
    : ::css::i18n::LocaleDataItem(unoID_, dateSeparator_, thousandSeparator_, decimalSeparator_, timeSeparator_, time100SecSeparator_, listSeparator_, quotationStart_, quotationEnd_, doubleQuotationStart_, doubleQuotationEnd_, timeAM_, timePM_, measurementSystem_, LongDateDayOfWeekSeparator_, LongDateDaySeparator_, LongDateMonthSeparator_, LongDateYearSeparator_)
    , decimalSeparatorAlternative(decimalSeparatorAlternative_)
{
}


inline bool operator==(const LocaleDataItem2& the_lhs, const LocaleDataItem2& the_rhs)
{
    return operator==( static_cast< ::css::i18n::LocaleDataItem>(the_lhs), static_cast< ::css::i18n::LocaleDataItem>(the_rhs) )

        && the_lhs.decimalSeparatorAlternative == the_rhs.decimalSeparatorAlternative;
}

inline bool operator!=(const LocaleDataItem2& the_lhs, const LocaleDataItem2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::LocaleDataItem2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.LocaleDataItem2", ::cppu::UnoType< ::css::i18n::LocaleDataItem >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::LocaleDataItem2 const *) {
    return ::cppu::UnoType< ::css::i18n::LocaleDataItem2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_LOCALEDATAITEM2_HPP
