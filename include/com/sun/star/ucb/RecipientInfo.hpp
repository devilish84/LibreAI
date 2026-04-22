#ifndef INCLUDED_COM_SUN_STAR_UCB_RECIPIENTINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_RECIPIENTINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/RecipientInfo.hdl"

#include "com/sun/star/ucb/OutgoingMessageState.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline RecipientInfo::RecipientInfo()
    : ProtocolType()
    , State(::css::ucb::OutgoingMessageState_WRITTEN)
    , To()
    , CC()
    , BCC()
    , Newsgroups()
    , Server()
    , Username()
    , Password()
    , VIMPostOfficePath()
    , ProtocolErrorString()
    , ProtocolErrorNumber(0)
    , SendTries(0)
{
}

inline RecipientInfo::RecipientInfo(const ::rtl::OUString& ProtocolType_, const ::css::ucb::OutgoingMessageState& State_, const ::rtl::OUString& To_, const ::rtl::OUString& CC_, const ::rtl::OUString& BCC_, const ::rtl::OUString& Newsgroups_, const ::rtl::OUString& Server_, const ::rtl::OUString& Username_, const ::rtl::OUString& Password_, const ::rtl::OUString& VIMPostOfficePath_, const ::rtl::OUString& ProtocolErrorString_, const ::sal_Int32& ProtocolErrorNumber_, const ::sal_Int32& SendTries_)
    : ProtocolType(ProtocolType_)
    , State(State_)
    , To(To_)
    , CC(CC_)
    , BCC(BCC_)
    , Newsgroups(Newsgroups_)
    , Server(Server_)
    , Username(Username_)
    , Password(Password_)
    , VIMPostOfficePath(VIMPostOfficePath_)
    , ProtocolErrorString(ProtocolErrorString_)
    , ProtocolErrorNumber(ProtocolErrorNumber_)
    , SendTries(SendTries_)
{
}


inline bool operator==(const RecipientInfo& the_lhs, const RecipientInfo& the_rhs)
{
    return the_lhs.ProtocolType == the_rhs.ProtocolType
        && the_lhs.State == the_rhs.State
        && the_lhs.To == the_rhs.To
        && the_lhs.CC == the_rhs.CC
        && the_lhs.BCC == the_rhs.BCC
        && the_lhs.Newsgroups == the_rhs.Newsgroups
        && the_lhs.Server == the_rhs.Server
        && the_lhs.Username == the_rhs.Username
        && the_lhs.Password == the_rhs.Password
        && the_lhs.VIMPostOfficePath == the_rhs.VIMPostOfficePath
        && the_lhs.ProtocolErrorString == the_rhs.ProtocolErrorString
        && the_lhs.ProtocolErrorNumber == the_rhs.ProtocolErrorNumber
        && the_lhs.SendTries == the_rhs.SendTries;
}

inline bool operator!=(const RecipientInfo& the_lhs, const RecipientInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::RecipientInfo const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::ucb::OutgoingMessageState >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.ucb.RecipientInfo", 0, 13, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::RecipientInfo const *) {
    return ::cppu::UnoType< ::css::ucb::RecipientInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_RECIPIENTINFO_HPP
