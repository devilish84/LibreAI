#ifndef INCLUDED_COM_SUN_STAR_SDBC_DATATRUNCATION_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_DATATRUNCATION_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/DataTruncation.hdl"

#include "com/sun/star/sdbc/SQLWarning.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline DataTruncation::DataTruncation(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::sdbc::SQLWarning(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Index(0)
    , IsParameter(false)
    , DuringRead(false)
    , DataSize(0)
    , TransferSize(0)
{ }

inline DataTruncation::DataTruncation(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& SQLState_, const ::sal_Int32& ErrorCode_, const ::css::uno::Any& NextException_, const ::sal_Int32& Index_, const ::sal_Bool& IsParameter_, const ::sal_Bool& DuringRead_, const ::sal_Int32& DataSize_, const ::sal_Int32& TransferSize_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::sdbc::SQLWarning(Message_, Context_, SQLState_, ErrorCode_, NextException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Index(Index_)
    , IsParameter(IsParameter_)
    , DuringRead(DuringRead_)
    , DataSize(DataSize_)
    , TransferSize(TransferSize_)
{ }

#if !defined LIBO_INTERNAL_ONLY
DataTruncation::DataTruncation(DataTruncation const & the_other): ::css::sdbc::SQLWarning(the_other), Index(the_other.Index), IsParameter(the_other.IsParameter), DuringRead(the_other.DuringRead), DataSize(the_other.DataSize), TransferSize(the_other.TransferSize) {}

DataTruncation::~DataTruncation() {}

DataTruncation & DataTruncation::operator =(DataTruncation const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::sdbc::SQLWarning::operator =(the_other);
    Index = the_other.Index;
    IsParameter = the_other.IsParameter;
    DuringRead = the_other.DuringRead;
    DataSize = the_other.DataSize;
    TransferSize = the_other.TransferSize;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::DataTruncation const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::sdbc::SQLWarning >::get();

        typelib_TypeDescriptionReference * aMemberRefs[5];
        const ::css::uno::Type& rMemberType_long = ::cppu::UnoType< ::sal_Int32 >::get();
        aMemberRefs[0] = rMemberType_long.getTypeLibType();
        const ::css::uno::Type& rMemberType_boolean = ::cppu::UnoType< ::sal_Bool >::get();
        aMemberRefs[1] = rMemberType_boolean.getTypeLibType();
        aMemberRefs[2] = rMemberType_boolean.getTypeLibType();
        aMemberRefs[3] = rMemberType_long.getTypeLibType();
        aMemberRefs[4] = rMemberType_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.sdbc.DataTruncation", rBaseType.getTypeLibType(), 5,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdbc::DataTruncation const *) {
    return ::cppu::UnoType< ::css::sdbc::DataTruncation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_DATATRUNCATION_HPP
