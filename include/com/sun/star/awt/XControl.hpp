#ifndef INCLUDED_COM_SUN_STAR_AWT_XCONTROL_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XCONTROL_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XControl.hdl"

#include "com/sun/star/awt/XControlModel.hpp"
#include "com/sun/star/awt/XToolkit.hpp"
#include "com/sun/star/awt/XView.hpp"
#include "com/sun/star/awt/XWindowPeer.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XControl const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.XControl", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::XControl > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XControl > >::get();
}

::css::uno::Type const & ::css::awt::XControl::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::XControl >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XCONTROL_HPP
