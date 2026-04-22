#ifndef INCLUDED_COM_SUN_STAR_MAIL_MAILSERVICEPROVIDER_HPP
#define INCLUDED_COM_SUN_STAR_MAIL_MAILSERVICEPROVIDER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/mail/XMailServiceProvider.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailServiceProvider && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailServiceProvider) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailServiceProvider
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailServiceProvider(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace mail {

class MailServiceProvider {
public:
    static ::css::uno::Reference< ::css::mail::XMailServiceProvider > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::mail::XMailServiceProvider > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailServiceProvider && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailServiceProvider) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailServiceProvider
            the_instance = ::css::uno::Reference< ::css::mail::XMailServiceProvider >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailServiceProvider)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(::css::uno::Sequence< ::css::uno::Any >());
            }
#else
            the_instance = ::css::uno::Reference< ::css::mail::XMailServiceProvider >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.mail.MailServiceProvider", ::css::uno::Sequence< ::css::uno::Any >(), the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.mail.MailServiceProvider" + " of type " + "com.sun.star.mail.XMailServiceProvider" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.mail.MailServiceProvider" + " of type " + "com.sun.star.mail.XMailServiceProvider", the_context);
        }
        return the_instance;
    }

private:
    MailServiceProvider(); // not implemented
    MailServiceProvider(MailServiceProvider &); // not implemented
    ~MailServiceProvider(); // not implemented
    void operator =(MailServiceProvider); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_MAIL_MAILSERVICEPROVIDER_HPP
