#ifndef INCLUDED_COM_SUN_STAR_AWT_WINDOWEVENT_HPP
#define INCLUDED_COM_SUN_STAR_AWT_WINDOWEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/awt/WindowEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline WindowEvent::WindowEvent()
    : ::css::lang::EventObject()
    , X(0)
    , Y(0)
    , Width(0)
    , Height(0)
    , LeftInset(0)
    , TopInset(0)
    , RightInset(0)
    , BottomInset(0)
{
}

inline WindowEvent::WindowEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& X_, const ::sal_Int32& Y_, const ::sal_Int32& Width_, const ::sal_Int32& Height_, const ::sal_Int32& LeftInset_, const ::sal_Int32& TopInset_, const ::sal_Int32& RightInset_, const ::sal_Int32& BottomInset_)
    : ::css::lang::EventObject(Source_)
    , X(X_)
    , Y(Y_)
    , Width(Width_)
    , Height(Height_)
    , LeftInset(LeftInset_)
    , TopInset(TopInset_)
    , RightInset(RightInset_)
    , BottomInset(BottomInset_)
{
}


inline bool operator==(const WindowEvent& the_lhs, const WindowEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.X == the_rhs.X
        && the_lhs.Y == the_rhs.Y
        && the_lhs.Width == the_rhs.Width
        && the_lhs.Height == the_rhs.Height
        && the_lhs.LeftInset == the_rhs.LeftInset
        && the_lhs.TopInset == the_rhs.TopInset
        && the_lhs.RightInset == the_rhs.RightInset
        && the_lhs.BottomInset == the_rhs.BottomInset;
}

inline bool operator!=(const WindowEvent& the_lhs, const WindowEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::WindowEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.WindowEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 8, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::WindowEvent const *) {
    return ::cppu::UnoType< ::css::awt::WindowEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_WINDOWEVENT_HPP
