#pragma once
#include <QList>
#include <QString>
#include <com/sun/star/text/XText.hpp>
#include <com/sun/star/text/XTextCursor.hpp>
#include <com/sun/star/text/XTextRange.hpp>

struct BatchSection {
    QString id;
    QString title;
    int     outlineLevel = 0;   // 1 = H1, 2 = H2, … (0 = plain paragraph)
    QString originalText;       // body text sent to AI (plain text)
    QString rewrittenText;      // AI response
    bool    success = false;
    QString errorMsg;
    int     wordsBefore = 0;
    int     wordsAfter  = 0;

    // Reference to the XText that owns the body ranges below.
    css::uno::Reference<css::text::XText> xText;

    // Ordered list of body paragraph ranges (excludes the heading paragraph itself).
    // Used at apply time to build a spanning cursor covering all body paragraphs.
    // For Paragraphs scope (no headings), contains exactly one range.
    QList<css::uno::Reference<css::text::XTextRange>> bodyRanges;
};

enum class BatchScope {
    AllHeadings,   // every heading at any level + its body
    H1Only,
    H2Only,
    H3Only,
    Paragraphs,    // split by paragraph when no headings found
};

namespace DocumentParser {

// Parse the Writer document reachable from the current UNO frame.
// Returns one BatchSection per logical section.
// Falls back to Paragraphs scope if no headings are found.
QList<BatchSection> detect(BatchScope scope);

// Build a single XTextCursor spanning all bodyRanges of a section.
// Returns an empty reference on failure.
css::uno::Reference<css::text::XTextCursor>
    buildBodyCursor(const BatchSection& section);

}
