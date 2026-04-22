#ifndef INCLUDED_COM_SUN_STAR_UTIL_THEMACROEXPANDER_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_THEMACROEXPANDER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/util/XMacroExpander.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_theMacroExpander && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_theMacroExpander) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_theMacroExpander
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_theMacroExpander(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace util {

class theMacroExpander {
public:
    static ::css::uno::Reference< ::css::util::XMacroExpander > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::util::XMacroExpander > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_theMacroExpander && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_util_dot_theMacroExpander) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_theMacroExpander
        instance = ::css::uno::Reference< ::css::util::XMacroExpander >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_util_dot_theMacroExpander)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.util.theMacroExpander" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.util.theMacroExpander of type com.sun.star.util.XMacroExpander" ), the_context);
        }
        return instance;
    }

private:
    theMacroExpander(); // not implemented
    theMacroExpander(theMacroExpander &); // not implemented
    ~theMacroExpander(); // not implemented
    void operator =(theMacroExpander); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_UTIL_THEMACROEXPANDER_HPP
