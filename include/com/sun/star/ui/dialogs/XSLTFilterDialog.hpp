#ifndef INCLUDED_COM_SUN_STAR_UI_DIALOGS_XSLTFILTERDIALOG_HPP
#define INCLUDED_COM_SUN_STAR_UI_DIALOGS_XSLTFILTERDIALOG_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/ui/dialogs/XExecutableDialog.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_XSLTFilterDialog && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_XSLTFilterDialog) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_XSLTFilterDialog
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_XSLTFilterDialog(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace ui { namespace dialogs {

class XSLTFilterDialog {
public:
    static ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_XSLTFilterDialog && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_XSLTFilterDialog) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_XSLTFilterDialog
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_dialogs_dot_XSLTFilterDialog)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog >(the_context->getServiceManager()->createInstanceWithContext( "com.sun.star.ui.dialogs.XSLTFilterDialog", the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.ui.dialogs.XSLTFilterDialog" + " of type " + "com.sun.star.ui.dialogs.XExecutableDialog" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.ui.dialogs.XSLTFilterDialog" + " of type " + "com.sun.star.ui.dialogs.XExecutableDialog", the_context);
        }
        return the_instance;
    }

private:
    XSLTFilterDialog(); // not implemented
    XSLTFilterDialog(XSLTFilterDialog &); // not implemented
    ~XSLTFilterDialog(); // not implemented
    void operator =(XSLTFilterDialog); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_UI_DIALOGS_XSLTFILTERDIALOG_HPP
