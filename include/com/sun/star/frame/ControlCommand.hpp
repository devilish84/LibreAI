#ifndef INCLUDED_COM_SUN_STAR_FRAME_CONTROLCOMMAND_HPP
#define INCLUDED_COM_SUN_STAR_FRAME_CONTROLCOMMAND_HPP

#include "sal/config.h"

#include "com/sun/star/frame/ControlCommand.hdl"

#include "com/sun/star/beans/NamedValue.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace frame {

inline ControlCommand::ControlCommand()
    : Command()
    , Arguments()
{
}

inline ControlCommand::ControlCommand(const ::rtl::OUString& Command_, const ::css::uno::Sequence< ::css::beans::NamedValue >& Arguments_)
    : Command(Command_)
    , Arguments(Arguments_)
{
}


inline bool operator==(const ControlCommand& the_lhs, const ControlCommand& the_rhs)
{
    return the_lhs.Command == the_rhs.Command
        && the_lhs.Arguments == the_rhs.Arguments;
}

inline bool operator!=(const ControlCommand& the_lhs, const ControlCommand& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace frame {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::frame::ControlCommand const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::NamedValue > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.frame.ControlCommand", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::frame::ControlCommand const *) {
    return ::cppu::UnoType< ::css::frame::ControlCommand >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FRAME_CONTROLCOMMAND_HPP
