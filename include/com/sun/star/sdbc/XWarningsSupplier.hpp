#ifndef INCLUDED_COM_SUN_STAR_SDBC_XWARNINGSSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_XWARNINGSSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/XWarningsSupplier.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::XWarningsSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdbc.XWarningsSupplier", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdbc::XWarningsSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XWarningsSupplier > >::get();
}

::css::uno::Type const & ::css::sdbc::XWarningsSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdbc::XWarningsSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_XWARNINGSSUPPLIER_HPP
