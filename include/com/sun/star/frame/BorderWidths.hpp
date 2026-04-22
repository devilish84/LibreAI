#ifndef INCLUDED_COM_SUN_STAR_FRAME_BORDERWIDTHS_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_BORDERWIDTHS_HPP

#include "sal/config.h"

#include "com/sun/star/frame/BorderWidths.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline BorderWidths::BorderWidths()
    : Left(0)
    , Top(0)
    , Right(0)
    , Bottom(0)
{
}

inline BorderWidths::BorderWidths(const ::sal_Int32& Left_, const ::sal_Int32& Top_, const ::sal_Int32& Right_, const ::sal_Int32& Bottom_)
    : Left(Left_)
    , Top(Top_)
    , Right(Right_)
    , Bottom(Bottom_)
{
}


inline bool operator==(const BorderWidths& the_lhs, const BorderWidths& the_rhs)
{
    return the_lhs.Left == the_rhs.Left
        && the_lhs.Top == the_rhs.Top
        && the_lhs.Right == the_rhs.Right
        && the_lhs.Bottom == the_rhs.Bottom;
}

inline bool operator!=(const BorderWidths& the_lhs, const BorderWidths& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::BorderWidths const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.BorderWidths", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::BorderWidths const *) {
    return ::cppu::UnoType< ::css::frame::BorderWidths >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_BORDERWIDTHS_HPP
