#ifndef INCLUDED_COM_SUN_STAR_UCB_CONTENTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CONTENTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ContentEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/ucb/XContent.hpp"
#include "com/sun/star/ucb/XContentIdentifier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ContentEvent::ContentEvent()
    : ::css::lang::EventObject()
    , Action(0)
    , Content()
    , Id()
{
}

inline ContentEvent::ContentEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& Action_, const ::css::uno::Reference< ::css::ucb::XContent >& Content_, const ::css::uno::Reference< ::css::ucb::XContentIdentifier >& Id_)
    : ::css::lang::EventObject(Source_)
    , Action(Action_)
    , Content(Content_)
    , Id(Id_)
{
}


inline bool operator==(const ContentEvent& the_lhs, const ContentEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Action == the_rhs.Action
        && the_lhs.Content == the_rhs.Content
        && the_lhs.Id == the_rhs.Id;
}

inline bool operator!=(const ContentEvent& the_lhs, const ContentEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ContentEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContent > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContentIdentifier > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.ContentEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ContentEvent const *) {
    return ::cppu::UnoType< ::css::ucb::ContentEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CONTENTEVENT_HPP
