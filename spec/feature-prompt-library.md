# Feature Specification: Prompt Library & Templates

**Version**: 1.0  
**Status**: Draft  
**Target Release**: v1.1.0  
**Author**: LibreAI Team  
**Date**: 2026-04-30

---

## Executive Summary

Prompt Library & Templates allows users to save frequently-used AI instructions as reusable templates with variable substitution. This eliminates repetitive copy-pasting of instructions across documents and accelerates common workflows (e.g., "Make conversational," "Fix grammar," "Summarize").

**Key Value**: 3-5x faster repeated rewrites; persistent instruction memory across sessions; document-context-aware templates.

**Effort**: 4-6 hours | **Complexity**: Low-Medium | **Risk**: Low

---

## 1. Problem Statement & Motivation

### User Pain Points
1. **"I type the same instruction 10+ times a day"**  
   Example: "Make this more conversational and engaging" → repeated daily across documents
   
2. **"I forget exact wording of my preferred style instruction"**  
   Example: Tries different variations of "Fix grammar and punctuation" instead of consistent standard

3. **"I want instructions tailored to this document's context"**  
   Example: Need "Fix tone to match the formal style of this executive report" but similar document uses "Make conversational for marketing blog"

4. **"Copy-pasting long instructions from notes is error-prone"**  
   Example: Typos in technical instructions lead to AI misunderstanding

### Competitive Gap
- **ChatGPT**: No saved prompts; manual copy-paste each session
- **Copilot** (Microsoft): Snippets exist but not integrated into document workflow
- **Claude.app**: No saved prompts; manual each time
- **LibreAI Opportunity**: Native to document; templates can include document metadata

---

## 2. Feature Overview

### 2.0 Access Path
Prompt Library is available as its own LibreAI menu item under `Tools → LibreAI → Prompt Library...` as well as from the chat window toolbar. It opens a dedicated Template Manager dialog for browsing, editing, importing, and exporting templates.

### What Users Can Do

#### 2.1 Save a Template
1. User writes instruction in ChatWindow: *"Rewrite for clarity, shorter sentences, keep technical terms"*
2. User clicks **"Save as Template"** button
3. Dialog: *"Template name: [Clarity Rewrite]"* + optional description
4. Click **"Save"** → Template stored in Config
5. Next time: Access from library dropdown

#### 2.2 Use a Template
1. Select text in Writer document
2. Open ChatWindow → Dropdown "**My Templates**"
3. Choose *"Clarity Rewrite"*
4. Template populated in text box with `{selected_text}` replaced by actual selection
5. Click **"Send"** → Standard Chat flow

#### 2.3 Template with Variables
1. User saves: *"Summarize this for a {audience} audience in {format}."*
   - `{audience}` = placeholder
   - `{format}` = placeholder
2. On use: Dialog appears asking to fill variables
   - *"Audience: [____]"* (dropdown or text)
   - *"Format: [____]"* (e.g., bullet points, paragraph)
3. Final prompt: *"Summarize this for a marketing specialist audience in bullet points."*

#### 2.4 Template with Document Metadata
1. User saves: *"Rewrite in the {tone} style of this document."*
2. On use: Auto-detect document tone from first paragraph
3. Final prompt: *"Rewrite in the formal, executive style of this document."*

#### 2.5 Organize & Manage Templates
1. **View all templates**: "My Templates" panel in ConfigDialog
2. **Edit**: Double-click template → Edit name, instruction, description
3. **Delete**: Right-click → Delete
4. **Export**: Export library as JSON file (share with colleagues, backup)
5. **Import**: Import exported JSON library

---

## 3. Requirements

### Functional Requirements

| ID | Requirement | Priority | Notes |
|----|-------------|----------|-------|
| FR1 | Save current chat instruction as template | MUST | Core feature |
| FR2 | Load template into ChatWindow input | MUST | Core feature |
| FR3 | Support `{selected_text}` variable auto-substitution | MUST | Most common case |
| FR4 | Support `{document_title}` variable | SHOULD | Document metadata |
| FR5 | Support `{document_tone}` variable | SHOULD | Auto-detect tone |
| FR6 | Support custom `{variables}` with user prompts | SHOULD | 80/20 flexibility |
| FR7 | View all saved templates in ConfigDialog | MUST | Discoverability |
| FR8 | Delete template | MUST | Cleanup |
| FR9 | Edit template name/instruction | SHOULD | Refinement |
| FR10 | Export library as JSON | SHOULD | Portability |
| FR11 | Import library from JSON | SHOULD | Sharing |
| FR12 | Template categories/tags | COULD | Organization for 50+ templates |

### Non-Functional Requirements

| ID | Requirement | Notes |
|----|-------------|-------|
| NFR1 | Load time <100ms | Library dropdown on ChatWindow |
| NFR2 | Support 100+ templates | No performance regression |
| NFR3 | Persist across sessions | Auto-save to config.json |
| NFR4 | Backward compatible | If library missing, no error |

---

## 4. Data Model

### Config.json Schema Addition
```json
{
  "version": "1.0.8",
  "...existing fields...": {},
  "prompt_library": {
    "templates": [
      {
        "id": "tmpl_001",
        "name": "Clarity Rewrite",
        "description": "Simplify and shorten sentences",
        "instruction": "Rewrite for clarity. Use shorter sentences. Keep technical terms unchanged. Format as paragraphs.",
        "category": "Writing Style",
        "variables": [],
        "created_at": "2026-04-30T15:23:45Z",
        "updated_at": "2026-04-30T15:23:45Z",
        "usage_count": 12
      },
      {
        "id": "tmpl_002",
        "name": "Market Audience Summary",
        "description": "Summarize for marketing/non-technical audience",
        "instruction": "Summarize this concisely for a {audience} audience. Focus on: benefits, use cases, ROI. Avoid: technical jargon, implementation details. Format: bullet points.",
        "category": "Summarization",
        "variables": [
          {
            "name": "audience",
            "type": "text",
            "prompt": "Target audience (e.g., managers, investors, end-users)",
            "default_value": "general"
          }
        ],
        "created_at": "2026-04-28T10:00:00Z",
        "updated_at": "2026-04-30T14:00:00Z",
        "usage_count": 5
      }
    ]
  }
}
```

### Template Structure (C++)
```cpp
struct PromptTemplate {
    QString id;                    // Unique identifier (uuid)
    QString name;                  // Display name
    QString description;           // Optional description
    QString instruction;           // Template instruction with {variables}
    QString category;              // Optional category (e.g., "Writing Style", "Summarization")
    QList<TemplateVariable> variables;  // List of {variable} placeholders
    QDateTime createdAt;
    QDateTime updatedAt;
    int usageCount;               // Track popularity for sorting
    
    bool isValid() const { return !name.isEmpty() && !instruction.isEmpty(); }
    QString expand(const QMap<QString, QString>& values) const;  // Substitute variables
};

struct TemplateVariable {
    QString name;                  // e.g., "audience"
    QString type;                  // "text", "dropdown", "auto"
    QString prompt;                // UI prompt shown to user
    QString defaultValue;          // Optional default
    QStringList dropdownOptions;   // If type == "dropdown"
};
```

### File Location
- Linux/macOS: `~/.config/libreai/prompt_library.json`
- Windows: `%APPDATA%\libreai\prompt_library.json`
- Fallback: Stored in `config.json` under `prompt_library.templates[]`

---

## 5. Architecture & Design

### 5.1 New Components

#### PromptLibrary Class (`src/core/PromptLibrary.hpp/cpp`)
```cpp
class PromptLibrary {
public:
    static PromptLibrary& instance();  // Meyer's singleton
    
    // CRUD operations
    bool addTemplate(const PromptTemplate& tmpl);
    bool updateTemplate(const PromptTemplate& tmpl);
    bool deleteTemplate(const QString& templateId);
    PromptTemplate getTemplate(const QString& templateId) const;
    
    // Query
    QList<PromptTemplate> getAllTemplates() const;
    QList<PromptTemplate> getTemplatesByCategory(const QString& category) const;
    QStringList getAllCategories() const;
    
    // File I/O
    bool loadFromFile(const QString& filePath);
    bool saveToFile(const QString& filePath) const;
    
    // Export/Import
    QString exportToJson() const;
    bool importFromJson(const QString& jsonStr);
    
    // Expansion
    QString expandTemplate(const PromptTemplate& tmpl, const QMap<QString, QString>& variables) const;
    QStringList extractVariables(const QString& instruction) const;
    
    // Signals
    void templateAdded(const PromptTemplate& tmpl);
    void templateUpdated(const PromptTemplate& tmpl);
    void templateDeleted(const QString& templateId);
    
private:
    QList<PromptTemplate> m_templates;
    QMap<QString, PromptTemplate> m_templateMap;  // For fast lookup
    QString m_libraryPath;
};
```

#### Integration with Config
```cpp
// In Config class
void Config::loadPromptLibrary() {
    PromptLibrary::instance().loadFromFile(
        QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "/prompt_library.json"
    );
}

void Config::savePromptLibrary() {
    PromptLibrary::instance().saveToFile(
        QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "/prompt_library.json"
    );
}
```

### 5.2 UI Changes

#### ChatWindow Changes
```cpp
// New UI elements
QComboBox* m_templateCombo;        // Dropdown "My Templates"
QPushButton* m_saveTemplateBtn;    // "Save as Template" button
QPushButton* m_manageTemplatesBtn; // "Manage Templates..." → ConfigDialog tab

// New slots
void onSaveTemplateClicked();       // Prompt for template name
void onTemplateSelected(int index); // Load selected template
void onManageTemplatesClicked();    // Open ConfigDialog → Templates tab
void onChatInputChanged();          // Enable "Save Template" only if input non-empty
```

#### UI Layout
```
ChatWindow:
┌─────────────────────────────────────────────┐
│  [My Templates ▼] [Manage Templates...] │
│  ┌─────────────────────────────────────────┐│
│  │ Prompt: "Rewrite for clarity..."        ││
│  │ [Send] [Save as Template...] [Clear]   ││
│  └─────────────────────────────────────────┘│
│                                              │
│  Response: ___________________________       │
│  [Apply to Document] [Copy] [Clear History]│
└─────────────────────────────────────────────┘
```

#### ConfigDialog → Templates Tab (NEW)
```
ConfigDialog → Templates Tab:
┌─────────────────────────────────────────────┐
│ [+ New Template] [Import...] [Export...]    │
├─────────────────────────────────────────────┤
│ Templates (sorted by usage):                │
│ ☐ Name            Category      Last Used  │
│ ☑ Clarity Rewrite Writing       2 days ago │
│ ☐ Grammar Fix     Writing       1 week ago │
│ ☐ Exec Summary    Summarization 3 days ago │
│ ☐ {double-click to edit}                   │
│                                              │
│ [Edit] [Delete] [Duplicate] [Export]       │
├─────────────────────────────────────────────┤
│ Detail View (below selected):                │
│ Name:        [Clarity Rewrite____________]  │
│ Category:    [Writing Style ▼]             │
│ Description: [Simplify sentences________]   │
│ Instruction: [________________________]      │
│              [________________________]      │
│              [________________________]      │
│                                              │
│ Variables: ☑ {selected_text}               │
│           ☐ {document_tone}                 │
│           ☐ Custom: [____________]          │
│                                              │
│ [Save] [Cancel]                             │
└─────────────────────────────────────────────┘
```

---

## 6. User Workflows

### Workflow 1: Save Template (Simple)
```
User action:
1. Type instruction in ChatWindow: "Make more concise and friendly"
2. Click [Save as Template]
3. Dialog: Name = "Friendly Concise" | Description = "Shorter, friendly tone"
4. Click [Save]

System:
→ PromptTemplate created with id, timestamp
→ Stored in Config.prompt_library.templates[]
→ Saved to prompt_library.json
→ ChatWindow template dropdown refreshed
```

### Workflow 2: Use Template (Simple)
```
User action:
1. Select text in Writer: "Lorem ipsum dolor sit amet..."
2. ChatWindow: Click dropdown [My Templates ▼]
3. Select "Friendly Concise"
4. Instruction auto-filled: "Make more concise and friendly"
5. Click [Send]

System:
→ Sent as normal chat with pre-filled instruction
→ Template.usage_count incremented
→ Response rendered
```

### Workflow 3: Save & Use Template with Variables
```
User action:
1. Type in ChatWindow: "Summarize for a {audience} audience in {format}."
2. Click [Save as Template]
3. Name = "Smart Summary"
4. System detects {audience}, {format} as variables
5. Dialog: Configure variables
   - {audience}: type="dropdown", options=["executive", "technical", "marketing"]
   - {format}: type="text", prompt="Format (e.g., bullet points, paragraph)"
6. Click [Save]

Later:
1. Open template → Variables popup shown
2. Audience: [executive ▼]
3. Format: [____________________]
4. Click [OK] → Instruction expanded
5. Send

System:
→ All {variable} placeholders replaced with user values
→ {selected_text} auto-substituted
```

### Workflow 4: Export/Import Library
```
User action (Export):
1. ConfigDialog → Templates tab
2. Click [Export...]
3. Save as prompt_library_backup.json
4. File contains all templates with metadata

User action (Import):
1. ConfigDialog → Templates tab
2. Click [Import...]
3. Select prompt_library_backup.json
4. Dialog: "Found 8 templates. Import all? [Merge/Replace]"
5. Click [Merge] → New templates added, existing unchanged

System:
→ JSON parsed
→ Templates de-duplicated by name/instruction hash
→ Merged into PromptLibrary
```

---

## 7. Implementation Details

### 7.1 Variable Substitution Engine

#### Pattern Recognition
```cpp
QStringList PromptLibrary::extractVariables(const QString& instruction) const {
    QStringList variables;
    QRegularExpression re(R"(\{([a-zA-Z_][a-zA-Z0-9_]*)\})");
    QRegularExpressionMatchIterator it = re.globalMatch(instruction);
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        variables.append(match.captured(1));
    }
    return variables;
}
```

#### Built-in Variables
```cpp
QString PromptLibrary::expandTemplate(const PromptTemplate& tmpl, 
                                       const QMap<QString, QString>& userVars) const {
    QString result = tmpl.instruction;
    
    // Auto-substitutions
    result.replace("{selected_text}", userVars.value("selected_text", "{selected_text}"));
    result.replace("{document_title}", UnoHelper::getDocumentTitle());
    result.replace("{document_author}", UnoHelper::getDocumentAuthor());
    
    // User-provided variables
    for (auto it = userVars.begin(); it != userVars.end(); ++it) {
        QString var = "{" + it.key() + "}";
        result.replace(var, it.value());
    }
    
    return result;
}
```

### 7.2 Persistence

#### Load on Startup
```cpp
// In Config::init() or LibreAIJob::trigger()
PromptLibrary::instance().loadFromFile(
    QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "/prompt_library.json"
);
```

#### Save on Exit
```cpp
// In ChatWindow destructor or UNO extension unload
PromptLibrary::instance().saveToFile(
    QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "/prompt_library.json"
);
```

### 7.3 UI Signal Flow

```cpp
// ChatWindow::onTemplateSelected(int index)
void ChatWindow::onTemplateSelected(int index) {
    if (index < 0) return;
    
    const auto& tmpl = PromptLibrary::instance().getAllTemplates().at(index);
    
    // Check if template has custom variables
    auto customVars = tmpl.variables;
    if (!customVars.isEmpty()) {
        // Show variable dialog
        TemplateVariableDialog dialog(this, tmpl);
        if (dialog.exec() == QDialog::Accepted) {
            auto values = dialog.getValues();
            QString expanded = PromptLibrary::instance().expandTemplate(tmpl, values);
            m_promptInput->setPlainText(expanded);
        }
    } else {
        // Direct expansion
        QMap<QString, QString> vars;
        vars["selected_text"] = m_currentSelection;
        QString expanded = PromptLibrary::instance().expandTemplate(tmpl, vars);
        m_promptInput->setPlainText(expanded);
    }
}

// ChatWindow::onSaveTemplateClicked()
void ChatWindow::onSaveTemplateClicked() {
    QString instruction = m_promptInput->toPlainText().trimmed();
    if (instruction.isEmpty()) {
        QMessageBox::warning(this, "Empty Template", "Please enter an instruction first.");
        return;
    }
    
    // Auto-detect variables
    auto detectedVars = PromptLibrary::instance().extractVariables(instruction);
    
    // Show save dialog
    SaveTemplateDialog dialog(this, instruction, detectedVars);
    if (dialog.exec() == QDialog::Accepted) {
        PromptTemplate tmpl = dialog.getTemplate();
        if (PromptLibrary::instance().addTemplate(tmpl)) {
            statusBar()->showMessage("Template saved: " + tmpl.name, 3000);
            refreshTemplateCombo();
        }
    }
}
```

---

## 8. Error Handling

| Scenario | Error | Recovery |
|----------|-------|----------|
| Template name empty | Validation error | Show dialog, require name |
| Template instruction empty | Validation error | Prevent save |
| File I/O error on load | Log warning | Continue with empty library |
| Corrupted JSON | Parse error | Log error, skip template |
| Variable not provided | Expansion fails | Keep `{variable}` placeholder in result |
| Duplicate template names | Warning | Allow (differentiate by category/description) |
| Too many templates (100+) | Perf warning | Show in UI, suggest cleanup |

---

## 9. Testing Strategy

### Unit Tests (`test_prompt_library.cpp`)
```cpp
TEST(PromptLibraryTest, AddTemplate) { ... }
TEST(PromptLibraryTest, DeleteTemplate) { ... }
TEST(PromptLibraryTest, UpdateTemplate) { ... }
TEST(PromptLibraryTest, ExtractVariables) { ... }
TEST(PromptLibraryTest, ExpandTemplateSimple) { ... }
TEST(PromptLibraryTest, ExpandTemplateWithUserVars) { ... }
TEST(PromptLibraryTest, ExpandTemplateWithDocMetadata) { ... }
TEST(PromptLibraryTest, ExportImportJson) { ... }
TEST(PromptLibraryTest, LoadSaveFile) { ... }
TEST(PromptLibraryTest, GetTemplatesByCategory) { ... }
```

### Integration Tests (`test_chatwindow_templates.py`)
```python
def test_save_template_from_chat():
    # 1. Send chat instruction
    # 2. Click "Save as Template"
    # 3. Verify template appears in dropdown
    
def test_use_template_expands_selection():
    # 1. Select text in Writer
    # 2. Choose template from ChatWindow dropdown
    # 3. Verify {selected_text} replaced correctly
    
def test_use_template_with_variables():
    # 1. Select template with variables
    # 2. Fill variable dialog
    # 3. Verify expansion correct
    
def test_export_import_library():
    # 1. Add 3 templates
    # 2. Export to JSON
    # 3. Delete templates
    # 4. Import from JSON
    # 5. Verify all 3 restored
```

### Manual Test Checklist
- [ ] Save simple template (no variables)
- [ ] Load template and send chat
- [ ] Save template with custom variable
- [ ] Fill variable dialog and verify expansion
- [ ] Auto-detect document metadata variable
- [ ] Edit template name and description
- [ ] Delete template
- [ ] Export library → JSON file readable
- [ ] Import library → templates appear
- [ ] 50+ templates → no UI slowdown
- [ ] Restart LibreOffice → library persists
- [ ] Corrupt JSON in file → graceful error

---

## 10. Performance & Scalability

### Performance Targets
- Template list load: < 100ms (even with 100+ templates)
- Variable expansion: < 10ms
- Save template: < 50ms
- UI dropdown render: < 50ms

### Scalability
- Support 100+ templates: Indexed QMap by ID for O(1) lookup
- No file growth concern: JSON ~500 bytes per template → 100 templates ≈ 50KB
- Memory: ~1MB for 100 templates in memory

### Optimization
- Lazy-load template library on first access
- Cache variable extraction regex
- Index templates by category for fast filtering

---

## 11. Localization (i18n)

### New Strings
```cpp
// In libreai_en.ts
<translation>Save as Template</translation>
<translation>My Templates</translation>
<translation>Manage Templates</translation>
<translation>Template name:</translation>
<translation>Category:</translation>
<translation>Description:</translation>
<translation>No templates found</translation>
<translation>Template saved: %1</translation>
<translation>Delete template: %1?</translation>
<translation>Export Templates</translation>
<translation>Import Templates</translation>
```

---

## 12. Security Considerations

- **API Keys in Templates**: Warn users not to save templates with hardcoded API keys
- **Credential Backend**: Template file stored in `~/.config/libreai/` (owned by user)
- **JSON Validation**: Strict parsing; reject templates with suspicious syntax

---

## 13. Backward Compatibility

- If `prompt_library.json` missing → start with empty library
- If `config.json` has old format → migrate to new file on save
- No breaking changes to existing Config structure

---

## 14. Success Metrics

- [ ] Users save >10 templates on average
- [ ] 50% of chat requests use templates (tracked via `usage_count`)
- [ ] Export/import feature used by >5% of users
- [ ] Zero crashes related to template expansion
- [ ] Page load time remains <100ms with 100 templates

---

## Appendix A: JSON Schema Example

```json
{
  "templates": [
    {
      "id": "550e8400-e29b-41d4-a716-446655440000",
      "name": "Clarity Rewrite",
      "description": "Simplify and shorten sentences while preserving meaning",
      "instruction": "Rewrite the following for clarity. Use shorter sentences. Preserve technical terms. Output as paragraphs.",
      "category": "Writing Style",
      "variables": [],
      "created_at": "2026-04-30T14:23:45.123Z",
      "updated_at": "2026-04-30T14:23:45.123Z",
      "usage_count": 12
    }
  ]
}
```

---

## Appendix B: CMakeLists.txt Changes

```cmake
# Add PromptLibrary sources
list(APPEND SOURCES
    src/core/PromptLibrary.cpp
)

# No new dependencies required (uses existing Qt)
```

---

## Appendix C: Migration from Older Versions

If v1.0.8 or earlier accessed, create empty library on first run:
```cpp
if (!QFile::exists(libraryPath)) {
    QJsonDocument emptyDoc(QJsonObject{{"templates", QJsonArray{}}});
    QFile file(libraryPath);
    file.open(QIODevice::WriteOnly);
    file.write(emptyDoc.toJson());
    file.close();
}
```
