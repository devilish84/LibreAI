#ifndef INCLUDED_COM_SUN_STAR_LOGGING_PLAINTEXTFORMATTER_HPP
#define INCLUDED_COM_SUN_STAR_LOGGING_PLAINTEXTFORMATTER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/logging/XLogFormatter.hpp"
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

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_logging_dot_PlainTextFormatter && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_logging_dot_PlainTextFormatter) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_logging_dot_PlainTextFormatter
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_logging_dot_PlainTextFormatter(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace logging {

class PlainTextFormatter {
public:
    static ::css::uno::Reference< ::css::logging::XLogFormatter > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::logging::XLogFormatter > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_logging_dot_PlainTextFormatter && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_logging_dot_PlainTextFormatter) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_logging_dot_PlainTextFormatter
            the_instance = ::css::uno::Reference< ::css::logging::XLogFormatter >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_logging_dot_PlainTextFormatter)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(::css::uno::Sequence< ::css::uno::Any >());
            }
#else
            the_instance = ::css::uno::Reference< ::css::logging::XLogFormatter >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.logging.PlainTextFormatter", ::css::uno::Sequence< ::css::uno::Any >(), the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.logging.PlainTextFormatter" + " of type " + "com.sun.star.logging.XLogFormatter" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.logging.PlainTextFormatter" + " of type " + "com.sun.star.logging.XLogFormatter", the_context);
        }
        return the_instance;
    }

private:
    PlainTextFormatter(); // not implemented
    PlainTextFormatter(PlainTextFormatter &); // not implemented
    ~PlainTextFormatter(); // not implemented
    void operator =(PlainTextFormatter); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_LOGGING_PLAINTEXTFORMATTER_HPP
