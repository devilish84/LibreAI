#ifndef INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_XCONFIGURATION_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_XCONFIGURATION_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/framework/XConfiguration.hdl"

#include "com/sun/star/drawing/framework/AnchorBindingMode.hpp"
#include "com/sun/star/drawing/framework/XResourceId.hpp"
#include "com/sun/star/util/XCloneable.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace drawing { namespace framework {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::framework::XConfiguration const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XCloneable > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.framework.XConfiguration", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::framework::XConfiguration > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::framework::XConfiguration > >::get();
}

::css::uno::Type const & ::css::drawing::framework::XConfiguration::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::framework::XConfiguration >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_XCONFIGURATION_HPP
