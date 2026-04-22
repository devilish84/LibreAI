#ifndef INCLUDED_COM_SUN_STAR_AWT_TREE_XMUTABLETREEDATAMODEL_HPP
#define INCLUDED_COM_SUN_STAR_AWT_TREE_XMUTABLETREEDATAMODEL_HPP

#include "sal/config.h"

#include "com/sun/star/awt/tree/XMutableTreeDataModel.hdl"

#include "com/sun/star/awt/tree/XMutableTreeNode.hpp"
#include "com/sun/star/awt/tree/XTreeDataModel.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace awt { namespace tree {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::tree::XMutableTreeDataModel const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::tree::XTreeDataModel > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.tree.XMutableTreeDataModel", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::tree::XMutableTreeDataModel > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::tree::XMutableTreeDataModel > >::get();
}

::css::uno::Type const & ::css::awt::tree::XMutableTreeDataModel::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::tree::XMutableTreeDataModel >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_TREE_XMUTABLETREEDATAMODEL_HPP
