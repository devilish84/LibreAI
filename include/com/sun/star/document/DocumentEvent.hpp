#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_DOCUMENTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_DOCUMENTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/document/DocumentEvent.hdl"

#include "com/sun/star/frame/XController2.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace document {

inline DocumentEvent::DocumentEvent()
    : ::css::lang::EventObject()
    , EventName()
    , ViewController()
    , Supplement()
{
}

inline DocumentEvent::DocumentEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& EventName_, const ::css::uno::Reference< ::css::frame::XController2 >& ViewController_, const ::css::uno::Any& Supplement_)
    : ::css::lang::EventObject(Source_)
    , EventName(EventName_)
    , ViewController(ViewController_)
    , Supplement(Supplement_)
{
}


inline bool operator==(const DocumentEvent& the_lhs, const DocumentEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.EventName == the_rhs.EventName
        && the_lhs.ViewController == the_rhs.ViewController
        && the_lhs.Supplement == the_rhs.Supplement;
}

inline bool operator!=(const DocumentEvent& the_lhs, const DocumentEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::DocumentEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::frame::XController2 > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.document.DocumentEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::document::DocumentEvent const *) {
    return ::cppu::UnoType< ::css::document::DocumentEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_DOCUMENTEVENT_HPP
