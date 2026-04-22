#ifndef INCLUDED_COM_SUN_STAR_AWT_ADJUSTMENTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_ADJUSTMENTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/AdjustmentEvent.hdl"

#include "com/sun/star/awt/AdjustmentType.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline AdjustmentEvent::AdjustmentEvent()
    : ::css::lang::EventObject()
    , Value(0)
    , Type(::css::awt::AdjustmentType_ADJUST_LINE)
{
}

inline AdjustmentEvent::AdjustmentEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& Value_, const ::css::awt::AdjustmentType& Type_)
    : ::css::lang::EventObject(Source_)
    , Value(Value_)
    , Type(Type_)
{
}


inline bool operator==(const AdjustmentEvent& the_lhs, const AdjustmentEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Value == the_rhs.Value
        && the_lhs.Type == the_rhs.Type;
}

inline bool operator!=(const AdjustmentEvent& the_lhs, const AdjustmentEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::AdjustmentEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::AdjustmentType >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.AdjustmentEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::AdjustmentEvent const *) {
    return ::cppu::UnoType< ::css::awt::AdjustmentEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_ADJUSTMENTEVENT_HPP
