#ifndef INCLUDED_COM_SUN_STAR_FRAME_THEDESKTOP_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_THEDESKTOP_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/frame/XDesktop2.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theDesktop && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theDesktop) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theDesktop
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theDesktop(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace frame {

class theDesktop {
public:
    static ::css::uno::Reference< ::css::frame::XDesktop2 > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::frame::XDesktop2 > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theDesktop && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theDesktop) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theDesktop
        instance = ::css::uno::Reference< ::css::frame::XDesktop2 >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theDesktop)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.frame.theDesktop" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.frame.theDesktop of type com.sun.star.frame.XDesktop2" ), the_context);
        }
        return instance;
    }

private:
    theDesktop(); // not implemented
    theDesktop(theDesktop &); // not implemented
    ~theDesktop(); // not implemented
    void operator =(theDesktop); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_FRAME_THEDESKTOP_HPP
