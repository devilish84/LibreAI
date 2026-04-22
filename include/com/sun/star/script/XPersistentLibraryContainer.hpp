#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_XPERSISTENTLIBRARYCONTAINER_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_XPERSISTENTLIBRARYCONTAINER_HPP

#include "sal/config.h"

#include "com/sun/star/script/XPersistentLibraryContainer.hdl"

#include "com/sun/star/script/XLibraryContainer2.hpp"
#include "com/sun/star/util/XModifiable.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::XPersistentLibraryContainer const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XModifiable > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::script::XLibraryContainer2 > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.script.XPersistentLibraryContainer", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::script::XPersistentLibraryContainer > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::script::XPersistentLibraryContainer > >::get();
}

::css::uno::Type const & ::css::script::XPersistentLibraryContainer::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::script::XPersistentLibraryContainer >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_XPERSISTENTLIBRARYCONTAINER_HPP
