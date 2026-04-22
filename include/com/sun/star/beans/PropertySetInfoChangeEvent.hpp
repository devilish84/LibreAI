#ifndef INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSETINFOCHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSETINFOCHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/beans/PropertySetInfoChangeEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

inline PropertySetInfoChangeEvent::PropertySetInfoChangeEvent()
    : ::css::lang::EventObject()
    , Name()
    , Handle(0)
    , Reason(0)
{
}

inline PropertySetInfoChangeEvent::PropertySetInfoChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& Name_, const ::sal_Int32& Handle_, const ::sal_Int32& Reason_)
    : ::css::lang::EventObject(Source_)
    , Name(Name_)
    , Handle(Handle_)
    , Reason(Reason_)
{
}


inline bool operator==(const PropertySetInfoChangeEvent& the_lhs, const PropertySetInfoChangeEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Name == the_rhs.Name
        && the_lhs.Handle == the_rhs.Handle
        && the_lhs.Reason == the_rhs.Reason;
}

inline bool operator!=(const PropertySetInfoChangeEvent& the_lhs, const PropertySetInfoChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::PropertySetInfoChangeEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.beans.PropertySetInfoChangeEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::PropertySetInfoChangeEvent const *) {
    return ::cppu::UnoType< ::css::beans::PropertySetInfoChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSETINFOCHANGEEVENT_HPP
