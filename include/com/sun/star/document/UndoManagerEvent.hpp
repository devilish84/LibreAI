#ifndef INCLUDED_COM_SUN_STAR_DOCUMENT_UNDOMANAGEREVENT_HPP
#define INCLUDED_COM_SUN_STAR_DOCUMENT_UNDOMANAGEREVENT_HPP

#include "sal/config.h"

#include "com/sun/star/document/UndoManagerEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace document {

inline UndoManagerEvent::UndoManagerEvent()
    : ::css::lang::EventObject()
    , UndoActionTitle()
    , UndoContextDepth(0)
{
}

inline UndoManagerEvent::UndoManagerEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& UndoActionTitle_, const ::sal_Int32& UndoContextDepth_)
    : ::css::lang::EventObject(Source_)
    , UndoActionTitle(UndoActionTitle_)
    , UndoContextDepth(UndoContextDepth_)
{
}


inline bool operator==(const UndoManagerEvent& the_lhs, const UndoManagerEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.UndoActionTitle == the_rhs.UndoActionTitle
        && the_lhs.UndoContextDepth == the_rhs.UndoContextDepth;
}

inline bool operator!=(const UndoManagerEvent& the_lhs, const UndoManagerEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace document {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::document::UndoManagerEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.document.UndoManagerEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::document::UndoManagerEvent const *) {
    return ::cppu::UnoType< ::css::document::UndoManagerEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DOCUMENT_UNDOMANAGEREVENT_HPP
