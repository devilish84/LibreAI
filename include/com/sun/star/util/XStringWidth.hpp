#ifndef INCLUDED_COM_SUN_STAR_UTIL_XSTRINGWIDTH_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_XSTRINGWIDTH_HPP

#include "sal/config.h"

#include "com/sun/star/util/XStringWidth.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::XStringWidth const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.util.XStringWidth", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::util::XStringWidth > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::util::XStringWidth > >::get();
}

::css::uno::Type const & ::css::util::XStringWidth::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::util::XStringWidth >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_XSTRINGWIDTH_HPP
