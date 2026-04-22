#ifndef INCLUDED_COM_SUN_STAR_TASK_XSTATUSINDICATORFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_TASK_XSTATUSINDICATORFACTORY_HPP

#include "sal/config.h"

#include "com/sun/star/task/XStatusIndicatorFactory.hdl"

#include "com/sun/star/task/XStatusIndicator.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::XStatusIndicatorFactory const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.task.XStatusIndicatorFactory", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::task::XStatusIndicatorFactory > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::task::XStatusIndicatorFactory > >::get();
}

::css::uno::Type const & ::css::task::XStatusIndicatorFactory::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::task::XStatusIndicatorFactory >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_XSTATUSINDICATORFACTORY_HPP
