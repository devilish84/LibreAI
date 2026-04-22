#ifndef INCLUDED_COM_SUN_STAR_XML_SAX_INPUTSOURCE_HPP
#define INCLUDED_COM_SUN_STAR_XML_SAX_INPUTSOURCE_HPP

#include "sal/config.h"

#include "com/sun/star/xml/sax/InputSource.hdl"

#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline InputSource::InputSource()
    : aInputStream()
    , sEncoding()
    , sPublicId()
    , sSystemId()
{
}

inline InputSource::InputSource(const ::css::uno::Reference< ::css::io::XInputStream >& aInputStream_, const ::rtl::OUString& sEncoding_, const ::rtl::OUString& sPublicId_, const ::rtl::OUString& sSystemId_)
    : aInputStream(aInputStream_)
    , sEncoding(sEncoding_)
    , sPublicId(sPublicId_)
    , sSystemId(sSystemId_)
{
}


inline bool operator==(const InputSource& the_lhs, const InputSource& the_rhs)
{
    return the_lhs.aInputStream == the_rhs.aInputStream
        && the_lhs.sEncoding == the_rhs.sEncoding
        && the_lhs.sPublicId == the_rhs.sPublicId
        && the_lhs.sSystemId == the_rhs.sSystemId;
}

inline bool operator!=(const InputSource& the_lhs, const InputSource& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace sax {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::sax::InputSource const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::css::uno::Reference< ::css::io::XInputStream > >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.xml.sax.InputSource", 0, 4, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::sax::InputSource const *) {
    return ::cppu::UnoType< ::css::xml::sax::InputSource >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_SAX_INPUTSOURCE_HPP
