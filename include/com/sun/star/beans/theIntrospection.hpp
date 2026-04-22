#ifndef INCLUDED_COM_SUN_STAR_BEANS_THEINTROSPECTION_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_THEINTROSPECTION_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/beans/XIntrospection.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_theIntrospection && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_theIntrospection) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_theIntrospection
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_theIntrospection(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace beans {

class theIntrospection {
public:
    static ::css::uno::Reference< ::css::beans::XIntrospection > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::beans::XIntrospection > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_theIntrospection && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_beans_dot_theIntrospection) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_theIntrospection
        instance = ::css::uno::Reference< ::css::beans::XIntrospection >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_beans_dot_theIntrospection)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.beans.theIntrospection" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.beans.theIntrospection of type com.sun.star.beans.XIntrospection" ), the_context);
        }
        return instance;
    }

private:
    theIntrospection(); // not implemented
    theIntrospection(theIntrospection &); // not implemented
    ~theIntrospection(); // not implemented
    void operator =(theIntrospection); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_BEANS_THEINTROSPECTION_HPP
