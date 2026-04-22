#ifndef INCLUDED_COM_SUN_STAR_SDB_APPLICATION_COPYTABLEWIZARD_HPP
#define INCLUDED_COM_SUN_STAR_SDB_APPLICATION_COPYTABLEWIZARD_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/lang/WrappedTargetException.hpp"
#include "com/sun/star/sdb/application/XCopyTableWizard.hpp"
#include "com/sun/star/sdbc/SQLException.hpp"
#include "com/sun/star/task/XInteractionHandler.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace sdb { namespace application {

class CopyTableWizard {
public:
    static ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::beans::XPropertySet >& Source, const ::css::uno::Reference< ::css::beans::XPropertySet >& Destination) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Source;
        the_arguments_array[1] <<= Destination;
        ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard
            the_instance = ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.sdb.application.CopyTableWizard", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::sdbc::SQLException &) {
            throw;
        } catch (const ::css::lang::WrappedTargetException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.application.CopyTableWizard" + " of type " + "com.sun.star.sdb.application.XCopyTableWizard" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.application.CopyTableWizard" + " of type " + "com.sun.star.sdb.application.XCopyTableWizard", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard > createWithInteractionHandler(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::beans::XPropertySet >& Source, const ::css::uno::Reference< ::css::beans::XPropertySet >& Destination, const ::css::uno::Reference< ::css::task::XInteractionHandler >& InteractionHandler) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(3);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Source;
        the_arguments_array[1] <<= Destination;
        the_arguments_array[2] <<= InteractionHandler;
        ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard
            the_instance = ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_application_dot_CopyTableWizard)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::sdb::application::XCopyTableWizard >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.sdb.application.CopyTableWizard", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::sdbc::SQLException &) {
            throw;
        } catch (const ::css::lang::WrappedTargetException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.application.CopyTableWizard" + " of type " + "com.sun.star.sdb.application.XCopyTableWizard" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.application.CopyTableWizard" + " of type " + "com.sun.star.sdb.application.XCopyTableWizard", the_context);
        }
        return the_instance;
    }

private:
    CopyTableWizard(); // not implemented
    CopyTableWizard(CopyTableWizard &); // not implemented
    ~CopyTableWizard(); // not implemented
    void operator =(CopyTableWizard); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_SDB_APPLICATION_COPYTABLEWIZARD_HPP
