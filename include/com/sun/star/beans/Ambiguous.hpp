#ifndef INCLUDED_COM_SUN_STAR_BEANS_AMBIGUOUS_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_AMBIGUOUS_HPP

#include "sal/config.h"

#include "com/sun/star/beans/Ambiguous.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/strbuf.hxx"
#include "rtl/textenc.h"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

template< typename typeparam_T > inline Ambiguous< typeparam_T >::Ambiguous()
    : Value()
    , IsAmbiguous(false)
{
}

template< typename typeparam_T > inline Ambiguous< typeparam_T >::Ambiguous(typeparam_T const & Value_, const ::sal_Bool& IsAmbiguous_)
    : Value(Value_)
    , IsAmbiguous(IsAmbiguous_)
{
}

template< typename typeparam_T > 
inline Ambiguous< typeparam_T >
make_Ambiguous(typeparam_T const & Value_, const ::sal_Bool& IsAmbiguous_)
{
    return Ambiguous< typeparam_T >(Value_, IsAmbiguous_);
}

template< typename typeparam_T >  inline bool operator==(const Ambiguous< typeparam_T >& the_lhs, const Ambiguous< typeparam_T >& the_rhs)
{
    return the_lhs.Value == the_rhs.Value
        && the_lhs.IsAmbiguous == the_rhs.IsAmbiguous;
}
template< typename typeparam_T >  inline bool operator!=(const Ambiguous< typeparam_T >& the_lhs, const Ambiguous< typeparam_T >& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace cppu {

template< typename typeparam_T > class UnoType< ::css::beans::Ambiguous< typeparam_T > > {
public:
    static inline ::css::uno::Type const & get() {
        //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
        static ::typelib_TypeDescriptionReference * the_type = 0;
        if (the_type == 0) {
            ::rtl::OStringBuffer the_buffer("com.sun.star.beans.Ambiguous<");
            the_buffer.append(::rtl::OUStringToOString(::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName(), RTL_TEXTENCODING_UTF8));
            the_buffer.append('>');
            ::typelib_TypeDescriptionReference * the_members[] = {
                ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeLibType(),
                ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType() };
            static ::sal_Bool const the_parameterizedTypes[] = { true, false };
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

template< typename typeparam_T > SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::Ambiguous< typeparam_T > const *) {
        return ::cppu::UnoType< ::css::beans::Ambiguous< typeparam_T > >::get();
    }

#endif // INCLUDED_COM_SUN_STAR_BEANS_AMBIGUOUS_HPP
