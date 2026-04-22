#ifndef INCLUDED_COM_SUN_STAR_SDBC_XPREPAREDSTATEMENT_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_XPREPAREDSTATEMENT_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/XPreparedStatement.hdl"

#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/sdbc/XResultSet.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::XPreparedStatement const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdbc.XPreparedStatement", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdbc::XPreparedStatement > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XPreparedStatement > >::get();
}

::css::uno::Type const & ::css::sdbc::XPreparedStatement::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdbc::XPreparedStatement >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_XPREPAREDSTATEMENT_HPP
