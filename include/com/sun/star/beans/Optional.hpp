#ifndef INCLUDED_COM_SUN_STAR_BEANS_OPTIONAL_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_OPTIONAL_HPP

#include "sal/config.h"

#include "com/sun/star/beans/Optional.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/strbuf.hxx"
#include "rtl/textenc.h"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

template< typename typeparam_T > inline Optional< typeparam_T >::Optional()
    : IsPresent(false)
    , Value()
{
}

template< typename typeparam_T > inline Optional< typeparam_T >::Optional(const ::sal_Bool& IsPresent_, typeparam_T const & Value_)
    : IsPresent(IsPresent_)
    , Value(Value_)
{
}

template< typename typeparam_T > 
inline Optional< typeparam_T >
make_Optional(const ::sal_Bool& IsPresent_, typeparam_T const & Value_)
{
    return Optional< typeparam_T >(IsPresent_, Value_);
}

template< typename typeparam_T >  inline bool operator==(const Optional< typeparam_T >& the_lhs, const Optional< typeparam_T >& the_rhs)
{
    return the_lhs.IsPresent == the_rhs.IsPresent
        && the_lhs.Value == the_rhs.Value;
}
template< typename typeparam_T >  inline bool operator!=(const Optional< typeparam_T >& the_lhs, const Optional< typeparam_T >& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace cppu {

template< typename typeparam_T > class UnoType< ::css::beans::Optional< typeparam_T > > {
public:
    static inline ::css::uno::Type const & get() {
        //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
        static ::typelib_TypeDescriptionReference * the_type = 0;
        if (the_type == 0) {
            ::rtl::OStringBuffer the_buffer("com.sun.star.beans.Optional<");
            the_buffer.append(::rtl::OUStringToOString(::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName(), RTL_TEXTENCODING_UTF8));
            the_buffer.append('>');
            ::typelib_TypeDescriptionReference * the_members[] = {
                ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
                ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeLibType() };
            static ::sal_Bool const the_parameterizedTypes[] = { false, true };
            ::typelib_static_struct_type_init(&the_type, the_buffer.getStr(), 0, 2, the_members, the_parameterizedTypes);
        }
        return *reinterpret_cast< ::css::uno::Type * >(&the_type);
    }

private:
    UnoType(UnoType &); // not defined
    ~UnoType(); // not defined
    void operator =(UnoType); // not defined
};

}

template< typename typeparam_T > SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::Optional< typeparam_T > const *) {
        return ::cppu::UnoType< ::css::beans::Optional< typeparam_T > >::get();
    }

#endif // INCLUDED_COM_SUN_STAR_BEANS_OPTIONAL_HPP
