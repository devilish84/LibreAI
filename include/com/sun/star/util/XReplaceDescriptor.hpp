#ifndef INCLUDED_COM_SUN_STAR_UTIL_XREPLACEDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_XREPLACEDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/util/XReplaceDescriptor.hdl"

#include "com/sun/star/util/XSearchDescriptor.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::XReplaceDescriptor const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XSearchDescriptor > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.util.XReplaceDescriptor", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::util::XReplaceDescriptor > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::util::XReplaceDescriptor > >::get();
}

::css::uno::Type const & ::css::util::XReplaceDescriptor::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::util::XReplaceDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_XREPLACEDESCRIPTOR_HPP
