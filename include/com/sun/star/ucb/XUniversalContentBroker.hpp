#ifndef INCLUDED_COM_SUN_STAR_UCB_XUNIVERSALCONTENTBROKER_HPP
#define INCLUDED_COM_SUN_STAR_UCB_XUNIVERSALCONTENTBROKER_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/XUniversalContentBroker.hdl"

#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/ucb/XCommandProcessor2.hpp"
#include "com/sun/star/ucb/XContentIdentifierFactory.hpp"
#include "com/sun/star/ucb/XContentProvider.hpp"
#include "com/sun/star/ucb/XContentProviderManager.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::XUniversalContentBroker const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[5];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ucb::XContentProvider > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ucb::XContentProviderManager > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ucb::XContentIdentifierFactory > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ucb::XCommandProcessor2 > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ucb.XUniversalContentBroker", 5, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ucb::XUniversalContentBroker > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XUniversalContentBroker > >::get();
}

::css::uno::Type const & ::css::ucb::XUniversalContentBroker::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ucb::XUniversalContentBroker >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_XUNIVERSALCONTENTBROKER_HPP
