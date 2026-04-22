#ifndef INCLUDED_COM_SUN_STAR_SDB_TABLEDEFINITION_HPP
#define INCLUDED_COM_SUN_STAR_SDB_TABLEDEFINITION_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/beans/XPropertySet.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace sdb {

class TableDefinition {
public:
    static ::css::uno::Reference< ::css::beans::XPropertySet > createDefault(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::beans::XPropertySet > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition
            the_instance = ::css::uno::Reference< ::css::beans::XPropertySet >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(::css::uno::Sequence< ::css::uno::Any >());
            }
#else
            the_instance = ::css::uno::Reference< ::css::beans::XPropertySet >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.sdb.TableDefinition", ::css::uno::Sequence< ::css::uno::Any >(), the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.TableDefinition" + " of type " + "com.sun.star.beans.XPropertySet" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.TableDefinition" + " of type " + "com.sun.star.beans.XPropertySet", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::beans::XPropertySet > createWithName(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, const ::rtl::OUString& Name) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(1);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= Name;
        ::css::uno::Reference< ::css::beans::XPropertySet > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition
            the_instance = ::css::uno::Reference< ::css::beans::XPropertySet >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_TableDefinition)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::beans::XPropertySet >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.sdb.TableDefinition", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.TableDefinition" + " of type " + "com.sun.star.beans.XPropertySet" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.sdb.TableDefinition" + " of type " + "com.sun.star.beans.XPropertySet", the_context);
        }
        return the_instance;
    }

private:
    TableDefinition(); // not implemented
    TableDefinition(TableDefinition &); // not implemented
    ~TableDefinition(); // not implemented
    void operator =(TableDefinition); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_SDB_TABLEDEFINITION_HPP
