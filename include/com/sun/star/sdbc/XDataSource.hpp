#ifndef INCLUDED_COM_SUN_STAR_SDBC_XDATASOURCE_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_XDATASOURCE_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/XDataSource.hdl"

#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::XDataSource const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdbc.XDataSource", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdbc::XDataSource > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XDataSource > >::get();
}

::css::uno::Type const & ::css::sdbc::XDataSource::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdbc::XDataSource >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_XDATASOURCE_HPP
