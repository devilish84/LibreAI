#ifndef INCLUDED_COM_SUN_STAR_UCB_PROPERTYCOMMANDARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_PROPERTYCOMMANDARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/PropertyCommandArgument.hdl"

#include "com/sun/star/beans/Property.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline PropertyCommandArgument::PropertyCommandArgument()
    : Property()
    , DefaultValue()
{
}

inline PropertyCommandArgument::PropertyCommandArgument(const ::css::beans::Property& Property_, const ::css::uno::Any& DefaultValue_)
    : Property(Property_)
    , DefaultValue(DefaultValue_)
{
}


inline bool operator==(const PropertyCommandArgument& the_lhs, const PropertyCommandArgument& the_rhs)
{
    return the_lhs.Property == the_rhs.Property
        && the_lhs.DefaultValue == the_rhs.DefaultValue;
}

inline bool operator!=(const PropertyCommandArgument& the_lhs, const PropertyCommandArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyCommandArgument const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::beans::Property >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.PropertyCommandArgument", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyCommandArgument const *) {
    return ::cppu::UnoType< ::css::ucb::PropertyCommandArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_PROPERTYCOMMANDARGUMENT_HPP
