#ifndef INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_PROPERTYINFO_HPP
#define INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_PROPERTYINFO_HPP

#include "sal/config.h"

#include "com/sun/star/configuration/backend/PropertyInfo.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline PropertyInfo::PropertyInfo()
    : Name()
    , Type()
    , Value()
    , Protected(false)
{
}

inline PropertyInfo::PropertyInfo(const ::rtl::OUString& Name_, const ::rtl::OUString& Type_, const ::css::uno::Any& Value_, const ::sal_Bool& Protected_)
    : Name(Name_)
    , Type(Type_)
    , Value(Value_)
    , Protected(Protected_)
{
}


inline bool operator==(const PropertyInfo& the_lhs, const PropertyInfo& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Type == the_rhs.Type
        && the_lhs.Value == the_rhs.Value
        && the_lhs.Protected == the_rhs.Protected;
}

inline bool operator!=(const PropertyInfo& the_lhs, const PropertyInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace configuration { namespace backend {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::configuration::backend::PropertyInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.configuration.backend.PropertyInfo", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::configuration::backend::PropertyInfo const *) {
    return ::cppu::UnoType< ::css::configuration::backend::PropertyInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONFIGURATION_BACKEND_PROPERTYINFO_HPP
