#ifndef INCLUDED_COM_SUN_STAR_DEPLOYMENT_INVALIDREMOVEDPARAMETEREXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_DEPLOYMENT_INVALIDREMOVEDPARAMETEREXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/deployment/InvalidRemovedParameterException.hdl"

#include "com/sun/star/deployment/XPackage.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace deployment {

inline InvalidRemovedParameterException::InvalidRemovedParameterException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , PreviousValue(false)
    , Extension()
{ }

inline InvalidRemovedParameterException::InvalidRemovedParameterException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Bool& PreviousValue_, const ::css::uno::Reference< ::css::deployment::XPackage >& Extension_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , PreviousValue(PreviousValue_)
    , Extension(Extension_)
{ }

#if !defined LIBO_INTERNAL_ONLY
InvalidRemovedParameterException::InvalidRemovedParameterException(InvalidRemovedParameterException const & the_other): ::css::uno::Exception(the_other), PreviousValue(the_other.PreviousValue), Extension(the_other.Extension) {}

InvalidRemovedParameterException::~InvalidRemovedParameterException() {}

InvalidRemovedParameterException & InvalidRemovedParameterException::operator =(InvalidRemovedParameterException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    PreviousValue = the_other.PreviousValue;
    Extension = the_other.Extension;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace deployment {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::deployment::InvalidRemovedParameterException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[2];
        const ::css::uno::Type& rMemberType_boolean = ::cppu::UnoType< ::sal_Bool >::get();
        aMemberRefs[0] = rMemberType_boolean.getTypeLibType();
        const ::css::uno::Type& rMemberType_com_sun_star_deployment_XPackage = ::cppu::UnoType< ::css::uno::Reference< ::css::deployment::XPackage > >::get();
        aMemberRefs[1] = rMemberType_com_sun_star_deployment_XPackage.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.deployment.InvalidRemovedParameterException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 2,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::deployment::InvalidRemovedParameterException const *) {
    return ::cppu::UnoType< ::css::deployment::InvalidRemovedParameterException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DEPLOYMENT_INVALIDREMOVEDPARAMETEREXCEPTION_HPP
