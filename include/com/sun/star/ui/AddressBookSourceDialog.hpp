#ifndef INCLUDED_COM_SUN_STAR_UI_ADDRESSBOOKSOURCEDIALOG_HPP
#define INCLUDED_COM_SUN_STAR_UI_ADDRESSBOOKSOURCEDIALOG_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/ui/dialogs/XExecutableDialog.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_AddressBookSourceDialog && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_AddressBookSourceDialog) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_AddressBookSourceDialog
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_AddressBookSourceDialog(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace ui {

class AddressBookSourceDialog {
public:
    static ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > createWithDataSource(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::awt::XWindow >& ParentWindow, const ::css::uno::Reference< ::css::beans::XPropertySet >& DataSource, const ::rtl::OUString& DataSourceName, const ::rtl::OUString& Command, const ::rtl::OUString& Title) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(5);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= ParentWindow;
        the_arguments_array[1] <<= DataSource;
        the_arguments_array[2] <<= DataSourceName;
        the_arguments_array[3] <<= Command;
        the_arguments_array[4] <<= Title;
        ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_AddressBookSourceDialog && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_AddressBookSourceDialog) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_AddressBookSourceDialog
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_AddressBookSourceDialog)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.ui.AddressBookSourceDialog", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.ui.AddressBookSourceDialog" + " of type " + "com.sun.star.ui.dialogs.XExecutableDialog" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.ui.AddressBookSourceDialog" + " of type " + "com.sun.star.ui.dialogs.XExecutableDialog", the_context);
        }
        return the_instance;
    }

private:
    AddressBookSourceDialog(); // not implemented
    AddressBookSourceDialog(AddressBookSourceDialog &); // not implemented
    ~AddressBookSourceDialog(); // not implemented
    void operator =(AddressBookSourceDialog); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_UI_ADDRESSBOOKSOURCEDIALOG_HPP
