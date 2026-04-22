#ifndef INCLUDED_COM_SUN_STAR_BRIDGE_OLEAUTOMATION_DATE_HPP
#define INCLUDED_COM_SUN_STAR_BRIDGE_OLEAUTOMATION_DATE_HPP

#include "sal/config.h"

#include "com/sun/star/bridge/oleautomation/Date.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace bridge { namespace oleautomation {

inline Date::Date()
    : Value(0)
{
}

inline Date::Date(const double& Value_)
    : Value(Value_)
{
}


inline bool operator==(const Date& the_lhs, const Date& the_rhs)
{
    return the_lhs.Value == the_rhs.Value;
}

inline bool operator!=(const Date& the_lhs, const Date& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace bridge { namespace oleautomation {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::bridge::oleautomation::Date const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< double >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.bridge.oleautomation.Date", 0, 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::bridge::oleautomation::Date const *) {
    return ::cppu::UnoType< ::css::bridge::oleautomation::Date >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BRIDGE_OLEAUTOMATION_DATE_HPP
