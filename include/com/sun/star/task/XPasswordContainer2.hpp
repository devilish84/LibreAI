#ifndef INCLUDED_COM_SUN_STAR_TASK_XPASSWORDCONTAINER2_HPP
#define INCLUDED_COM_SUN_STAR_TASK_XPASSWORDCONTAINER2_HPP

#include "sal/config.h"

#include "com/sun/star/task/XPasswordContainer2.hdl"

#include "com/sun/star/task/XMasterPasswordHandling2.hpp"
#include "com/sun/star/task/XPasswordContainer.hpp"
#include "com/sun/star/task/XUrlContainer.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace task {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::task::XPasswordContainer2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::task::XPasswordContainer > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::task::XMasterPasswordHandling2 > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::task::XUrlContainer > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.task.XPasswordContainer2", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::task::XPasswordContainer2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::task::XPasswordContainer2 > >::get();
}

::css::uno::Type const & ::css::task::XPasswordContainer2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::task::XPasswordContainer2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TASK_XPASSWORDCONTAINER2_HPP
