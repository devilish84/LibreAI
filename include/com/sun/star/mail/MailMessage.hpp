#ifndef INCLUDED_COM_SUN_STAR_MAIL_MAILMESSAGE_HPP
#define INCLUDED_COM_SUN_STAR_MAIL_MAILMESSAGE_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/datatransfer/XTransferable.hpp"
#include "com/sun/star/mail/MailAttachment.hpp"
#include "com/sun/star/mail/XMailMessage.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailMessage && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailMessage) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailMessage
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailMessage(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace mail {

class MailMessage {
public:
    static ::css::uno::Reference< ::css::mail::XMailMessage > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& sTo, const ::rtl::OUString& sFrom, const ::rtl::OUString& sSubject, const ::css::uno::Reference< ::css::datatransfer::XTransferable >& xBody) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(4);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= sTo;
        the_arguments_array[1] <<= sFrom;
        the_arguments_array[2] <<= sSubject;
        the_arguments_array[3] <<= xBody;
        ::css::uno::Reference< ::css::mail::XMailMessage > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailMessage && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailMessage) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailMessage
            the_instance = ::css::uno::Reference< ::css::mail::XMailMessage >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailMessage)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::mail::XMailMessage >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.mail.MailMessage", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.mail.MailMessage" + " of type " + "com.sun.star.mail.XMailMessage" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.mail.MailMessage" + " of type " + "com.sun.star.mail.XMailMessage", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::mail::XMailMessage > createWithAttachment(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& sTo, const ::rtl::OUString& sFrom, const ::rtl::OUString& sSubject, const ::css::uno::Reference< ::css::datatransfer::XTransferable >& xBody, const ::css::mail::MailAttachment& aMailAttachment) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(5);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= sTo;
        the_arguments_array[1] <<= sFrom;
        the_arguments_array[2] <<= sSubject;
        the_arguments_array[3] <<= xBody;
        the_arguments_array[4] <<= aMailAttachment;
        ::css::uno::Reference< ::css::mail::XMailMessage > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailMessage && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_mail_dot_MailMessage) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailMessage
            the_instance = ::css::uno::Reference< ::css::mail::XMailMessage >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_mail_dot_MailMessage)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::mail::XMailMessage >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.mail.MailMessage", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.mail.MailMessage" + " of type " + "com.sun.star.mail.XMailMessage" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.mail.MailMessage" + " of type " + "com.sun.star.mail.XMailMessage", the_context);
        }
        return the_instance;
    }

private:
    MailMessage(); // not implemented
    MailMessage(MailMessage &); // not implemented
    ~MailMessage(); // not implemented
    void operator =(MailMessage); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_MAIL_MAILMESSAGE_HPP
