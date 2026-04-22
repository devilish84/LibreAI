#ifndef INCLUDED_COM_SUN_STAR_AWT_GRID_XSORTABLEMUTABLEGRIDDATAMODEL_HPP
#define INCLUDED_COM_SUN_STAR_AWT_GRID_XSORTABLEMUTABLEGRIDDATAMODEL_HPP

#include "sal/config.h"

#include "com/sun/star/awt/grid/XSortableMutableGridDataModel.hdl"

#include "com/sun/star/awt/grid/XMutableGridDataModel.hpp"
#include "com/sun/star/awt/grid/XSortableGridData.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace awt { namespace grid {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::grid::XSortableMutableGridDataModel const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::grid::XMutableGridDataModel > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::awt::grid::XSortableGridData > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.grid.XSortableMutableGridDataModel", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::grid::XSortableMutableGridDataModel > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::grid::XSortableMutableGridDataModel > >::get();
}

::css::uno::Type const & ::css::awt::grid::XSortableMutableGridDataModel::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::grid::XSortableMutableGridDataModel >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_GRID_XSORTABLEMUTABLEGRIDDATAMODEL_HPP
