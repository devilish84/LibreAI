#ifndef INCLUDED_COM_SUN_STAR_REPORT_XREPORTDEFINITION_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_XREPORTDEFINITION_HPP

#include "sal/config.h"

#include "com/sun/star/report/XReportDefinition.hdl"

#include "com/sun/star/document/XDocumentSubStorageSupplier.hpp"
#include "com/sun/star/document/XEventBroadcaster.hpp"
#include "com/sun/star/document/XStorageBasedDocument.hpp"
#include "com/sun/star/document/XViewDataSupplier.hpp"
#include "com/sun/star/embed/XVisualObject.hpp"
#include "com/sun/star/frame/XLoadable.hpp"
#include "com/sun/star/frame/XModel.hpp"
#include "com/sun/star/report/XFunctionsSupplier.hpp"
#include "com/sun/star/report/XGroups.hpp"
#include "com/sun/star/report/XReportComponent.hpp"
#include "com/sun/star/report/XSection.hpp"
#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/style/XStyleFamiliesSupplier.hpp"
#include "com/sun/star/ui/XUIConfigurationManagerSupplier.hpp"
#include "com/sun/star/util/XCloseable.hpp"
#include "com/sun/star/util/XModifiable2.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace report {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::report::XReportDefinition const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_TypeDescriptionReference * aSuperTypes[12];
        aSuperTypes[0] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XModel > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< const ::css::uno::Reference< ::css::frame::XLoadable > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< const ::css::uno::Reference< ::css::embed::XVisualObject > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< const ::css::uno::Reference< ::css::document::XStorageBasedDocument > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< const ::css::uno::Reference< ::css::document::XViewDataSupplier > >::get().getTypeLibType();
        aSuperTypes[5] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XCloseable > >::get().getTypeLibType();
        aSuperTypes[6] = ::cppu::UnoType< const ::css::uno::Reference< ::css::ui::XUIConfigurationManagerSupplier > >::get().getTypeLibType();
        aSuperTypes[7] = ::cppu::UnoType< const ::css::uno::Reference< ::css::document::XDocumentSubStorageSupplier > >::get().getTypeLibType();
        aSuperTypes[8] = ::cppu::UnoType< const ::css::uno::Reference< ::css::style::XStyleFamiliesSupplier > >::get().getTypeLibType();
        aSuperTypes[9] = ::cppu::UnoType< const ::css::uno::Reference< ::css::util::XModifiable2 > >::get().getTypeLibType();
        aSuperTypes[10] = ::cppu::UnoType< const ::css::uno::Reference< ::css::report::XReportComponent > >::get().getTypeLibType();
        aSuperTypes[11] = ::cppu::UnoType< const ::css::uno::Reference< ::css::report::XFunctionsSupplier > >::get().getTypeLibType();
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.report.XReportDefinition", 12, aSuperTypes );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::report::XReportDefinition > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::report::XReportDefinition > >::get();
}

::css::uno::Type const & ::css::report::XReportDefinition::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::report::XReportDefinition >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REPORT_XREPORTDEFINITION_HPP
