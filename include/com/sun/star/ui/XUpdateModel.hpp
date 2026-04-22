#ifndef INCLUDED_COM_SUN_STAR_UI_XUPDATEMODEL_HPP
#define INCLUDED_COM_SUN_STAR_UI_XUPDATEMODEL_HPP

#include "sal/config.h"

#include "com/sun/star/ui/XUpdateModel.hdl"

#include "com/sun/star/frame/XModel.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace ui {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::XUpdateModel const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.ui.XUpdateModel", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ui::XUpdateModel > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ui::XUpdateModel > >::get();
}

::css::uno::Type const & ::css::ui::XUpdateModel::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ui::XUpdateModel >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_XUPDATEMODEL_HPP
