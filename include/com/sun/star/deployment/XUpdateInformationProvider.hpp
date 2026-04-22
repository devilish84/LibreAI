#ifndef INCLUDED_COM_SUN_STAR_DEPLOYMENT_XUPDATEINFORMATIONPROVIDER_HPP
#define INCLUDED_COM_SUN_STAR_DEPLOYMENT_XUPDATEINFORMATIONPROVIDER_HPP

#include "sal/config.h"

#include "com/sun/star/deployment/XUpdateInformationProvider.hdl"

#include "com/sun/star/container/XEnumeration.hpp"
#include "com/sun/star/task/XInteractionHandler.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/xml/dom/XElement.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace deployment {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::deployment::XUpdateInformationProvider const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.deployment.XUpdateInformationProvider", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::deployment::XUpdateInformationProvider > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::deployment::XUpdateInformationProvider > >::get();
}

::css::uno::Type const & ::css::deployment::XUpdateInformationProvider::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::deployment::XUpdateInformationProvider >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DEPLOYMENT_XUPDATEINFORMATIONPROVIDER_HPP
