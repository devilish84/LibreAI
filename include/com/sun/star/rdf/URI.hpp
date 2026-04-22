#ifndef INCLUDED_COM_SUN_STAR_RDF_URI_HPP
#define INCLUDED_COM_SUN_STAR_RDF_URI_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/rdf/XURI.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "sal/types.h"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rdf_dot_URI && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rdf_dot_URI) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rdf_dot_URI
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rdf_dot_URI(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace rdf {

class URI {
public:
    static ::css::uno::Reference< ::css::rdf::XURI > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& Value) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Value;
        ::css::uno::Reference< ::css::rdf::XURI > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rdf_dot_URI && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rdf_dot_URI) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rdf_dot_URI
            the_instance = ::css::uno::Reference< ::css::rdf::XURI >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rdf_dot_URI)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::rdf::XURI >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.rdf.URI", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.rdf.URI" + " of type " + "com.sun.star.rdf.XURI" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.rdf.URI" + " of type " + "com.sun.star.rdf.XURI", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::rdf::XURI > createNS(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& Namespace, const ::rtl::OUString& LocalName) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Namespace;
        the_arguments_array[1] <<= LocalName;
        ::css::uno::Reference< ::css::rdf::XURI > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rdf_dot_URI && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rdf_dot_URI) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rdf_dot_URI
            the_instance = ::css::uno::Reference< ::css::rdf::XURI >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rdf_dot_URI)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::rdf::XURI >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.rdf.URI", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.rdf.URI" + " of type " + "com.sun.star.rdf.XURI" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.rdf.URI" + " of type " + "com.sun.star.rdf.XURI", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::rdf::XURI > createKnown(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, ::sal_Int16 Id) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Id;
        ::css::uno::Reference< ::css::rdf::XURI > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rdf_dot_URI && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rdf_dot_URI) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rdf_dot_URI
            the_instance = ::css::uno::Reference< ::css::rdf::XURI >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rdf_dot_URI)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::rdf::XURI >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.rdf.URI", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.rdf.URI" + " of type " + "com.sun.star.rdf.XURI" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.rdf.URI" + " of type " + "com.sun.star.rdf.XURI", the_context);
        }
        return the_instance;
    }

private:
    URI(); // not implemented
    URI(URI &); // not implemented
    ~URI(); // not implemented
    void operator =(URI); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_RDF_URI_HPP
