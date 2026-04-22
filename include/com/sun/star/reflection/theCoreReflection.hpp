#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_THECOREREFLECTION_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_THECOREREFLECTION_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/reflection/XIdlReflection.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_reflection_dot_theCoreReflection && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_reflection_dot_theCoreReflection) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_reflection_dot_theCoreReflection
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_reflection_dot_theCoreReflection(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace reflection {

class theCoreReflection {
public:
    static ::css::uno::Reference< ::css::reflection::XIdlReflection > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::reflection::XIdlReflection > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_reflection_dot_theCoreReflection && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_reflection_dot_theCoreReflection) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_reflection_dot_theCoreReflection
        instance = ::css::uno::Reference< ::css::reflection::XIdlReflection >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_reflection_dot_theCoreReflection)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.reflection.theCoreReflection" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.reflection.theCoreReflection of type com.sun.star.reflection.XIdlReflection" ), the_context);
        }
        return instance;
    }

private:
    theCoreReflection(); // not implemented
    theCoreReflection(theCoreReflection &); // not implemented
    ~theCoreReflection(); // not implemented
    void operator =(theCoreReflection); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_THECOREREFLECTION_HPP
