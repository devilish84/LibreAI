#ifndef INCLUDED_COM_SUN_STAR_AWT_XTABLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XTABLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XTabListener.hdl"

#include "com/sun/star/beans/NamedValue.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XTabListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.XTabListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::XTabListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XTabListener > >::get();
}

::css::uno::Type const & ::css::awt::XTabListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::XTabListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XTABLISTENER_HPP
