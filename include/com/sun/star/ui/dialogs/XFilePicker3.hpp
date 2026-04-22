#ifndef INCLUDED_COM_SUN_STAR_UI_DIALOGS_XFILEPICKER3_HPP
#define INCLUDED_COM_SUN_STAR_UI_DIALOGS_XFILEPICKER3_HPP

#include "sal/config.h"

#include "com/sun/star/ui/dialogs/XFilePicker3.hdl"

#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/ui/dialogs/XFilePicker2.hpp"
#include "com/sun/star/ui/dialogs/XFilePickerNotifier.hpp"
#include "com/sun/star/ui/dialogs/XFilterGroupManager.hpp"
#include "com/sun/star/ui/dialogs/XFilterManager.hpp"
#include "com/sun/star/util/XCancellable.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace ui { namespace dialogs {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::dialogs::XFilePicker3 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[6];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::dialogs::XFilePicker2 > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::dialogs::XFilePickerNotifier > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::dialogs::XFilterManager > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::dialogs::XFilterGroupManager > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XCancellable > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ui.dialogs.XFilePicker3", 6, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ui::dialogs::XFilePicker3 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ui::dialogs::XFilePicker3 > >::get();
}

::css::uno::Type const & ::css::ui::dialogs::XFilePicker3::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ui::dialogs::XFilePicker3 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_DIALOGS_XFILEPICKER3_HPP
