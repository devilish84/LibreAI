#ifndef INCLUDED_COM_SUN_STAR_UTIL_XIMPORTABLE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_XIMPORTABLE_HPP

#include "sal/config.h"

#include "com/sun/star/util/XImportable.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::XImportable const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.util.XImportable", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::util::XImportable > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::util::XImportable > >::get();
}

::css::uno::Type const & ::css::util::XImportable::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::util::XImportable >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_XIMPORTABLE_HPP
