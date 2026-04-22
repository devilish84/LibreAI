#ifndef INCLUDED_COM_SUN_STAR_SDB_APPLICATION_COPYTABLEROWEVENT_HPP
#define INCLUDED_COM_SUN_STAR_SDB_APPLICATION_COPYTABLEROWEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/application/CopyTableRowEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/sdbc/XResultSet.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sdb { namespace application {

inline CopyTableRowEvent::CopyTableRowEvent()
    : ::css::lang::EventObject()
    , SourceData()
    , Error()
{
}

inline CopyTableRowEvent::CopyTableRowEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Reference< ::css::sdbc::XResultSet >& SourceData_, const ::css::uno::Any& Error_)
    : ::css::lang::EventObject(Source_)
    , SourceData(SourceData_)
    , Error(Error_)
{
}


inline bool operator==(const CopyTableRowEvent& the_lhs, const CopyTableRowEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.SourceData == the_rhs.SourceData
        && the_lhs.Error == the_rhs.Error;
}

inline bool operator!=(const CopyTableRowEvent& the_lhs, const CopyTableRowEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace sdb { namespace application {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::application::CopyTableRowEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XResultSet > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sdb.application.CopyTableRowEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdb::application::CopyTableRowEvent const *) {
    return ::cppu::UnoType< ::css::sdb::application::CopyTableRowEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_APPLICATION_COPYTABLEROWEVENT_HPP
