#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_DOCUMENTDIALOGLIBRARYCONTAINER_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_DOCUMENTDIALOGLIBRARYCONTAINER_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/document/XStorageBasedDocument.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/script/XStorageBasedLibraryContainer.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace script {

class DocumentDialogLibraryContainer {
public:
    static ::css::uno::Reference< ::css::script::XStorageBasedLibraryContainer > create(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::css::uno::Reference< ::css::document::XStorageBasedDocument >& Document) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Document;
        ::css::uno::Reference< ::css::script::XStorageBasedLibraryContainer > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer
            the_instance = ::css::uno::Reference< ::css::script::XStorageBasedLibraryContainer >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::script::XStorageBasedLibraryContainer >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.script.DocumentDialogLibraryContainer", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.script.DocumentDialogLibraryContainer" + " of type " + "com.sun.star.script.XStorageBasedLibraryContainer" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.script.DocumentDialogLibraryContainer" + " of type " + "com.sun.star.script.XStorageBasedLibraryContainer", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::script::XStorageBasedLibraryContainer > createWithURL(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& URL) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= URL;
        ::css::uno::Reference< ::css::script::XStorageBasedLibraryContainer > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer
            the_instance = ::css::uno::Reference< ::css::script::XStorageBasedLibraryContainer >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_script_dot_DocumentDialogLibraryContainer)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::script::XStorageBasedLibraryContainer >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.script.DocumentDialogLibraryContainer", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.script.DocumentDialogLibraryContainer" + " of type " + "com.sun.star.script.XStorageBasedLibraryContainer" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.script.DocumentDialogLibraryContainer" + " of type " + "com.sun.star.script.XStorageBasedLibraryContainer", the_context);
        }
        return the_instance;
    }

private:
    DocumentDialogLibraryContainer(); // not implemented
    DocumentDialogLibraryContainer(DocumentDialogLibraryContainer &); // not implemented
    ~DocumentDialogLibraryContainer(); // not implemented
    void operator =(DocumentDialogLibraryContainer); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_DOCUMENTDIALOGLIBRARYCONTAINER_HPP
