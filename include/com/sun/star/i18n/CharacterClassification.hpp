#ifndef INCLUDED_COM_SUN_STAR_I18N_CHARACTERCLASSIFICATION_HPP
#define INCLUDED_COM_SUN_STAR_I18N_CHARACTERCLASSIFICATION_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/i18n/XCharacterClassification.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_i18n_dot_CharacterClassification && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_i18n_dot_CharacterClassification) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_i18n_dot_CharacterClassification
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_i18n_dot_CharacterClassification(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace i18n {

class CharacterClassification {
public:
    static ::css::uno::Reference< ::css::i18n::XCharacterClassification > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::i18n::XCharacterClassification > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_i18n_dot_CharacterClassification && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_i18n_dot_CharacterClassification) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_i18n_dot_CharacterClassification
            the_instance = ::css::uno::Reference< ::css::i18n::XCharacterClassification >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_i18n_dot_CharacterClassification)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
            the_instance = ::css::uno::Reference< ::css::i18n::XCharacterClassification >(the_context->getServiceManager()->createInstanceWithContext( "com.sun.star.i18n.CharacterClassification", the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.i18n.CharacterClassification" + " of type " + "com.sun.star.i18n.XCharacterClassification" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.i18n.CharacterClassification" + " of type " + "com.sun.star.i18n.XCharacterClassification", the_context);
        }
        return the_instance;
    }

private:
    CharacterClassification(); // not implemented
    CharacterClassification(CharacterClassification &); // not implemented
    ~CharacterClassification(); // not implemented
    void operator =(CharacterClassification); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_I18N_CHARACTERCLASSIFICATION_HPP
