#ifndef INCLUDED_COM_SUN_STAR_RESOURCE_STRINGRESOURCEWITHSTORAGE_HPP
#define INCLUDED_COM_SUN_STAR_RESOURCE_STRINGRESOURCEWITHSTORAGE_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/embed/XStorage.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/resource/XStringResourceWithStorage.hpp"
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
#include "sal/types.h"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithStorage && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithStorage) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithStorage
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithStorage(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace resource {

class StringResourceWithStorage {
public:
    static ::css::uno::Reference< ::css::resource::XStringResourceWithStorage > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::embed::XStorage >& Storage, ::sal_Bool ReadOnly, const ::css::lang::Locale& locale, const ::rtl::OUString& BaseName, const ::rtl::OUString& Comment) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(5);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Storage;
        the_arguments_array[1] <<= ReadOnly;
        the_arguments_array[2] <<= locale;
        the_arguments_array[3] <<= BaseName;
        the_arguments_array[4] <<= Comment;
        ::css::uno::Reference< ::css::resource::XStringResourceWithStorage > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithStorage && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithStorage) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithStorage
            the_instance = ::css::uno::Reference< ::css::resource::XStringResourceWithStorage >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_resource_dot_StringResourceWithStorage)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::resource::XStringResourceWithStorage >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.resource.StringResourceWithStorage", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.resource.StringResourceWithStorage" + " of type " + "com.sun.star.resource.XStringResourceWithStorage" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.resource.StringResourceWithStorage" + " of type " + "com.sun.star.resource.XStringResourceWithStorage", the_context);
        }
        return the_instance;
    }

private:
    StringResourceWithStorage(); // not implemented
    StringResourceWithStorage(StringResourceWithStorage &); // not implemented
    ~StringResourceWithStorage(); // not implemented
    void operator =(StringResourceWithStorage); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_RESOURCE_STRINGRESOURCEWITHSTORAGE_HPP
