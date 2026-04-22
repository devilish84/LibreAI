#ifndef INCLUDED_COM_SUN_STAR_UCB_SEARCHINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_SEARCHINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/SearchInfo.hdl"

#include "com/sun/star/ucb/SearchCriterium.hpp"
#include "com/sun/star/ucb/SearchRecursion.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline SearchInfo::SearchInfo()
    : Criteria()
    , Recursion(::css::ucb::SearchRecursion_NONE)
    , IncludeBase(false)
    , RespectFolderViewRestrictions(false)
    , RespectDocViewRestrictions(false)
    , FollowIndirections(false)
{
}

inline SearchInfo::SearchInfo(const ::css::uno::Sequence< ::css::ucb::SearchCriterium >& Criteria_, const ::css::ucb::SearchRecursion& Recursion_, const ::sal_Bool& IncludeBase_, const ::sal_Bool& RespectFolderViewRestrictions_, const ::sal_Bool& RespectDocViewRestrictions_, const ::sal_Bool& FollowIndirections_)
    : Criteria(Criteria_)
    , Recursion(Recursion_)
    , IncludeBase(IncludeBase_)
    , RespectFolderViewRestrictions(RespectFolderViewRestrictions_)
    , RespectDocViewRestrictions(RespectDocViewRestrictions_)
    , FollowIndirections(FollowIndirections_)
{
}


inline bool operator==(const SearchInfo& the_lhs, const SearchInfo& the_rhs)
{
    return the_lhs.Criteria == the_rhs.Criteria
        && the_lhs.Recursion == the_rhs.Recursion
        && the_lhs.IncludeBase == the_rhs.IncludeBase
        && the_lhs.RespectFolderViewRestrictions == the_rhs.RespectFolderViewRestrictions
        && the_lhs.RespectDocViewRestrictions == the_rhs.RespectDocViewRestrictions
        && the_lhs.FollowIndirections == the_rhs.FollowIndirections;
}

inline bool operator!=(const SearchInfo& the_lhs, const SearchInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::SearchInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::SearchCriterium > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::ucb::SearchRecursion >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.SearchInfo", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::SearchInfo const *) {
    return ::cppu::UnoType< ::css::ucb::SearchInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_SEARCHINFO_HPP
