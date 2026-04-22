#ifndef INCLUDED_COM_SUN_STAR_SDB_XQUERYDEFINITION_HPP
#define INCLUDED_COM_SUN_STAR_SDB_XQUERYDEFINITION_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/XQueryDefinition.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/ucb/XContent.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::XQueryDefinition const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ucb::XContent > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sdb.XQueryDefinition", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdb::XQueryDefinition > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdb::XQueryDefinition > >::get();
}

::css::uno::Type const & ::css::sdb::XQueryDefinition::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdb::XQueryDefinition >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_XQUERYDEFINITION_HPP
