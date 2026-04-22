#ifndef INCLUDED_COM_SUN_STAR_ANIMATIONS_TIMEFILTERPAIR_HPP
#define INCLUDED_COM_SUN_STAR_ANIMATIONS_TIMEFILTERPAIR_HPP

#include "sal/config.h"

#include "com/sun/star/animations/TimeFilterPair.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace animations {

inline TimeFilterPair::TimeFilterPair()
    : Time(0)
    , Progress(0)
{
}

inline TimeFilterPair::TimeFilterPair(const double& Time_, const double& Progress_)
    : Time(Time_)
    , Progress(Progress_)
{
}


inline bool operator==(const TimeFilterPair& the_lhs, const TimeFilterPair& the_rhs)
{
    return the_lhs.Time == the_rhs.Time
        && the_lhs.Progress == the_rhs.Progress;
}

inline bool operator!=(const TimeFilterPair& the_lhs, const TimeFilterPair& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace animations {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::animations::TimeFilterPair const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.animations.TimeFilterPair", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::animations::TimeFilterPair const *) {
    return ::cppu::UnoType< ::css::animations::TimeFilterPair >::get();
}

#endif // INCLUDED_COM_SUN_STAR_ANIMATIONS_TIMEFILTERPAIR_HPP
