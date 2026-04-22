#ifndef INCLUDED_COM_SUN_STAR_AWT_RASTEROPERATION_HPP
#define INCLUDED_COM_SUN_STAR_AWT_RASTEROPERATION_HPP

#include "sal/config.h"

#include "com/sun/star/awt/RasterOperation.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::RasterOperation const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.awt.RasterOperation",
                                       ::css::awt::RasterOperation_OVERPAINT );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::RasterOperation const *) {
    return ::cppu::UnoType< ::css::awt::RasterOperation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_RASTEROPERATION_HPP
