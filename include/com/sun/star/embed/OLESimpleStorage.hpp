#ifndef INCLUDED_COM_SUN_STAR_EMBED_OLESIMPLESTORAGE_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_OLESIMPLESTORAGE_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/embed/XOLESimpleStorage.hpp"
#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/io/XStream.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace embed {

class OLESimpleStorage {
public:
    static ::css::uno::Reference< ::css::embed::XOLESimpleStorage > createFromInputStream(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::io::XInputStream >& xInputStream, ::sal_Bool bNoTempCopy) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= xInputStream;
        the_arguments_array[1] <<= bNoTempCopy;
        ::css::uno::Reference< ::css::embed::XOLESimpleStorage > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage
            the_instance = ::css::uno::Reference< ::css::embed::XOLESimpleStorage >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::embed::XOLESimpleStorage >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.embed.OLESimpleStorage", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.embed.OLESimpleStorage" + " of type " + "com.sun.star.embed.XOLESimpleStorage" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.embed.OLESimpleStorage" + " of type " + "com.sun.star.embed.XOLESimpleStorage", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::embed::XOLESimpleStorage > createFromStream(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::io::XStream >& xStream, ::sal_Bool bNoTempCopy) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= xStream;
        the_arguments_array[1] <<= bNoTempCopy;
        ::css::uno::Reference< ::css::embed::XOLESimpleStorage > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage
            the_instance = ::css::uno::Reference< ::css::embed::XOLESimpleStorage >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_OLESimpleStorage)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::embed::XOLESimpleStorage >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.embed.OLESimpleStorage", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.embed.OLESimpleStorage" + " of type " + "com.sun.star.embed.XOLESimpleStorage" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.embed.OLESimpleStorage" + " of type " + "com.sun.star.embed.XOLESimpleStorage", the_context);
        }
        return the_instance;
    }

private:
    OLESimpleStorage(); // not implemented
    OLESimpleStorage(OLESimpleStorage &); // not implemented
    ~OLESimpleStorage(); // not implemented
    void operator =(OLESimpleStorage); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_EMBED_OLESIMPLESTORAGE_HPP
