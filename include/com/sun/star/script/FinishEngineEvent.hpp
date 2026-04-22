#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_FINISHENGINEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_FINISHENGINEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/script/FinishEngineEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/script/FinishReason.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace script {

inline FinishEngineEvent::FinishEngineEvent()
    : ::css::lang::EventObject()
    , Finish(::css::script::FinishReason_OK)
    , ErrorMessage()
    , Return()
{
}

inline FinishEngineEvent::FinishEngineEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::script::FinishReason& Finish_, const ::rtl::OUString& ErrorMessage_, const ::css::uno::Any& Return_)
    : ::css::lang::EventObject(Source_)
    , Finish(Finish_)
    , ErrorMessage(ErrorMessage_)
    , Return(Return_)
{
}


inline bool operator==(const FinishEngineEvent& the_lhs, const FinishEngineEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Finish == the_rhs.Finish
        && the_lhs.ErrorMessage == the_rhs.ErrorMessage
        && the_lhs.Return == the_rhs.Return;
}

inline bool operator!=(const FinishEngineEvent& the_lhs, const FinishEngineEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::FinishEngineEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::script::FinishReason >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.script.FinishEngineEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::FinishEngineEvent const *) {
    return ::cppu::UnoType< ::css::script::FinishEngineEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_FINISHENGINEEVENT_HPP
