#ifndef INCLUDED_COM_SUN_STAR_LANG_EVENTOBJECT_HPP
#define INCLUDED_COM_SUN_STAR_LANG_EVENTOBJECT_HPP

#include "sal/config.h"

#include "com/sun/star/lang/EventObject.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace lang {

inline EventObject::EventObject()
    : Source()
{
}

inline EventObject::EventObject(const ::css::uno::Reference< ::css::uno::XInterface >& Source_)
    : Source(Source_)
{
}


inline bool operator==(const EventObject& the_lhs, const EventObject& the_rhs)
{
    return the_lhs.Source == the_rhs.Source;
}

inline bool operator!=(const EventObject& the_lhs, const EventObject& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace lang { namespace detail {

struct theEventObjectType : public rtl::StaticWithInit< ::css::uno::Type *, theEventObjectType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.lang.EventObject" );
        ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get();
        ::rtl::OUString the_tname0( "com.sun.star.uno.XInterface" );
        ::rtl::OUString the_name0( "Source" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_INTERFACE, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace lang {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::lang::EventObject const *) {
    return *detail::theEventObjectType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::lang::EventObject const *) {
    return ::cppu::UnoType< ::css::lang::EventObject >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LANG_EVENTOBJECT_HPP
