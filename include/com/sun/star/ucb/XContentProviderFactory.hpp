#ifndef INCLUDED_COM_SUN_STAR_UCB_XCONTENTPROVIDERFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_UCB_XCONTENTPROVIDERFACTORY_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/XContentProviderFactory.hdl"

#include "com/sun/star/ucb/XContentProvider.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::XContentProviderFactory const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ucb.XContentProviderFactory", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ucb::XContentProviderFactory > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContentProviderFactory > >::get();
}

::css::uno::Type const & ::css::ucb::XContentProviderFactory::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ucb::XContentProviderFactory >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_XCONTENTPROVIDERFACTORY_HPP
