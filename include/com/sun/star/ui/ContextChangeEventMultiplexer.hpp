#ifndef INCLUDED_COM_SUN_STAR_UI_CONTEXTCHANGEEVENTMULTIPLEXER_HPP
#define INCLUDED_COM_SUN_STAR_UI_CONTEXTCHANGEEVENTMULTIPLEXER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/ui/XContextChangeEventMultiplexer.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_ContextChangeEventMultiplexer && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_ContextChangeEventMultiplexer) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_ContextChangeEventMultiplexer
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_ContextChangeEventMultiplexer(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace ui {

class ContextChangeEventMultiplexer {
public:
    static ::css::uno::Reference< ::css::ui::XContextChangeEventMultiplexer > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::ui::XContextChangeEventMultiplexer > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_ContextChangeEventMultiplexer && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_ui_dot_ContextChangeEventMultiplexer) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_ContextChangeEventMultiplexer
        instance = ::css::uno::Reference< ::css::ui::XContextChangeEventMultiplexer >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_ui_dot_ContextChangeEventMultiplexer)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.ui.ContextChangeEventMultiplexer" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.ui.ContextChangeEventMultiplexer of type com.sun.star.ui.XContextChangeEventMultiplexer" ), the_context);
        }
        return instance;
    }

private:
    ContextChangeEventMultiplexer(); // not implemented
    ContextChangeEventMultiplexer(ContextChangeEventMultiplexer &); // not implemented
    ~ContextChangeEventMultiplexer(); // not implemented
    void operator =(ContextChangeEventMultiplexer); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_UI_CONTEXTCHANGEEVENTMULTIPLEXER_HPP
