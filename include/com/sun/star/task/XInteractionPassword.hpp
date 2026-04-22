#ifndef INCLUDED_COM_SUN_STAR_TASK_XINTERACTIONPASSWORD_HPP
#define INCLUDED_COM_SUN_STAR_TASK_XINTERACTIONPASSWORD_HPP

#include "sal/config.h"

#include "com/sun/star/task/XInteractionPassword.hdl"

#include "com/sun/star/task/XInteractionContinuation.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::XInteractionPassword const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::task::XInteractionContinuation > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.task.XInteractionPassword", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::task::XInteractionPassword > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::task::XInteractionPassword > >::get();
}

::css::uno::Type const & ::css::task::XInteractionPassword::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::task::XInteractionPassword >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_XINTERACTIONPASSWORD_HPP
