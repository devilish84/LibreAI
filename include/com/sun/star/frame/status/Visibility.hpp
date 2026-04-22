#ifndef INCLUDED_COM_SUN_STAR_FRAME_STATUS_VISIBILITY_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_STATUS_VISIBILITY_HPP

#include "sal/config.h"

#include "com/sun/star/frame/status/Visibility.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline Visibility::Visibility()
    : bVisible(false)
{
}

inline Visibility::Visibility(const ::sal_Bool& bVisible_)
    : bVisible(bVisible_)
{
}


inline bool operator==(const Visibility& the_lhs, const Visibility& the_rhs)
{
    return the_lhs.bVisible == the_rhs.bVisible;
}

inline bool operator!=(const Visibility& the_lhs, const Visibility& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace frame { namespace status {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::status::Visibility const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.status.Visibility", 0, 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::status::Visibility const *) {
    return ::cppu::UnoType< ::css::frame::status::Visibility >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_STATUS_VISIBILITY_HPP
