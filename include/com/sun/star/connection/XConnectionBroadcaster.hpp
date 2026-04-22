#ifndef INCLUDED_COM_SUN_STAR_CONNECTION_XCONNECTIONBROADCASTER_HPP
#define INCLUDED_COM_SUN_STAR_CONNECTION_XCONNECTIONBROADCASTER_HPP

#include "sal/config.h"

#include "com/sun/star/connection/XConnectionBroadcaster.hdl"

#include "com/sun/star/io/XStreamListener.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace connection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::connection::XConnectionBroadcaster const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.connection.XConnectionBroadcaster", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::connection::XConnectionBroadcaster > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::connection::XConnectionBroadcaster > >::get();
}

::css::uno::Type const & ::css::connection::XConnectionBroadcaster::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::connection::XConnectionBroadcaster >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONNECTION_XCONNECTIONBROADCASTER_HPP
