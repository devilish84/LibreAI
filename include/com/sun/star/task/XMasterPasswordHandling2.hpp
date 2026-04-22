#ifndef INCLUDED_COM_SUN_STAR_TASK_XMASTERPASSWORDHANDLING2_HPP
#define INCLUDED_COM_SUN_STAR_TASK_XMASTERPASSWORDHANDLING2_HPP

#include "sal/config.h"

#include "com/sun/star/task/XMasterPasswordHandling2.hdl"

#include "com/sun/star/task/XInteractionHandler.hpp"
#include "com/sun/star/task/XMasterPasswordHandling.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::XMasterPasswordHandling2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::task::XMasterPasswordHandling > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.task.XMasterPasswordHandling2", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::task::XMasterPasswordHandling2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::task::XMasterPasswordHandling2 > >::get();
}

::css::uno::Type const & ::css::task::XMasterPasswordHandling2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::task::XMasterPasswordHandling2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_XMASTERPASSWORDHANDLING2_HPP
