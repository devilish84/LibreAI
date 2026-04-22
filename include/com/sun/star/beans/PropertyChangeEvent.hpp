#ifndef INCLUDED_COM_SUN_STAR_BEANS_PROPERTYCHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_PROPERTYCHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/beans/PropertyChangeEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
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

inline PropertyChangeEvent::PropertyChangeEvent()
    : ::css::lang::EventObject()
    , PropertyName()
    , Further(false)
    , PropertyHandle(0)
    , OldValue()
    , NewValue()
{
}

inline PropertyChangeEvent::PropertyChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& PropertyName_, const ::sal_Bool& Further_, const ::sal_Int32& PropertyHandle_, const ::css::uno::Any& OldValue_, const ::css::uno::Any& NewValue_)
    : ::css::lang::EventObject(Source_)
    , PropertyName(PropertyName_)
    , Further(Further_)
    , PropertyHandle(PropertyHandle_)
    , OldValue(OldValue_)
    , NewValue(NewValue_)
{
}


inline bool operator==(const PropertyChangeEvent& the_lhs, const PropertyChangeEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.PropertyName == the_rhs.PropertyName
        && the_lhs.Further == the_rhs.Further
        && the_lhs.PropertyHandle == the_rhs.PropertyHandle
        && the_lhs.OldValue == the_rhs.OldValue
        && the_lhs.NewValue == the_rhs.NewValue;
}

inline bool operator!=(const PropertyChangeEvent& the_lhs, const PropertyChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans { namespace detail {

struct thePropertyChangeEventType : public rtl::StaticWithInit< ::css::uno::Type *, thePropertyChangeEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.beans.PropertyChangeEvent" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "PropertyName" );
        ::rtl::OUString the_tname1( "boolean" );
        ::rtl::OUString the_name1( "Further" );
        ::rtl::OUString the_tname2( "long" );
        ::rtl::OUString the_name2( "PropertyHandle" );
        ::rtl::OUString the_tname3( "any" );
        ::rtl::OUString the_name3( "OldValue" );
        ::rtl::OUString the_name4( "NewValue" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_LONG, the_tname2.pData, the_name2.pData }, false },
            { { typelib_TypeClass_ANY, the_tname3.pData, the_name3.pData }, false },
            { { typelib_TypeClass_ANY, the_tname3.pData, the_name4.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 5, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::PropertyChangeEvent const *) {
    return *detail::thePropertyChangeEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::PropertyChangeEvent const *) {
    return ::cppu::UnoType< ::css::beans::PropertyChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_PROPERTYCHANGEEVENT_HPP
