#ifndef INCLUDED_COM_SUN_STAR_UI_DIALOGS_XWIZARDCONTROLLER_HPP
#define INCLUDED_COM_SUN_STAR_UI_DIALOGS_XWIZARDCONTROLLER_HPP

#include "sal/config.h"

#include "com/sun/star/ui/dialogs/XWizardController.hdl"

#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/ui/dialogs/XWizardPage.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ui { namespace dialogs {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::dialogs::XWizardController const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ui.dialogs.XWizardController", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ui::dialogs::XWizardController > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ui::dialogs::XWizardController > >::get();
}

::css::uno::Type const & ::css::ui::dialogs::XWizardController::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ui::dialogs::XWizardController >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_DIALOGS_XWIZARDCONTROLLER_HPP
