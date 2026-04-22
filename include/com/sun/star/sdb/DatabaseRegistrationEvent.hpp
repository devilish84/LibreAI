#ifndef INCLUDED_COM_SUN_STAR_SDB_DATABASEREGISTRATIONEVENT_HPP
#define INCLUDED_COM_SUN_STAR_SDB_DATABASEREGISTRATIONEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/sdb/DatabaseRegistrationEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sdb {

inline DatabaseRegistrationEvent::DatabaseRegistrationEvent()
    : ::css::lang::EventObject()
    , Name()
    , OldLocation()
    , NewLocation()
{
}

inline DatabaseRegistrationEvent::DatabaseRegistrationEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& Name_, const ::rtl::OUString& OldLocation_, const ::rtl::OUString& NewLocation_)
    : ::css::lang::EventObject(Source_)
    , Name(Name_)
    , OldLocation(OldLocation_)
    , NewLocation(NewLocation_)
{
}


inline bool operator==(const DatabaseRegistrationEvent& the_lhs, const DatabaseRegistrationEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.Name == the_rhs.Name
        && the_lhs.OldLocation == the_rhs.OldLocation
        && the_lhs.NewLocation == the_rhs.NewLocation;
}

inline bool operator!=(const DatabaseRegistrationEvent& the_lhs, const DatabaseRegistrationEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sdb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdb::DatabaseRegistrationEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sdb.DatabaseRegistrationEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdb::DatabaseRegistrationEvent const *) {
    return ::cppu::UnoType< ::css::sdb::DatabaseRegistrationEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDB_DATABASEREGISTRATIONEVENT_HPP
