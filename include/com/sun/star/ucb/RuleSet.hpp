#ifndef INCLUDED_COM_SUN_STAR_UCB_RULESET_HPP
#define INCLUDED_COM_SUN_STAR_UCB_RULESET_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/RuleSet.hdl"

#include "com/sun/star/ucb/Rule.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline RuleSet::RuleSet()
    : Rules()
    , HandleFolder(false)
{
}

inline RuleSet::RuleSet(const ::css::uno::Sequence< ::css::ucb::Rule >& Rules_, const ::sal_Bool& HandleFolder_)
    : Rules(Rules_)
    , HandleFolder(HandleFolder_)
{
}


inline bool operator==(const RuleSet& the_lhs, const RuleSet& the_rhs)
{
    return the_lhs.Rules == the_rhs.Rules
        && the_lhs.HandleFolder == the_rhs.HandleFolder;
}

inline bool operator!=(const RuleSet& the_lhs, const RuleSet& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::RuleSet const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::Rule > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.RuleSet", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::RuleSet const *) {
    return ::cppu::UnoType< ::css::ucb::RuleSet >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_RULESET_HPP
