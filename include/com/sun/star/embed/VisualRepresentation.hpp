#ifndef INCLUDED_COM_SUN_STAR_EMBED_VISUALREPRESENTATION_HPP
#define INCLUDED_COM_SUN_STAR_EMBED_VISUALREPRESENTATION_HPP

#include "sal/config.h"

#include "com/sun/star/embed/VisualRepresentation.hdl"

#include "com/sun/star/datatransfer/DataFlavor.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace embed {

inline VisualRepresentation::VisualRepresentation()
    : Flavor()
    , Data()
{
}

inline VisualRepresentation::VisualRepresentation(const ::css::datatransfer::DataFlavor& Flavor_, const ::css::uno::Any& Data_)
    : Flavor(Flavor_)
    , Data(Data_)
{
}


inline bool operator==(const VisualRepresentation& the_lhs, const VisualRepresentation& the_rhs)
{
    return the_lhs.Flavor == the_rhs.Flavor
        && the_lhs.Data == the_rhs.Data;
}

inline bool operator!=(const VisualRepresentation& the_lhs, const VisualRepresentation& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace embed {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::embed::VisualRepresentation const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::datatransfer::DataFlavor >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.embed.VisualRepresentation", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::embed::VisualRepresentation const *) {
    return ::cppu::UnoType< ::css::embed::VisualRepresentation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_EMBED_VISUALREPRESENTATION_HPP
