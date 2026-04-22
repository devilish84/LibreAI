#ifndef INCLUDED_COM_SUN_STAR_AWT_XEXTENDEDTOOLKIT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XEXTENDEDTOOLKIT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XExtendedToolkit.hdl"

#include "com/sun/star/awt/XFocusListener.hpp"
#include "com/sun/star/awt/XKeyHandler.hpp"
#include "com/sun/star/awt/XTopWindow.hpp"
#include "com/sun/star/awt/XTopWindowListener.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XExtendedToolkit const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.XExtendedToolkit", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::XExtendedToolkit > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XExtendedToolkit > >::get();
}

::css::uno::Type const & ::css::awt::XExtendedToolkit::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::XExtendedToolkit >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XEXTENDEDTOOLKIT_HPP
