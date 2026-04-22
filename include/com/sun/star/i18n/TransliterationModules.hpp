#ifndef INCLUDED_COM_SUN_STAR_I18N_TRANSLITERATIONMODULES_HPP
#define INCLUDED_COM_SUN_STAR_I18N_TRANSLITERATIONMODULES_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/TransliterationModules.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::TransliterationModules const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.i18n.TransliterationModules",
                                       ::css::i18n::TransliterationModules_UPPERCASE_LOWERCASE );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::TransliterationModules const *) {
    return ::cppu::UnoType< ::css::i18n::TransliterationModules >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_TRANSLITERATIONMODULES_HPP
