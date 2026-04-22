#ifndef INCLUDED_COM_SUN_STAR_XFORMS_XDATATYPEREPOSITORY_HPP
#define INCLUDED_COM_SUN_STAR_XFORMS_XDATATYPEREPOSITORY_HPP

#include "sal/config.h"

#include "com/sun/star/xforms/XDataTypeRepository.hdl"

#include "com/sun/star/container/XEnumerationAccess.hpp"
#include "com/sun/star/container/XNameAccess.hpp"
#include "com/sun/star/xsd/XDataType.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace xforms {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xforms::XDataTypeRepository const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XEnumerationAccess > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::container::XNameAccess > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xforms.XDataTypeRepository", 2, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xforms::XDataTypeRepository > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xforms::XDataTypeRepository > >::get();
}

::css::uno::Type const & ::css::xforms::XDataTypeRepository::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xforms::XDataTypeRepository >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XFORMS_XDATATYPEREPOSITORY_HPP
