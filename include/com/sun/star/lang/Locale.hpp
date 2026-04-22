#ifndef INCLUDED_COM_SUN_STAR_LANG_LOCALE_HPP
#define INCLUDED_COM_SUN_STAR_LANG_LOCALE_HPP

#include "sal/config.h"

#include "com/sun/star/lang/Locale.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace lang {

inline Locale::Locale()
    : Language()
    , Country()
    , Variant()
{
}

inline Locale::Locale(const ::rtl::OUString& Language_, const ::rtl::OUString& Country_, const ::rtl::OUString& Variant_)
    : Language(Language_)
    , Country(Country_)
    , Variant(Variant_)
{
}


inline bool operator==(const Locale& the_lhs, const Locale& the_rhs)
{
    return the_lhs.Language == the_rhs.Language
        && the_lhs.Country == the_rhs.Country
        && the_lhs.Variant == the_rhs.Variant;
}

inline bool operator!=(const Locale& the_lhs, const Locale& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace lang {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::lang::Locale const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.lang.Locale", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::lang::Locale const *) {
    return ::cppu::UnoType< ::css::lang::Locale >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LANG_LOCALE_HPP
