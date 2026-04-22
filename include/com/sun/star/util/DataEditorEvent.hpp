#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATAEDITOREVENT_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATAEDITOREVENT_HPP

#include "sal/config.h"

#include "com/sun/star/util/DataEditorEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/util/DataEditorEventType.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline DataEditorEvent::DataEditorEvent()
    : ::css::lang::EventObject()
    , Type(::css::util::DataEditorEventType_DONE)
{
}

inline DataEditorEvent::DataEditorEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::util::DataEditorEventType& Type_)
    : ::css::lang::EventObject(Source_)
    , Type(Type_)
{
}


inline bool operator==(const DataEditorEvent& the_lhs, const DataEditorEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Type == the_rhs.Type;
}

inline bool operator!=(const DataEditorEvent& the_lhs, const DataEditorEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DataEditorEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::util::DataEditorEventType >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.DataEditorEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DataEditorEvent const *) {
    return ::cppu::UnoType< ::css::util::DataEditorEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATAEDITOREVENT_HPP
