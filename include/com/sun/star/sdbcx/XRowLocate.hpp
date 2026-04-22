#ifndef INCLUDED_COM_SUN_STAR_SDBCX_XROWLOCATE_HPP
#define INCLUDED_COM_SUN_STAR_SDBCX_XROWLOCATE_HPP

#include "sal/config.h"

#include "com/sun/star/sdbcx/XRowLocate.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdbcx {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbcx::XRowLocate const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdbcx.XRowLocate", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdbcx::XRowLocate > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdbcx::XRowLocate > >::get();
}

::css::uno::Type const & ::css::sdbcx::XRowLocate::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdbcx::XRowLocate >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBCX_XROWLOCATE_HPP
