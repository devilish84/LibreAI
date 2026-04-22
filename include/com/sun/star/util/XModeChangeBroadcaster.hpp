#ifndef INCLUDED_COM_SUN_STAR_UTIL_XMODECHANGEBROADCASTER_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_XMODECHANGEBROADCASTER_HPP

#include "sal/config.h"

#include "com/sun/star/util/XModeChangeBroadcaster.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/util/XModeChangeApproveListener.hpp"
#include "com/sun/star/util/XModeChangeListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::XModeChangeBroadcaster const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.util.XModeChangeBroadcaster", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::util::XModeChangeBroadcaster > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::util::XModeChangeBroadcaster > >::get();
}

::css::uno::Type const & ::css::util::XModeChangeBroadcaster::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::util::XModeChangeBroadcaster >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_XMODECHANGEBROADCASTER_HPP
