#ifndef INCLUDED_COM_SUN_STAR_AWT_ITEMEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_ITEMEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/ItemEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline ItemEvent::ItemEvent()
    : ::css::lang::EventObject()
    , Selected(0)
    , Highlighted(0)
    , ItemId(0)
{
}

inline ItemEvent::ItemEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& Selected_, const ::sal_Int32& Highlighted_, const ::sal_Int32& ItemId_)
    : ::css::lang::EventObject(Source_)
    , Selected(Selected_)
    , Highlighted(Highlighted_)
    , ItemId(ItemId_)
{
}


inline bool operator==(const ItemEvent& the_lhs, const ItemEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Selected == the_rhs.Selected
        && the_lhs.Highlighted == the_rhs.Highlighted
        && the_lhs.ItemId == the_rhs.ItemId;
}

inline bool operator!=(const ItemEvent& the_lhs, const ItemEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::ItemEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.ItemEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::ItemEvent const *) {
    return ::cppu::UnoType< ::css::awt::ItemEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_ITEMEVENT_HPP
