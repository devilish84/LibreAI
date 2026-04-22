#ifndef INCLUDED_COM_SUN_STAR_XML_CRYPTO_SAX_ELEMENTSTACKITEM_HPP
#define INCLUDED_COM_SUN_STAR_XML_CRYPTO_SAX_ELEMENTSTACKITEM_HPP

#include "sal/config.h"

#include "com/sun/star/xml/crypto/sax/ElementStackItem.hdl"

#include "com/sun/star/xml/sax/XAttributeList.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace xml { namespace crypto { namespace sax {

inline ElementStackItem::ElementStackItem()
    : isStartElementEvent(false)
    , elementName()
    , xAttributes()
{
}

inline ElementStackItem::ElementStackItem(const ::sal_Bool& isStartElementEvent_, const ::rtl::OUString& elementName_, const ::css::uno::Reference< ::css::xml::sax::XAttributeList >& xAttributes_)
    : isStartElementEvent(isStartElementEvent_)
    , elementName(elementName_)
    , xAttributes(xAttributes_)
{
}


inline bool operator==(const ElementStackItem& the_lhs, const ElementStackItem& the_rhs)
{
    return the_lhs.isStartElementEvent == the_rhs.isStartElementEvent
        && the_lhs.elementName == the_rhs.elementName
        && the_lhs.xAttributes == the_rhs.xAttributes;
}

inline bool operator!=(const ElementStackItem& the_lhs, const ElementStackItem& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } } }

namespace com { namespace sun { namespace star { namespace xml { namespace crypto { namespace sax {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::xml::crypto::sax::ElementStackItem const *) {
    //TODO: On certain platforms with weak memory models, the following code can result in some threads observing that the_type points to garbage
    static ::typelib_TypeDescriptionReference * the_type = 0;
    if (the_type == 0) {
        ::typelib_TypeDescriptionReference * the_members[] = {
            ::cppu::UnoType< ::sal_Bool >::get().getTypeLibType(),
            ::cppu::UnoType< ::rtl::OUString >::get().getTypeLibType(),
            ::cppu::UnoType< ::css::uno::Reference< ::css::xml::sax::XAttributeList > >::get().getTypeLibType() };
        ::typelib_static_struct_type_init(&the_type, "com.sun.star.xml.crypto.sax.ElementStackItem", 0, 3, the_members, 0);
    }
    return *reinterpret_cast< ::css::uno::Type * >(&the_type);
}

} } } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::xml::crypto::sax::ElementStackItem const *) {
    return ::cppu::UnoType< ::css::xml::crypto::sax::ElementStackItem >::get();
}

#endif // INCLUDED_COM_SUN_STAR_XML_CRYPTO_SAX_ELEMENTSTACKITEM_HPP
