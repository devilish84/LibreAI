#ifndef INCLUDED_COM_SUN_STAR_UNO_XINTERFACE_HPP
#define INCLUDED_COM_SUN_STAR_UNO_XINTERFACE_HPP

#include "sal/config.h"

#include "com/sun/star/uno/XInterface.hdl"

#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER const ::css::uno::Reference< ::css::uno::XInterface > *) {
    return ::cppu::UnoType< ::css::uno::XInterface >::get();
}

::css::uno::Type const & ::css::uno::XInterface::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::uno::XInterface >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UNO_XINTERFACE_HPP
