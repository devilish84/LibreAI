#ifndef INCLUDED_COM_SUN_STAR_SDB_FILTERDIALOG_HPP
#define INCLUDED_COM_SUN_STAR_SDB_FILTERDIALOG_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/awt/XWindow.hpp"
#include "com/sun/star/sdb/XSingleSelectQueryComposer.hpp"
#include "com/sun/star/sdbc/XRowSet.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace sdb {

class FilterDialog {
public:
    static ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > createDefault(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(::css::uno::Sequence< ::css::uno::Any >());
            }
#else
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.sdb.FilterDialog", ::css::uno::Sequence< ::css::uno::Any >(), the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.FilterDialog" + " of type " + "com.sun.star.ui.dialogs.XExecutableDialog" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.FilterDialog" + " of type " + "com.sun.star.ui.dialogs.XExecutableDialog", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > createWithQuery(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::sdb::XSingleSelectQueryComposer >& QueryComposer, const ::css::uno::Reference< ::css::sdbc::XRowSet >& RowSet, const ::css::uno::Reference< ::css::awt::XWindow >& ParentWindow) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(3);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= QueryComposer;
        the_arguments_array[1] <<= RowSet;
        the_arguments_array[2] <<= ParentWindow;
        ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_FilterDialog)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::ui::dialogs::XExecutableDialog >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.sdb.FilterDialog", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.FilterDialog" + " of type " + "com.sun.star.ui.dialogs.XExecutableDialog" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.FilterDialog" + " of type " + "com.sun.star.ui.dialogs.XExecutableDialog", the_context);
        }
        return the_instance;
    }

private:
    FilterDialog(); // not implemented
    FilterDialog(FilterDialog &); // not implemented
    ~FilterDialog(); // not implemented
    void operator =(FilterDialog); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_SDB_FILTERDIALOG_HPP
