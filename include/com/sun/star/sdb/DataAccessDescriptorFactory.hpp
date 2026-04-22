#ifndef INCLUDED_COM_SUN_STAR_SDB_DATAACCESSDESCRIPTORFACTORY_HPP
#define INCLUDED_COM_SUN_STAR_SDB_DATAACCESSDESCRIPTORFACTORY_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/sdb/XDataAccessDescriptorFactory.hpp"
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

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_DataAccessDescriptorFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_DataAccessDescriptorFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_DataAccessDescriptorFactory
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_DataAccessDescriptorFactory(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace sdb {

class DataAccessDescriptorFactory {
public:
    static ::css::uno::Reference< ::css::sdb::XDataAccessDescriptorFactory > get(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::sdb::XDataAccessDescriptorFactory > instance;
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_DataAccessDescriptorFactory && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_sdb_dot_DataAccessDescriptorFactory) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_DataAccessDescriptorFactory
        instance = ::css::uno::Reference< ::css::sdb::XDataAccessDescriptorFactory >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_sdb_dot_DataAccessDescriptorFactory)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
#else
        the_context->getValueByName(::rtl::OUString( "/singletons/com.sun.star.sdb.DataAccessDescriptorFactory" )) >>= instance;
#endif
        if (!instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString( "component context fails to supply singleton com.sun.star.sdb.DataAccessDescriptorFactory of type com.sun.star.sdb.XDataAccessDescriptorFactory" ), the_context);
        }
        return instance;
    }

private:
    DataAccessDescriptorFactory(); // not implemented
    DataAccessDescriptorFactory(DataAccessDescriptorFactory &); // not implemented
    ~DataAccessDescriptorFactory(); // not implemented
    void operator =(DataAccessDescriptorFactory); // not implemented
};

} } } }

#endif // INCLUDED_COM_SUN_STAR_SDB_DATAACCESSDESCRIPTORFACTORY_HPP
