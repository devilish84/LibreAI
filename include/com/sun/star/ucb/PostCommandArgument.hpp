#ifndef INCLUDED_COM_SUN_STAR_UCB_POSTCOMMANDARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_POSTCOMMANDARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/PostCommandArgument.hdl"

#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline PostCommandArgument::PostCommandArgument()
    : Source()
    , Sink()
{
}

inline PostCommandArgument::PostCommandArgument(const ::css::uno::Reference< ::css::io::XInputStream >& Source_, const ::css::uno::Reference< ::css::uno::XInterface >& Sink_)
    : Source(Source_)
    , Sink(Sink_)
{
}


inline bool operator==(const PostCommandArgument& the_lhs, const PostCommandArgument& the_rhs)
{
    return the_lhs.Source == the_rhs.Source
        && the_lhs.Sink == the_rhs.Sink;
}

inline bool operator!=(const PostCommandArgument& the_lhs, const PostCommandArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::PostCommandArgument const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::io::XInputStream > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.PostCommandArgument", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::PostCommandArgument const *) {
    return ::cppu::UnoType< ::css::ucb::PostCommandArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_POSTCOMMANDARGUMENT_HPP
