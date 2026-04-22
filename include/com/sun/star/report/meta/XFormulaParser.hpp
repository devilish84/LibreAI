#ifndef INCLUDED_COM_SUN_STAR_REPORT_META_XFORMULAPARSER_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_META_XFORMULAPARSER_HPP

#include "sal/config.h"

#include "com/sun/star/report/meta/XFormulaParser.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/sheet/FormulaOpCodeMapEntry.hpp"
#include "com/sun/star/sheet/XFormulaOpCodeMapper.hpp"
#include "com/sun/star/sheet/XFormulaParser.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"

namespace com { namespace sun { namespace star { namespace report { namespace meta {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::meta::XFormulaParser const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[3];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::sheet::XFormulaParser > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.meta.XFormulaParser", 3, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::meta::XFormulaParser > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::meta::XFormulaParser > >::get();
}

::css::uno::Type const & ::css::report::meta::XFormulaParser::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::meta::XFormulaParser >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_META_XFORMULAPARSER_HPP
