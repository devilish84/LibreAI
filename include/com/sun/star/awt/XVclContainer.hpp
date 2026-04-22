#ifndef INCLUDED_COM_SUN_STAR_AWT_XVCLCONTAINER_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XVCLCONTAINER_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XVclContainer.hdl"

#include "com/sun/star/awt/XVclContainerListener.hpp"
#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XVclContainer const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.XVclContainer", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::XVclContainer > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XVclContainer > >::get();
}

::css::uno::Type const & ::css::awt::XVclContainer::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::XVclContainer >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XVCLCONTAINER_HPP
