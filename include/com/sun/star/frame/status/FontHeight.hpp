#ifndef INCLUDED_COM_SUN_STAR_FRAME_STATUS_FONTHEIGHT_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_STATUS_FONTHEIGHT_HPP

#include "sal/config.h"

#include "com/sun/star/frame/status/FontHeight.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline FontHeight::FontHeight()
    : Height(0)
    , Prop(0)
    , Diff(0)
{
}

inline FontHeight::FontHeight(const float& Height_, const ::sal_Int16& Prop_, const float& Diff_)
    : Height(Height_)
    , Prop(Prop_)
    , Diff(Diff_)
{
}


inline bool operator==(const FontHeight& the_lhs, const FontHeight& the_rhs)
{
    return the_lhs.Height == the_rhs.Height
        && the_lhs.Prop == the_rhs.Prop
        && the_lhs.Diff == the_rhs.Diff;
}

inline bool operator!=(const FontHeight& the_lhs, const FontHeight& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::status::FontHeight const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< float >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< float >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.status.FontHeight", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::status::FontHeight const *) {
    return ::cppu::UnoType< ::css::frame::status::FontHeight >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_STATUS_FONTHEIGHT_HPP
