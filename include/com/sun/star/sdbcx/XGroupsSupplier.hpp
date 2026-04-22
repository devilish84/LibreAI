#ifndef INCLUDED_COM_SUN_STAR_SDBCX_XGROUPSSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_SDBCX_XGROUPSSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/sdbcx/XGroupsSupplier.hdl"

#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sdbcx {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbcx::XGroupsSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdbcx.XGroupsSupplier", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdbcx::XGroupsSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdbcx::XGroupsSupplier > >::get();
}

::css::uno::Type const & ::css::sdbcx::XGroupsSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdbcx::XGroupsSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBCX_XGROUPSSUPPLIER_HPP
