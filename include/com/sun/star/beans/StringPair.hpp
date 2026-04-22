#ifndef INCLUDED_COM_SUN_STAR_BEANS_STRINGPAIR_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_STRINGPAIR_HPP

#include "sal/config.h"

#include "com/sun/star/beans/StringPair.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

inline StringPair::StringPair()
    : First()
    , Second()
{
}

inline StringPair::StringPair(const ::rtl::OUString& First_, const ::rtl::OUString& Second_)
    : First(First_)
    , Second(Second_)
{
}


inline bool operator==(const StringPair& the_lhs, const StringPair& the_rhs)
{
    return the_lhs.First == the_rhs.First
        && the_lhs.Second == the_rhs.Second;
}

inline bool operator!=(const StringPair& the_lhs, const StringPair& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::StringPair const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.beans.StringPair", 0, 2, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::StringPair const *) {
    return ::cppu::UnoType< ::css::beans::StringPair >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_STRINGPAIR_HPP
