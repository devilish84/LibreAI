#ifndef INCLUDED_COM_SUN_STAR_FRAME_POPUPMENUCONTROLLERFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_POPUPMENUCONTROLLERFACTORY_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/frame/XUIControllerFactory.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_PopupMenuControllerFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_PopupMenuControllerFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_PopupMenuControllerFactory
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_PopupMenuControllerFactory(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace frame {

class PopupMenuControllerFactory {
public:
    static ::css::uno::Reference< ::css::frame::XUIControllerFactory > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::frame::XUIControllerFactory > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_PopupMenuControllerFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_frame_dot_PopupMenuControllerFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_PopupMenuControllerFactory
            the_instance = ::css::uno::Reference< ::css::frame::XUIControllerFactory >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_frame_dot_PopupMenuControllerFactory)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
            the_instance = ::css::uno::Reference< ::css::frame::XUIControllerFactory >(the_context->getServiceManager()->createInstanceWithContext( "com.sun.star.frame.PopupMenuControllerFactory", the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.frame.PopupMenuControllerFactory" + " of type " + "com.sun.star.frame.XUIControllerFactory" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.frame.PopupMenuControllerFactory" + " of type " + "com.sun.star.frame.XUIControllerFactory", the_context);
        }
        return the_instance;
    }

private:
    PopupMenuControllerFactory(); // not implemented
    PopupMenuControllerFactory(PopupMenuControllerFactory &); // not implemented
    ~PopupMenuControllerFactory(); // not implemented
    void operator =(PopupMenuControllerFactory); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_FRAME_POPUPMENUCONTROLLERFACTORY_HPP
