#ifndef INCLUDED_COM_SUN_STAR_PACKAGES_ZIP_ZIPENTRY_HPP
#define INCLUDED_COM_SUN_STAR_PACKAGES_ZIP_ZIPENTRY_HPP

#include "sal/config.h"

#include "com/sun/star/packages/zip/ZipEntry.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace packages { namespace zip {

inline ZipEntry::ZipEntry()
    : nVersion(0)
    , nFlag(0)
    , nMethod(0)
    , nTime(0)
    , nCrc(0)
    , nCompressedSize(0)
    , nSize(0)
    , nOffset(0)
    , nDiskNumber(0)
    , sName()
    , extra()
    , sComment()
{
}

inline ZipEntry::ZipEntry(const ::sal_Int16& nVersion_, const ::sal_Int16& nFlag_, const ::sal_Int16& nMethod_, const ::sal_Int32& nTime_, const ::sal_Int32& nCrc_, const ::sal_Int32& nCompressedSize_, const ::sal_Int32& nSize_, const ::sal_Int32& nOffset_, const ::sal_Int16& nDiskNumber_, const ::rtl::OUString& sName_, const ::css::uno::Sequence< ::sal_Int8 >& extra_, const ::rtl::OUString& sComment_)
    : nVersion(nVersion_)
    , nFlag(nFlag_)
    , nMethod(nMethod_)
    , nTime(nTime_)
    , nCrc(nCrc_)
    , nCompressedSize(nCompressedSize_)
    , nSize(nSize_)
    , nOffset(nOffset_)
    , nDiskNumber(nDiskNumber_)
    , sName(sName_)
    , extra(extra_)
    , sComment(sComment_)
{
}


inline bool operator==(const ZipEntry& the_lhs, const ZipEntry& the_rhs)
{
    return the_lhs.nVersion == the_rhs.nVersion
        && the_lhs.nFlag == the_rhs.nFlag
        && the_lhs.nMethod == the_rhs.nMethod
        && the_lhs.nTime == the_rhs.nTime
        && the_lhs.nCrc == the_rhs.nCrc
        && the_lhs.nCompressedSize == the_rhs.nCompressedSize
        && the_lhs.nSize == the_rhs.nSize
        && the_lhs.nOffset == the_rhs.nOffset
        && the_lhs.nDiskNumber == the_rhs.nDiskNumber
        && the_lhs.sName == the_rhs.sName
        && the_lhs.extra == the_rhs.extra
        && the_lhs.sComment == the_rhs.sComment;
}

inline bool operator!=(const ZipEntry& the_lhs, const ZipEntry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace packages { namespace zip {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::packages::zip::ZipEntry const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int16 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int8 > >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.packages.zip.ZipEntry", 0, 12, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::packages::zip::ZipEntry const *) {
    return ::cppu::UnoType< ::css::packages::zip::ZipEntry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_PACKAGES_ZIP_ZIPENTRY_HPP
