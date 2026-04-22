#ifndef INCLUDED_COM_SUN_STAR_AWT_SYSTEMDEPENDENTXWINDOW_HPP
#define INCLUDED_COM_SUN_STAR_AWT_SYSTEMDEPENDENTXWINDOW_HPP

#include "sal/config.h"

#include "com/sun/star/awt/SystemDependentXWindow.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline SystemDependentXWindow::SystemDependentXWindow()
    : WindowHandle(0)
    , DisplayPointer(0)
{
}

inline SystemDependentXWindow::SystemDependentXWindow(const ::sal_Int32& WindowHandle_, const ::sal_Int64& DisplayPointer_)
    : WindowHandle(WindowHandle_)
    , DisplayPointer(DisplayPointer_)
{
}


inline bool operator==(const SystemDependentXWindow& the_lhs, const SystemDependentXWindow& the_rhs)
{
    return the_lhs.WindowHandle == the_rhs.WindowHandle
        && the_lhs.DisplayPointer == the_rhs.DisplayPointer;
}

inline bool operator!=(const SystemDependentXWindow& the_lhs, const SystemDependentXWindow& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::SystemDependentXWindow const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int64 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.SystemDependentXWindow", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::SystemDependentXWindow const *) {
    return ::cppu::UnoType< ::css::awt::SystemDependentXWindow >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_SYSTEMDEPENDENTXWINDOW_HPP
