#ifndef INCLUDED_COM_SUN_STAR_UTIL_CHANGESEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_CHANGESEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/util/ChangesEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/util/ChangesSet.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline ChangesEvent::ChangesEvent()
    : ::css::lang::EventObject()
    , Base()
    , Changes()
{
}

inline ChangesEvent::ChangesEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Any& Base_, const ::css::uno::Sequence< ::css::util::ElementChange >& Changes_)
    : ::css::lang::EventObject(Source_)
    , Base(Base_)
    , Changes(Changes_)
{
}


inline bool operator==(const ChangesEvent& the_lhs, const ChangesEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Base == the_rhs.Base
        && the_lhs.Changes == the_rhs.Changes;
}

inline bool operator!=(const ChangesEvent& the_lhs, const ChangesEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::ChangesEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::util::ElementChange > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.ChangesEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::ChangesEvent const *) {
    return ::cppu::UnoType< ::css::util::ChangesEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_CHANGESEVENT_HPP
