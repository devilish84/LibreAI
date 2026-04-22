#ifndef INCLUDED_COM_SUN_STAR_UCB_SEARCHCRITERIUM_HPP
#define INCLUDED_COM_SUN_STAR_UCB_SEARCHCRITERIUM_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/SearchCriterium.hdl"

#include "com/sun/star/ucb/RuleTerm.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline SearchCriterium::SearchCriterium()
    : Terms()
{
}

inline SearchCriterium::SearchCriterium(const ::css::uno::Sequence< ::css::ucb::RuleTerm >& Terms_)
    : Terms(Terms_)
{
}


inline bool operator==(const SearchCriterium& the_lhs, const SearchCriterium& the_rhs)
{
    return the_lhs.Terms == the_rhs.Terms;
}

inline bool operator!=(const SearchCriterium& the_lhs, const SearchCriterium& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::SearchCriterium const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::RuleTerm > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.SearchCriterium", 0, 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::SearchCriterium const *) {
    return ::cppu::UnoType< ::css::ucb::SearchCriterium >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_SEARCHCRITERIUM_HPP
