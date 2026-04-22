#ifndef INCLUDED_COM_SUN_STAR_RENDERING_CANVASFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_CANVASFACTORY_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/lang/XMultiComponentFactory.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rendering_dot_CanvasFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rendering_dot_CanvasFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rendering_dot_CanvasFactory
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rendering_dot_CanvasFactory(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace rendering {

class CanvasFactory {
public:
    static ::css::uno::Reference< ::css::lang::XMultiComponentFactory > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::lang::XMultiComponentFactory > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rendering_dot_CanvasFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_rendering_dot_CanvasFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rendering_dot_CanvasFactory
            the_instance = ::css::uno::Reference< ::css::lang::XMultiComponentFactory >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_rendering_dot_CanvasFactory)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
            the_instance = ::css::uno::Reference< ::css::lang::XMultiComponentFactory >(the_context->getServiceManager()->createInstanceWithContext( "com.sun.star.rendering.CanvasFactory", the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.rendering.CanvasFactory" + " of type " + "com.sun.star.lang.XMultiComponentFactory" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.rendering.CanvasFactory" + " of type " + "com.sun.star.lang.XMultiComponentFactory", the_context);
        }
        return the_instance;
    }

private:
    CanvasFactory(); // not implemented
    CanvasFactory(CanvasFactory &); // not implemented
    ~CanvasFactory(); // not implemented
    void operator =(CanvasFactory); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_RENDERING_CANVASFACTORY_HPP
