#ifndef INCLUDED_COM_SUN_STAR_SDB_APPLICATION_XTABLEUIPROVIDER_HPP
#define INCLUDED_COM_SUN_STAR_SDB_APPLICATION_XTABLEUIPROVIDER_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/application/XTableUIProvider.hdl"

#include "com/sun/star/graphic/XGraphic.hpp"
#include "com/sun/star/sdb/application/XDatabaseDocumentUI.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdb { namespace application {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::application::XTableUIProvider const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.application.XTableUIProvider", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::application::XTableUIProvider > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::application::XTableUIProvider > >::get();
}

::css::uno::Type const & ::css::sdb::application::XTableUIProvider::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::application::XTableUIProvider >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_APPLICATION_XTABLEUIPROVIDER_HPP
