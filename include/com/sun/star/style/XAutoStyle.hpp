#ifndef INCLUDED_COM_SUN_STAR_STYLE_XAUTOSTYLE_HPP
#define INCLUDED_COM_SUN_STAR_STYLE_XAUTOSTYLE_HPP

#include "sal/config.h"

#include "com/sun/star/style/XAutoStyle.hdl"

#include "com/sun/star/beans/PropertyValues.hpp"
#include "com/sun/star/beans/XMultiPropertySet.hpp"
#include "com/sun/star/beans/XMultiPropertyStates.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace style {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::style::XAutoStyle const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XMultiPropertySet > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XMultiPropertyStates > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.style.XAutoStyle", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::style::XAutoStyle > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::style::XAutoStyle > >::get();
}

::css::uno::Type const & ::css::style::XAutoStyle::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::style::XAutoStyle >::get();
}

#endif // INCLUDED_COM_SUN_STAR_STYLE_XAUTOSTYLE_HPP
