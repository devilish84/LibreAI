#ifndef INCLUDED_COM_SUN_STAR_UNO_EXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UNO_EXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/uno/Exception.hdl"

#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"
#if defined LIBO_INTERNAL_ONLY
#include <ostream>
#include <typeinfo>
#endif

namespace com { namespace sun { namespace star { namespace uno {

inline Exception::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : Message()
    , Context()
{ 
#if defined LIBO_USE_SOURCE_LOCATION
    if (!Message.isEmpty())
        Message += " ";
    Message += o3tl::runtimeToOUString(location.file_name()) + ":" + OUString::number(location.line());
#endif
}

inline Exception::Exception(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : Message(Message_)
    , Context(Context_)
{ 
#if defined LIBO_USE_SOURCE_LOCATION
    if (!Message.isEmpty())
        Message += " ";
    Message += o3tl::runtimeToOUString(location.file_name()) + ":" + OUString::number(location.line());
#endif
}

#if !defined LIBO_INTERNAL_ONLY
Exception::Exception(Exception const & the_other): Message(the_other.Message), Context(the_other.Context) {}

Exception::~Exception() {}

Exception & Exception::operator =(Exception const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    Message = the_other.Message;
    Context = the_other.Context;
    return *this;
}
#endif

#if defined LIBO_INTERNAL_ONLY
template< typename charT, typename traits >
inline ::std::basic_ostream<charT, traits> & operator<<(
    ::std::basic_ostream<charT, traits> & os, ::com::sun::star::uno::Exception const & exception)
{
    // the class name is useful because exception throwing code does not always pass in a useful message
    os << typeid(exception).name();
    if (!exception.Message.isEmpty())
      os << " msg: " << exception.Message;
    return os;
}
#endif

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER const ::css::uno::Exception *) {
    return ::cppu::UnoType< ::css::uno::Exception >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UNO_EXCEPTION_HPP
