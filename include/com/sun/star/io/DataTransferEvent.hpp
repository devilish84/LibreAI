#ifndef INCLUDED_COM_SUN_STAR_IO_DATATRANSFEREVENT_HPP
#define INCLUDED_COM_SUN_STAR_IO_DATATRANSFEREVENT_HPP

#include "sal/config.h"

#include "com/sun/star/io/DataTransferEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace io {

inline DataTransferEvent::DataTransferEvent()
    : ::css::lang::EventObject()
    , aException()
{
}

inline DataTransferEvent::DataTransferEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Any& aException_)
    : ::css::lang::EventObject(Source_)
    , aException(aException_)
{
}


inline bool operator==(const DataTransferEvent& the_lhs, const DataTransferEvent& the_rhs)
{
    return operator==( static_cast< ::css::lang::EventObject>(the_lhs), static_cast< ::css::lang::EventObject>(the_rhs) )

        && the_lhs.aException == the_rhs.aException;
}

inline bool operator!=(const DataTransferEvent& the_lhs, const DataTransferEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace io {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::DataTransferEvent const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Any >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.io.DataTransferEvent", ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::io::DataTransferEvent const *) {
    return ::cppu::UnoType< ::css::io::DataTransferEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_IO_DATATRANSFEREVENT_HPP
