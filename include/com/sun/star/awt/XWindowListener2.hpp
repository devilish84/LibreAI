#ifndef INCLUDED_COM_SUN_STAR_AWT_XWINDOWLISTENER2_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XWINDOWLISTENER2_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XWindowListener2.hdl"

#include "com/sun/star/awt/XWindowListener.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XWindowListener2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::XWindowListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.XWindowListener2", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::XWindowListener2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XWindowListener2 > >::get();
}

::css::uno::Type const & ::css::awt::XWindowListener2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::XWindowListener2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XWINDOWLISTENER2_HPP
