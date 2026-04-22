#ifndef INCLUDED_COM_SUN_STAR_UI_CONFIGURATIONEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UI_CONFIGURATIONEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/ui/ConfigurationEvent.hdl"

#include "com/sun/star/container/ContainerEvent.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ui {

inline ConfigurationEvent::ConfigurationEvent()
    : ::css::container::ContainerEvent()
    , ResourceURL()
    , aInfo()
{
}

inline ConfigurationEvent::ConfigurationEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Any& Accessor_, const ::css::uno::Any& Element_, const ::css::uno::Any& ReplacedElement_, const ::rtl::OUString& ResourceURL_, const ::css::uno::Any& aInfo_)
    : ::css::container::ContainerEvent(Source_, Accessor_, Element_, ReplacedElement_)
    , ResourceURL(ResourceURL_)
    , aInfo(aInfo_)
{
}


inline bool operator==(const ConfigurationEvent& the_lhs, const ConfigurationEvent& the_rhs)
{
    return operator==( static_cast< ::css::container::ContainerEvent>(the_lhs), static_cast< ::css::container::ContainerEvent>(the_rhs) )

        && the_lhs.ResourceURL == the_rhs.ResourceURL
        && the_lhs.aInfo == the_rhs.aInfo;
}

inline bool operator!=(const ConfigurationEvent& the_lhs, const ConfigurationEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ui {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::ConfigurationEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ui.ConfigurationEvent", ::cppu::UnoType< ::css::container::ContainerEvent >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ui::ConfigurationEvent const *) {
    return ::cppu::UnoType< ::css::ui::ConfigurationEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_CONFIGURATIONEVENT_HPP
