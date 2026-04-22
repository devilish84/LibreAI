#ifndef INCLUDED_COM_SUN_STAR_UTIL_ATOMCLASSREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_ATOMCLASSREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/util/AtomClassRequest.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline AtomClassRequest::AtomClassRequest()
    : atomClass(0)
    , atoms()
{
}

inline AtomClassRequest::AtomClassRequest(const ::sal_Int32& atomClass_, const ::css::uno::Sequence< ::sal_Int32 >& atoms_)
    : atomClass(atomClass_)
    , atoms(atoms_)
{
}


inline bool operator==(const AtomClassRequest& the_lhs, const AtomClassRequest& the_rhs)
{
    return the_lhs.atomClass == the_rhs.atomClass
        && the_lhs.atoms == the_rhs.atoms;
}

inline bool operator!=(const AtomClassRequest& the_lhs, const AtomClassRequest& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::AtomClassRequest const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Int32 >::get().getTypeLibType(),
            ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int32 > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.util.AtomClassRequest", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::AtomClassRequest const *) {
    return ::cppu::UnoType< ::css::util::AtomClassRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_ATOMCLASSREQUEST_HPP
