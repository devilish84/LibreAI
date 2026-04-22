#ifndef INCLUDED_COM_SUN_STAR_LINGUISTIC2_SINGLEPROOFREADINGERROR_HPP
#define INCLUDED_COM_SUN_STAR_LINGUISTIC2_SINGLEPROOFREADINGERROR_HPP

#include "sal/config.h"

#include "com/sun/star/linguistic2/SingleProofreadingError.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace linguistic2 {

inline SingleProofreadingError::SingleProofreadingError()
    : nErrorStart(0)
    , nErrorLength(0)
    , nErrorType(0)
    , aRuleIdentifier()
    , aShortComment()
    , aFullComment()
    , aSuggestions()
    , aProperties()
{
}

inline SingleProofreadingError::SingleProofreadingError(const ::sal_Int32& nErrorStart_, const ::sal_Int32& nErrorLength_, const ::sal_Int32& nErrorType_, const ::rtl::OUString& aRuleIdentifier_, const ::rtl::OUString& aShortComment_, const ::rtl::OUString& aFullComment_, const ::css::uno::Sequence< ::rtl::OUString >& aSuggestions_, const ::css::uno::Sequence< ::css::beans::PropertyValue >& aProperties_)
    : nErrorStart(nErrorStart_)
    , nErrorLength(nErrorLength_)
    , nErrorType(nErrorType_)
    , aRuleIdentifier(aRuleIdentifier_)
    , aShortComment(aShortComment_)
    , aFullComment(aFullComment_)
    , aSuggestions(aSuggestions_)
    , aProperties(aProperties_)
{
}


inline bool operator==(const SingleProofreadingError& the_lhs, const SingleProofreadingError& the_rhs)
{
    return the_lhs.nErrorStart == the_rhs.nErrorStart
        && the_lhs.nErrorLength == the_rhs.nErrorLength
        && the_lhs.nErrorType == the_rhs.nErrorType
        && the_lhs.aRuleIdentifier == the_rhs.aRuleIdentifier
        && the_lhs.aShortComment == the_rhs.aShortComment
        && the_lhs.aFullComment == the_rhs.aFullComment
        && the_lhs.aSuggestions == the_rhs.aSuggestions
        && the_lhs.aProperties == the_rhs.aProperties;
}

inline bool operator!=(const SingleProofreadingError& the_lhs, const SingleProofreadingError& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace linguistic2 {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::linguistic2::SingleProofreadingError const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::PropertyValue > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.linguistic2.SingleProofreadingError", 0, 8, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::linguistic2::SingleProofreadingError const *) {
    return ::cppu::UnoType< ::css::linguistic2::SingleProofreadingError >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LINGUISTIC2_SINGLEPROOFREADINGERROR_HPP
