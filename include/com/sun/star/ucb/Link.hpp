#ifndef INCLUDED_COM_SUN_STAR_UCB_LINK_HPP
#define INCLUDED_COM_SUN_STAR_UCB_LINK_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/Link.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline Link::Link()
    : Source()
    , Destination()
{
}

inline Link::Link(const ::rtl::OUString& Source_, const ::rtl::OUString& Destination_)
    : Source(Source_)
    , Destination(Destination_)
{
}


inline bool operator==(const Link& the_lhs, const Link& the_rhs)
{
    return the_lhs.Source == the_rhs.Source
        && the_lhs.Destination == the_rhs.Destination;
}

inline bool operator!=(const Link& the_lhs, const Link& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::Link const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.Link", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::Link const *) {
    return ::cppu::UnoType< ::css::ucb::Link >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_LINK_HPP
