#ifndef INCLUDED_COM_SUN_STAR_FORM_RUNTIME_FEATURESTATE_HPP
#define INCLUDED_COM_SUN_STAR_FORM_RUNTIME_FEATURESTATE_HPP

#include "sal/config.h"

#include "com/sun/star/form/runtime/FeatureState.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace form { namespace runtime {

inline FeatureState::FeatureState()
    : Enabled(false)
    , State()
{
}

inline FeatureState::FeatureState(const ::sal_Bool& Enabled_, const ::css::uno::Any& State_)
    : Enabled(Enabled_)
    , State(State_)
{
}


inline bool operator==(const FeatureState& the_lhs, const FeatureState& the_rhs)
{
    return the_lhs.Enabled == the_rhs.Enabled
        && the_lhs.State == the_rhs.State;
}

inline bool operator!=(const FeatureState& the_lhs, const FeatureState& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace form { namespace runtime {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::form::runtime::FeatureState const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.form.runtime.FeatureState", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::form::runtime::FeatureState const *) {
    return ::cppu::UnoType< ::css::form::runtime::FeatureState >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORM_RUNTIME_FEATURESTATE_HPP
