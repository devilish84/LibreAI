#ifndef INCLUDED_COM_SUN_STAR_FRAME_DISPATCHSTATEMENT_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_DISPATCHSTATEMENT_HPP

#include "sal/config.h"

#include "com/sun/star/frame/DispatchStatement.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline DispatchStatement::DispatchStatement()
    : aCommand()
    , aTarget()
    , aArgs()
    , nFlags(0)
    , bIsComment(false)
{
}

inline DispatchStatement::DispatchStatement(const ::rtl::OUString& aCommand_, const ::rtl::OUString& aTarget_, const ::css::uno::Sequence< ::css::beans::PropertyValue >& aArgs_, const ::sal_Int32& nFlags_, const ::sal_Bool& bIsComment_)
    : aCommand(aCommand_)
    , aTarget(aTarget_)
    , aArgs(aArgs_)
    , nFlags(nFlags_)
    , bIsComment(bIsComment_)
{
}


inline bool operator==(const DispatchStatement& the_lhs, const DispatchStatement& the_rhs)
{
    return the_lhs.aCommand == the_rhs.aCommand
        && the_lhs.aTarget == the_rhs.aTarget
        && the_lhs.aArgs == the_rhs.aArgs
        && the_lhs.nFlags == the_rhs.nFlags
        && the_lhs.bIsComment == the_rhs.bIsComment;
}

inline bool operator!=(const DispatchStatement& the_lhs, const DispatchStatement& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::DispatchStatement const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::PropertyValue > >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.DispatchStatement", 0, 5, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::DispatchStatement const *) {
    return ::cppu::UnoType< ::css::frame::DispatchStatement >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_DISPATCHSTATEMENT_HPP
