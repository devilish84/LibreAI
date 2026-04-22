#ifndef INCLUDED_COM_SUN_STAR_SHEET_COMPLEXREFERENCE_HPP
#define INCLUDED_COM_SUN_STAR_SHEET_COMPLEXREFERENCE_HPP

#include "sal/config.h"

#include "com/sun/star/sheet/ComplexReference.hdl"

#include "com/sun/star/sheet/SingleReference.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sheet {

inline ComplexReference::ComplexReference()
    : Reference1()
    , Reference2()
{
}

inline ComplexReference::ComplexReference(const ::css::sheet::SingleReference& Reference1_, const ::css::sheet::SingleReference& Reference2_)
    : Reference1(Reference1_)
    , Reference2(Reference2_)
{
}


inline bool operator==(const ComplexReference& the_lhs, const ComplexReference& the_rhs)
{
    return the_lhs.Reference1 == the_rhs.Reference1
        && the_lhs.Reference2 == the_rhs.Reference2;
}

inline bool operator!=(const ComplexReference& the_lhs, const ComplexReference& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sheet {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sheet::ComplexReference const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::sheet::SingleReference >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::sheet::SingleReference >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.sheet.ComplexReference", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sheet::ComplexReference const *) {
    return ::cppu::UnoType< ::css::sheet::ComplexReference >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SHEET_COMPLEXREFERENCE_HPP
