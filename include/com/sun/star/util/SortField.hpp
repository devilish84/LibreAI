#ifndef INCLUDED_COM_SUN_STAR_UTIL_SORTFIELD_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_SORTFIELD_HPP

#include "sal/config.h"

#include "com/sun/star/util/SortField.hdl"

#include "com/sun/star/util/SortFieldType.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline SortField::SortField()
    : Field(0)
    , SortAscending(false)
    , FieldType(::css::util::SortFieldType_AUTOMATIC)
{
}

inline SortField::SortField(const ::sal_Int32& Field_, const ::sal_Bool& SortAscending_, const ::css::util::SortFieldType& FieldType_)
    : Field(Field_)
    , SortAscending(SortAscending_)
    , FieldType(FieldType_)
{
}


inline bool operator==(const SortField& the_lhs, const SortField& the_rhs)
{
    return the_lhs.Field == the_rhs.Field
        && the_lhs.SortAscending == the_rhs.SortAscending
        && the_lhs.FieldType == the_rhs.FieldType;
}

inline bool operator!=(const SortField& the_lhs, const SortField& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::SortField const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::util::SortFieldType >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.SortField", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::SortField const *) {
    return ::cppu::UnoType< ::css::util::SortField >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_SORTFIELD_HPP
