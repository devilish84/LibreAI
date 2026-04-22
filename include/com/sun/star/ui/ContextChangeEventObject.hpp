#ifndef INCLUDED_COM_SUN_STAR_UI_CONTEXTCHANGEEVENTOBJECT_HPP
#define INCLUDED_COM_SUN_STAR_UI_CONTEXTCHANGEEVENTOBJECT_HPP

#include "sal/config.h"

#include "com/sun/star/ui/ContextChangeEventObject.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ui {

inline ContextChangeEventObject::ContextChangeEventObject()
    : ::css::lang::EventObject()
    , ApplicationName()
    , ContextName()
{
}

inline ContextChangeEventObject::ContextChangeEventObject(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& ApplicationName_, const ::rtl::OUString& ContextName_)
    : ::css::lang::EventObject(Source_)
    , ApplicationName(ApplicationName_)
    , ContextName(ContextName_)
{
}


inline bool operator==(const ContextChangeEventObject& the_lhs, const ContextChangeEventObject& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.ApplicationName == the_rhs.ApplicationName
        && the_lhs.ContextName == the_rhs.ContextName;
}

inline bool operator!=(const ContextChangeEventObject& the_lhs, const ContextChangeEventObject& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ui {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::ContextChangeEventObject const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ui.ContextChangeEventObject", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ui::ContextChangeEventObject const *) {
    return ::cppu::UnoType< ::css::ui::ContextChangeEventObject >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_CONTEXTCHANGEEVENTOBJECT_HPP
