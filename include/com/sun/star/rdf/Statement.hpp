#ifndef INCLUDED_COM_SUN_STAR_RDF_STATEMENT_HPP
#define INCLUDED_COM_SUN_STAR_RDF_STATEMENT_HPP

#include "sal/config.h"

#include "com/sun/star/rdf/Statement.hdl"

#include "com/sun/star/rdf/XNode.hpp"
#include "com/sun/star/rdf/XResource.hpp"
#include "com/sun/star/rdf/XURI.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace rdf {

inline Statement::Statement()
    : Subject()
    , Predicate()
    , Object()
    , Graph()
{
}

inline Statement::Statement(const ::css::uno::Reference< ::css::rdf::XResource >& Subject_, const ::css::uno::Reference< ::css::rdf::XURI >& Predicate_, const ::css::uno::Reference< ::css::rdf::XNode >& Object_, const ::css::uno::Reference< ::css::rdf::XURI >& Graph_)
    : Subject(Subject_)
    , Predicate(Predicate_)
    , Object(Object_)
    , Graph(Graph_)
{
}


inline bool operator==(const Statement& the_lhs, const Statement& the_rhs)
{
    return the_lhs.Subject == the_rhs.Subject
        && the_lhs.Predicate == the_rhs.Predicate
        && the_lhs.Object == the_rhs.Object
        && the_lhs.Graph == the_rhs.Graph;
}

inline bool operator!=(const Statement& the_lhs, const Statement& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace rdf {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::rdf::Statement const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::rdf::XResource > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::rdf::XURI > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::rdf::XNode > >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::rdf::XURI > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.rdf.Statement", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::rdf::Statement const *) {
    return ::cppu::UnoType< ::css::rdf::Statement >::get();
}

#endif // INCLUDED_COM_SUN_STAR_RDF_STATEMENT_HPP
