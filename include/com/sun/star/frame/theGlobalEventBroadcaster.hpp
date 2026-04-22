#ifndef INCLUDED_COM_SUN_STAR_FRAME_THEGLOBALEVENTBROADCASTER_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_THEGLOBALEVENTBROADCASTER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/frame/XGlobalEventBroadcaster.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theGlobalEventBroadcaster && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theGlobalEventBroadcaster) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theGlobalEventBroadcaster
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theGlobalEventBroadcaster(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace frame {

class theGlobalEventBroadcaster {
public:
    static ::css::uno::Reference< ::css::frame::XGlobalEventBroadcaster > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::frame::XGlobalEventBroadcaster > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theGlobalEventBroadcaster && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theGlobalEventBroadcaster) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theGlobalEventBroadcaster
        instance = ::css::uno::Reference< ::css::frame::XGlobalEventBroadcaster >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theGlobalEventBroadcaster)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.frame.theGlobalEventBroadcaster" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.frame.theGlobalEventBroadcaster of type com.sun.star.frame.XGlobalEventBroadcaster" ), the_context);
        }
        return instance;
    }

private:
    theGlobalEventBroadcaster(); // not implemented
    theGlobalEventBroadcaster(theGlobalEventBroadcaster &); // not implemented
    ~theGlobalEventBroadcaster(); // not implemented
    void operator =(theGlobalEventBroadcaster); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_FRAME_THEGLOBALEVENTBROADCASTER_HPP
