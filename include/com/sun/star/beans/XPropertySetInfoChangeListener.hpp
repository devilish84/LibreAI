#ifndef INCLUDED_COM_SUN_STAR_BEANS_XPROPERTYSETINFOCHANGELISTENER_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_XPROPERTYSETINFOCHANGELISTENER_HPP

#include "sal/config.h"

#include "com/sun/star/beans/XPropertySetInfoChangeListener.hdl"

#include "com/sun/star/beans/PropertySetInfoChangeEvent.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::XPropertySetInfoChangeListener const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XEventListener > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.beans.XPropertySetInfoChangeListener", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::beans::XPropertySetInfoChangeListener > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::beans::XPropertySetInfoChangeListener > >::get();
}

::css::uno::Type const & ::css::beans::XPropertySetInfoChangeListener::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::beans::XPropertySetInfoChangeListener >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_XPROPERTYSETINFOCHANGELISTENER_HPP
