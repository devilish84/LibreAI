#ifndef INCLUDED_COM_SUN_STAR_UCB_TRANSFERINFO2_HPP
#define INCLUDED_COM_SUN_STAR_UCB_TRANSFERINFO2_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/TransferInfo2.hdl"

#include "com/sun/star/ucb/TransferInfo.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline TransferInfo2::TransferInfo2()
    : ::css::ucb::TransferInfo()
    , MimeType()
{
}

inline TransferInfo2::TransferInfo2(const ::sal_Bool& MoveData_, const ::rtl::OUString& SourceURL_, const ::rtl::OUString& NewTitle_, const ::sal_Int32& NameClash_, const ::rtl::OUString& MimeType_)
    : ::css::ucb::TransferInfo(MoveData_, SourceURL_, NewTitle_, NameClash_)
    , MimeType(MimeType_)
{
}


inline bool operator==(const TransferInfo2& the_lhs, const TransferInfo2& the_rhs)
{
    return operator==( static_cast< ::css::ucb::TransferInfo>(the_lhs), static_cast< ::css::ucb::TransferInfo>(the_rhs) )

        && the_lhs.MimeType == the_rhs.MimeType;
}

inline bool operator!=(const TransferInfo2& the_lhs, const TransferInfo2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::TransferInfo2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.TransferInfo2", ::cppu::UnoType< ::css::ucb::TransferInfo >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::TransferInfo2 const *) {
    return ::cppu::UnoType< ::css::ucb::TransferInfo2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_TRANSFERINFO2_HPP
