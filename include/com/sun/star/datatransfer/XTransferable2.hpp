#ifndef INCLUDED_COM_SUN_STAR_DATATRANSFER_XTRANSFERABLE2_HPP
#define INCLUDED_COM_SUN_STAR_DATATRANSFER_XTRANSFERABLE2_HPP

#include "sal/config.h"

#include "com/sun/star/datatransfer/XTransferable2.hdl"

#include "com/sun/star/datatransfer/DataFlavor.hpp"
#include "com/sun/star/datatransfer/XTransferable.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace datatransfer {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::datatransfer::XTransferable2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::datatransfer::XTransferable > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.datatransfer.XTransferable2", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::datatransfer::XTransferable2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::datatransfer::XTransferable2 > >::get();
}

::css::uno::Type const & ::css::datatransfer::XTransferable2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::datatransfer::XTransferable2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DATATRANSFER_XTRANSFERABLE2_HPP
