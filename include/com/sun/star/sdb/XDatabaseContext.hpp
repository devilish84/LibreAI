#ifndef INCLUDED_COM_SUN_STAR_SDB_XDATABASECONTEXT_HPP
#define INCLUDED_COM_SUN_STAR_SDB_XDATABASECONTEXT_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/XDatabaseContext.hdl"

#include "com/sun/star/container/XContainer.hpp"
#include "com/sun/star/container/XEnumerationAccess.hpp"
#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/lang/XSingleServiceFactory.hpp"
#include "com/sun/star/sdb/XDatabaseRegistrations.hpp"
#include "com/sun/star/uno/XNamingService.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::XDatabaseContext const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[6];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XEnumerationAccess > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNameAccess > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::uno::XNamingService > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XContainer > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XSingleServiceFactory > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sdb::XDatabaseRegistrations > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.XDatabaseContext", 6, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::XDatabaseContext > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::XDatabaseContext > >::get();
}

::css::uno::Type const & ::css::sdb::XDatabaseContext::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::XDatabaseContext >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_XDATABASECONTEXT_HPP
