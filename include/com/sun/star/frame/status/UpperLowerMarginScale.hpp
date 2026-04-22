#ifndef INCLUDED_COM_SUN_STAR_FRAME_STATUS_UPPERLOWERMARGINSCALE_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_STATUS_UPPERLOWERMARGINSCALE_HPP

#include "sal/config.h"

#include "com/sun/star/frame/status/UpperLowerMarginScale.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline UpperLowerMarginScale::UpperLowerMarginScale()
    : Upper(0)
    , Lower(0)
    , ScaleUpper(0)
    , ScaleLower(0)
{
}

inline UpperLowerMarginScale::UpperLowerMarginScale(const ::sal_Int32& Upper_, const ::sal_Int32& Lower_, const ::sal_Int16& ScaleUpper_, const ::sal_Int16& ScaleLower_)
    : Upper(Upper_)
    , Lower(Lower_)
    , ScaleUpper(ScaleUpper_)
    , ScaleLower(ScaleLower_)
{
}


inline bool operator==(const UpperLowerMarginScale& the_lhs, const UpperLowerMarginScale& the_rhs)
{
    return the_lhs.Upper == the_rhs.Upper
        && the_lhs.Lower == the_rhs.Lower
        && the_lhs.ScaleUpper == the_rhs.ScaleUpper
        && the_lhs.ScaleLower == the_rhs.ScaleLower;
}

inline bool operator!=(const UpperLowerMarginScale& the_lhs, const UpperLowerMarginScale& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::status::UpperLowerMarginScale const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.status.UpperLowerMarginScale", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::status::UpperLowerMarginScale const *) {
    return ::cppu::UnoType< ::css::frame::status::UpperLowerMarginScale >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_STATUS_UPPERLOWERMARGINSCALE_HPP
