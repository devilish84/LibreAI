#ifndef INCLUDED_COM_SUN_STAR_UCB_INSERTCOMMANDARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INSERTCOMMANDARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InsertCommandArgument.hdl"

#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline InsertCommandArgument::InsertCommandArgument()
    : Data()
    , ReplaceExisting(false)
{
}

inline InsertCommandArgument::InsertCommandArgument(const ::css::uno::Reference< ::css::io::XInputStream >& Data_, const ::sal_Bool& ReplaceExisting_)
    : Data(Data_)
    , ReplaceExisting(ReplaceExisting_)
{
}


inline bool operator==(const InsertCommandArgument& the_lhs, const InsertCommandArgument& the_rhs)
{
    return the_lhs.Data == the_rhs.Data
        && the_lhs.ReplaceExisting == the_rhs.ReplaceExisting;
}

inline bool operator!=(const InsertCommandArgument& the_lhs, const InsertCommandArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InsertCommandArgument const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::io::XInputStream > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.InsertCommandArgument", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InsertCommandArgument const *) {
    return ::cppu::UnoType< ::css::ucb::InsertCommandArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INSERTCOMMANDARGUMENT_HPP
