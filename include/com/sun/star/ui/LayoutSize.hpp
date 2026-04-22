#ifndef INCLUDED_COM_SUN_STAR_UI_LAYOUTSIZE_HPP
#define INCLUDED_COM_SUN_STAR_UI_LAYOUTSIZE_HPP

#include "sal/config.h"

#include "com/sun/star/ui/LayoutSize.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ui {

inline LayoutSize::LayoutSize()
    : Minimum(0)
    , Maximum(0)
    , Preferred(0)
{
}

inline LayoutSize::LayoutSize(const ::sal_Int32& Minimum_, const ::sal_Int32& Maximum_, const ::sal_Int32& Preferred_)
    : Minimum(Minimum_)
    , Maximum(Maximum_)
    , Preferred(Preferred_)
{
}


inline bool operator==(const LayoutSize& the_lhs, const LayoutSize& the_rhs)
{
    return the_lhs.Minimum == the_rhs.Minimum
        && the_lhs.Maximum == the_rhs.Maximum
        && the_lhs.Preferred == the_rhs.Preferred;
}

inline bool operator!=(const LayoutSize& the_lhs, const LayoutSize& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ui {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ui::LayoutSize const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ui.LayoutSize", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ui::LayoutSize const *) {
    return ::cppu::UnoType< ::css::ui::LayoutSize >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UI_LAYOUTSIZE_HPP
