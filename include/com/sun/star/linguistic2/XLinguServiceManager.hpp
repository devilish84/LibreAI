#ifndef INCLUDED_COM_SUN_STAR_LINGUISTIC2_XLINGUSERVICEMANAGER_HPP
#define INCLUDED_COM_SUN_STAR_LINGUISTIC2_XLINGUSERVICEMANAGER_HPP

#include "sal/config.h"

#include "com/sun/star/linguistic2/XLinguServiceManager.hdl"

#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/lang/XEventListener.hpp"
#include "com/sun/star/linguistic2/XHyphenator.hpp"
#include "com/sun/star/linguistic2/XSpellChecker.hpp"
#include "com/sun/star/linguistic2/XThesaurus.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace linguistic2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::linguistic2::XLinguServiceManager const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.linguistic2.XLinguServiceManager", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::linguistic2::XLinguServiceManager > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::linguistic2::XLinguServiceManager > >::get();
}

::css::uno::Type const & ::css::linguistic2::XLinguServiceManager::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::linguistic2::XLinguServiceManager >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LINGUISTIC2_XLINGUSERVICEMANAGER_HPP
