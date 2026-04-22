#ifndef INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_RESOURCEID_HPP
#define INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_RESOURCEID_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/drawing/framework/XResourceId.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace drawing { namespace framework {

class ResourceId {
public:
    static ::css::uno::Reference< ::css::drawing::framework::XResourceId > createEmpty(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::drawing::framework::XResourceId > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId
            the_instance = ::css::uno::Reference< ::css::drawing::framework::XResourceId >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(::css::uno::Sequence< ::css::uno::Any >());
            }
#else
            the_instance = ::css::uno::Reference< ::css::drawing::framework::XResourceId >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.drawing.framework.ResourceId", ::css::uno::Sequence< ::css::uno::Any >(), the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.drawing.framework.ResourceId" + " of type " + "com.sun.star.drawing.framework.XResourceId" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.drawing.framework.ResourceId" + " of type " + "com.sun.star.drawing.framework.XResourceId", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::drawing::framework::XResourceId > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& sResourceURL) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= sResourceURL;
        ::css::uno::Reference< ::css::drawing::framework::XResourceId > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId
            the_instance = ::css::uno::Reference< ::css::drawing::framework::XResourceId >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::drawing::framework::XResourceId >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.drawing.framework.ResourceId", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.drawing.framework.ResourceId" + " of type " + "com.sun.star.drawing.framework.XResourceId" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.drawing.framework.ResourceId" + " of type " + "com.sun.star.drawing.framework.XResourceId", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::drawing::framework::XResourceId > createWithAnchor(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& sResourceURL, const ::css::uno::Reference< ::css::drawing::framework::XResourceId >& xAnchor) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= sResourceURL;
        the_arguments_array[1] <<= xAnchor;
        ::css::uno::Reference< ::css::drawing::framework::XResourceId > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId
            the_instance = ::css::uno::Reference< ::css::drawing::framework::XResourceId >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::drawing::framework::XResourceId >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.drawing.framework.ResourceId", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.drawing.framework.ResourceId" + " of type " + "com.sun.star.drawing.framework.XResourceId" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.drawing.framework.ResourceId" + " of type " + "com.sun.star.drawing.framework.XResourceId", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::drawing::framework::XResourceId > createWithAnchorURL(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& sResourceURL, const ::rtl::OUString& sAnchorURL) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= sResourceURL;
        the_arguments_array[1] <<= sAnchorURL;
        ::css::uno::Reference< ::css::drawing::framework::XResourceId > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId
            the_instance = ::css::uno::Reference< ::css::drawing::framework::XResourceId >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_drawing_dot_framework_dot_ResourceId)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::drawing::framework::XResourceId >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.drawing.framework.ResourceId", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.drawing.framework.ResourceId" + " of type " + "com.sun.star.drawing.framework.XResourceId" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.drawing.framework.ResourceId" + " of type " + "com.sun.star.drawing.framework.XResourceId", the_context);
        }
        return the_instance;
    }

private:
    ResourceId(); // not implemented
    ResourceId(ResourceId &); // not implemented
    ~ResourceId(); // not implemented
    void operator =(ResourceId); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_DRAWING_FRAMEWORK_RESOURCEID_HPP
