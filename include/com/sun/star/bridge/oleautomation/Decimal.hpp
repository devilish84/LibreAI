#ifndef INCLUDED_COM_SUN_STAR_BRIDGE_OLEAUTOMATION_DECIMAL_HPP
#define INCLUDED_COM_SUN_STAR_BRIDGE_OLEAUTOMATION_DECIMAL_HPP

#include "sal/config.h"

#include "com/sun/star/bridge/oleautomation/Decimal.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace bridge { namespace oleautomation {

inline Decimal::Decimal()
    : Scale(0)
    , Sign(0)
    , LowValue(0)
    , MiddleValue(0)
    , HighValue(0)
{
}

inline Decimal::Decimal(const ::sal_Int8& Scale_, const ::sal_Int8& Sign_, const ::sal_uInt32& LowValue_, const ::sal_uInt32& MiddleValue_, const ::sal_uInt32& HighValue_)
    : Scale(Scale_)
    , Sign(Sign_)
    , LowValue(LowValue_)
    , MiddleValue(MiddleValue_)
    , HighValue(HighValue_)
{
}


inline bool operator==(const Decimal& the_lhs, const Decimal& the_rhs)
{
    return the_lhs.Scale == the_rhs.Scale
        && the_lhs.Sign == the_rhs.Sign
        && the_lhs.LowValue == the_rhs.LowValue
        && the_lhs.MiddleValue == the_rhs.MiddleValue
        && the_lhs.HighValue == the_rhs.HighValue;
}

inline bool operator!=(const Decimal& the_lhs, const Decimal& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace bridge { namespace oleautomation {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::bridge::oleautomation::Decimal const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int8 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_uInt32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_uInt32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_uInt32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.bridge.oleautomation.Decimal", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::bridge::oleautomation::Decimal const *) {
    return ::cppu::UnoType< ::css::bridge::oleautomation::Decimal >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BRIDGE_OLEAUTOMATION_DECIMAL_HPP
