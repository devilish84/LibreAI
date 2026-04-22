#ifndef INCLUDED_COM_SUN_STAR_SDBC_DRIVERPROPERTYINFO_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_DRIVERPROPERTYINFO_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/DriverPropertyInfo.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline DriverPropertyInfo::DriverPropertyInfo()
    : Name()
    , Description()
    , IsRequired(false)
    , Value()
    , Choices()
{
}

inline DriverPropertyInfo::DriverPropertyInfo(const ::rtl::OUString& Name_, const ::rtl::OUString& Description_, const ::sal_Bool& IsRequired_, const ::rtl::OUString& Value_, const ::css::uno::Sequence< ::rtl::OUString >& Choices_)
    : Name(Name_)
    , Description(Description_)
    , IsRequired(IsRequired_)
    , Value(Value_)
    , Choices(Choices_)
{
}


inline bool operator==(const DriverPropertyInfo& the_lhs, const DriverPropertyInfo& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Description == the_rhs.Description
        && the_lhs.IsRequired == the_rhs.IsRequired
        && the_lhs.Value == the_rhs.Value
        && the_lhs.Choices == the_rhs.Choices;
}

inline bool operator!=(const DriverPropertyInfo& the_lhs, const DriverPropertyInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::DriverPropertyInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sdbc.DriverPropertyInfo", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdbc::DriverPropertyInfo const *) {
    return ::cppu::UnoType< ::css::sdbc::DriverPropertyInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_DRIVERPROPERTYINFO_HPP
