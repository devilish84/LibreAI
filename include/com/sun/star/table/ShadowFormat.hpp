#ifndef INCLUDED_COM_SUN_STAR_TABLE_SHADOWFORMAT_HPP
#define INCLUDED_COM_SUN_STAR_TABLE_SHADOWFORMAT_HPP

#include "sal/config.h"

#include "com/sun/star/table/ShadowFormat.hdl"

#include "com/sun/star/table/ShadowLocation.hpp"
#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace table {

inline ShadowFormat::ShadowFormat()
    : Location(::css::table::ShadowLocation_NONE)
    , ShadowWidth(0)
    , IsTransparent(false)
    , Color(0)
{
}

inline ShadowFormat::ShadowFormat(const ::css::table::ShadowLocation& Location_, const ::sal_Int16& ShadowWidth_, const ::sal_Bool& IsTransparent_, const ::sal_Int32& Color_)
    : Location(Location_)
    , ShadowWidth(ShadowWidth_)
    , IsTransparent(IsTransparent_)
    , Color(Color_)
{
}


inline bool operator==(const ShadowFormat& the_lhs, const ShadowFormat& the_rhs)
{
    return the_lhs.Location == the_rhs.Location
        && the_lhs.ShadowWidth == the_rhs.ShadowWidth
        && the_lhs.IsTransparent == the_rhs.IsTransparent
        && the_lhs.Color == the_rhs.Color;
}

inline bool operator!=(const ShadowFormat& the_lhs, const ShadowFormat& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace table {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::table::ShadowFormat const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::table::ShadowLocation >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.table.ShadowFormat", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::table::ShadowFormat const *) {
    return ::cppu::UnoType< ::css::table::ShadowFormat >::get();
}

#endif // INCLUDED_COM_SUN_STAR_TABLE_SHADOWFORMAT_HPP
