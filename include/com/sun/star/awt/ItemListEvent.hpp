#ifndef INCLUDED_COM_SUN_STAR_AWT_ITEMLISTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_ITEMLISTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/ItemListEvent.hdl"

#include "com/sun/star/beans/Optional.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline ItemListEvent::ItemListEvent()
    : ::css::lang::EventObject()
    , ItemPosition(0)
    , ItemText()
    , ItemImageURL()
{
}

inline ItemListEvent::ItemListEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& ItemPosition_, const ::css::beans::Optional< ::rtl::OUString >& ItemText_, const ::css::beans::Optional< ::rtl::OUString >& ItemImageURL_)
    : ::css::lang::EventObject(Source_)
    , ItemPosition(ItemPosition_)
    , ItemText(ItemText_)
    , ItemImageURL(ItemImageURL_)
{
}


inline bool operator==(const ItemListEvent& the_lhs, const ItemListEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.ItemPosition == the_rhs.ItemPosition
        && the_lhs.ItemText == the_rhs.ItemText
        && the_lhs.ItemImageURL == the_rhs.ItemImageURL;
}

inline bool operator!=(const ItemListEvent& the_lhs, const ItemListEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::ItemListEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::beans::Optional< ::rtl::OUString > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::beans::Optional< ::rtl::OUString > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.ItemListEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::ItemListEvent const *) {
    return ::cppu::UnoType< ::css::awt::ItemListEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_ITEMLISTEVENT_HPP
