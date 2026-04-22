#ifndef INCLUDED_COM_SUN_STAR_I18N_NATIVENUMBERXMLATTRIBUTES_HPP
#define INCLUDED_COM_SUN_STAR_I18N_NATIVENUMBERXMLATTRIBUTES_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/NativeNumberXmlAttributes.hdl"

#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline NativeNumberXmlAttributes::NativeNumberXmlAttributes()
    : Locale()
    , Format()
    , Style()
{
}

inline NativeNumberXmlAttributes::NativeNumberXmlAttributes(const ::css::lang::Locale& Locale_, const ::rtl::OUString& Format_, const ::rtl::OUString& Style_)
    : Locale(Locale_)
    , Format(Format_)
    , Style(Style_)
{
}


inline bool operator==(const NativeNumberXmlAttributes& the_lhs, const NativeNumberXmlAttributes& the_rhs)
{
    return the_lhs.Locale == the_rhs.Locale
        && the_lhs.Format == the_rhs.Format
        && the_lhs.Style == the_rhs.Style;
}

inline bool operator!=(const NativeNumberXmlAttributes& the_lhs, const NativeNumberXmlAttributes& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::NativeNumberXmlAttributes const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::lang::Locale >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.NativeNumberXmlAttributes", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::NativeNumberXmlAttributes const *) {
    return ::cppu::UnoType< ::css::i18n::NativeNumberXmlAttributes >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_NATIVENUMBERXMLATTRIBUTES_HPP
