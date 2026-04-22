#ifndef INCLUDED_COM_SUN_STAR_XFORMS_XMODEL_HPP
#define INCLUDED_COM_SUN_STAR_XFORMS_XMODEL_HPP

#include "sal/config.h"

#include "com/sun/star/xforms/XModel.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
#include "com/sun/star/container/XSet.hpp"
#include "com/sun/star/task/XInteractionHandler.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/xforms/XDataTypeRepository.hpp"
#include "com/sun/star/xforms/XSubmission.hpp"
#include "com/sun/star/xml/dom/XDocument.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"

namespace com { namespace sun { namespace star { namespace xforms {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xforms::XModel const *) {
    static typelib_TypeDescriptionReference * the_type = 0;
    if ( !the_type )
    {
        typelib_static_mi_interface_type_init( &the_type, "com.sun.star.xforms.XModel", 0, 0 );
    }
    return * reinterpret_cast< ::css::uno::Type * >( &the_type );
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::xforms::XModel > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::xforms::XModel > >::get();
}

::css::uno::Type const & ::css::xforms::XModel::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::xforms::XModel >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XFORMS_XMODEL_HPP
