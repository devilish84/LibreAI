#ifndef INCLUDED_COM_SUN_STAR_UI_DIALOGS_WIZARD_HPP
#define INCLUDED_COM_SUN_STAR_UI_DIALOGS_WIZARD_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/ui/dialogs/XWizard.hpp"
#include "com/sun/star/ui/dialogs/XWizardController.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace ui { namespace dialogs {

class Wizard {
public:
    static ::css::uno::Reference< ::css::ui::dialogs::XWizard > createSinglePathWizard(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Sequence< ::sal_Int16 >& PageIds, const ::css::uno::Reference< ::css::ui::dialogs::XWizardController >& Controller) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= PageIds;
        the_arguments_array[1] <<= Controller;
        ::css::uno::Reference< ::css::ui::dialogs::XWizard > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XWizard >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XWizard >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.ui.dialogs.Wizard", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.ui.dialogs.Wizard" + " of type " + "com.sun.star.ui.dialogs.XWizard" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.ui.dialogs.Wizard" + " of type " + "com.sun.star.ui.dialogs.XWizard", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::ui::dialogs::XWizard > createMultiplePathsWizard(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Sequence< ::css::uno::Sequence< ::sal_Int16 > >& PageIds, const ::css::uno::Reference< ::css::ui::dialogs::XWizardController >& Controller) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= PageIds;
        the_arguments_array[1] <<= Controller;
        ::css::uno::Reference< ::css::ui::dialogs::XWizard > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XWizard >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_Wizard)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XWizard >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.ui.dialogs.Wizard", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.ui.dialogs.Wizard" + " of type " + "com.sun.star.ui.dialogs.XWizard" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.ui.dialogs.Wizard" + " of type " + "com.sun.star.ui.dialogs.XWizard", the_context);
        }
        return the_instance;
    }

private:
    Wizard(); // not implemented
    Wizard(Wizard &); // not implemented
    ~Wizard(); // not implemented
    void operator =(Wizard); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_UI_DIALOGS_WIZARD_HPP
