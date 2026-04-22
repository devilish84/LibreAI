#ifndef INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_XCONFIGURATIONCONTROLLER_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_XCONFIGURATIONCONTROLLER_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/framework/XConfigurationController.hdl"

#include "com/sun/star/drawing/framework/ResourceActivationMode.hpp"
#include "com/sun/star/drawing/framework/XConfiguration.hpp"
#include "com/sun/star/drawing/framework/XConfigurationControllerBroadcaster.hpp"
#include "com/sun/star/drawing/framework/XConfigurationControllerRequestQueue.hpp"
#include "com/sun/star/drawing/framework/XResource.hpp"
#include "com/sun/star/drawing/framework/XResourceFactoryManager.hpp"
#include "com/sun/star/drawing/framework/XResourceId.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace drawing { namespace framework {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::framework::XConfigurationController const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::framework::XConfigurationControllerRequestQueue > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::framework::XConfigurationControllerBroadcaster > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::drawing::framework::XResourceFactoryManager > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.drawing.framework.XConfigurationController", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::drawing::framework::XConfigurationController > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::framework::XConfigurationController > >::get();
}

::css::uno::Type const & ::css::drawing::framework::XConfigurationController::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::drawing::framework::XConfigurationController >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_XCONFIGURATIONCONTROLLER_HPP
