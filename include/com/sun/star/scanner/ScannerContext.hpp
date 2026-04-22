#ifndef INCLUDED_COM_SUN_STAR_SCANNER_SCANNERCONTEXT_HPP
#define INCLUDED_COM_SUN_STAR_SCANNER_SCANNERCONTEXT_HPP

#include "sal/config.h"

#include "com/sun/star/scanner/ScannerContext.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace scanner {

inline ScannerContext::ScannerContext()
    : ScannerName()
    , InternalData(0)
{
}

inline ScannerContext::ScannerContext(const ::rtl::OUString& ScannerName_, const ::sal_Int32& InternalData_)
    : ScannerName(ScannerName_)
    , InternalData(InternalData_)
{
}


inline bool operator==(const ScannerContext& the_lhs, const ScannerContext& the_rhs)
{
    return the_lhs.ScannerName == the_rhs.ScannerName
        && the_lhs.InternalData == the_rhs.InternalData;
}

inline bool operator!=(const ScannerContext& the_lhs, const ScannerContext& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace scanner {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::scanner::ScannerContext const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.scanner.ScannerContext", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::scanner::ScannerContext const *) {
    return ::cppu::UnoType< ::css::scanner::ScannerContext >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCANNER_SCANNERCONTEXT_HPP
