#ifndef INCLUDED_COM_SUN_STAR_UCB_FETCHRESULT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_FETCHRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/FetchResult.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline FetchResult::FetchResult()
    : Rows()
    , StartIndex(0)
    , Orientation(false)
    , FetchError(0)
{
}

inline FetchResult::FetchResult(const ::css::uno::Sequence< ::css::uno::Any >& Rows_, const ::sal_Int32& StartIndex_, const ::sal_Bool& Orientation_, const ::sal_Int16& FetchError_)
    : Rows(Rows_)
    , StartIndex(StartIndex_)
    , Orientation(Orientation_)
    , FetchError(FetchError_)
{
}


inline bool operator==(const FetchResult& the_lhs, const FetchResult& the_rhs)
{
    return the_lhs.Rows == the_rhs.Rows
        && the_lhs.StartIndex == the_rhs.StartIndex
        && the_lhs.Orientation == the_rhs.Orientation
        && the_lhs.FetchError == the_rhs.FetchError;
}

inline bool operator!=(const FetchResult& the_lhs, const FetchResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::FetchResult const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::uno::Any > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.FetchResult", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::FetchResult const *) {
    return ::cppu::UnoType< ::css::ucb::FetchResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_FETCHRESULT_HPP
