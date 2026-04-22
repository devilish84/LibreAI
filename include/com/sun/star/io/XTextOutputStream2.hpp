#ifndef INCLUDED_COM_SUN_STAR_IO_XTEXTOUTPUTSTREAM2_HPP
#define INCLUDED_COM_SUN_STAR_IO_XTEXTOUTPUTSTREAM2_HPP

#include "sal/config.h"

#include "com/sun/star/io/XTextOutputStream2.hdl"

#include "com/sun/star/io/XActiveDataSource.hpp"
#include "com/sun/star/io/XTextOutputStream.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace io {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::XTextOutputStream2 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::io::XTextOutputStream > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::io::XActiveDataSource > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.io.XTextOutputStream2", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::io::XTextOutputStream2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::io::XTextOutputStream2 > >::get();
}

::css::uno::Type const & ::css::io::XTextOutputStream2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::io::XTextOutputStream2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_IO_XTEXTOUTPUTSTREAM2_HPP
