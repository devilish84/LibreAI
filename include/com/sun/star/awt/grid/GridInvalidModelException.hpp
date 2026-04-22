#ifndef INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDINVALIDMODELEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDINVALIDMODELEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/awt/grid/GridInvalidModelException.hdl"

#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace awt { namespace grid {

inline GridInvalidModelException::GridInvalidModelException(
#if defined LIBO_USE_SOURCE_LOCATION
    std::experimental::source_location location
#endif
    )
    : ::css::uno::RuntimeException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{ }

inline GridInvalidModelException::GridInvalidModelException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , std::experimental::source_location location
#endif
)
    : ::css::uno::RuntimeException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{ }

#if !defined LIBO_INTERNAL_ONLY
GridInvalidModelException::GridInvalidModelException(GridInvalidModelException const & the_other): ::css::uno::RuntimeException(the_other) {}

GridInvalidModelException::~GridInvalidModelException() {}

GridInvalidModelException & GridInvalidModelException::operator =(GridInvalidModelException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::RuntimeException::operator =(the_other);
    return *this;
}
#endif

} } } } }

namespace com { namespace sun { namespace star { namespace awt { namespace grid {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::awt::grid::GridInvalidModelException const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        const ::css::uno::Type& rBaseType = ::cppu::UnoType< const ::css::uno::RuntimeException >::get();

        typelib_static_compound_type_init( &the_type, typelib_TypeClass_EXCEPTION, "com.sun.star.awt.grid.GridInvalidModelException", rBaseType.getTypeLibType(), 0,  0 );
    }
    return * reinterpret_cast< const ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::awt::grid::GridInvalidModelException const *) {
    return ::cppu::UnoType< ::css::awt::grid::GridInvalidModelException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_AWT_GRID_GRIDINVALIDMODELEXCEPTION_HPP
