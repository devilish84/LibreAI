#ifndef INCLUDED_COM_SUN_STAR_SDB_XTEXTCONNECTIONSETTINGS_HPP
#define INCLUDED_COM_SUN_STAR_SDB_XTEXTCONNECTIONSETTINGS_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/XTextConnectionSettings.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/ui/dialogs/XExecutableDialog.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::XTextConnectionSettings const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.XTextConnectionSettings", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::XTextConnectionSettings > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::XTextConnectionSettings > >::get();
}

::css::uno::Type const & ::css::sdb::XTextConnectionSettings::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::XTextConnectionSettings >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_XTEXTCONNECTIONSETTINGS_HPP
