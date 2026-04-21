#pragma once
#include <QString>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>

namespace UnoHelper {

void setContext(const css::uno::Reference<css::uno::XComponentContext>& ctx);

css::uno::Reference<css::frame::XFrame> getCurrentFrame();
QString getSelectedText();
void    applyText(const QString& text);

}
