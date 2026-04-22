#ifndef INCLUDED_COM_SUN_STAR_REPORT_INSPECTION_DEFAULTCOMPONENTINSPECTORMODEL_HPP
#define INCLUDED_COM_SUN_STAR_REPORT_INSPECTION_DEFAULTCOMPONENTINSPECTORMODEL_HPP

#include "sal/config.h"

#include <cassert>

#include "com/sun/star/inspection/XObjectInspectorModel.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/uno/DeploymentException.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XComponentContext.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "sal/types.h"

#if defined ANDROID || defined IOS //TODO
#include <com/sun/star/lang/XInitialization.hpp>
#include <osl/detail/component-defines.h>
#endif

#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel
extern "C" ::css::uno::XInterface * SAL_CALL LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel(::css::uno::XComponentContext *, ::css::uno::Sequence< ::css::uno::Any > const &);
#endif

namespace com { namespace sun { namespace star { namespace report { namespace inspection {

class DefaultComponentInspectorModel {
public:
    static ::css::uno::Reference< ::css::inspection::XObjectInspectorModel > createDefault(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context) {
        assert(the_context.is());
        ::css::uno::Reference< ::css::inspection::XObjectInspectorModel > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel
            the_instance = ::css::uno::Reference< ::css::inspection::XObjectInspectorModel >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel)(the_context.get(), ::css::uno::Sequence< ::css::uno::Any >())), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(::css::uno::Sequence< ::css::uno::Any >());
            }
#else
            the_instance = ::css::uno::Reference< ::css::inspection::XObjectInspectorModel >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.report.inspection.DefaultComponentInspectorModel", ::css::uno::Sequence< ::css::uno::Any >(), the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.report.inspection.DefaultComponentInspectorModel" + " of type " + "com.sun.star.inspection.XObjectInspectorModel" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.report.inspection.DefaultComponentInspectorModel" + " of type " + "com.sun.star.inspection.XObjectInspectorModel", the_context);
        }
        return the_instance;
    }

    static ::css::uno::Reference< ::css::inspection::XObjectInspectorModel > createWithHelpSection(::css::uno::Reference< ::css::uno::XComponentContext > const & the_context, ::sal_Int32 minHelpTextLines, ::sal_Int32 maxHelpTextLines) {
        assert(the_context.is());
        ::css::uno::Sequence< ::css::uno::Any > the_arguments(2);
        ::css::uno::Any* the_arguments_array = the_arguments.getArray();
        the_arguments_array[0] <<= minHelpTextLines;
        the_arguments_array[1] <<= maxHelpTextLines;
        ::css::uno::Reference< ::css::inspection::XObjectInspectorModel > the_instance;
        try {
#if defined LO_URE_CURRENT_ENV && defined LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel && (LO_URE_CURRENT_ENV) == (LO_URE_CTOR_ENV_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel) && defined LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel
            the_instance = ::css::uno::Reference< ::css::inspection::XObjectInspectorModel >(::css::uno::Reference< ::css::uno::XInterface >(static_cast< ::css::uno::XInterface * >((*LO_URE_CTOR_FUN_com_dot_sun_dot_star_dot_report_dot_inspection_dot_DefaultComponentInspectorModel)(the_context.get(), the_arguments)), ::SAL_NO_ACQUIRE), ::css::uno::UNO_QUERY);
            ::css::uno::Reference< ::css::lang::XInitialization > init(the_instance, ::css::uno::UNO_QUERY);
            if (init.is()) {
                init->initialize(the_arguments);
            }
#else
            the_instance = ::css::uno::Reference< ::css::inspection::XObjectInspectorModel >(the_context->getServiceManager()->createInstanceWithArgumentsAndContext( "com.sun.star.report.inspection.DefaultComponentInspectorModel", the_arguments, the_context), ::css::uno::UNO_QUERY);
#endif
        } catch (const ::css::uno::RuntimeException &) {
            throw;
        } catch (const ::css::uno::Exception & the_exception) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.report.inspection.DefaultComponentInspectorModel" + " of type " + "com.sun.star.inspection.XObjectInspectorModel" + ": " + the_exception.Message, the_context);
        }
        if (!the_instance.is()) {
            throw ::css::uno::DeploymentException(::rtl::OUString("component context fails to supply service ") + "com.sun.star.report.inspection.DefaultComponentInspectorModel" + " of type " + "com.sun.star.inspection.XObjectInspectorModel", the_context);
        }
        return the_instance;
    }

private:
    DefaultComponentInspectorModel(); // not implemented
    DefaultComponentInspectorModel(DefaultComponentInspectorModel &); // not implemented
    ~DefaultComponentInspectorModel(); // not implemented
    void operator =(DefaultComponentInspectorModel); // not implemented
};

} } } } }

#endif // INCLUDED_COM_SUN_STAR_REPORT_INSPECTION_DEFAULTCOMPONENTINSPECTORMODEL_HPP
