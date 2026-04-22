#ifndef INCLUDED_COM_SUN_STAR_I18N_BOUNDARY_HPP
#define INCLUDED_COM_SUN_STAR_I18N_BOUNDARY_HPP

#include "sal/config.h"

#include "com/sun/star/i18n/Boundary.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace i18n {

inline Boundary::Boundary()
    : startPos(0)
    , endPos(0)
{
}

inline Boundary::Boundary(const ::sal_Int32& startPos_, const ::sal_Int32& endPos_)
    : startPos(startPos_)
    , endPos(endPos_)
{
}


inline bool operator==(const Boundary& the_lhs, const Boundary& the_rhs)
{
    return the_lhs.startPos == the_rhs.startPos
        && the_lhs.endPos == the_rhs.endPos;
}

inline bool operator!=(const Boundary& the_lhs, const Boundary& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::i18n::Boundary const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.i18n.Boundary", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::i18n::Boundary const *) {
    return ::cppu::UnoType< ::css::i18n::Boundary >::get();
}

#endif // INCLUDED_COM_SUN_STAR_I18N_BOUNDARY_HPP
