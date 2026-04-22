#ifndef INCLUDED_COM_SUN_STAR_FRAME_STATUS_ITEMSTATUS_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_STATUS_ITEMSTATUS_HPP

#include "sal/config.h"

#include "com/sun/star/frame/status/ItemStatus.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ItemStatus::ItemStatus()
    : State(0)
    , aStateData()
{
}

inline ItemStatus::ItemStatus(const ::sal_Int16& State_, const ::css::uno::Any& aStateData_)
    : State(State_)
    , aStateData(aStateData_)
{
}


inline bool operator==(const ItemStatus& the_lhs, const ItemStatus& the_rhs)
{
    return the_lhs.State == the_rhs.State
        && the_lhs.aStateData == the_rhs.aStateData;
}

inline bool operator!=(const ItemStatus& the_lhs, const ItemStatus& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::status::ItemStatus const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.status.ItemStatus", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::status::ItemStatus const *) {
    return ::cppu::UnoType< ::css::frame::status::ItemStatus >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_STATUS_ITEMSTATUS_HPP
