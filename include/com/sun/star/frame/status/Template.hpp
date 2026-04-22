#ifndef INCLUDED_COM_SUN_STAR_FRAME_STATUS_TEMPLATE_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_STATUS_TEMPLATE_HPP

#include "sal/config.h"

#include "com/sun/star/frame/status/Template.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline Template::Template()
    : StyleName()
    , Value(0)
    , StyleNameIdentifier()
{
}

inline Template::Template(const ::rtl::OUString& StyleName_, const ::sal_Int32& Value_, const ::rtl::OUString& StyleNameIdentifier_)
    : StyleName(StyleName_)
    , Value(Value_)
    , StyleNameIdentifier(StyleNameIdentifier_)
{
}


inline bool operator==(const Template& the_lhs, const Template& the_rhs)
{
    return the_lhs.StyleName == the_rhs.StyleName
        && the_lhs.Value == the_rhs.Value
        && the_lhs.StyleNameIdentifier == the_rhs.StyleNameIdentifier;
}

inline bool operator!=(const Template& the_lhs, const Template& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::status::Template const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.status.Template", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::status::Template const *) {
    return ::cppu::UnoType< ::css::frame::status::Template >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_STATUS_TEMPLATE_HPP
