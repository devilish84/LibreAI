#ifndef INCLUDED_COM_SUN_STAR_FORM_XDATABASEPARAMETERLISTENER_HPP
#define INCLUDED_COM_SUN_STAR_FORM_XDATABASEPARAMETERLISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/form/XDatabaseParameterListener.hdl"

#include "com/sun/star/form/DatabaseParameterEvent.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace form {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::XDatabaseParameterListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.form.XDatabaseParameterListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::form::XDatabaseParameterListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::form::XDatabaseParameterListener > >::get();
}

::css::uno::Type const & ::css::form::XDatabaseParameterListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::form::XDatabaseParameterListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_XDATABASEPARAMETERLISTENER_HPP
