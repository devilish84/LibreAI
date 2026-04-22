#ifndef INCLUDED_COM_SUN_STAR_AWT_WINDOWDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_AWT_WINDOWDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/awt/WindowDescriptor.hdl"

#include "com/sun/star/awt/Rectangle.hpp"
#include "com/sun/star/awt/WindowClass.hpp"
#include "com/sun/star/awt/XWindowPeer.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline WindowDescriptor::WindowDescriptor()
    : Type(::css::awt::WindowClass_TOP)
    , WindowServiceName()
    , Parent()
    , ParentIndex(0)
    , Bounds()
    , WindowAttributes(0)
{
}

inline WindowDescriptor::WindowDescriptor(const ::css::awt::WindowClass& Type_, const ::rtl::OUString& WindowServiceName_, const ::css::uno::Reference< ::css::awt::XWindowPeer >& Parent_, const ::sal_Int16& ParentIndex_, const ::css::awt::Rectangle& Bounds_, const ::sal_Int32& WindowAttributes_)
    : Type(Type_)
    , WindowServiceName(WindowServiceName_)
    , Parent(Parent_)
    , ParentIndex(ParentIndex_)
    , Bounds(Bounds_)
    , WindowAttributes(WindowAttributes_)
{
}


inline bool operator==(const WindowDescriptor& the_lhs, const WindowDescriptor& the_rhs)
{
    return the_lhs.Type == the_rhs.Type
        && the_lhs.WindowServiceName == the_rhs.WindowServiceName
        && the_lhs.Parent == the_rhs.Parent
        && the_lhs.ParentIndex == the_rhs.ParentIndex
        && the_lhs.Bounds == the_rhs.Bounds
        && the_lhs.WindowAttributes == the_rhs.WindowAttributes;
}

inline bool operator!=(const WindowDescriptor& the_lhs, const WindowDescriptor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::WindowDescriptor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::awt::WindowClass >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::awt::XWindowPeer > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::awt::Rectangle >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.WindowDescriptor", 0, 6, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::WindowDescriptor const *) {
    return ::cppu::UnoType< ::css::awt::WindowDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_WINDOWDESCRIPTOR_HPP
