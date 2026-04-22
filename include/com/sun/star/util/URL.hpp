#ifndef INCLUDED_COM_SUN_STAR_UTIL_URL_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_URL_HPP

#include "sal/config.h"

#include "com/sun/star/util/URL.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline URL::URL()
    : Complete()
    , Main()
    , Protocol()
    , User()
    , Password()
    , Server()
    , Port(0)
    , Path()
    , Name()
    , Arguments()
    , Mark()
{
}

inline URL::URL(const ::rtl::OUString& Complete_, const ::rtl::OUString& Main_, const ::rtl::OUString& Protocol_, const ::rtl::OUString& User_, const ::rtl::OUString& Password_, const ::rtl::OUString& Server_, const ::sal_Int16& Port_, const ::rtl::OUString& Path_, const ::rtl::OUString& Name_, const ::rtl::OUString& Arguments_, const ::rtl::OUString& Mark_)
    : Complete(Complete_)
    , Main(Main_)
    , Protocol(Protocol_)
    , User(User_)
    , Password(Password_)
    , Server(Server_)
    , Port(Port_)
    , Path(Path_)
    , Name(Name_)
    , Arguments(Arguments_)
    , Mark(Mark_)
{
}


inline bool operator==(const URL& the_lhs, const URL& the_rhs)
{
    return the_lhs.Complete == the_rhs.Complete
        && the_lhs.Main == the_rhs.Main
        && the_lhs.Protocol == the_rhs.Protocol
        && the_lhs.User == the_rhs.User
        && the_lhs.Password == the_rhs.Password
        && the_lhs.Server == the_rhs.Server
        && the_lhs.Port == the_rhs.Port
        && the_lhs.Path == the_rhs.Path
        && the_lhs.Name == the_rhs.Name
        && the_lhs.Arguments == the_rhs.Arguments
        && the_lhs.Mark == the_rhs.Mark;
}

inline bool operator!=(const URL& the_lhs, const URL& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::URL const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.URL", 0, 11, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::URL const *) {
    return ::cppu::UnoType< ::css::util::URL >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_URL_HPP
