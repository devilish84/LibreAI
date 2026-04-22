#ifndef INCLUDED_COM_SUN_STAR_SCRIPT_ARRAYWRAPPER_HPP
#define INCLUDED_COM_SUN_STAR_SCRIPT_ARRAYWRAPPER_HPP

#include "sal/config.h"

#include "com/sun/star/script/ArrayWrapper.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace script {

inline ArrayWrapper::ArrayWrapper()
    : IsZeroIndex(false)
    , Array()
{
}

inline ArrayWrapper::ArrayWrapper(const ::sal_Bool& IsZeroIndex_, const ::css::uno::Any& Array_)
    : IsZeroIndex(IsZeroIndex_)
    , Array(Array_)
{
}


inline bool operator==(const ArrayWrapper& the_lhs, const ArrayWrapper& the_rhs)
{
    return the_lhs.IsZeroIndex == the_rhs.IsZeroIndex
        && the_lhs.Array == the_rhs.Array;
}

inline bool operator!=(const ArrayWrapper& the_lhs, const ArrayWrapper& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace script {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::script::ArrayWrapper const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.script.ArrayWrapper", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::script::ArrayWrapper const *) {
    return ::cppu::UnoType< ::css::script::ArrayWrapper >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SCRIPT_ARRAYWRAPPER_HPP
