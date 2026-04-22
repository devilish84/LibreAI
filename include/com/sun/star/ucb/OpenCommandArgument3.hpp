#ifndef INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT3_HPP
#define INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT3_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/OpenCommandArgument3.hdl"

#include "com/sun/star/beans/NamedValue.hpp"
#include "com/sun/star/ucb/OpenCommandArgument2.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline OpenCommandArgument3::OpenCommandArgument3()
    : ::css::ucb::OpenCommandArgument2()
    , OpeningFlags()
{
}

inline OpenCommandArgument3::OpenCommandArgument3(const ::sal_Int32& Mode_, const ::sal_Int32& Priority_, const ::css::uno::Reference< ::css::uno::XInterface >& Sink_, const ::css::uno::Sequence< ::css::beans::Property >& Properties_, const ::css::uno::Sequence< ::css::ucb::NumberedSortingInfo >& SortingInfo_, const ::css::uno::Sequence< ::css::beans::NamedValue >& OpeningFlags_)
    : ::css::ucb::OpenCommandArgument2(Mode_, Priority_, Sink_, Properties_, SortingInfo_)
    , OpeningFlags(OpeningFlags_)
{
}


inline bool operator==(const OpenCommandArgument3& the_lhs, const OpenCommandArgument3& the_rhs)
{
    return operator==( static_cast< ::css::ucb::OpenCommandArgument2>(the_lhs), static_cast< ::css::ucb::OpenCommandArgument2>(the_rhs) )

        && the_lhs.OpeningFlags == the_rhs.OpeningFlags;
}

inline bool operator!=(const OpenCommandArgument3& the_lhs, const OpenCommandArgument3& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument3 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::NamedValue > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.OpenCommandArgument3", ::cppu::UnoType< ::css::ucb::OpenCommandArgument2 >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument3 const *) {
    return ::cppu::UnoType< ::css::ucb::OpenCommandArgument3 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT3_HPP
