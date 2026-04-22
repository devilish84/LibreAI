#ifndef INCLUDED_COM_SUN_STAR_UCB_EXPORTSTREAMINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_EXPORTSTREAMINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ExportStreamInfo.hdl"

#include "com/sun/star/io/XOutputStream.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ExportStreamInfo::ExportStreamInfo()
    : Target()
    , ForceBodies(false)
{
}

inline ExportStreamInfo::ExportStreamInfo(const ::css::uno::Reference< ::css::io::XOutputStream >& Target_, const ::sal_Bool& ForceBodies_)
    : Target(Target_)
    , ForceBodies(ForceBodies_)
{
}


inline bool operator==(const ExportStreamInfo& the_lhs, const ExportStreamInfo& the_rhs)
{
    return the_lhs.Target == the_rhs.Target
        && the_lhs.ForceBodies == the_rhs.ForceBodies;
}

inline bool operator!=(const ExportStreamInfo& the_lhs, const ExportStreamInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ExportStreamInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::io::XOutputStream > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.ExportStreamInfo", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ExportStreamInfo const *) {
    return ::cppu::UnoType< ::css::ucb::ExportStreamInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_EXPORTSTREAMINFO_HPP
