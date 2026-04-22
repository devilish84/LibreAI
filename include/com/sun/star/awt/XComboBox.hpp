#ifndef INCLUDED_COM_SUN_STAR_AWT_XCOMBOBOX_HPP
#define INCLUDED_COM_SUN_STAR_AWT_XCOMBOBOX_HPP

#include "sal/config.h"

#include "com/sun/star/awt/XComboBox.hdl"

#include "com/sun/star/awt/XActionListener.hpp"
#include "com/sun/star/awt/XItemListener.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::XComboBox const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.awt.XComboBox", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::awt::XComboBox > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XComboBox > >::get();
}

::css::uno::Type const & ::css::awt::XComboBox::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::awt::XComboBox >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_XCOMBOBOX_HPP
