#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_CONTEXTINFORMATION_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_CONTEXTINFORMATION_HPP

#include "sal/config.h"

#include "com/sun/star/script/ContextInformation.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace script {

inline ContextInformation::ContextInformation()
    : Name()
    , SourceCode()
    , StartLine(0)
    , StartColumn(0)
    , EndLine(0)
    , EndColumn(0)
    , LocalVariableNames()
{
}

inline ContextInformation::ContextInformation(const ::rtl::OUString& Name_, const ::rtl::OUString& SourceCode_, const ::sal_Int32& StartLine_, const ::sal_Int32& StartColumn_, const ::sal_Int32& EndLine_, const ::sal_Int32& EndColumn_, const ::css::uno::Sequence< ::rtl::OUString >& LocalVariableNames_)
    : Name(Name_)
    , SourceCode(SourceCode_)
    , StartLine(StartLine_)
    , StartColumn(StartColumn_)
    , EndLine(EndLine_)
    , EndColumn(EndColumn_)
    , LocalVariableNames(LocalVariableNames_)
{
}


inline bool operator==(const ContextInformation& the_lhs, const ContextInformation& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.SourceCode == the_rhs.SourceCode
        && the_lhs.StartLine == the_rhs.StartLine
        && the_lhs.StartColumn == the_rhs.StartColumn
        && the_lhs.EndLine == the_rhs.EndLine
        && the_lhs.EndColumn == the_rhs.EndColumn
        && the_lhs.LocalVariableNames == the_rhs.LocalVariableNames;
}

inline bool operator!=(const ContextInformation& the_lhs, const ContextInformation& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::ContextInformation const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.script.ContextInformation", 0, 7, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::ContextInformation const *) {
    return ::cppu::UnoType< ::css::script::ContextInformation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_CONTEXTINFORMATION_HPP
