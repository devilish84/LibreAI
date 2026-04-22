#ifndef INCLUDED_COM_SUN_STAR_FRAME_STATUS_LEFTRIGHTMARGINSCALE_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_STATUS_LEFTRIGHTMARGINSCALE_HPP

#include "sal/config.h"

#include "com/sun/star/frame/status/LeftRightMarginScale.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline LeftRightMarginScale::LeftRightMarginScale()
    : TextLeft(0)
    , Left(0)
    , Right(0)
    , FirstLine(0)
    , ScaleLeft(0)
    , ScaleRight(0)
    , ScaleFirstLine(0)
    , AutoFirstLine(false)
{
}

inline LeftRightMarginScale::LeftRightMarginScale(const ::sal_Int32& TextLeft_, const ::sal_Int32& Left_, const ::sal_Int32& Right_, const ::sal_Int32& FirstLine_, const ::sal_Int32& ScaleLeft_, const ::sal_Int32& ScaleRight_, const ::sal_Int32& ScaleFirstLine_, const ::sal_Bool& AutoFirstLine_)
    : TextLeft(TextLeft_)
    , Left(Left_)
    , Right(Right_)
    , FirstLine(FirstLine_)
    , ScaleLeft(ScaleLeft_)
    , ScaleRight(ScaleRight_)
    , ScaleFirstLine(ScaleFirstLine_)
    , AutoFirstLine(AutoFirstLine_)
{
}


inline bool operator==(const LeftRightMarginScale& the_lhs, const LeftRightMarginScale& the_rhs)
{
    return the_lhs.TextLeft == the_rhs.TextLeft
        && the_lhs.Left == the_rhs.Left
        && the_lhs.Right == the_rhs.Right
        && the_lhs.FirstLine == the_rhs.FirstLine
        && the_lhs.ScaleLeft == the_rhs.ScaleLeft
        && the_lhs.ScaleRight == the_rhs.ScaleRight
        && the_lhs.ScaleFirstLine == the_rhs.ScaleFirstLine
        && the_lhs.AutoFirstLine == the_rhs.AutoFirstLine;
}

inline bool operator!=(const LeftRightMarginScale& the_lhs, const LeftRightMarginScale& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::status::LeftRightMarginScale const *) {
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
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.status.LeftRightMarginScale", 0, 8, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::status::LeftRightMarginScale const *) {
    return ::cppu::UnoType< ::css::frame::status::LeftRightMarginScale >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_STATUS_LEFTRIGHTMARGINSCALE_HPP
