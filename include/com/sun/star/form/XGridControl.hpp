#ifndef INCLUDED_COM_SUN_STAR_FORM_XGRIDCONTROL_HPP
#define INCLUDED_COM_SUN_STAR_FORM_XGRIDCONTROL_HPP

#include "sal/config.h"

#include "com/sun/star/form/XGridControl.hdl"

#include "com/sun/star/form/XGrid.hpp"
#include "com/sun/star/form/XGridControlListener.hpp"
#include "com/sun/star/form/XGridFieldDataSupplier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace form {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::XGridControl const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::form::XGrid > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::form::XGridFieldDataSupplier > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.form.XGridControl", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::form::XGridControl > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::form::XGridControl > >::get();
}

::css::uno::Type const & ::css::form::XGridControl::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::form::XGridControl >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_XGRIDCONTROL_HPP
