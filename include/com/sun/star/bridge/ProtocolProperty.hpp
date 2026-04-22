#ifndef INCLUDED_COM_SUN_STAR_BRIDGE_PROTOCOLPROPERTY_HPP
#define INCLUDED_COM_SUN_STAR_BRIDGE_PROTOCOLPROPERTY_HPP

#include "sal/config.h"

#include "com/sun/star/bridge/ProtocolProperty.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace bridge {

inline ProtocolProperty::ProtocolProperty()
    : Name()
    , Value()
{
}

inline ProtocolProperty::ProtocolProperty(const ::rtl::OUString& Name_, const ::css::uno::Any& Value_)
    : Name(Name_)
    , Value(Value_)
{
}


inline bool operator==(const ProtocolProperty& the_lhs, const ProtocolProperty& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Value == the_rhs.Value;
}

inline bool operator!=(const ProtocolProperty& the_lhs, const ProtocolProperty& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace bridge {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::bridge::ProtocolProperty const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.bridge.ProtocolProperty", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::bridge::ProtocolProperty const *) {
    return ::cppu::UnoType< ::css::bridge::ProtocolProperty >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BRIDGE_PROTOCOLPROPERTY_HPP
