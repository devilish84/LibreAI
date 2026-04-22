#ifndef INCLUDED_COM_SUN_STAR_UCB_XDYNAMICRESULTSET_HPP
#define INCLUDED_COM_SUN_STAR_UCB_XDYNAMICRESULTSET_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/XDynamicResultSet.hdl"

#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/sdbc/XResultSet.hpp"
#include "com/sun/star/ucb/XDynamicResultSetListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::XDynamicResultSet const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ucb.XDynamicResultSet", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ucb::XDynamicResultSet > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XDynamicResultSet > >::get();
}

::css::uno::Type const & ::css::ucb::XDynamicResultSet::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ucb::XDynamicResultSet >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_XDYNAMICRESULTSET_HPP
