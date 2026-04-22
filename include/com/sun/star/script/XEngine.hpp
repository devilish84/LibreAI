#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_XENGINE_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_XENGINE_HPP

#include "sal/config.h"

#include "com/sun/star/script/XEngine.hdl"

#include "com/sun/star/script/XEngineListener.hpp"
#include "com/sun/star/script/XLibraryAccess.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::XEngine const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.script.XEngine", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::script::XEngine > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::script::XEngine > >::get();
}

::css::uno::Type const & ::css::script::XEngine::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::script::XEngine >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_XENGINE_HPP
