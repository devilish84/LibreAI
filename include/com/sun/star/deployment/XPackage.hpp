#ifndef INCLUDED_COM_SUN_STAR_DEPLOYMENT_XPACKAGE_HPP
#define INCLUDED_COM_SUN_STAR_DEPLOYMENT_XPACKAGE_HPP

#include "sal/config.h"

#include "com/sun/star/deployment/XPackage.hdl"

#include "com/sun/star/beans/Ambiguous.hpp"
#include "com/sun/star/beans/Optional.hpp"
#include "com/sun/star/beans/StringPair.hpp"
#include "com/sun/star/deployment/XPackageTypeInfo.hpp"
#include "com/sun/star/graphic/XGraphic.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/task/XAbortChannel.hpp"
#include "com/sun/star/ucb/XCommandEnvironment.hpp"
#include "com/sun/star/util/XModifyBroadcaster.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace deployment {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::deployment::XPackage const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XModifyBroadcaster > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.deployment.XPackage", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::deployment::XPackage > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::deployment::XPackage > >::get();
}

::css::uno::Type const & ::css::deployment::XPackage::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::deployment::XPackage >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DEPLOYMENT_XPACKAGE_HPP
