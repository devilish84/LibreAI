#ifndef INCLUDED_COM_SUN_STAR_UCB_PROPERTYVALUEINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_PROPERTYVALUEINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/PropertyValueInfo.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/ucb/PropertyValueState.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline PropertyValueInfo::PropertyValueInfo()
    : ::css::beans::PropertyValue()
    , ValueState(::css::ucb::PropertyValueState_UNPROCESSED)
{
}

inline PropertyValueInfo::PropertyValueInfo(const ::rtl::OUString& Name_, const ::sal_Int32& Handle_, const ::css::uno::Any& Value_, const ::css::beans::PropertyState& State_, const ::css::ucb::PropertyValueState& ValueState_)
    : ::css::beans::PropertyValue(Name_, Handle_, Value_, State_)
    , ValueState(ValueState_)
{
}


inline bool operator==(const PropertyValueInfo& the_lhs, const PropertyValueInfo& the_rhs)
{
    return operator==( static_cast< ::css::beans::PropertyValue>(the_lhs), static_cast< ::css::beans::PropertyValue>(the_rhs) )

        && the_lhs.ValueState == the_rhs.ValueState;
}

inline bool operator!=(const PropertyValueInfo& the_lhs, const PropertyValueInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyValueInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::ucb::PropertyValueState >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.PropertyValueInfo", ::cppu::UnoType< ::css::beans::PropertyValue >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyValueInfo const *) {
    return ::cppu::UnoType< ::css::ucb::PropertyValueInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_PROPERTYVALUEINFO_HPP
