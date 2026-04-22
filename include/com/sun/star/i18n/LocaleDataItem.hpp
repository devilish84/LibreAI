#ifndef INCLUDED_COM_SUN_STAR_I18N_LOCALEDATAITEM_HPP
#define INCLUDED_COM_SUN_STAR_I18N_LOCALEDATAITEM_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/LocaleDataItem.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline LocaleDataItem::LocaleDataItem()
    : unoID()
    , dateSeparator()
    , thousandSeparator()
    , decimalSeparator()
    , timeSeparator()
    , time100SecSeparator()
    , listSeparator()
    , quotationStart()
    , quotationEnd()
    , doubleQuotationStart()
    , doubleQuotationEnd()
    , timeAM()
    , timePM()
    , measurementSystem()
    , LongDateDayOfWeekSeparator()
    , LongDateDaySeparator()
    , LongDateMonthSeparator()
    , LongDateYearSeparator()
{
}

inline LocaleDataItem::LocaleDataItem(const ::rtl::OUString& unoID_, const ::rtl::OUString& dateSeparator_, const ::rtl::OUString& thousandSeparator_, const ::rtl::OUString& decimalSeparator_, const ::rtl::OUString& timeSeparator_, const ::rtl::OUString& time100SecSeparator_, const ::rtl::OUString& listSeparator_, const ::rtl::OUString& quotationStart_, const ::rtl::OUString& quotationEnd_, const ::rtl::OUString& doubleQuotationStart_, const ::rtl::OUString& doubleQuotationEnd_, const ::rtl::OUString& timeAM_, const ::rtl::OUString& timePM_, const ::rtl::OUString& measurementSystem_, const ::rtl::OUString& LongDateDayOfWeekSeparator_, const ::rtl::OUString& LongDateDaySeparator_, const ::rtl::OUString& LongDateMonthSeparator_, const ::rtl::OUString& LongDateYearSeparator_)
    : unoID(unoID_)
    , dateSeparator(dateSeparator_)
    , thousandSeparator(thousandSeparator_)
    , decimalSeparator(decimalSeparator_)
    , timeSeparator(timeSeparator_)
    , time100SecSeparator(time100SecSeparator_)
    , listSeparator(listSeparator_)
    , quotationStart(quotationStart_)
    , quotationEnd(quotationEnd_)
    , doubleQuotationStart(doubleQuotationStart_)
    , doubleQuotationEnd(doubleQuotationEnd_)
    , timeAM(timeAM_)
    , timePM(timePM_)
    , measurementSystem(measurementSystem_)
    , LongDateDayOfWeekSeparator(LongDateDayOfWeekSeparator_)
    , LongDateDaySeparator(LongDateDaySeparator_)
    , LongDateMonthSeparator(LongDateMonthSeparator_)
    , LongDateYearSeparator(LongDateYearSeparator_)
{
}


inline bool operator==(const LocaleDataItem& the_lhs, const LocaleDataItem& the_rhs)
{
    return the_lhs.unoID == the_rhs.unoID
        && the_lhs.dateSeparator == the_rhs.dateSeparator
        && the_lhs.thousandSeparator == the_rhs.thousandSeparator
        && the_lhs.decimalSeparator == the_rhs.decimalSeparator
        && the_lhs.timeSeparator == the_rhs.timeSeparator
        && the_lhs.time100SecSeparator == the_rhs.time100SecSeparator
        && the_lhs.listSeparator == the_rhs.listSeparator
        && the_lhs.quotationStart == the_rhs.quotationStart
        && the_lhs.quotationEnd == the_rhs.quotationEnd
        && the_lhs.doubleQuotationStart == the_rhs.doubleQuotationStart
        && the_lhs.doubleQuotationEnd == the_rhs.doubleQuotationEnd
        && the_lhs.timeAM == the_rhs.timeAM
        && the_lhs.timePM == the_rhs.timePM
        && the_lhs.measurementSystem == the_rhs.measurementSystem
        && the_lhs.LongDateDayOfWeekSeparator == the_rhs.LongDateDayOfWeekSeparator
        && the_lhs.LongDateDaySeparator == the_rhs.LongDateDaySeparator
        && the_lhs.LongDateMonthSeparator == the_rhs.LongDateMonthSeparator
        && the_lhs.LongDateYearSeparator == the_rhs.LongDateYearSeparator;
}

inline bool operator!=(const LocaleDataItem& the_lhs, const LocaleDataItem& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::LocaleDataItem const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.LocaleDataItem", 0, 18, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::LocaleDataItem const *) {
    return ::cppu::UnoType< ::css::i18n::LocaleDataItem >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_LOCALEDATAITEM_HPP
