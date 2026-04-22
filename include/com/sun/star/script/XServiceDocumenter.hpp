#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_XSERVICEDOCUMENTER_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_XSERVICEDOCUMENTER_HPP

#include "sal/config.h"

#include "com/sun/star/script/XServiceDocumenter.hdl"

#include "com/sun/star/lang/XServiceInfo.hpp"
#include "com/sun/star/lang/XTypeProvider.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::XServiceDocumenter const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.script.XServiceDocumenter", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::script::XServiceDocumenter > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::script::XServiceDocumenter > >::get();
}

::css::uno::Type const & ::css::script::XServiceDocumenter::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::script::XServiceDocumenter >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_XSERVICEDOCUMENTER_HPP
