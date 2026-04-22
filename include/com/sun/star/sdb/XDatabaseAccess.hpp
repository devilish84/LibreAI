#ifndef INCLUDED_COM_SUN_STAR_SDB_XDATABASEACCESS_HPP
#define INCLUDED_COM_SUN_STAR_SDB_XDATABASEACCESS_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/XDatabaseAccess.hdl"

#include "com/sun/star/sdb/XDatabaseAccessListener.hpp"
#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/sdbc/XDataSource.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::XDatabaseAccess const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sdbc::XDataSource > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.XDatabaseAccess", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::XDatabaseAccess > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::XDatabaseAccess > >::get();
}

::css::uno::Type const & ::css::sdb::XDatabaseAccess::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::XDatabaseAccess >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_XDATABASEACCESS_HPP
