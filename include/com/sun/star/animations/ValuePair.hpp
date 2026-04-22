#ifndef INCLUDED_COM_SUN_STAR_ANIMATIONS_VALUEPAIR_HPP
#define INCLUDED_COM_SUN_STAR_ANIMATIONS_VALUEPAIR_HPP

#include "sal/config.h"

#include "com/sun/star/animations/ValuePair.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace animations {

inline ValuePair::ValuePair()
    : First()
    , Second()
{
}

inline ValuePair::ValuePair(const ::css::uno::Any& First_, const ::css::uno::Any& Second_)
    : First(First_)
    , Second(Second_)
{
}


inline bool operator==(const ValuePair& the_lhs, const ValuePair& the_rhs)
{
    return the_lhs.First == the_rhs.First
        && the_lhs.Second == the_rhs.Second;
}

inline bool operator!=(const ValuePair& the_lhs, const ValuePair& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace animations {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::animations::ValuePair const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.animations.ValuePair", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::animations::ValuePair const *) {
    return ::cppu::UnoType< ::css::animations::ValuePair >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ANIMATIONS_VALUEPAIR_HPP
