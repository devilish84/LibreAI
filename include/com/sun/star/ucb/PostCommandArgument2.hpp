#ifndef INCLUDED_COM_SUN_STAR_UCB_POSTCOMMANDARGUMENT2_HPP
#define INCLUDED_COM_SUN_STAR_UCB_POSTCOMMANDARGUMENT2_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/PostCommandArgument2.hdl"

#include "com/sun/star/ucb/PostCommandArgument.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline PostCommandArgument2::PostCommandArgument2()
    : ::css::ucb::PostCommandArgument()
    , MediaType()
    , Referer()
{
}

inline PostCommandArgument2::PostCommandArgument2(const ::css::uno::Reference< ::css::io::XInputStream >& Source_, const ::css::uno::Reference< ::css::uno::XInterface >& Sink_, const ::rtl::OUString& MediaType_, const ::rtl::OUString& Referer_)
    : ::css::ucb::PostCommandArgument(Source_, Sink_)
    , MediaType(MediaType_)
    , Referer(Referer_)
{
}


inline bool operator==(const PostCommandArgument2& the_lhs, const PostCommandArgument2& the_rhs)
{
    return operator==( static_cast< ::css::ucb::PostCommandArgument>(the_lhs), static_cast< ::css::ucb::PostCommandArgument>(the_rhs) )

        && the_lhs.MediaType == the_rhs.MediaType
        && the_lhs.Referer == the_rhs.Referer;
}

inline bool operator!=(const PostCommandArgument2& the_lhs, const PostCommandArgument2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::PostCommandArgument2 const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.PostCommandArgument2", ::cppu::UnoType< ::css::ucb::PostCommandArgument >::get().getTypeLibType(), 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::PostCommandArgument2 const *) {
    return ::cppu::UnoType< ::css::ucb::PostCommandArgument2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_POSTCOMMANDARGUMENT2_HPP
