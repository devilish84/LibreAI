#ifndef INCLUDED_COM_SUN_STAR_XFORMS_INVALIDDATAONSUBMITEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_XFORMS_INVALIDDATAONSUBMITEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/xforms/InvalidDataOnSubmitException.hdl"

#include "com/sun/star/util/VetoException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace xforms {

inline InvalidDataOnSubmitException::InvalidDataOnSubmitException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::util::VetoException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline InvalidDataOnSubmitException::InvalidDataOnSubmitException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::util::VetoException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
InvalidDataOnSubmitException::InvalidDataOnSubmitException(InvalidDataOnSubmitException const & the_other): ::css::util::VetoException(the_other) {}

InvalidDataOnSubmitException::~InvalidDataOnSubmitException() {}

InvalidDataOnSubmitException & InvalidDataOnSubmitException::operator =(InvalidDataOnSubmitException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::util::VetoException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace xforms {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xforms::InvalidDataOnSubmitException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::util::VetoException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.xforms.InvalidDataOnSubmitException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xforms::InvalidDataOnSubmitException const *) {
    return ::cppu::UnoType< ::css::xforms::InvalidDataOnSubmitException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XFORMS_INVALIDDATAONSUBMITEXCEPTION_HPP
