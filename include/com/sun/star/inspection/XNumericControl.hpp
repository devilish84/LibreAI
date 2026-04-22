#ifndef INCLUDED_COM_SUN_STAR_INSPECTION_XNUMERICCONTROL_HPP
#define INCLUDED_COM_SUN_STAR_INSPECTION_XNUMERICCONTROL_HPP

#include "sal/config.h"

#include "com/sun/star/inspection/XNumericControl.hdl"

#include "com/sun/star/beans/Optional.hpp"
#include "com/sun/star/inspection/XPropertyControl.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace inspection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::inspection::XNumericControl const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::inspection::XPropertyControl > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.inspection.XNumericControl", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::inspection::XNumericControl > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::inspection::XNumericControl > >::get();
}

::css::uno::Type const & ::css::inspection::XNumericControl::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::inspection::XNumericControl >::get();
}

#endif // INCLUDED_COM_SUN_STAR_INSPECTION_XNUMERICCONTROL_HPP
