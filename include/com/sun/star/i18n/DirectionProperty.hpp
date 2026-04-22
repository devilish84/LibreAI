#ifndef INCLUDED_COM_SUN_STAR_I18N_DIRECTIONPROPERTY_HPP
#define INCLUDED_COM_SUN_STAR_I18N_DIRECTIONPROPERTY_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/DirectionProperty.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::DirectionProperty const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.i18n.DirectionProperty",
                                       ::css::i18n::DirectionProperty_LEFT_TO_RIGHT );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::DirectionProperty const *) {
    return ::cppu::UnoType< ::css::i18n::DirectionProperty >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_DIRECTIONPROPERTY_HPP
