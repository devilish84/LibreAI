#ifndef INCLUDED_COM_SUN_STAR_GRAPHIC_XGRAPHICRASTERIZER_HPP
#define INCLUDED_COM_SUN_STAR_GRAPHIC_XGRAPHICRASTERIZER_HPP

#include "sal/config.h"

#include "com/sun/star/graphic/XGraphicRasterizer.hdl"

#include "com/sun/star/awt/Size.hpp"
#include "com/sun/star/beans/PropertyValues.hpp"
#include "com/sun/star/graphic/XGraphic.hpp"
#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace graphic {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::graphic::XGraphicRasterizer const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.graphic.XGraphicRasterizer", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::graphic::XGraphicRasterizer > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::graphic::XGraphicRasterizer > >::get();
}

::css::uno::Type const & ::css::graphic::XGraphicRasterizer::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::graphic::XGraphicRasterizer >::get();
}

#endif // INCLUDED_COM_SUN_STAR_GRAPHIC_XGRAPHICRASTERIZER_HPP
