#ifndef INCLUDED_COM_SUN_STAR_PACKAGES_ZIP_ZIPFILEACCESS_HPP
#define INCLUDED_COM_SUN_STAR_PACKAGES_ZIP_ZIPFILEACCESS_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/io/IOException.hpp"
#include "com/sun/star/packages/zip/XZipFileAccess2.hpp"
#include "com/sun/star/packages/zip/ZipException.hpp"
#include "com/sun/star/ucb/ContentCreationException.hpp"
#include "com/sun/star/ucb/InteractiveIOException.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_packages_dot_zip_dot_ZipFileAccess && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_packages_dot_zip_dot_ZipFileAccess) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_packages_dot_zip_dot_ZipFileAccess
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_packages_dot_zip_dot_ZipFileAccess(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace packages { namespace zip {

class ZipFileAccess {
public:
    static ::css::uno::Reference< ::css::packages::zip::XZipFileAccess2 > createWithURL(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& URL) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= URL;
        ::css::uno::Reference< ::css::packages::zip::XZipFileAccess2 > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_packages_dot_zip_dot_ZipFileAccess && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_packages_dot_zip_dot_ZipFileAccess) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_packages_dot_zip_dot_ZipFileAccess
            the_instance = ::css::uno::Reference< ::css::packages::zip::XZipFileAccess2 >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_packages_dot_zip_dot_ZipFileAccess)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::packages::zip::XZipFileAccess2 >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.packages.zip.ZipFileAccess", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::io::IOException &) {
            throw;
        } catch (const ::css::ucb::ContentCreationException &) {
            throw;
        } catch (const ::css::ucb::InteractiveIOException &) {
            throw;
        } catch (const ::css::packages::zip::ZipException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.packages.zip.ZipFileAccess" + " of type " + "com.sun.star.packages.zip.XZipFileAccess2" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.packages.zip.ZipFileAccess" + " of type " + "com.sun.star.packages.zip.XZipFileAccess2", the_context);
        }
        return the_instance;
    }

private:
    ZipFileAccess(); // not implemented
    ZipFileAccess(ZipFileAccess &); // not implemented
    ~ZipFileAccess(); // not implemented
    void operator =(ZipFileAccess); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_PACKAGES_ZIP_ZIPFILEACCESS_HPP
