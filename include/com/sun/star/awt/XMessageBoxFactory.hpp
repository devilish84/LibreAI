#ifndef INCLUDED_COM_SUN_STAR_AWT_XMESSAGEBOXFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XMESSAGEBOXFACTORY_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XMessageBoxFactory.hdl"

#include "com/sun/star/awt/MessageBoxType.hpp"
#include "com/sun/star/awt/XMessageBox.hpp"
#include "com/sun/star/awt/XWindowPeer.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XMessageBoxFactory const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.XMessageBoxFactory", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::XMessageBoxFactory > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XMessageBoxFactory > >::get();
}

::css::uno::Type const & ::css::awt::XMessageBoxFactory::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::XMessageBoxFactory >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XMESSAGEBOXFACTORY_HPP
