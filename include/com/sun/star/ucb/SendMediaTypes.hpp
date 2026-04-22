#ifndef INCLUDED_COM_SUN_STAR_UCB_SENDMEDIATYPES_HPP
#define INCLUDED_COM_SUN_STAR_UCB_SENDMEDIATYPES_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/SendMediaTypes.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline SendMediaTypes::SendMediaTypes()
    : ProtocolType()
    , Value()
{
}

inline SendMediaTypes::SendMediaTypes(const ::rtl::OUString& ProtocolType_, const ::css::uno::Sequence< ::rtl::OUString >& Value_)
    : ProtocolType(ProtocolType_)
    , Value(Value_)
{
}


inline bool operator==(const SendMediaTypes& the_lhs, const SendMediaTypes& the_rhs)
{
    return the_lhs.ProtocolType == the_rhs.ProtocolType
        && the_lhs.Value == the_rhs.Value;
}

inline bool operator!=(const SendMediaTypes& the_lhs, const SendMediaTypes& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::SendMediaTypes const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.SendMediaTypes", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::SendMediaTypes const *) {
    return ::cppu::UnoType< ::css::ucb::SendMediaTypes >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_SENDMEDIATYPES_HPP
