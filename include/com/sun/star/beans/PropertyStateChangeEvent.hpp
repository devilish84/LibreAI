#ifndef INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSTATECHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSTATECHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/beans/PropertyStateChangeEvent.hdl"

#include "com/sun/star/beans/PropertyState.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

inline PropertyStateChangeEvent::PropertyStateChangeEvent()
    : ::css::lang::EventObject()
    , PropertyName()
    , PropertyHandle(0)
    , OldValue(::css::beans::PropertyState_DIRECT_VALUE)
    , NewValue(::css::beans::PropertyState_DIRECT_VALUE)
{
}

inline PropertyStateChangeEvent::PropertyStateChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& PropertyName_, const ::sal_Int32& PropertyHandle_, const ::css::beans::PropertyState& OldValue_, const ::css::beans::PropertyState& NewValue_)
    : ::css::lang::EventObject(Source_)
    , PropertyName(PropertyName_)
    , PropertyHandle(PropertyHandle_)
    , OldValue(OldValue_)
    , NewValue(NewValue_)
{
}


inline bool operator==(const PropertyStateChangeEvent& the_lhs, const PropertyStateChangeEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.PropertyName == the_rhs.PropertyName
        && the_lhs.PropertyHandle == the_rhs.PropertyHandle
        && the_lhs.OldValue == the_rhs.OldValue
        && the_lhs.NewValue == the_rhs.NewValue;
}

inline bool operator!=(const PropertyStateChangeEvent& the_lhs, const PropertyStateChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::PropertyStateChangeEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::beans::PropertyState >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::beans::PropertyState >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.beans.PropertyStateChangeEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::PropertyStateChangeEvent const *) {
    return ::cppu::UnoType< ::css::beans::PropertyStateChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSTATECHANGEEVENT_HPP
