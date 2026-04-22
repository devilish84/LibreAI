#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_XSCRIPTPROVIDERSUPPLIER_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_XSCRIPTPROVIDERSUPPLIER_HPP

#include "sal/config.h"

#include "com/sun/star/script/provider/XScriptProviderSupplier.hdl"

#include "com/sun/star/script/provider/XScriptProvider.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace script { namespace provider {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::provider::XScriptProviderSupplier const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.script.provider.XScriptProviderSupplier", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::script::provider::XScriptProviderSupplier > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::script::provider::XScriptProviderSupplier > >::get();
}

::css::uno::Type const & ::css::script::provider::XScriptProviderSupplier::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::script::provider::XScriptProviderSupplier >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_XSCRIPTPROVIDERSUPPLIER_HPP
