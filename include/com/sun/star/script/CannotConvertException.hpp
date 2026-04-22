#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_CANNOTCONVERTEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_CANNOTCONVERTEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/script/CannotConvertException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/TypeClass.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace script {

inline CannotConvertException::CannotConvertException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , DestinationTypeClass(::css::uno::TypeClass_VOID)
    , Reason(0)
    , ArgumentIndex(0)
{ }

inline CannotConvertException::CannotConvertException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::TypeClass& DestinationTypeClass_, const ::sal_Int32& Reason_, const ::sal_Int32& ArgumentIndex_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , DestinationTypeClass(DestinationTypeClass_)
    , Reason(Reason_)
    , ArgumentIndex(ArgumentIndex_)
{ }

#if !defined LIBO_INTERNAL_ONLY
CannotConvertException::CannotConvertException(CannotConvertException const & the_other): ::css::uno::Exception(the_other), DestinationTypeClass(the_other.DestinationTypeClass), Reason(the_other.Reason), ArgumentIndex(the_other.ArgumentIndex) {}

CannotConvertException::~CannotConvertException() {}

CannotConvertException & CannotConvertException::operator =(CannotConvertException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    DestinationTypeClass = the_other.DestinationTypeClass;
    Reason = the_other.Reason;
    ArgumentIndex = the_other.ArgumentIndex;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::CannotConvertException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[3];
        const ::css::uno::Type& rMemberType_com_sun_star_uno_TypeClass = ::cppu::UnoType< ::css::uno::TypeClass >::get();
        aMemberRefs[0] = rMemberType_com_sun_star_uno_TypeClass.getTypeLibType();
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[1] = rMemberType_long.getTypeLibType();
        aMemberRefs[2] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.script.CannotConvertException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 3,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::CannotConvertException const *) {
    return ::cppu::UnoType< ::css::script::CannotConvertException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_CANNOTCONVERTEXCEPTION_HPP
