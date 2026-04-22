#ifndef INCLUDED_COM_SUN_STAR_AWT_SELECTION_HPP
#define INCLUDED_COM_SUN_STAR_AWT_SELECTION_HPP

#include "sal/config.h"

#include "com/sun/star/awt/Selection.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace awt {

inline Selection::Selection()
    : Min(0)
    , Max(0)
{
}

inline Selection::Selection(const ::sal_Int32& Min_, const ::sal_Int32& Max_)
    : Min(Min_)
    , Max(Max_)
{
}


inline bool operator==(const Selection& the_lhs, const Selection& the_rhs)
{
    return the_lhs.Min == the_rhs.Min
        && the_lhs.Max == the_rhs.Max;
}

inline bool operator!=(const Selection& the_lhs, const Selection& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace awt {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::Selection const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.awt.Selection", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::Selection const *) {
    return ::cppu::UnoType< ::css::awt::Selection >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_SELECTION_HPP
