#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_THEMASTERSCRIPTPROVIDERFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_THEMASTERSCRIPTPROVIDERFACTORY_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/script/provider/XScriptProviderFactory.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_provider_dot_theMasterScriptProviderFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_provider_dot_theMasterScriptProviderFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_provider_dot_theMasterScriptProviderFactory
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_provider_dot_theMasterScriptProviderFactory(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace script { namespace provider {

class theMasterScriptProviderFactory {
public:
    static ::css::uno::Reference< ::css::script::provider::XScriptProviderFactory > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::script::provider::XScriptProviderFactory > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_provider_dot_theMasterScriptProviderFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_provider_dot_theMasterScriptProviderFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_provider_dot_theMasterScriptProviderFactory
        instance = ::css::uno::Reference< ::css::script::provider::XScriptProviderFactory >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_provider_dot_theMasterScriptProviderFactory)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.script.provider.theMasterScriptProviderFactory" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.script.provider.theMasterScriptProviderFactory of type com.sun.star.script.provider.XScriptProviderFactory" ), the_context);
        }
        return instance;
    }

private:
    theMasterScriptProviderFactory(); // not implemented
    theMasterScriptProviderFactory(theMasterScriptProviderFactory &); // not implemented
    ~theMasterScriptProviderFactory(); // not implemented
    void operator =(theMasterScriptProviderFactory); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_PROVIDER_THEMASTERSCRIPTPROVIDERFACTORY_HPP
