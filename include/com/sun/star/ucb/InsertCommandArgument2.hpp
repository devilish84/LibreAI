#ifndef INCLUDED_COM_SUN_STAR_UCB_INSERTCOMMANDARGUMENT2_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INSERTCOMMANDARGUMENT2_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InsertCommandArgument2.hdl"

#include "com/sun/star/ucb/InsertCommandArgument.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline InsertCommandArgument2::InsertCommandArgument2()
    : ::css::ucb::InsertCommandArgument()
    , MimeType()
    , DocumentId()
{
}

inline InsertCommandArgument2::InsertCommandArgument2(const ::css::uno::Reference< ::css::io::XInputStream >& Data_, const ::sal_Bool& ReplaceExisting_, const ::rtl::OUString& MimeType_, const ::rtl::OUString& DocumentId_)
    : ::css::ucb::InsertCommandArgument(Data_, ReplaceExisting_)
    , MimeType(MimeType_)
    , DocumentId(DocumentId_)
{
}


inline bool operator==(const InsertCommandArgument2& the_lhs, const InsertCommandArgument2& the_rhs)
{
    return operator==( static_cast< ::css::ucb::InsertCommandArgument>(the_lhs), static_cast< ::css::ucb::InsertCommandArgument>(the_rhs) )

        && the_lhs.MimeType == the_rhs.MimeType
        && the_lhs.DocumentId == the_rhs.DocumentId;
}

inline bool operator!=(const InsertCommandArgument2& the_lhs, const InsertCommandArgument2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InsertCommandArgument2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.InsertCommandArgument2", ::cppu::UnoType< ::css::ucb::InsertCommandArgument >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InsertCommandArgument2 const *) {
    return ::cppu::UnoType< ::css::ucb::InsertCommandArgument2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INSERTCOMMANDARGUMENT2_HPP
