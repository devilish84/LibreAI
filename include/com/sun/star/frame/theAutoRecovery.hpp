#ifndef INCLUDED_COM_SUN_STAR_FRAME_THEAUTORECOVERY_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_THEAUTORECOVERY_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/frame/XDispatch.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theAutoRecovery && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theAutoRecovery) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theAutoRecovery
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theAutoRecovery(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace frame {

class theAutoRecovery {
public:
    static ::css::uno::Reference< ::css::frame::XDispatch > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::frame::XDispatch > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theAutoRecovery && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_theAutoRecovery) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theAutoRecovery
        instance = ::css::uno::Reference< ::css::frame::XDispatch >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_theAutoRecovery)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.frame.theAutoRecovery" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.frame.theAutoRecovery of type com.sun.star.frame.XDispatch" ), the_context);
        }
        return instance;
    }

private:
    theAutoRecovery(); // not implemented
    theAutoRecovery(theAutoRecovery &); // not implemented
    ~theAutoRecovery(); // not implemented
    void operator =(theAutoRecovery); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_FRAME_THEAUTORECOVERY_HPP
