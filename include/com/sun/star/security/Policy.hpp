#ifndef INCLUDED_COM_SUN_STAR_SECURITY_POLICY_HPP
#define INCLUDED_COM_SUN_STAR_SECURITY_POLICY_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/security/XPolicy.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_security_dot_Policy && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_security_dot_Policy) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_security_dot_Policy
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_security_dot_Policy(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace security {

class Policy {
public:
    static ::css::uno::Reference< ::css::security::XPolicy > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::security::XPolicy > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_security_dot_Policy && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_security_dot_Policy) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_security_dot_Policy
            the_instance = ::css::uno::Reference< ::css::security::XPolicy >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_security_dot_Policy)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
            the_instance = ::css::uno::Reference< ::css::security::XPolicy >(the_context->getServiceManager()->createInstanceWithContext( "com.sun.star.security.Policy", the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.security.Policy" + " of type " + "com.sun.star.security.XPolicy" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.security.Policy" + " of type " + "com.sun.star.security.XPolicy", the_context);
        }
        return the_instance;
    }

private:
    Policy(); // not implemented
    Policy(Policy &); // not implemented
    ~Policy(); // not implemented
    void operator =(Policy); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_SECURITY_POLICY_HPP
