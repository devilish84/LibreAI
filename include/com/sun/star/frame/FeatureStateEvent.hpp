#ifndef INCLUDED_COM_SUN_STAR_FRAME_FEATURESTATEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_FEATURESTATEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/frame/FeatureStateEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/util/URL.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline FeatureStateEvent::FeatureStateEvent()
    : ::css::lang::EventObject()
    , FeatureURL()
    , FeatureDescriptor()
    , IsEnabled(false)
    , Requery(false)
    , State()
{
}

inline FeatureStateEvent::FeatureStateEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::util::URL& FeatureURL_, const ::rtl::OUString& FeatureDescriptor_, const ::sal_Bool& IsEnabled_, const ::sal_Bool& Requery_, const ::css::uno::Any& State_)
    : ::css::lang::EventObject(Source_)
    , FeatureURL(FeatureURL_)
    , FeatureDescriptor(FeatureDescriptor_)
    , IsEnabled(IsEnabled_)
    , Requery(Requery_)
    , State(State_)
{
}


inline bool operator==(const FeatureStateEvent& the_lhs, const FeatureStateEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.FeatureURL == the_rhs.FeatureURL
        && the_lhs.FeatureDescriptor == the_rhs.FeatureDescriptor
        && the_lhs.IsEnabled == the_rhs.IsEnabled
        && the_lhs.Requery == the_rhs.Requery
        && the_lhs.State == the_rhs.State;
}

inline bool operator!=(const FeatureStateEvent& the_lhs, const FeatureStateEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::FeatureStateEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::util::URL >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.FeatureStateEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::FeatureStateEvent const *) {
    return ::cppu::UnoType< ::css::frame::FeatureStateEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_FEATURESTATEEVENT_HPP
