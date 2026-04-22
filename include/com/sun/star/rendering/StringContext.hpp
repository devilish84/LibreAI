#ifndef INCLUDED_COM_SUN_STAR_RENDERING_STRINGCONTEXT_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_STRINGCONTEXT_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/StringContext.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline StringContext::StringContext()
    : Text()
    , StartPosition(0)
    , Length(0)
{
}

inline StringContext::StringContext(const ::rtl::OUString& Text_, const ::sal_Int32& StartPosition_, const ::sal_Int32& Length_)
    : Text(Text_)
    , StartPosition(StartPosition_)
    , Length(Length_)
{
}


inline bool operator==(const StringContext& the_lhs, const StringContext& the_rhs)
{
    return the_lhs.Text == the_rhs.Text
        && the_lhs.StartPosition == the_rhs.StartPosition
        && the_lhs.Length == the_rhs.Length;
}

inline bool operator!=(const StringContext& the_lhs, const StringContext& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::StringContext const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.StringContext", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::StringContext const *) {
    return ::cppu::UnoType< ::css::rendering::StringContext >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_STRINGCONTEXT_HPP
