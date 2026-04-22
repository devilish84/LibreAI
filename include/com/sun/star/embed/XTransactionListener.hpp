#ifndef INCLUDED_COM_SUN_STAR_EMBED_XTRANSACTIONLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_XTRANSACTIONLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/embed/XTransactionListener.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::XTransactionListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.embed.XTransactionListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::embed::XTransactionListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::embed::XTransactionListener > >::get();
}

::css::uno::Type const & ::css::embed::XTransactionListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::embed::XTransactionListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_XTRANSACTIONLISTENER_HPP
