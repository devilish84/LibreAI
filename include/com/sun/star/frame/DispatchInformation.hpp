#ifndef INCLUDED_COM_SUN_STAR_FRAME_DISPATCHINFORMATION_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_DISPATCHINFORMATION_HPP

#include "sal/config.h"

#include "com/sun/star/frame/DispatchInformation.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline DispatchInformation::DispatchInformation()
    : Command()
    , GroupId(0)
{
}

inline DispatchInformation::DispatchInformation(const ::rtl::OUString& Command_, const ::sal_Int16& GroupId_)
    : Command(Command_)
    , GroupId(GroupId_)
{
}


inline bool operator==(const DispatchInformation& the_lhs, const DispatchInformation& the_rhs)
{
    return the_lhs.Command == the_rhs.Command
        && the_lhs.GroupId == the_rhs.GroupId;
}

inline bool operator!=(const DispatchInformation& the_lhs, const DispatchInformation& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::DispatchInformation const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.DispatchInformation", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::DispatchInformation const *) {
    return ::cppu::UnoType< ::css::frame::DispatchInformation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_DISPATCHINFORMATION_HPP
