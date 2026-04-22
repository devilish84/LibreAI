#ifndef INCLUDED_COM_SUN_STAR_FORM_VALIDATION_XFORMCOMPONENTVALIDITYLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_FORM_VALIDATION_XFORMCOMPONENTVALIDITYLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/form/validation/XFormComponentValidityListener.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace form { namespace validation {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::validation::XFormComponentValidityListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.form.validation.XFormComponentValidityListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::form::validation::XFormComponentValidityListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::form::validation::XFormComponentValidityListener > >::get();
}

::css::uno::Type const & ::css::form::validation::XFormComponentValidityListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::form::validation::XFormComponentValidityListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_VALIDATION_XFORMCOMPONENTVALIDITYLISTENER_HPP
