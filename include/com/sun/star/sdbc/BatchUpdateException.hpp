#ifndef INCLUDED_COM_SUN_STAR_SDBC_BATCHUPDATEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_BATCHUPDATEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/BatchUpdateException.hdl"

#include "com/sun/star/sdbc/SQLException.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline BatchUpdateException::BatchUpdateException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::sdbc::SQLException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , UpdateCounts()
{ }

inline BatchUpdateException::BatchUpdateException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& SQLState_, const ::sal_Int32& ErrorCode_, const ::css::uno::Any& NextException_, const ::css::uno::Sequence< ::sal_Int32 >& UpdateCounts_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::sdbc::SQLException(Message_, Context_, SQLState_, ErrorCode_, NextException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , UpdateCounts(UpdateCounts_)
{ }

#if !defined LIBO_INTERNAL_ONLY
BatchUpdateException::BatchUpdateException(BatchUpdateException const & the_other): ::css::sdbc::SQLException(the_other), UpdateCounts(the_other.UpdateCounts) {}

BatchUpdateException::~BatchUpdateException() {}

BatchUpdateException & BatchUpdateException::operator =(BatchUpdateException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::sdbc::SQLException::operator =(the_other);
    UpdateCounts = the_other.UpdateCounts;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::BatchUpdateException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::sdbc::SQLException >::get();

        typelib_TypeDescriptionReference * aMemberRefs[1];
        const ::css::uno::Type& rMemberType_seq_long = ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int32 > >::get();
        aMemberRefs[0] = rMemberType_seq_long.getTypeLibType();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.sdbc.BatchUpdateException", rBaseType.getTypeLibType(), 1,  aMemberRefs );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdbc::BatchUpdateException const *) {
    return ::cppu::UnoType< ::css::sdbc::BatchUpdateException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_BATCHUPDATEEXCEPTION_HPP
