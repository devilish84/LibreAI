#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_BROWSE_THEBROWSENODEFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_BROWSE_THEBROWSENODEFACTORY_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/script/browse/XBrowseNodeFactory.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_browse_dot_theBrowseNodeFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_browse_dot_theBrowseNodeFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_browse_dot_theBrowseNodeFactory
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_browse_dot_theBrowseNodeFactory(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace script { namespace browse {

class theBrowseNodeFactory {
public:
    static ::css::uno::Reference< ::css::script::browse::XBrowseNodeFactory > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::script::browse::XBrowseNodeFactory > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_browse_dot_theBrowseNodeFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_browse_dot_theBrowseNodeFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_browse_dot_theBrowseNodeFactory
        instance = ::css::uno::Reference< ::css::script::browse::XBrowseNodeFactory >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_browse_dot_theBrowseNodeFactory)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.script.browse.theBrowseNodeFactory" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.script.browse.theBrowseNodeFactory of type com.sun.star.script.browse.XBrowseNodeFactory" ), the_context);
        }
        return instance;
    }

private:
    theBrowseNodeFactory(); // not implemented
    theBrowseNodeFactory(theBrowseNodeFactory &); // not implemented
    ~theBrowseNodeFactory(); // not implemented
    void operator =(theBrowseNodeFactory); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_BROWSE_THEBROWSENODEFACTORY_HPP
