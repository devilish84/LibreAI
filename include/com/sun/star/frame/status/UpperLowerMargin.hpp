#ifndef INCLUDED_COM_SUN_STAR_FRAME_STATUS_UPPERLOWERMARGIN_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_STATUS_UPPERLOWERMARGIN_HPP

#include "sal/config.h"

#include "com/sun/star/frame/status/UpperLowerMargin.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline UpperLowerMargin::UpperLowerMargin()
    : Upper(0)
    , Lower(0)
{
}

inline UpperLowerMargin::UpperLowerMargin(const ::sal_Int32& Upper_, const ::sal_Int32& Lower_)
    : Upper(Upper_)
    , Lower(Lower_)
{
}


inline bool operator==(const UpperLowerMargin& the_lhs, const UpperLowerMargin& the_rhs)
{
    return the_lhs.Upper == the_rhs.Upper
        && the_lhs.Lower == the_rhs.Lower;
}

inline bool operator!=(const UpperLowerMargin& the_lhs, const UpperLowerMargin& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::status::UpperLowerMargin const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.status.UpperLowerMargin", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::status::UpperLowerMargin const *) {
    return ::cppu::UnoType< ::css::frame::status::UpperLowerMargin >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_STATUS_UPPERLOWERMARGIN_HPP
