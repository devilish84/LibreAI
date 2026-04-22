#ifndef INCLUDED_ORG_FREEDESKTOP_PACKAGEKIT_SYNCDBUSSESSIONHELPER_HPP
#define INCLUDED_ORG_FREEDESKTOP_PACKAGEKIT_SYNCDBUSSESSIONHELPER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "org/freedesktop/PackageKit/XSyncDbusSessionHelper.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_org_dot_freedesktop_dot_PackageKit_dot_SyncDbusSessionHelper && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_org_dot_freedesktop_dot_PackageKit_dot_SyncDbusSessionHelper) && defined LO_URE_CTOR_FUN_org_dot_freedesktop_dot_PackageKit_dot_SyncDbusSessionHelper
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_org_dot_freedesktop_dot_PackageKit_dot_SyncDbusSessionHelper(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace org { namespace freedesktop { namespace PackageKit {

class SyncDbusSessionHelper {
public:
    static ::css::uno::Reference< ::org::freedesktop::PackageKit::XSyncDbusSessionHelper > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::org::freedesktop::PackageKit::XSyncDbusSessionHelper > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_org_dot_freedesktop_dot_PackageKit_dot_SyncDbusSessionHelper && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_org_dot_freedesktop_dot_PackageKit_dot_SyncDbusSessionHelper) && defined LO_URE_CTOR_FUN_org_dot_freedesktop_dot_PackageKit_dot_SyncDbusSessionHelper
            the_instance = ::css::uno::Reference< ::org::freedesktop::PackageKit::XSyncDbusSessionHelper >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_org_dot_freedesktop_dot_PackageKit_dot_SyncDbusSessionHelper)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
            the_instance = ::css::uno::Reference< ::org::freedesktop::PackageKit::XSyncDbusSessionHelper >(the_context->getServiceManager()->createInstanceWithContext( "org.freedesktop.PackageKit.SyncDbusSessionHelper", the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "org.freedesktop.PackageKit.SyncDbusSessionHelper" + " of type " + "org.freedesktop.PackageKit.XSyncDbusSessionHelper" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "org.freedesktop.PackageKit.SyncDbusSessionHelper" + " of type " + "org.freedesktop.PackageKit.XSyncDbusSessionHelper", the_context);
        }
        return the_instance;
    }

private:
    SyncDbusSessionHelper(); // not implemented
    SyncDbusSessionHelper(SyncDbusSessionHelper &); // not implemented
    ~SyncDbusSessionHelper(); // not implemented
    void operator =(SyncDbusSessionHelper); // not implemented
};

} } }

#endif // INCLUDED_ORG_FREEDESKTOP_PACKAGEKIT_SYNCDBUSSESSIONHELPER_HPP
