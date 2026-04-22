#ifndef INCLUDED_COM_SUN_STAR_SHEET_RESULTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_RESULTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/ResultEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline ResultEvent::ResultEvent()
    : ::css::lang::EventObject()
    , Value()
{
}

inline ResultEvent::ResultEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Any& Value_)
    : ::css::lang::EventObject(Source_)
    , Value(Value_)
{
}


inline bool operator==(const ResultEvent& the_lhs, const ResultEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Value == the_rhs.Value;
}

inline bool operator!=(const ResultEvent& the_lhs, const ResultEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::ResultEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.ResultEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::ResultEvent const *) {
    return ::cppu::UnoType< ::css::sheet::ResultEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_RESULTEVENT_HPP
