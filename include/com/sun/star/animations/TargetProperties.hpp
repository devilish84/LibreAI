#ifndef INCLUDED_COM_SUN_STAR_ANIMATIONS_TARGETPROPERTIES_HPP
#define INCLUDED_COM_SUN_STAR_ANIMATIONS_TARGETPROPERTIES_HPP

#include "sal/config.h"

#include "com/sun/star/animations/TargetProperties.hdl"

#include "com/sun/star/beans/NamedValue.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace animations {

inline TargetProperties::TargetProperties()
    : Target()
    , Properties()
{
}

inline TargetProperties::TargetProperties(const ::css::uno::Any& Target_, const ::css::uno::Sequence< ::css::beans::NamedValue >& Properties_)
    : Target(Target_)
    , Properties(Properties_)
{
}


inline bool operator==(const TargetProperties& the_lhs, const TargetProperties& the_rhs)
{
    return the_lhs.Target == the_rhs.Target
        && the_lhs.Properties == the_rhs.Properties;
}

inline bool operator!=(const TargetProperties& the_lhs, const TargetProperties& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace animations {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::animations::TargetProperties const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::NamedValue > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.animations.TargetProperties", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::animations::TargetProperties const *) {
    return ::cppu::UnoType< ::css::animations::TargetProperties >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ANIMATIONS_TARGETPROPERTIES_HPP
