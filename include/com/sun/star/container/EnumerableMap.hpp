#ifndef INCLUDED_COM_SUN_STAR_CONTAINER_ENUMERABLEMAP_HPP
#define INCLUDED_COM_SUN_STAR_CONTAINER_ENUMERABLEMAP_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/beans/IllegalTypeException.hpp"
#include "com/sun/star/beans/Pair.hpp"
#include "com/sun/star/container/XEnumerableMap.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_container_dot_EnumerableMap && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_container_dot_EnumerableMap) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_container_dot_EnumerableMap
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_container_dot_EnumerableMap(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace container {

class EnumerableMap {
public:
    static ::css::uno::Reference< ::css::container::XEnumerableMap > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Type& KeyType, const ::css::uno::Type& ValueType) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= KeyType;
        the_arguments_array[1] <<= ValueType;
        ::css::uno::Reference< ::css::container::XEnumerableMap > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_container_dot_EnumerableMap && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_container_dot_EnumerableMap) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_container_dot_EnumerableMap
            the_instance = ::css::uno::Reference< ::css::container::XEnumerableMap >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_container_dot_EnumerableMap)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::container::XEnumerableMap >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.container.EnumerableMap", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::beans::IllegalTypeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.container.EnumerableMap" + " of type " + "com.sun.star.container.XEnumerableMap" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.container.EnumerableMap" + " of type " + "com.sun.star.container.XEnumerableMap", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::container::XEnumerableMap > createImmutable(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Type& KeyType, const ::css::uno::Type& ValueType, const ::css::uno::Sequence< ::css::beans::Pair< ::css::uno::Any, ::css::uno::Any > >& Values) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(3);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= KeyType;
        the_arguments_array[1] <<= ValueType;
        the_arguments_array[2] <<= Values;
        ::css::uno::Reference< ::css::container::XEnumerableMap > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_container_dot_EnumerableMap && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_container_dot_EnumerableMap) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_container_dot_EnumerableMap
            the_instance = ::css::uno::Reference< ::css::container::XEnumerableMap >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_container_dot_EnumerableMap)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::container::XEnumerableMap >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.container.EnumerableMap", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::beans::IllegalTypeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.container.EnumerableMap" + " of type " + "com.sun.star.container.XEnumerableMap" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.container.EnumerableMap" + " of type " + "com.sun.star.container.XEnumerableMap", the_context);
        }
        return the_instance;
    }

private:
    EnumerableMap(); // not implemented
    EnumerableMap(EnumerableMap &); // not implemented
    ~EnumerableMap(); // not implemented
    void operator =(EnumerableMap); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_CONTAINER_ENUMERABLEMAP_HPP
