#ifndef INCLUDED_COM_SUN_STAR_FORM_XERRORLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_FORM_XERRORLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/form/XErrorListener.hdl"

#include "com/sun/star/form/ErrorEvent.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace form {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::XErrorListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.form.XErrorListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::form::XErrorListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::form::XErrorListener > >::get();
}

::css::uno::Type const & ::css::form::XErrorListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::form::XErrorListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_XERRORLISTENER_HPP
