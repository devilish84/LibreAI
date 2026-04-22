#ifndef INCLUDED_COM_SUN_STAR_BEANS_PROPERTYVALUE_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_PROPERTYVALUE_HPP

#include "sal/config.h"

#include "com/sun/star/beans/PropertyValue.hdl"

#include "com/sun/star/beans/PropertyState.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

inline PropertyValue::PropertyValue()
    : Name()
    , Handle(0)
    , Value()
    , State(::css::beans::PropertyState_DIRECT_VALUE)
{
}

inline PropertyValue::PropertyValue(const ::rtl::OUString& Name_, const ::sal_Int32& Handle_, const ::css::uno::Any& Value_, const ::css::beans::PropertyState& State_)
    : Name(Name_)
    , Handle(Handle_)
    , Value(Value_)
    , State(State_)
{
}


inline bool operator==(const PropertyValue& the_lhs, const PropertyValue& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Handle == the_rhs.Handle
        && the_lhs.Value == the_rhs.Value
        && the_lhs.State == the_rhs.State;
}

inline bool operator!=(const PropertyValue& the_lhs, const PropertyValue& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans { namespace detail {

struct thePropertyValueType : public rtl::StaticWithInit< ::css::uno::Type *, thePropertyValueType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.beans.PropertyValue" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Name" );
        ::rtl::OUString the_tname1( "long" );
        ::rtl::OUString the_name1( "Handle" );
        ::rtl::OUString the_tname2( "any" );
        ::rtl::OUString the_name2( "Value" );
        ::cppu::UnoType< ::css::beans::PropertyState >::get();
        ::rtl::OUString the_tname3( "com.sun.star.beans.PropertyState" );
        ::rtl::OUString the_name3( "State" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_ANY, the_tname2.pData, the_name2.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname3.pData, the_name3.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 4, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::PropertyValue const *) {
    return *detail::thePropertyValueType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::PropertyValue const *) {
    return ::cppu::UnoType< ::css::beans::PropertyValue >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_PROPERTYVALUE_HPP
