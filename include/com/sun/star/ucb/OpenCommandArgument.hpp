#ifndef INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/OpenCommandArgument.hdl"

#include "com/sun/star/beans/Property.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline OpenCommandArgument::OpenCommandArgument()
    : Mode(0)
    , Priority(0)
    , Sink()
    , Properties()
{
}

inline OpenCommandArgument::OpenCommandArgument(const ::sal_Int32& Mode_, const ::sal_Int32& Priority_, const ::css::uno::Reference< ::css::uno::XInterface >& Sink_, const ::css::uno::Sequence< ::css::beans::Property >& Properties_)
    : Mode(Mode_)
    , Priority(Priority_)
    , Sink(Sink_)
    , Properties(Properties_)
{
}


inline bool operator==(const OpenCommandArgument& the_lhs, const OpenCommandArgument& the_rhs)
{
    return the_lhs.Mode == the_rhs.Mode
        && the_lhs.Priority == the_rhs.Priority
        && the_lhs.Sink == the_rhs.Sink
        && the_lhs.Properties == the_rhs.Properties;
}

inline bool operator!=(const OpenCommandArgument& the_lhs, const OpenCommandArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::Property > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.OpenCommandArgument", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument const *) {
    return ::cppu::UnoType< ::css::ucb::OpenCommandArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT_HPP
