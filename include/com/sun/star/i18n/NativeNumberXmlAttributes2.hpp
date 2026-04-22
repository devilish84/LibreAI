#ifndef INCLUDED_COM_SUN_STAR_I18N_NATIVENUMBERXMLATTRIBUTES2_HPP
#define INCLUDED_COM_SUN_STAR_I18N_NATIVENUMBERXMLATTRIBUTES2_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/NativeNumberXmlAttributes2.hdl"

#include "com/sun/star/i18n/NativeNumberXmlAttributes.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline NativeNumberXmlAttributes2::NativeNumberXmlAttributes2()
    : ::css::i18n::NativeNumberXmlAttributes()
    , Spellout()
{
}

inline NativeNumberXmlAttributes2::NativeNumberXmlAttributes2(const ::css::lang::Locale& Locale_, const ::rtl::OUString& Format_, const ::rtl::OUString& Style_, const ::rtl::OUString& Spellout_)
    : ::css::i18n::NativeNumberXmlAttributes(Locale_, Format_, Style_)
    , Spellout(Spellout_)
{
}


inline bool operator==(const NativeNumberXmlAttributes2& the_lhs, const NativeNumberXmlAttributes2& the_rhs)
{
    return operator==( static_cast< ::css::i18n::NativeNumberXmlAttributes>(the_lhs), static_cast< ::css::i18n::NativeNumberXmlAttributes>(the_rhs) )

        && the_lhs.Spellout == the_rhs.Spellout;
}

inline bool operator!=(const NativeNumberXmlAttributes2& the_lhs, const NativeNumberXmlAttributes2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::NativeNumberXmlAttributes2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.NativeNumberXmlAttributes2", ::cppu::UnoType< ::css::i18n::NativeNumberXmlAttributes >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::NativeNumberXmlAttributes2 const *) {
    return ::cppu::UnoType< ::css::i18n::NativeNumberXmlAttributes2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_NATIVENUMBERXMLATTRIBUTES2_HPP
