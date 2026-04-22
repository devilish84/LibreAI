#ifndef INCLUDED_COM_SUN_STAR_FRAME_XNOTIFYINGDISPATCH_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_XNOTIFYINGDISPATCH_HPP

#include "sal/config.h"

#include "com/sun/star/frame/XNotifyingDispatch.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/frame/XDispatch.hpp"
#include "com/sun/star/frame/XDispatchResultListener.hpp"
#include "com/sun/star/util/URL.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::XNotifyingDispatch const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XDispatch > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.frame.XNotifyingDispatch", 1, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::frame::XNotifyingDispatch > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XNotifyingDispatch > >::get();
}

::css::uno::Type const & ::css::frame::XNotifyingDispatch::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::frame::XNotifyingDispatch >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_XNOTIFYINGDISPATCH_HPP
