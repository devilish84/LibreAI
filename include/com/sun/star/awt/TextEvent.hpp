#ifndef INCLUDED_COM_SUN_STAR_AWT_TEXTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_TEXTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/TextEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline TextEvent::TextEvent()
    : ::css::lang::EventObject()
    , dummy1(0)
{
}

inline TextEvent::TextEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int16& dummy1_)
    : ::css::lang::EventObject(Source_)
    , dummy1(dummy1_)
{
}


inline bool operator==(const TextEvent& the_lhs, const TextEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.dummy1 == the_rhs.dummy1;
}

inline bool operator!=(const TextEvent& the_lhs, const TextEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::TextEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.TextEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::TextEvent const *) {
    return ::cppu::UnoType< ::css::awt::TextEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_TEXTEVENT_HPP
