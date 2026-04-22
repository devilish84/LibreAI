#ifndef INCLUDED_COM_SUN_STAR_UCB_TRANSFERRESULT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_TRANSFERRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/TransferResult.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline TransferResult::TransferResult()
    : Source()
    , Target()
    , Result()
{
}

inline TransferResult::TransferResult(const ::rtl::OUString& Source_, const ::rtl::OUString& Target_, const ::css::uno::Any& Result_)
    : Source(Source_)
    , Target(Target_)
    , Result(Result_)
{
}


inline bool operator==(const TransferResult& the_lhs, const TransferResult& the_rhs)
{
    return the_lhs.Source == the_rhs.Source
        && the_lhs.Target == the_rhs.Target
        && the_lhs.Result == the_rhs.Result;
}

inline bool operator!=(const TransferResult& the_lhs, const TransferResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::TransferResult const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.TransferResult", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::TransferResult const *) {
    return ::cppu::UnoType< ::css::ucb::TransferResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_TRANSFERRESULT_HPP
