#ifndef INCLUDED_COM_SUN_STAR_SDB_XALTERQUERY_HPP
#define INCLUDED_COM_SUN_STAR_SDB_XALTERQUERY_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/XAlterQuery.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::XAlterQuery const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.XAlterQuery", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::XAlterQuery > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::XAlterQuery > >::get();
}

::css::uno::Type const & ::css::sdb::XAlterQuery::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::XAlterQuery >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_XALTERQUERY_HPP
