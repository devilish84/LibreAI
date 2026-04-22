#ifndef INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_CONFIGURATIONCHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_CONFIGURATIONCHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/drawing/framework/ConfigurationChangeEvent.hdl"

#include "com/sun/star/drawing/framework/XConfiguration.hpp"
#include "com/sun/star/drawing/framework/XResourceId.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace drawing { namespace framework {

inline ConfigurationChangeEvent::ConfigurationChangeEvent()
    : ::css::lang::EventObject()
    , Type()
    , Configuration()
    , ResourceId()
    , ResourceObject()
    , UserData()
{
}

inline ConfigurationChangeEvent::ConfigurationChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& Type_, const ::css::uno::Reference< ::css::drawing::framework::XConfiguration >& Configuration_, const ::css::uno::Reference< ::css::drawing::framework::XResourceId >& ResourceId_, const ::css::uno::Reference< ::css::uno::XInterface >& ResourceObject_, const ::css::uno::Any& UserData_)
    : ::css::lang::EventObject(Source_)
    , Type(Type_)
    , Configuration(Configuration_)
    , ResourceId(ResourceId_)
    , ResourceObject(ResourceObject_)
    , UserData(UserData_)
{
}


inline bool operator==(const ConfigurationChangeEvent& the_lhs, const ConfigurationChangeEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Type == the_rhs.Type
        && the_lhs.Configuration == the_rhs.Configuration
        && the_lhs.ResourceId == the_rhs.ResourceId
        && the_lhs.ResourceObject == the_rhs.ResourceObject
        && the_lhs.UserData == the_rhs.UserData;
}

inline bool operator!=(const ConfigurationChangeEvent& the_lhs, const ConfigurationChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace drawing { namespace framework {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::drawing::framework::ConfigurationChangeEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::framework::XConfiguration > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::drawing::framework::XResourceId > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.drawing.framework.ConfigurationChangeEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::drawing::framework::ConfigurationChangeEvent const *) {
    return ::cppu::UnoType< ::css::drawing::framework::ConfigurationChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_CONFIGURATIONCHANGEEVENT_HPP
