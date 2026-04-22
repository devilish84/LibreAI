#ifndef INCLUDED_COM_SUN_STAR_AWT_XTOPWINDOW_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XTOPWINDOW_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XTopWindow.hdl"

#include "com/sun/star/awt/XMenuBar.hpp"
#include "com/sun/star/awt/XTopWindowListener.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XTopWindow const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.XTopWindow", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::XTopWindow > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XTopWindow > >::get();
}

::css::uno::Type const & ::css::awt::XTopWindow::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::XTopWindow >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XTOPWINDOW_HPP
