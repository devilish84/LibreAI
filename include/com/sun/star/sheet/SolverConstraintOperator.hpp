#ifndef INCLUDED_COM_SUN_STAR_SHEET_SOLVERCONSTRAINTOPERATOR_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_SOLVERCONSTRAINTOPERATOR_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/SolverConstraintOperator.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::SolverConstraintOperator const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_enum_type_init( &the_type,
                                       "com.sun.star.sheet.SolverConstraintOperator",
                                       ::css::sheet::SolverConstraintOperator_LESS_EQUAL );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::SolverConstraintOperator const *) {
    return ::cppu::UnoType< ::css::sheet::SolverConstraintOperator >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_SOLVERCONSTRAINTOPERATOR_HPP
