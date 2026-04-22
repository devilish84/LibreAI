#ifndef INCLUDED_COM_SUN_STAR_SHEET_XGOALSEEK_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_XGOALSEEK_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/XGoalSeek.hdl"

#include "com/sun/star/sheet/GoalResult.hpp"
#include "com/sun/star/table/CellAddress.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::XGoalSeek const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.sheet.XGoalSeek", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sheet::XGoalSeek > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sheet::XGoalSeek > >::get();
}

::css::uno::Type const & ::css::sheet::XGoalSeek::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sheet::XGoalSeek >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_XGOALSEEK_HPP
