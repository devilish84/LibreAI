#ifndef INCLUDED_COM_SUN_STAR_SHEET_GOALRESULT_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_GOALRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/GoalResult.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline GoalResult::GoalResult()
    : Divergence(0)
    , Result(0)
{
}

inline GoalResult::GoalResult(const double& Divergence_, const double& Result_)
    : Divergence(Divergence_)
    , Result(Result_)
{
}


inline bool operator==(const GoalResult& the_lhs, const GoalResult& the_rhs)
{
    return the_lhs.Divergence == the_rhs.Divergence
        && the_lhs.Result == the_rhs.Result;
}

inline bool operator!=(const GoalResult& the_lhs, const GoalResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::GoalResult const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.GoalResult", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::GoalResult const *) {
    return ::cppu::UnoType< ::css::sheet::GoalResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_GOALRESULT_HPP
