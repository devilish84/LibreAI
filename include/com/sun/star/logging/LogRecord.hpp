#ifndef INCLUDED_COM_SUN_STAR_LOGGING_LOGRECORD_HPP
#define INCLUDED_COM_SUN_STAR_LOGGING_LOGRECORD_HPP

#include "sal/config.h"

#include "com/sun/star/logging/LogRecord.hdl"

#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace logging {

inline LogRecord::LogRecord()
    : LoggerName()
    , SourceClassName()
    , SourceMethodName()
    , Message()
    , LogTime()
    , SequenceNumber(0)
    , ThreadID()
    , Level(0)
{
}

inline LogRecord::LogRecord(const ::rtl::OUString& LoggerName_, const ::rtl::OUString& SourceClassName_, const ::rtl::OUString& SourceMethodName_, const ::rtl::OUString& Message_, const ::css::util::DateTime& LogTime_, const ::sal_Int64& SequenceNumber_, const ::rtl::OUString& ThreadID_, const ::sal_Int32& Level_)
    : LoggerName(LoggerName_)
    , SourceClassName(SourceClassName_)
    , SourceMethodName(SourceMethodName_)
    , Message(Message_)
    , LogTime(LogTime_)
    , SequenceNumber(SequenceNumber_)
    , ThreadID(ThreadID_)
    , Level(Level_)
{
}


inline bool operator==(const LogRecord& the_lhs, const LogRecord& the_rhs)
{
    return the_lhs.LoggerName == the_rhs.LoggerName
        && the_lhs.SourceClassName == the_rhs.SourceClassName
        && the_lhs.SourceMethodName == the_rhs.SourceMethodName
        && the_lhs.Message == the_rhs.Message
        && the_lhs.LogTime == the_rhs.LogTime
        && the_lhs.SequenceNumber == the_rhs.SequenceNumber
        && the_lhs.ThreadID == the_rhs.ThreadID
        && the_lhs.Level == the_rhs.Level;
}

inline bool operator!=(const LogRecord& the_lhs, const LogRecord& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace logging {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::logging::LogRecord const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::util::DateTime >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int64 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.logging.LogRecord", 0, 8, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::logging::LogRecord const *) {
    return ::cppu::UnoType< ::css::logging::LogRecord >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LOGGING_LOGRECORD_HPP
