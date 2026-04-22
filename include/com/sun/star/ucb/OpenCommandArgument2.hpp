#ifndef INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT2_HPP
#define INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT2_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/OpenCommandArgument2.hdl"

#include "com/sun/star/ucb/NumberedSortingInfo.hpp"
#include "com/sun/star/ucb/OpenCommandArgument.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline OpenCommandArgument2::OpenCommandArgument2()
    : ::css::ucb::OpenCommandArgument()
    , SortingInfo()
{
}

inline OpenCommandArgument2::OpenCommandArgument2(const ::sal_Int32& Mode_, const ::sal_Int32& Priority_, const ::css::uno::Reference< ::css::uno::XInterface >& Sink_, const ::css::uno::Sequence< ::css::beans::Property >& Properties_, const ::css::uno::Sequence< ::css::ucb::NumberedSortingInfo >& SortingInfo_)
    : ::css::ucb::OpenCommandArgument(Mode_, Priority_, Sink_, Properties_)
    , SortingInfo(SortingInfo_)
{
}


inline bool operator==(const OpenCommandArgument2& the_lhs, const OpenCommandArgument2& the_rhs)
{
    return operator==( static_cast< ::css::ucb::OpenCommandArgument>(the_lhs), static_cast< ::css::ucb::OpenCommandArgument>(the_rhs) )

        && the_lhs.SortingInfo == the_rhs.SortingInfo;
}

inline bool operator!=(const OpenCommandArgument2& the_lhs, const OpenCommandArgument2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::NumberedSortingInfo > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.OpenCommandArgument2", ::cppu::UnoType< ::css::ucb::OpenCommandArgument >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument2 const *) {
    return ::cppu::UnoType< ::css::ucb::OpenCommandArgument2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT2_HPP
