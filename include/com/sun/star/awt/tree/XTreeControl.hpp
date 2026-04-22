#ifndef INCLUDED_COM_SUN_STAR_AWT_TREE_XTREECONTROL_HPP
#define INCLUDED_COM_SUN_STAR_AWT_TREE_XTREECONTROL_HPP

#include "sal/config.h"

#include "com/sun/star/awt/tree/XTreeControl.hdl"

#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/awt/tree/XTreeEditListener.hpp"
#include "com/sun/star/awt/tree/XTreeExpansionListener.hpp"
#include "com/sun/star/awt/tree/XTreeNode.hpp"
#include "com/sun/star/view/XMultiSelectionSupplier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace awt { namespace tree {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::tree::XTreeControl const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::view::XMultiSelectionSupplier > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.tree.XTreeControl", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::tree::XTreeControl > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::tree::XTreeControl > >::get();
}

::css::uno::Type const & ::css::awt::tree::XTreeControl::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::tree::XTreeControl >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_TREE_XTREECONTROL_HPP
