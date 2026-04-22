#ifndef INCLUDED_COM_SUN_STAR_FRAME_STATUS_LEFTRIGHTMARGIN_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_STATUS_LEFTRIGHTMARGIN_HPP

#include "sal/config.h"

#include "com/sun/star/frame/status/LeftRightMargin.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline LeftRightMargin::LeftRightMargin()
    : Left(0)
    , Right(0)
{
}

inline LeftRightMargin::LeftRightMargin(const ::sal_Int32& Left_, const ::sal_Int32& Right_)
    : Left(Left_)
    , Right(Right_)
{
}


inline bool operator==(const LeftRightMargin& the_lhs, const LeftRightMargin& the_rhs)
{
    return the_lhs.Left == the_rhs.Left
        && the_lhs.Right == the_rhs.Right;
}

inline bool operator!=(const LeftRightMargin& the_lhs, const LeftRightMargin& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::status::LeftRightMargin const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.status.LeftRightMargin", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::status::LeftRightMargin const *) {
    return ::cppu::UnoType< ::css::frame::status::LeftRightMargin >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_STATUS_LEFTRIGHTMARGIN_HPP
