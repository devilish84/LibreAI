# Feature Specification: Batch Rewrite Mode

**Version**: 1.0  
**Status**: Draft  
**Target Release**: v1.2.0  
**Author**: LibreAI Team  
**Date**: 2026-04-30

---

## Executive Summary

Batch Rewrite Mode enables users to apply the same AI instruction to multiple document sections automatically, without manually running chat 15+ times. This transforms productivity workflows for large documents, enabling style consistency, bulk corrections, and structural improvements at scale.

**Key Value**: Save 30+ minutes on typical multi-section document edits; apply consistent style across entire documents; enable document-wide AI transformations.

**Unique**: Only possible with embedded LibreOffice integration; impossible in standalone AI chat tools.

**Access**: Exposed as a dedicated LibreAI menu command and dialog, not just as a chat window option.

**Effort**: 8-10 hours | **Complexity**: Medium-High | **Risk**: Medium (UNO interaction)

---

## 1. Problem Statement & Motivation

### User Pain Points

1. **"I need this style applied to 15 paragraphs but can't run chat 15 times"**  
   Example: Rewrite all article introductions in same conversational tone → currently manual 1-by-1

2. **"Consistency across sections takes forever"**  
   Example: "Fix grammar" on each section independently → inconsistent corrections

3. **"Bulk AI improvements require manual section extraction"**  
   Example: Split doc into 10 text files, process each, reassemble → tedious and error-prone

4. **"Need to update tone across entire document structure"**  
   Example: Change from formal to casual → must manually select and rewrite each heading level

### Use Cases
- **Content Rewrites**: "Make all intro paragraphs conversational"
- **Grammar Fixes**: "Fix punctuation in all bulleted lists"
- **Tone Normalization**: "Rewrite all sections to match this formal tone"
- **Structure Improvement**: "Add a summary sentence to each section"
- **Content Generation**: "Generate an executive summary for each chapter"
- **Translation**: "Translate each section to French"
- **Summarization**: "Create a one-liner summary for each paragraph"

### Competitive Gap
- **ChatGPT Pro**: Manual section-by-section upload and processing
- **Copilot**: File-level, no structural awareness; no iteration across sections
- **Claude.app**: Manual per-section interaction
- **LibreAI Opportunity**: Document structure parsed via UNO; automatic traversal + iteration

---

## 2. Feature Overview

### 2.0 Access Path
This feature is surfaced as its own LibreAI menu item under `Tools → LibreAI → Batch Rewrite...`. It opens a dedicated Batch Rewrite dialog and may also be available from the LibreAI toolbar.

### 2.1 Basic Workflow

```
User selects:
1. Document scope (All | Current Outline Level | Selection)
2. Instruction: "Rewrite for clarity"
3. Checkbox: "Batch Mode"
4. Dialog: "Found 12 sections. Apply to all? [Apply] [Review] [Cancel]"
5. Progress bar: "Processing 3/12..."
6. Result: Each section rewritten, document updated in-place
```

### 2.2 In-Depth User Experience

#### Step 1: Prepare Selection
User in Writer → Multiple options:
- **Option A**: Select entire document (Ctrl+A)
- **Option B**: Select specific chapters/sections (highlighted)
- **Option C**: Auto-detect outline structure → apply to all H1, H2, or H3 sections

#### Step 2: Enter Instruction
ChawWindow:
```
Instruction: [Rewrite each section for clarity and brevity]
[Batch Mode ☐] ← NEW CHECKBOX
[Send]
```

#### Step 3: Confirm Scope
Dialog appears:
```
╔════════════════════════════════════════╗
║  Batch Processing Confirmation         ║
├────────────────────────────────────────┤
│ Document scope: All                   │
│ Structure detected: 12 outline items   │
│                                        │
│ Sections to process:                  │
│ ☑ 1. Introduction (237 words)         │
│ ☑ 2. Background (412 words)           │
│ ☑ 3. Methodology (189 words)          │
│ ☑ 4. Results (567 words)              │
│ ☑ ... (showing first 4 of 12)        │
│                                        │
│ Processing will:                       │
│ • Send 12 requests to OpenAI           │
│ • Apply each response in-place         │
│ • Estimated time: 2–3 minutes         │
│ • API cost estimate: ~$0.15           │
│                                        │
│ [Apply to All] [Review Each] [Cancel] │
╚════════════════════════════════════════╝
```

#### Step 4: Processing Progress
```
╔════════════════════════════════════════╗
║  Batch Processing: In Progress         ║
├────────────────────────────────────────┤
│ ████████░░ 8/12 sections               │
│                                        │
│ Current: "7. Conclusion" (124 words)  │
│ Status: Awaiting AI response...       │
│ Time elapsed: 1m 23s                  │
│ Est. remaining: 45s                   │
│                                        │
│                           [Stop]       │
╚════════════════════════════════════════╝
```

#### Step 5: Results & Review
```
╔════════════════════════════════════════╗
║  Batch Processing: Complete            ║
├────────────────────────────────────────┤
│ ✓ Successfully processed: 12/12        │
│                                        │
│ Summary:                               │
│ • Words before: 2,847                 │
│ • Words after: 2,134 (↓ 25%)          │
│ • Avg. chars removed per section: 59  │
│ • Total requests: 12                  │
│ • Time taken: 2m 14s                  │
│ • API cost: $0.14                     │
│                                        │
│ ☐ Undo all changes                    │
│ ☐ Show section-by-section review      │
│                                        │
│                  [Close] [Export Log]  │
╚════════════════════════════════════════╝
```

---

## 3. Requirements

### Functional Requirements

| ID | Requirement | Priority | Notes |
|----|-------------|----------|-------|
| FR1 | Detect document outline structure (H1, H2, etc.) | MUST | Core feature—parse TextRanges |
| FR2 | Allow user to select scope (All / H-level / Selection) | MUST | Flexibility |
| FR3 | Show preview of sections before processing | MUST | Safety—prevent accidents |
| FR4 | Process sections sequentially with delays | MUST | Avoid rate-limiting |
| FR5 | Support "Review Each" mode (confirm per section) | SHOULD | Quality control |
| FR6 | Show real-time progress bar | MUST | UX feedback |
| FR7 | Apply each response to original section location | MUST | Core functionality |
| FR8 | Allow stop/cancel mid-processing | MUST | User control |
| FR9 | Collect detailed logs (section, status, tokens used) | SHOULD | Diagnostics |
| FR10 | Support undo (Ctrl+Z) all changes | SHOULD | Safety valve |
| FR11 | Calculate cost estimate (token cost × API pricing) | COULD | Transparency |
| FR12 | Export batch log as JSON/CSV | COULD | Record-keeping |

### Non-Functional Requirements

| ID | Requirement | Notes |
|----|-------------|-------|
| NFR1 | Support 100+ sections | Tested with large docs |
| NFR2 | Delay 500ms+ between requests | Avoid rate-limiting (3500 req/min for OpenAI) |
| NFR3 | UI responsive during batch (async processing) | Don't freeze on main thread |
| NFR4 | Graceful error handling (skip failed, continue) | One failure ≠ stop |
| NFR5 | Memory: <50MB for 100-section doc | Don't accumulate responses |
| NFR6 | Timeout per request: 60s (config) | Cancel if stuck |

---

## 4. Data Model

### Batch Processing State
```cpp
struct BatchSection {
    QString id;                    // Unique section ID (e.g., "h1_2")
    QString title;                 // Section heading (e.g., "Introduction")
    int outlineLevel;              // 0=H1, 1=H2, 2=H3, etc.
    QString originalText;          // Original content
    QString rewrittenText;         // AI response (after processing)
    int tokensBefore;              // Word count before
    int tokensAfter;               // Word count after (estimate)
    QDateTime processedAt;         // When AI processed this section
    QString provider;              // Provider used (OpenAI, etc.)
    QString model;                 // Model used
    bool success;                  // Processing succeeded?
    QString errorMsg;              // If failed, why?
    int delayMs;                   // Delay before sending (for rate limit)
};

enum class BatchMode {
    ALL,              // All content
    OUTLINE_H1,       // Only H1 sections
    OUTLINE_H2,       // Only H2 sections
    OUTLINE_H3,       // Only H3 sections
    SELECTION,        // User-selected range
    REVIEW_EACH       // Pause between sections for manual review
};

struct BatchJob {
    QString id;                    // Job ID (uuid)
    QString instruction;           // AI instruction (e.g., "Make concise")
    BatchMode mode;
    QList<BatchSection> sections;  // Sections to process
    int currentIndex;              // Progress tracker
    int totalSections;
    bool isRunning;
    bool wasCancelled;
    QDateTime startedAt;
    QDateTime completedAt;
    
    // Statistics
    int totalTokensBefore;
    int totalTokensAfter;
    int successCount;
    int errorCount;
    double estimatedCost;          // $ cost for this batch
};

// Configuration for batch processing
struct BatchConfig {
    int delayBetweenRequests;      // milliseconds (default 500)
    int requestTimeout;            // seconds (default 60)
    bool stopOnError;              // false = skip failed, continue (default)
    bool includeCostEstimate;      // Show $ cost? (default true for paid APIs)
    bool autoUndo;                 // Auto-offer undo? (default true)
};
```

### Config.json Addition
```json
{
  "batch_processing": {
    "delay_ms": 500,
    "timeout_s": 60,
    "auto_undo": true,
    "show_cost": true
  },
  "batch_history": [
    {
      "id": "batch_2026_04_30_001",
      "timestamp": "2026-04-30T15:30:00Z",
      "instruction": "Rewrite for clarity",
      "sections_count": 12,
      "success_count": 12,
      "error_count": 0,
      "total_cost": 0.14
    }
  ]
}
```

---

## 5. Architecture & Design

### 5.1 New Components

#### BatchProcessor Class (`src/core/BatchProcessor.hpp/cpp`)

```cpp
class BatchProcessor : public QObject {
    Q_OBJECT
    
public:
    static BatchProcessor& instance();
    
    // Setup & Validation
    void parseDocumentStructure(const QString& sourceText);
    QList<BatchSection> detectSections(BatchMode mode);
    bool validateBatch(const QList<BatchSection>& sections);
    
    // Processing
    void startBatch(const QString& instruction, const QList<BatchSection>& sections);
    void pauseBatch();
    void resumeBatch();
    void cancelBatch();
    
    // Queries
    BatchJob* currentJob() const;
    int getProgress() const;
    QString getStatusMessage() const;
    
    // Results & Cleanup
    QList<BatchSection> getResults() const;
    bool applyResultsToDocument(const QString& targetDocPath);
    void saveBatchLog(const QString& filePath);
    
    // Cost Estimation
    double estimateCost(const QList<BatchSection>& sections);
    
    // Signals
    void batchStarted(int totalSections);
    void sectionProcessed(int current, int total, const QString& sectionName);
    void batchCompleted(int successCount, int errorCount);
    void batchError(const QString& message);
    void processingStateChanged(bool isRunning);
    
private:
    void processSectionAsync(int index);
    void onResponseReceived(const QString& response, int sectionIndex);
    void applyResponseToSection(int sectionIndex, const QString& response);
    void scheduleNextSection();
    
    BatchJob m_currentJob;
    BatchConfig m_config;
    QTimer m_delayTimer;           // For rate-limiting
    AIClient* m_aiClient;          // Reused from ChatWindow
};
```

#### UNO Document Structure Parser (`src/uno/DocumentParser.hpp/cpp`)

```cpp
class DocumentParser {
public:
    // Parse document by outline
    static QList<DocumentSection> parseOutlineStructure(const css::uno::Reference<css::text::XTextDocument>& doc);
    
    // Extract section by range
    static QString extractSectionText(const css::uno::Reference<css::text::XTextRange>& range);
    
    // Apply text to range with formatting preserved
    static void applySectionText(const css::uno::Reference<css::text::XTextRange>& range, 
                                 const QString& newText);
    
private:
    static int getOutlineLevel(const css::uno::Reference<css::text::XTextContent>& paragraph);
};
```

### 5.2 Integration with Existing Components

#### Batch Rewrite Entry Point
Batch Rewrite is launched through the LibreAI menu and dispatched through `LibreAIJob::trigger("batch_rewrite")`.
It uses a dedicated dialog flow rather than requiring the main chat window to be open.

#### ChatWindow Modifications
```cpp
class ChatWindow {
    // ... existing members ...
    
    // New batch-related UI
    QCheckBox* m_batchModeCheckbox;
    QPushButton* m_batchPreviewBtn;
    QLabel* m_batchStatusLabel;
    
    // New methods
    void onBatchModeToggled(bool checked);
    void onBatchPreviewClicked();
    void onSendBatch();
    void onBatchProgress(int current, int total, const QString& sectionName);
    void onBatchCompleted(int successCount, int errorCount);
    
    // Connect to BatchProcessor signals
    void connectBatchSignals();
};
```

#### New Dialog: BatchConfirmationDialog
```cpp
class BatchConfirmationDialog : public QDialog {
    Q_OBJECT
public:
    explicit BatchConfirmationDialog(const QList<BatchSection>& sections, QWidget* parent = nullptr);
    
    BatchMode selectedMode() const;
    bool shouldReview() const;
    
private:
    void refreshSectionList();
    
    QList<BatchSection> m_sections;
    QTableWidget* m_sectionTable;
    QRadioButton* m_rbApplyAll;
    QRadioButton* m_rbReview;
    QLabel* m_costEstimate;
};
```

#### New Dialog: BatchProgressDialog
```cpp
class BatchProgressDialog : public QDialog {
    Q_OBJECT
public:
    explicit BatchProgressDialog(QWidget* parent = nullptr);
    
    void setTotalSections(int count);
    void updateProgress(int current, const QString& currentSection);
    void setComplete(int successCount, int errorCount);
    
private slots:
    void onStopClicked();
    
    QProgressBar* m_progressBar;
    QLabel* m_statusLabel;
    QLabel* m_timeLabel;
    QPushButton* m_stopBtn;
};
```

### 5.3 Processing Flow Diagram
```
User: Enables "Batch Mode" + Enters instruction

ChatWindow::onSend()
  ├─ Detect: "Batch Mode" is checked?
  │  
  ├─ YES → BatchProcessor::parseDocumentStructure()
  │  │     └─ UnoHelper: Get all text ranges from document
  │  │
  │  ├─ BatchConfirmationDialog::exec()
  │  │  └─ User selects: All | H1 | H2 | H3 | Selection
  │  │
  │  └─ BatchProcessor::startBatch(instruction, sections)
  │     └─ For each section (async):
  │        ├─ Wait delay (500ms rate-limiting)
  │        ├─ AIClient::sendChat(section_text + instruction)
  │        ├─ Emit sectionProcessed(i, total, name)
  │        ├─ Apply response to document
  │        ├─ Log result
  │        └─ Schedule next
  │
  └─ NO → Normal single-turn chat

BatchProcessor signals:
  ├─ batchStarted() → Show progress dialog
  ├─ sectionProcessed() → Update progress bar
  ├─ batchCompleted() → Show results summary
  └─ batchError() → Show error, optionally retry
```

---

## 6. User Workflows

### Workflow 1: Batch Rewrite All Sections
```
1. User: Select all text (Ctrl+A)
2. ChatWindow: Type "Rewrite each section for clarity"
3. ChatWindow: Check [Batch Mode ☑]
4. ChatWindow: Click [Send]

System:
└─ BatchProcessor detects outline structure
   └─ Dialog: "Found 12 H1 sections. Include nested H2? [Yes] [No]"
   └─ BatchConfirmationDialog shown with preview
   └─ User clicks [Apply to All]
   └─ For each section:
      ├─ Wait 500ms
      ├─ Send to OpenAI with section text + instruction
      ├─ Receive response
      ├─ Apply to original location in document
      ├─ Update progress bar
   └─ Show: "12/12 complete ✓ | Words: 2847 → 2134 (↓25%)"
```

### Workflow 2: Batch with Manual Review
```
1. User: Select specific chapter (lines 100–500)
2. ChatWindow: "Fix all grammar issues in this chapter"
3. ChatWindow: Check [Batch Mode ☑]
4. ChatWindow: Click [Send]

System:
└─ BatchProcessor detects 8 paragraphs in selection
└─ Dialog: "Found 8 sections within selection"
└─ User chooses [Review Each] tab
└─ For each section:
   ├─ Show section number in progress dialog
   ├─ Send to AI
   ├─ Display response in preview pane
   ├─ User clicks [✓ Apply] or [✗ Skip]
   ├─ Apply if approved
└─ Show final count: "7/8 sections updated (1 skipped)"
```

### Workflow 3: Batch with Error Recovery
```
1. User starts batch rewrite on 10 sections
2. On section 5: Network error (timeout)

System:
└─ BatchProcessor: stopOnError=false (default)
└─ Log: "Section 5 failed: timeout"
└─ Skip and continue with section 6
└─ Emit batchError("Section 5 timed out; continuing...")
└─ User sees in progress: "Processing section 6/10 (Section 5 failed)"
└─ Batch completes: "9/10 successful"
└─ Show retry option for section 5
```

---

## 7. Implementation Details

### 7.1 Document Structure Detection

#### Using UNO Outline API
```cpp
QList<BatchSection> BatchProcessor::parseDocumentStructure(
    const css::uno::Reference<css::text::XTextDocument>& doc) {
    
    QList<BatchSection> sections;
    
    try {
        auto xText = doc->getText();
        auto xEnum = xText->createEnumeration();
        
        int sectionIndex = 0;
        while (xEnum->hasMoreElements()) {
            auto xElement = xEnum->nextElement();
            auto xParagraph = css::uno::Reference<css::text::XTextContent>(xElement, css::uno::UNO_QUERY);
            
            // Check if this is a heading (outline level > 0)
            auto xProps = css::uno::Reference<css::beans::XPropertySet>(xParagraph, css::uno::UNO_QUERY);
            sal_Int16 outlineLevel = 0;
            xProps->getPropertyValue("OutlineLevel") >>= outlineLevel;
            
            if (outlineLevel > 0) {  // It's a heading
                BatchSection section;
                section.id = QString("section_%1").arg(sectionIndex++);
                section.outlineLevel = outlineLevel - 1;
                section.title = *xParagraph->getString();
                
                // Collect content until next heading
                // ... (collect following paragraphs)
                
                sections.append(section);
            }
        }
    } catch (...) {
        qWarning() << "Error parsing document structure";
    }
    
    return sections;
}
```

#### Fallback: Paragraph-by-Paragraph
If outline structure not detected, split by empty lines:
```cpp
QList<BatchSection> sections;
auto paragraphs = document.split(QRegularExpression("\n{2,}"));  // Empty lines
for (int i = 0; i < paragraphs.size(); ++i) {
    BatchSection s;
    s.id = QString("para_%1").arg(i);
    s.originalText = paragraphs[i];
    sections.append(s);
}
```

### 7.2 Rate Limiting & Delays

```cpp
void BatchProcessor::processSectionAsync(int index) {
    if (index >= m_currentJob.sections.size()) {
        // All done
        emit batchCompleted(m_currentJob.successCount, m_currentJob.errorCount);
        return;
    }
    
    auto& section = m_currentJob.sections[index];
    
    // Calculate delay to avoid rate limits
    // OpenAI: 3500 req/min = 1 req per ~17ms, but be safe with 500ms
    int delayMs = m_config.delayBetweenRequests;
    
    // Scale delay for batch size (10 sections → 5s total delay overhead)
    if (m_currentJob.sections.size() > 50) {
        delayMs = std::max(100, delayMs / 2);
    }
    
    m_delayTimer.singleShot(delayMs, [this, index]() {
        sendSectionToAI(index);
    });
}

void BatchProcessor::sendSectionToAI(int index) {
    auto& section = m_currentJob.sections[index];
    
    // Build prompt: section_text + instruction
    QString prompt = QString(
        "Process this text according to the following instruction:\n"
        "Instruction: %1\n\n"
        "Text:\n\n"
        "%2"
    ).arg(m_currentJob.instruction, section.originalText);
    
    // Send to AI (reuse existing AIClient)
    // Connect reply signal to onResponseReceived(response, index)
}
```

### 7.3 Results Application to Document

```cpp
bool BatchProcessor::applyResultsToDocument(const QString& targetDocPath) {
    try {
        auto xDoc = UnoHelper::getDocument(targetDocPath);
        auto xText = xDoc->getText();
        
        for (const auto& section : m_currentJob.sections) {
            if (!section.success) continue;  // Skip failed sections
            
            // Find original section range
            auto xRange = findSectionRange(xText, section.title);
            if (!xRange) {
                qWarning() << "Could not find section:" << section.title;
                continue;
            }
            
            // Apply new text while preserving formatting
            xRange->setString(section.rewrittenText.toStdString());
            
            // Update stats
            section.tokensAfter = section.rewrittenText.split(" ").size();
        }
        
        return true;
    } catch (const css::uno::Exception& e) {
        qWarning() << "Error applying results:" << QString::fromStdString(e.Message);
        return false;
    }
}
```

### 7.4 Progress Tracking & UI Updates

```cpp
void BatchProcessor::onResponseReceived(const QString& response, int sectionIndex) {
    auto& section = m_currentJob.sections[sectionIndex];
    section.rewrittenText = response;
    section.success = true;
    section.processedAt = QDateTime::currentDateTime();
    
    m_currentJob.successCount++;
    m_currentJob.currentIndex = sectionIndex;
    
    // Calculate stats
    int wordsBefore = section.originalText.split(" ").size();
    int wordsAfter = response.split(" ").size();
    section.tokensBefore = wordsBefore;
    section.tokensAfter = wordsAfter;
    m_currentJob.totalTokensAfter += wordsAfter;
    
    // Emit signal (UI updates on main thread)
    emit sectionProcessed(
        sectionIndex + 1,
        m_currentJob.sections.size(),
        section.title
    );
    
    // Schedule next
    scheduleNextSection();
}
```

### 7.5 Cost Estimation

```cpp
double BatchProcessor::estimateCost(const QList<BatchSection>& sections) {
    // Typical cost model: ~$0.0015 per 1K tokens (GPT-3.5 input)
    
    double totalTokens = 0;
    for (const auto& section : sections) {
        // Estimate: ~1 token per 4 characters (rough)
        totalTokens += section.originalText.length() / 4.0;
        // Add instruction tokens (fixed ~15)
        totalTokens += 15;
    }
    
    // Output estimate: usually 0.5–0.8x input tokens
    totalTokens += totalTokens * 0.6;
    
    // Price: GPT-3.5 Turbo = $0.0015/1K input, $0.002/1K output
    return (totalTokens / 1000.0) * 0.00175;
}
```

---

## 8. Error Handling

| Scenario | Error | Recovery |
|----------|-------|----------|
| Document contains no headings | Parse error | Fall back to paragraph-by-paragraph split |
| Section too long (>2000 tokens) | API error (context overflow) | Split into sub-sections or warn user |
| Network timeout mid-batch | Connection error | Skip section, log, continue (if stopOnError=false) |
| API rate limit (429 error) | Rate limit | Increase delay, retry after backoff |
| Malformed response JSON | Parse error | Log, treat as failed section, continue |
| User cancels mid-batch | User action | Mark remaining sections as skipped, allow undo |
| Cannot apply to document (doc locked) | I/O error | Show error dialog, optionally export results to file |
| Out of memory (100+ large sections) | Resource | Chunk processing, process 10 at a time |

---

## 9. Testing Strategy

### Unit Tests (`test_batch_processor.cpp`)
```cpp
TEST(BatchProcessorTest, DetectOutlineStructure) { ... }
TEST(BatchProcessorTest, SplitByOutlineLevel) { ... }
TEST(BatchProcessorTest, EstimateCost) { ... }
TEST(BatchProcessorTest, ExpandPromptWithSection) { ... }
TEST(BatchProcessorTest, ApplyResultConcurrency) { ... }
TEST(BatchProcessorTest, HandleTimeoutAndRetry) { ... }
TEST(BatchProcessorTest, SkipFailedSectionContinue) { ... }
TEST(BatchProcessorTest, UndoAllChanges) { ... }
```

### Integration Tests (`test_batch_rewrite.py`)
```python
def test_batch_rewrite_all_h1_sections():
    # 1. Create Writer doc with 5 H1 sections
    # 2. Enable batch mode
    # 3. Send "Rewrite concisely"
    # 4. Verify all 5 sections updated in doc
    
def test_batch_mode_respects_selection():
    # 1. Select 3 paragraphs out of 10
    # 2. Enable batch, send instruction
    # 3. Verify only selected 3 updated

def test_batch_cancel_mid_processing():
    # 1. Start batch of 10 sections
    # 2. After 3 complete, click Stop
    # 3. Verify sections 4–10 unchanged

def test_batch_cost_estimate():
    # 1. Show cost estimate before batch
    # 2. Complete batch
    # 3. Show actual cost vs estimate

def test_batch_undo_all():
    # 1. Complete batch rewrite
    # 2. Document changed
    # 3. Undo (Ctrl+Z)
    # 4. Verify all original text restored
```

### Manual Test Checklist
- [ ] Create 10-section Writer doc (H1+H2+H3 mixed)
- [ ] Enable batch mode, send instruction
- [ ] Verify all sections rewritten correctly
- [ ] Check progress bar updates smoothly
- [ ] Calculate cost estimate, compare to actual
- [ ] Test cancel mid-batch
- [ ] Test undo all changes
- [ ] Test "Review Each" mode
- [ ] Test error recovery (network timeout on section 5)
- [ ] Test with 50+ sections (memory check)
- [ ] Test with very large sections (2000+ words)
- [ ] Export batch log, verify JSON readable
- [ ] Test on Calc sheet (if FR12 planned)

---

## 10. Performance & Scalability

### Performance Targets
- Detect outline structure: <500ms (even 50-section doc)
- Show confirmation dialog: <200ms (render 50 sections)
- Per-section processing: 500ms delay + 5–10s for API response
- Apply result to document: <100ms per section
- Total for 10 sections: ~90–120 seconds (realistic)
- Total for 50 sections: ~7–10 minutes

### Scalability
- Support 100+ sections: Tested, should work
- Memory: ~50MB for 100 sections + responses
- UI responsiveness: All processing on background thread (QThread or async signals)

### Optimization
- Lazy-load document structure (don't parse entire doc at once)
- Batch apply results (write all in one pass, not per-section)
- Cache section boundaries (don't re-scan document)

---

## 11. Undo/Redo Support

Batch operations should be undoable as a single group:

```cpp
// Before batch: Group undo operations
xUndoManager->enterUndoContext("Batch Rewrite");

// Apply each result
for (auto& section : sections) {
    applyResultToDocument(section);
}

// After batch: Close undo group
xUndoManager->leaveUndoContext();

// User presses Ctrl+Z once → all changes undone
```

---

## 12. Configuration

Add to Config:
```cpp
struct BatchProcessingConfig {
    int delayBetweenRequests = 500;  // ms
    int requestTimeout = 60;         // seconds
    bool stopOnError = false;        // Continue on failure?
    bool showCostEstimate = true;    // Show $ before batch?
    int maxSectionsPerBatch = 100;   // Safety limit
};
```

Configurable via ConfigDialog → Advanced tab:
```
Batch Processing Settings:
- Delay between requests: [500] ms
- Request timeout: [60] seconds
- ☑ Show cost estimate (for paid APIs)
- ☐ Stop on first error
- Max sections per batch: [100]
```

---

## 13. Logging & Diagnostics

### Batch Log Structure
```json
{
  "batch_id": "batch_2026_04_30_15_30_001",
  "timestamp": "2026-04-30T15:30:45Z",
  "instruction": "Rewrite for clarity",
  "scope": "all_h1",
  "total_sections": 12,
  "sections": [
    {
      "index": 0,
      "id": "h1_0",
      "title": "Introduction",
      "outline_level": 0,
      "tokens_before": 247,
      "tokens_after": 189,
      "processing_time_ms": 4521,
      "status": "success",
      "provider": "openai",
      "model": "gpt-3.5-turbo",
      "cost": 0.011
    },
    {
      "index": 1,
      "id": "h1_1",
      "title": "Background",
      "status": "failed",
      "error": "timeout",
      "retry_count": 1
    }
  ],
  "summary": {
    "success_count": 11,
    "error_count": 1,
    "total_cost": 0.128,
    "total_tokens_before": 2847,
    "total_tokens_after": 2134,
    "processing_time_s": 67
  }
}
```

Export available via: `[Export Log]` button → Save as JSON/CSV

---

## 14. Internationalization (i18n)

### New Strings
```cpp
// libreai_en.ts
<translation>Batch Mode</translation>
<translation>Process all sections with the same instruction</translation>
<translation>Batch Processing Confirmation</translation>
<translation>Found %1 sections. Apply instruction to all?</translation>
<translation>Apply to All</translation>
<translation>Review Each</translation>
<translation>Processing %1 of %2</translation>
<translation>Batch complete: %1 successful, %2 failed</translation>
<translation>Estimated cost: $%1</translation>
<translation>Undo all batch changes?</translation>
<translation>Section timed out; continuing...</translation>
```

---

## 15. Security & Safety

- **Large Batch Prevention**: Limit to 100 sections max (configurable)
- **Accidental Send Prevention**: Confirmation dialog before processing starts
- **Cost Warnings**: Show estimated cost before batch for paid APIs
- **Undo Safety**: All changes grouped, single Undo reverses entire batch
- **Rate Limit Respect**: Configurable delays between requests (default 500ms)

---

## 16. Success Metrics

- [ ] Users run batch mode on average 1× per week (tracked via logs)
- [ ] Completion rate: >95% (fewer than 5% cancellations)
- [ ] Error recovery: >90% of batches complete successfully even with network hiccups
- [ ] Performance: 10-section batch takes <2 minutes (100% of time on API wait)
- [ ] Memory: Processing 50 sections uses <100MB
- [ ] Zero data loss (undo fully restores all original text)
- [ ] Export feature used by >10% of batch users

---

## Appendix A: Outline Structure Detection Algorithm

```
1. Open document via UNO
2. Iterate all paragraphs:
   a. Check OutlineLevel property
   b. If > 0 → It's a heading, collect as section start
   c. If == 0 → Regular paragraph, add to current section
3. Group paragraphs between headings into sections
4. Return list of BatchSection with hierarchy

Example:
Document:
  H1: "Introduction"         ← Heading 1 (outline level 1)
    Paragraph 1              ← Add to "Introduction" section
    Paragraph 2
  H2: "Background"           ← Heading 2 (outline level 2)
    Paragraph 3
  H1: "Methodology"          ← New section
    ...

Result:
  Section[0]: title="Introduction", content=[Para1, Para2], level=0
  Section[1]: title="Background", content=[Para3], level=1
  Section[2]: title="Methodology", content=[...], level=0
```

---

## Appendix B: CMakeLists.txt Changes

```cmake
# Add batch processing sources
list(APPEND SOURCES
    src/core/BatchProcessor.cpp
    src/uno/DocumentParser.cpp
)

# Add UI dialogs
set(HEADERS ${HEADERS}
    src/ui/BatchConfirmationDialog.hpp
    src/ui/BatchProgressDialog.hpp
)

# No new dependencies required (uses existing Qt + UNO)
```

---

## Appendix C: Future Enhancements

- **Streaming per section**: Show partial responses as they arrive (v1.3)
- **ML-based section grouping**: Auto-detect logical document sections independent of heading levels
- **Template integration**: Use Prompt Library templates in batch mode
- **Calc/Impress support**: Batch process cell ranges or slide collections
- **Comparison mode**: Show before/after side-by-side for each section
- **Collaborative batch**: Share batch job with team members
