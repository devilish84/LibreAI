#ifndef INCLUDED_COM_SUN_STAR_FRAME_CONTROLEVENT_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_CONTROLEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/frame/ControlEvent.hdl"

#include "com/sun/star/beans/NamedValue.hpp"
#include "com/sun/star/util/URL.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline ControlEvent::ControlEvent()
    : aURL()
    , Event()
    , aInformation()
{
}

inline ControlEvent::ControlEvent(const ::css::util::URL& aURL_, const ::rtl::OUString& Event_, const ::css::uno::Sequence< ::css::beans::NamedValue >& aInformation_)
    : aURL(aURL_)
    , Event(Event_)
    , aInformation(aInformation_)
{
}


inline bool operator==(const ControlEvent& the_lhs, const ControlEvent& the_rhs)
{
    return the_lhs.aURL == the_rhs.aURL
        && the_lhs.Event == the_rhs.Event
        && the_lhs.aInformation == the_rhs.aInformation;
}

inline bool operator!=(const ControlEvent& the_lhs, const ControlEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::ControlEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::util::URL >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::NamedValue > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.ControlEvent", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::ControlEvent const *) {
    return ::cppu::UnoType< ::css::frame::ControlEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_CONTROLEVENT_HPP
