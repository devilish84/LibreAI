#ifndef INCLUDED_COM_SUN_STAR_ANIMATIONS_EVENT_HPP
#define INCLUDED_COM_SUN_STAR_ANIMATIONS_EVENT_HPP

#include "sal/config.h"

#include "com/sun/star/animations/Event.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace animations {

inline Event::Event()
    : Source()
    , Trigger(0)
    , Offset()
    , Repeat(0)
{
}

inline Event::Event(const ::css::uno::Any& Source_, const ::sal_Int16& Trigger_, const ::css::uno::Any& Offset_, const ::sal_uInt16& Repeat_)
    : Source(Source_)
    , Trigger(Trigger_)
    , Offset(Offset_)
    , Repeat(Repeat_)
{
}


inline bool operator==(const Event& the_lhs, const Event& the_rhs)
{
    return the_lhs.Source == the_rhs.Source
        && the_lhs.Trigger == the_rhs.Trigger
        && the_lhs.Offset == the_rhs.Offset
        && the_lhs.Repeat == the_rhs.Repeat;
}

inline bool operator!=(const Event& the_lhs, const Event& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace animations {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::animations::Event const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoUnsignedShortType >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.animations.Event", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::animations::Event const *) {
    return ::cppu::UnoType< ::css::animations::Event >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ANIMATIONS_EVENT_HPP
