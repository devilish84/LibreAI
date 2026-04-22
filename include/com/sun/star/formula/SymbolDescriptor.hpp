#ifndef INCLUDED_COM_SUN_STAR_FORMULA_SYMBOLDESCRIPTOR_HPP
#define INCLUDED_COM_SUN_STAR_FORMULA_SYMBOLDESCRIPTOR_HPP

#include "sal/config.h"

#include "com/sun/star/formula/SymbolDescriptor.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace formula {

inline SymbolDescriptor::SymbolDescriptor()
    : sName()
    , sExportName()
    , sSymbolSet()
    , nCharacter(0)
    , sFontName()
    , nCharSet(0)
    , nFamily(0)
    , nPitch(0)
    , nWeight(0)
    , nItalic(0)
{
}

inline SymbolDescriptor::SymbolDescriptor(const ::rtl::OUString& sName_, const ::rtl::OUString& sExportName_, const ::rtl::OUString& sSymbolSet_, const ::sal_Int32& nCharacter_, const ::rtl::OUString& sFontName_, const ::sal_Int16& nCharSet_, const ::sal_Int16& nFamily_, const ::sal_Int16& nPitch_, const ::sal_Int16& nWeight_, const ::sal_Int16& nItalic_)
    : sName(sName_)
    , sExportName(sExportName_)
    , sSymbolSet(sSymbolSet_)
    , nCharacter(nCharacter_)
    , sFontName(sFontName_)
    , nCharSet(nCharSet_)
    , nFamily(nFamily_)
    , nPitch(nPitch_)
    , nWeight(nWeight_)
    , nItalic(nItalic_)
{
}


inline bool operator==(const SymbolDescriptor& the_lhs, const SymbolDescriptor& the_rhs)
{
    return the_lhs.sName == the_rhs.sName
        && the_lhs.sExportName == the_rhs.sExportName
        && the_lhs.sSymbolSet == the_rhs.sSymbolSet
        && the_lhs.nCharacter == the_rhs.nCharacter
        && the_lhs.sFontName == the_rhs.sFontName
        && the_lhs.nCharSet == the_rhs.nCharSet
        && the_lhs.nFamily == the_rhs.nFamily
        && the_lhs.nPitch == the_rhs.nPitch
        && the_lhs.nWeight == the_rhs.nWeight
        && the_lhs.nItalic == the_rhs.nItalic;
}

inline bool operator!=(const SymbolDescriptor& the_lhs, const SymbolDescriptor& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace formula {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::formula::SymbolDescriptor const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.formula.SymbolDescriptor", 0, 10, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::formula::SymbolDescriptor const *) {
    return ::cppu::UnoType< ::css::formula::SymbolDescriptor >::get();
}

#endif // INCLUDED_COM_SUN_STAR_FORMULA_SYMBOLDESCRIPTOR_HPP
