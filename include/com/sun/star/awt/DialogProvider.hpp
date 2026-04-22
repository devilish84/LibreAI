#ifndef INCLUDED_COM_SUN_STAR_AWT_DIALOGPROVIDER_HPP
#define INCLUDED_COM_SUN_STAR_AWT_DIALOGPROVIDER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/awt/XDialogProvider.hpp"
#include "com/sun/star/container/XNameContainer.hpp"
#include "com/sun/star/frame/XModel.hpp"
#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/script/XScriptListener.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_awt_dot_DialogProvider && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_awt_dot_DialogProvider) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_awt_dot_DialogProvider
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_awt_dot_DialogProvider(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace awt {

class DialogProvider {
public:
    static ::css::uno::Reference< ::css::awt::XDialogProvider > createWithModel(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::frame::XModel >& Model) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Model;
        ::css::uno::Reference< ::css::awt::XDialogProvider > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_awt_dot_DialogProvider && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_awt_dot_DialogProvider) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_awt_dot_DialogProvider
            the_instance = ::css::uno::Reference< ::css::awt::XDialogProvider >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_awt_dot_DialogProvider)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::awt::XDialogProvider >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.awt.DialogProvider", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.awt.DialogProvider" + " of type " + "com.sun.star.awt.XDialogProvider" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.awt.DialogProvider" + " of type " + "com.sun.star.awt.XDialogProvider", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::awt::XDialogProvider > createWithModelAndScripting(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::frame::XModel >& Model, const ::css::uno::Reference< ::css::io::XInputStream >& InStream, const ::css::uno::Reference< ::css::container::XNameContainer >& DialogLib, const ::css::uno::Reference< ::css::script::XScriptListener >& ScriptListener) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(4);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Model;
        the_arguments_array[1] <<= InStream;
        the_arguments_array[2] <<= DialogLib;
        the_arguments_array[3] <<= ScriptListener;
        ::css::uno::Reference< ::css::awt::XDialogProvider > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_awt_dot_DialogProvider && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_awt_dot_DialogProvider) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_awt_dot_DialogProvider
            the_instance = ::css::uno::Reference< ::css::awt::XDialogProvider >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_awt_dot_DialogProvider)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::awt::XDialogProvider >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.awt.DialogProvider", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.awt.DialogProvider" + " of type " + "com.sun.star.awt.XDialogProvider" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.awt.DialogProvider" + " of type " + "com.sun.star.awt.XDialogProvider", the_context);
        }
        return the_instance;
    }

private:
    DialogProvider(); // not implemented
    DialogProvider(DialogProvider &); // not implemented
    ~DialogProvider(); // not implemented
    void operator =(DialogProvider); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_AWT_DIALOGPROVIDER_HPP
