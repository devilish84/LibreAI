#ifndef INCLUDED_COM_SUN_STAR_UCB_SEARCHCOMMANDARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_SEARCHCOMMANDARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/SearchCommandArgument.hdl"

#include "com/sun/star/beans/Property.hpp"
#include "com/sun/star/ucb/SearchInfo.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline SearchCommandArgument::SearchCommandArgument()
    : Info()
    , Properties()
{
}

inline SearchCommandArgument::SearchCommandArgument(const ::css::ucb::SearchInfo& Info_, const ::css::uno::Sequence< ::css::beans::Property >& Properties_)
    : Info(Info_)
    , Properties(Properties_)
{
}


inline bool operator==(const SearchCommandArgument& the_lhs, const SearchCommandArgument& the_rhs)
{
    return the_lhs.Info == the_rhs.Info
        && the_lhs.Properties == the_rhs.Properties;
}

inline bool operator!=(const SearchCommandArgument& the_lhs, const SearchCommandArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::SearchCommandArgument const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::ucb::SearchInfo >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::Property > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.SearchCommandArgument", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::SearchCommandArgument const *) {
    return ::cppu::UnoType< ::css::ucb::SearchCommandArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_SEARCHCOMMANDARGUMENT_HPP
