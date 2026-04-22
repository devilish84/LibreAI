#ifndef INCLUDED_COM_SUN_STAR_SDB_XROWSETSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_SDB_XROWSETSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/XRowSetSupplier.hdl"

#include "com/sun/star/sdbc/XRowSet.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::XRowSetSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.XRowSetSupplier", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::XRowSetSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::XRowSetSupplier > >::get();
}

::css::uno::Type const & ::css::sdb::XRowSetSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::XRowSetSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_XROWSETSUPPLIER_HPP
