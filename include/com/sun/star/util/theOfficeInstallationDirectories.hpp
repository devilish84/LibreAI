#ifndef INCLUDED_COM_SUN_STAR_UTIL_THEOFFICEINSTALLATIONDIRECTORIES_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_THEOFFICEINSTALLATIONDIRECTORIES_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/util/XOfficeInstallationDirectories.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_theOfficeInstallationDirectories && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_theOfficeInstallationDirectories) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_theOfficeInstallationDirectories
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_theOfficeInstallationDirectories(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace util {

class theOfficeInstallationDirectories {
public:
    static ::css::uno::Reference< ::css::util::XOfficeInstallationDirectories > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::util::XOfficeInstallationDirectories > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_theOfficeInstallationDirectories && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_theOfficeInstallationDirectories) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_theOfficeInstallationDirectories
        instance = ::css::uno::Reference< ::css::util::XOfficeInstallationDirectories >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_theOfficeInstallationDirectories)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.util.theOfficeInstallationDirectories" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.util.theOfficeInstallationDirectories of type com.sun.star.util.XOfficeInstallationDirectories" ), the_context);
        }
        return instance;
    }

private:
    theOfficeInstallationDirectories(); // not implemented
    theOfficeInstallationDirectories(theOfficeInstallationDirectories &); // not implemented
    ~theOfficeInstallationDirectories(); // not implemented
    void operator =(theOfficeInstallationDirectories); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_UTIL_THEOFFICEINSTALLATIONDIRECTORIES_HPP
