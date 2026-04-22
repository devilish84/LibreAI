#ifndef INCLUDED_COM_SUN_STAR_I18N_FORMATELEMENT_HPP
#define INCLUDED_COM_SUN_STAR_I18N_FORMATELEMENT_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/FormatElement.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline FormatElement::FormatElement()
    : formatCode()
    , formatName()
    , formatKey()
    , formatType()
    , formatUsage()
    , formatIndex(0)
    , isDefault(false)
{
}

inline FormatElement::FormatElement(const ::rtl::OUString& formatCode_, const ::rtl::OUString& formatName_, const ::rtl::OUString& formatKey_, const ::rtl::OUString& formatType_, const ::rtl::OUString& formatUsage_, const ::sal_Int16& formatIndex_, const ::sal_Bool& isDefault_)
    : formatCode(formatCode_)
    , formatName(formatName_)
    , formatKey(formatKey_)
    , formatType(formatType_)
    , formatUsage(formatUsage_)
    , formatIndex(formatIndex_)
    , isDefault(isDefault_)
{
}


inline bool operator==(const FormatElement& the_lhs, const FormatElement& the_rhs)
{
    return the_lhs.formatCode == the_rhs.formatCode
        && the_lhs.formatName == the_rhs.formatName
        && the_lhs.formatKey == the_rhs.formatKey
        && the_lhs.formatType == the_rhs.formatType
        && the_lhs.formatUsage == the_rhs.formatUsage
        && the_lhs.formatIndex == the_rhs.formatIndex
        && the_lhs.isDefault == the_rhs.isDefault;
}

inline bool operator!=(const FormatElement& the_lhs, const FormatElement& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::FormatElement const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.FormatElement", 0, 7, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::FormatElement const *) {
    return ::cppu::UnoType< ::css::i18n::FormatElement >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_FORMATELEMENT_HPP
