#ifndef INCLUDED_COM_SUN_STAR_SMARTTAGS_XSMARTTAGACTION_HPP
#define INCLUDED_COM_SUN_STAR_SMARTTAGS_XSMARTTAGACTION_HPP

#include "sal/config.h"

#include "com/sun/star/smarttags/XSmartTagAction.hdl"

#include "com/sun/star/container/XStringKeyMap.hpp"
#include "com/sun/star/frame/XController.hpp"
#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/lang/XInitialization.hpp"
#include "com/sun/star/text/XTextRange.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace smarttags {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::smarttags::XSmartTagAction const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XInitialization > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.smarttags.XSmartTagAction", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::smarttags::XSmartTagAction > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::smarttags::XSmartTagAction > >::get();
}

::css::uno::Type const & ::css::smarttags::XSmartTagAction::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::smarttags::XSmartTagAction >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SMARTTAGS_XSMARTTAGACTION_HPP
