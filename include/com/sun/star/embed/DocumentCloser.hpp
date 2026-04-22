#ifndef INCLUDED_COM_SUN_STAR_EMBED_DOCUMENTCLOSER_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_DOCUMENTCLOSER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/frame/DoubleInitializationException.hpp"
#include "com/sun/star/frame/XFrame.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_DocumentCloser && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_DocumentCloser) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_DocumentCloser
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_DocumentCloser(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace embed {

class DocumentCloser {
public:
    static ::css::uno::Reference< ::css::lang::XComponent > DocumentCloserCtor1(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::frame::XFrame >& xFrame) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= xFrame;
        ::css::uno::Reference< ::css::lang::XComponent > the_instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_DocumentCloser && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_embed_dot_DocumentCloser) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_DocumentCloser
        the_instance = ::css::uno::Reference< ::css::lang::XComponent >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_embed_dot_DocumentCloser)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
        ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
        if (init.is()) {
            init->initialize(the_arguments);
        }
#else
        the_instance = ::css::uno::Reference< ::css::lang::XComponent >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.embed.DocumentCloser", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.embed.DocumentCloser" + " of type " + "com.sun.star.lang.XComponent", the_context);
        }
        return the_instance;
    }

private:
    DocumentCloser(); // not implemented
    DocumentCloser(DocumentCloser &); // not implemented
    ~DocumentCloser(); // not implemented
    void operator =(DocumentCloser); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_EMBED_DOCUMENTCLOSER_HPP
