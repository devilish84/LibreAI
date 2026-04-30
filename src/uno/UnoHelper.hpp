#pragma once
#include <QString>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/text/XTextCursor.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>

class QTextDocument;

namespace UnoHelper {

void setContext(const css::uno::Reference<css::uno::XComponentContext>& ctx);

css::uno::Reference<css::frame::XFrame> getCurrentFrame();
QString getSelectedText();
void    applyText(const QString& text);
void    applyRichText(const QTextDocument* doc);

// Apply markdown-parsed QTextDocument to an arbitrary programmatic text cursor.
// Used by BatchProcessor to write AI responses back to stored section ranges.
void    applyRichTextToRange(const QTextDocument* doc,
                             const css::uno::Reference<css::text::XTextCursor>& cursor);

}
