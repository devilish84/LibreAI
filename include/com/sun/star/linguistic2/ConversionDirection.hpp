#ifndef INCLUDED_COM_SUN_STAR_LINGUISTIC2_CONVERSIONDIRECTION_HPP
#define INCLUDED_COM_SUN_STAR_LINGUISTIC2_CONVERSIONDIRECTION_HPP

#include "sal/config.h"

#include "com/sun/star/linguistic2/ConversionDirection.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace linguistic2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::linguistic2::ConversionDirection const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.linguistic2.ConversionDirection",
                                       ::css::linguistic2::ConversionDirection_FROM_LEFT );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::linguistic2::ConversionDirection const *) {
    return ::cppu::UnoType< ::css::linguistic2::ConversionDirection >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LINGUISTIC2_CONVERSIONDIRECTION_HPP
