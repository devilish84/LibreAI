#ifndef INCLUDED_COM_SUN_STAR_RENDERING_FONTREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_RENDERING_FONTREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/rendering/FontRequest.hdl"

#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/rendering/FontInfo.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rendering {

inline FontRequest::FontRequest()
    : FontDescription()
    , CellSize(0)
    , ReferenceAdvancement(0)
    , Locale()
{
}

inline FontRequest::FontRequest(const ::css::rendering::FontInfo& FontDescription_, const double& CellSize_, const double& ReferenceAdvancement_, const ::css::lang::Locale& Locale_)
    : FontDescription(FontDescription_)
    , CellSize(CellSize_)
    , ReferenceAdvancement(ReferenceAdvancement_)
    , Locale(Locale_)
{
}


inline bool operator==(const FontRequest& the_lhs, const FontRequest& the_rhs)
{
    return the_lhs.FontDescription == the_rhs.FontDescription
        && the_lhs.CellSize == the_rhs.CellSize
        && the_lhs.ReferenceAdvancement == the_rhs.ReferenceAdvancement
        && the_lhs.Locale == the_rhs.Locale;
}

inline bool operator!=(const FontRequest& the_lhs, const FontRequest& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rendering {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rendering::FontRequest const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::rendering::FontInfo >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< double >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::lang::Locale >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rendering.FontRequest", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rendering::FontRequest const *) {
    return ::cppu::UnoType< ::css::rendering::FontRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RENDERING_FONTREQUEST_HPP
