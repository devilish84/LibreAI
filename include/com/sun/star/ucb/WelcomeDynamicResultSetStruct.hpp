#ifndef INCLUDED_COM_SUN_STAR_UCB_WELCOMEDYNAMICRESULTSETSTRUCT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_WELCOMEDYNAMICRESULTSETSTRUCT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/WelcomeDynamicResultSetStruct.hdl"

#include "com/sun/star/sdbc/XResultSet.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline WelcomeDynamicResultSetStruct::WelcomeDynamicResultSetStruct()
    : Old()
    , New()
{
}

inline WelcomeDynamicResultSetStruct::WelcomeDynamicResultSetStruct(const ::css::uno::Reference< ::css::sdbc::XResultSet >& Old_, const ::css::uno::Reference< ::css::sdbc::XResultSet >& New_)
    : Old(Old_)
    , New(New_)
{
}


inline bool operator==(const WelcomeDynamicResultSetStruct& the_lhs, const WelcomeDynamicResultSetStruct& the_rhs)
{
    return the_lhs.Old == the_rhs.Old
        && the_lhs.New == the_rhs.New;
}

inline bool operator!=(const WelcomeDynamicResultSetStruct& the_lhs, const WelcomeDynamicResultSetStruct& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::WelcomeDynamicResultSetStruct const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XResultSet > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XResultSet > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.WelcomeDynamicResultSetStruct", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::WelcomeDynamicResultSetStruct const *) {
    return ::cppu::UnoType< ::css::ucb::WelcomeDynamicResultSetStruct >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_WELCOMEDYNAMICRESULTSETSTRUCT_HPP
