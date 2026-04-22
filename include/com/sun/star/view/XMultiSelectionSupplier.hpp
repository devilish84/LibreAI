#ifndef INCLUDED_COM_SUN_STAR_VIEW_XMULTISELECTIONSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_VIEW_XMULTISELECTIONSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/view/XMultiSelectionSupplier.hdl"

#include "com/sun/star/container/XEnumeration.hpp"
#include "com/sun/star/view/XSelectionSupplier.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace view {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::view::XMultiSelectionSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::view::XSelectionSupplier > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.view.XMultiSelectionSupplier", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::view::XMultiSelectionSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::view::XMultiSelectionSupplier > >::get();
}

::css::uno::Type const & ::css::view::XMultiSelectionSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::view::XMultiSelectionSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_VIEW_XMULTISELECTIONSUPPLIER_HPP
