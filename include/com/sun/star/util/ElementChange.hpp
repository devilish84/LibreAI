#ifndef INCLUDED_COM_SUN_STAR_UTIL_ELEMENTCHANGE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_ELEMENTCHANGE_HPP

#include "sal/config.h"

#include "com/sun/star/util/ElementChange.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline ElementChange::ElementChange()
    : Accessor()
    , Element()
    , ReplacedElement()
{
}

inline ElementChange::ElementChange(const ::css::uno::Any& Accessor_, const ::css::uno::Any& Element_, const ::css::uno::Any& ReplacedElement_)
    : Accessor(Accessor_)
    , Element(Element_)
    , ReplacedElement(ReplacedElement_)
{
}


inline bool operator==(const ElementChange& the_lhs, const ElementChange& the_rhs)
{
    return the_lhs.Accessor == the_rhs.Accessor
        && the_lhs.Element == the_rhs.Element
        && the_lhs.ReplacedElement == the_rhs.ReplacedElement;
}

inline bool operator!=(const ElementChange& the_lhs, const ElementChange& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::ElementChange const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.ElementChange", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::ElementChange const *) {
    return ::cppu::UnoType< ::css::util::ElementChange >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_ELEMENTCHANGE_HPP
