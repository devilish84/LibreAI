#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_XLIBRARYCONTAINER3_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_XLIBRARYCONTAINER3_HPP

#include "sal/config.h"

#include "com/sun/star/script/XLibraryContainer3.hdl"

#include "com/sun/star/script/XLibraryContainer2.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::XLibraryContainer3 const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::script::XLibraryContainer2 > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.script.XLibraryContainer3", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::script::XLibraryContainer3 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::script::XLibraryContainer3 > >::get();
}

::css::uno::Type const & ::css::script::XLibraryContainer3::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::script::XLibraryContainer3 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_XLIBRARYCONTAINER3_HPP
