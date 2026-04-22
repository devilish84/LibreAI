#ifndef INCLUDED_COM_SUN_STAR_SDB_APPLICATION_XCOPYTABLEWIZARD_HPP
#define INCLUDED_COM_SUN_STAR_SDB_APPLICATION_XCOPYTABLEWIZARD_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/application/XCopyTableWizard.hdl"

#include "com/sun/star/beans/Optional.hpp"
#include "com/sun/star/sdb/application/XCopyTableListener.hpp"
#include "com/sun/star/ui/dialogs/XExecutableDialog.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdb { namespace application {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::application::XCopyTableWizard const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.application.XCopyTableWizard", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard > >::get();
}

::css::uno::Type const & ::css::sdb::application::XCopyTableWizard::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::application::XCopyTableWizard >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_APPLICATION_XCOPYTABLEWIZARD_HPP
