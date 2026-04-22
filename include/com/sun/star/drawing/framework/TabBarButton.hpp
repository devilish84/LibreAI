#ifndef INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_TABBARBUTTON_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_TABBARBUTTON_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/framework/TabBarButton.hdl"

#include "com/sun/star/drawing/framework/XResourceId.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing { namespace framework {

inline TabBarButton::TabBarButton()
    : ButtonLabel()
    , HelpText()
    , ResourceId()
{
}

inline TabBarButton::TabBarButton(const ::rtl::OUString& ButtonLabel_, const ::rtl::OUString& HelpText_, const ::css::uno::Reference< ::css::drawing::framework::XResourceId >& ResourceId_)
    : ButtonLabel(ButtonLabel_)
    , HelpText(HelpText_)
    , ResourceId(ResourceId_)
{
}


inline bool operator==(const TabBarButton& the_lhs, const TabBarButton& the_rhs)
{
    return the_lhs.ButtonLabel == the_rhs.ButtonLabel
        && the_lhs.HelpText == the_rhs.HelpText
        && the_lhs.ResourceId == the_rhs.ResourceId;
}

inline bool operator!=(const TabBarButton& the_lhs, const TabBarButton& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace drawing { namespace framework {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::framework::TabBarButton const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::framework::XResourceId > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.framework.TabBarButton", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::framework::TabBarButton const *) {
    return ::cppu::UnoType< ::css::drawing::framework::TabBarButton >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_TABBARBUTTON_HPP
