#ifndef INCLUDED_COM_SUN_STAR_SHEET_SOLVERCONSTRAINT_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_SOLVERCONSTRAINT_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/SolverConstraint.hdl"

#include "com/sun/star/sheet/SolverConstraintOperator.hpp"
#include "com/sun/star/table/CellAddress.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline SolverConstraint::SolverConstraint()
    : Left()
    , Operator(::css::sheet::SolverConstraintOperator_LESS_EQUAL)
    , Right()
{
}

inline SolverConstraint::SolverConstraint(const ::css::table::CellAddress& Left_, const ::css::sheet::SolverConstraintOperator& Operator_, const ::css::uno::Any& Right_)
    : Left(Left_)
    , Operator(Operator_)
    , Right(Right_)
{
}


inline bool operator==(const SolverConstraint& the_lhs, const SolverConstraint& the_rhs)
{
    return the_lhs.Left == the_rhs.Left
        && the_lhs.Operator == the_rhs.Operator
        && the_lhs.Right == the_rhs.Right;
}

inline bool operator!=(const SolverConstraint& the_lhs, const SolverConstraint& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::SolverConstraint const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::table::CellAddress >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::sheet::SolverConstraintOperator >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.SolverConstraint", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::SolverConstraint const *) {
    return ::cppu::UnoType< ::css::sheet::SolverConstraint >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_SOLVERCONSTRAINT_HPP
