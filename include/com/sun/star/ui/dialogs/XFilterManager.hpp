#ifndef INCLUDED_COM_SUN_STAR_UI_DIALOGS_XFILTERMANAGER_HPP
#define INCLUDED_COM_SUN_STAR_UI_DIALOGS_XFILTERMANAGER_HPP

#include "sal/config.h"

#include "com/sun/star/ui/dialogs/XFilterManager.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace ui { namespace dialogs {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::dialogs::XFilterManager const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ui.dialogs.XFilterManager", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ui::dialogs::XFilterManager > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ui::dialogs::XFilterManager > >::get();
}

::css::uno::Type const & ::css::ui::dialogs::XFilterManager::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ui::dialogs::XFilterManager >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_DIALOGS_XFILTERMANAGER_HPP
