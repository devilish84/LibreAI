#ifndef INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_XPANE_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_XPANE_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/framework/XPane.hdl"

#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/drawing/framework/XResource.hpp"
#include "com/sun/star/rendering/XCanvas.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing { namespace framework {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::framework::XPane const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::framework::XResource > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.framework.XPane", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::framework::XPane > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::framework::XPane > >::get();
}

::css::uno::Type const & ::css::drawing::framework::XPane::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::framework::XPane >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_XPANE_HPP
