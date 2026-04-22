#ifndef INCLUDED_COM_SUN_STAR_SDB_XDATABASEENVIRONMENT_HPP
#define INCLUDED_COM_SUN_STAR_SDB_XDATABASEENVIRONMENT_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/XDatabaseEnvironment.hdl"

#include "com/sun/star/sdb/XDatabaseAccess.hpp"
#include "com/sun/star/sdbc/XDriverManager.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::XDatabaseEnvironment const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sdbc::XDriverManager > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.XDatabaseEnvironment", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::XDatabaseEnvironment > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::XDatabaseEnvironment > >::get();
}

::css::uno::Type const & ::css::sdb::XDatabaseEnvironment::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::XDatabaseEnvironment >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_XDATABASEENVIRONMENT_HPP
