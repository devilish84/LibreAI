#ifndef INCLUDED_COM_SUN_STAR_SDBC_XCONNECTIONPOOL_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_XCONNECTIONPOOL_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/XConnectionPool.hdl"

#include "com/sun/star/sdbc/XDriverAccess.hpp"
#include "com/sun/star/sdbc/XDriverManager.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::XConnectionPool const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sdbc::XDriverManager > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sdbc::XDriverAccess > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdbc.XConnectionPool", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdbc::XConnectionPool > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XConnectionPool > >::get();
}

::css::uno::Type const & ::css::sdbc::XConnectionPool::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdbc::XConnectionPool >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_XCONNECTIONPOOL_HPP
