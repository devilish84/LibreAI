#ifndef INCLUDED_COM_SUN_STAR_SDBC_XCONNECTION_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_XCONNECTION_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/XConnection.hdl"

#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/sdbc/XCloseable.hpp"
#include "com/sun/star/sdbc/XDatabaseMetaData.hpp"
#include "com/sun/star/sdbc/XPreparedStatement.hpp"
#include "com/sun/star/sdbc/XStatement.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::XConnection const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sdbc::XCloseable > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdbc.XConnection", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdbc::XConnection > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XConnection > >::get();
}

::css::uno::Type const & ::css::sdbc::XConnection::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdbc::XConnection >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_XCONNECTION_HPP
