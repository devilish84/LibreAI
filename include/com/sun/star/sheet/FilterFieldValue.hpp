#ifndef INCLUDED_COM_SUN_STAR_SHEET_FILTERFIELDVALUE_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_FILTERFIELDVALUE_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/FilterFieldValue.hdl"

#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline FilterFieldValue::FilterFieldValue()
    : IsNumeric(false)
    , NumericValue(0)
    , StringValue()
    , FilterType(0)
    , ColorValue(0)
{
}

inline FilterFieldValue::FilterFieldValue(const ::sal_Bool& IsNumeric_, const double& NumericValue_, const ::rtl::OUString& StringValue_, const ::sal_Int32& FilterType_, const ::sal_Int32& ColorValue_)
    : IsNumeric(IsNumeric_)
    , NumericValue(NumericValue_)
    , StringValue(StringValue_)
    , FilterType(FilterType_)
    , ColorValue(ColorValue_)
{
}


inline bool operator==(const FilterFieldValue& the_lhs, const FilterFieldValue& the_rhs)
{
    return the_lhs.IsNumeric == the_rhs.IsNumeric
        && the_lhs.NumericValue == the_rhs.NumericValue
        && the_lhs.StringValue == the_rhs.StringValue
        && the_lhs.FilterType == the_rhs.FilterType
        && the_lhs.ColorValue == the_rhs.ColorValue;
}

inline bool operator!=(const FilterFieldValue& the_lhs, const FilterFieldValue& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::FilterFieldValue const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.FilterFieldValue", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::FilterFieldValue const *) {
    return ::cppu::UnoType< ::css::sheet::FilterFieldValue >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_FILTERFIELDVALUE_HPP
