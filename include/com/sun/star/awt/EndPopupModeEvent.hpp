#ifndef INCLUDED_COM_SUN_STAR_AWT_ENDPOPUPMODEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_ENDPOPUPMODEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/EndPopupModeEvent.hdl"

#include "com/sun/star/awt/Point.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline EndPopupModeEvent::EndPopupModeEvent()
    : ::css::lang::EventObject()
    , bTearoff(false)
    , FloatingPosition()
{
}

inline EndPopupModeEvent::EndPopupModeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Bool& bTearoff_, const ::css::awt::Point& FloatingPosition_)
    : ::css::lang::EventObject(Source_)
    , bTearoff(bTearoff_)
    , FloatingPosition(FloatingPosition_)
{
}


inline bool operator==(const EndPopupModeEvent& the_lhs, const EndPopupModeEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.bTearoff == the_rhs.bTearoff
        && the_lhs.FloatingPosition == the_rhs.FloatingPosition;
}

inline bool operator!=(const EndPopupModeEvent& the_lhs, const EndPopupModeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::EndPopupModeEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::Point >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.EndPopupModeEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::EndPopupModeEvent const *) {
    return ::cppu::UnoType< ::css::awt::EndPopupModeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_ENDPOPUPMODEEVENT_HPP
