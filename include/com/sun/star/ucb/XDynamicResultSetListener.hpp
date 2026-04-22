#ifndef INCLUDED_COM_SUN_STAR_UCB_XDYNAMICRESULTSETLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_UCB_XDYNAMICRESULTSETLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/XDynamicResultSetListener.hdl"

#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/ucb/ListEvent.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::XDynamicResultSetListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ucb.XDynamicResultSetListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ucb::XDynamicResultSetListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XDynamicResultSetListener > >::get();
}

::css::uno::Type const & ::css::ucb::XDynamicResultSetListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ucb::XDynamicResultSetListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_XDYNAMICRESULTSETLISTENER_HPP
