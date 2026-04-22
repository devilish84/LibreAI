#ifndef INCLUDED_COM_SUN_STAR_DEPLOYMENT_DEPENDENCYEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_DEPLOYMENT_DEPENDENCYEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/deployment/DependencyException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/xml/dom/XElement.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace deployment {

inline DependencyException::DependencyException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , UnsatisfiedDependencies()
{ }

inline DependencyException::DependencyException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Sequence< ::css::uno::Reference< ::css::xml::dom::XElement > >& UnsatisfiedDependencies_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , UnsatisfiedDependencies(UnsatisfiedDependencies_)
{ }

#if !defined LIBO_INTERNAL_ONLY
DependencyException::DependencyException(DependencyException const & the_other): ::css::uno::Exception(the_other), UnsatisfiedDependencies(the_other.UnsatisfiedDependencies) {}

DependencyException::~DependencyException() {}

DependencyException & DependencyException::operator =(DependencyException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    UnsatisfiedDependencies = the_other.UnsatisfiedDependencies;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace deployment {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::deployment::DependencyException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_seq_com_sun_star_xml_dom_XElement = ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::uno::Reference< ::css::xml::dom::XElement > > >::get();
        aMemberRefs[0] = rMemberType_seq_com_sun_star_xml_dom_XElement.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.deployment.DependencyException", * ::typelib_static_type_getByTypeClass( typelib_TypeClass_EXCEPTION ), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::deployment::DependencyException const *) {
    return ::cppu::UnoType< ::css::deployment::DependencyException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_DEPLOYMENT_DEPENDENCYEXCEPTION_HPP
