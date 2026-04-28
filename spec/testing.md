# Testing

Testing is split into two automated tiers (both run in CI) and a manual smoke-test checklist.

CI workflow: `.github/workflows/test.yml` — runs on every push and PR to `development` / `main`.

---

## Manual Smoke Tests

Run after every change before committing:

```bash
bash build.sh --install
pkill -x soffice.bin; soffice --writer &
```

**Checklist:**
- [ ] Extension loads without error (no crash on startup)
- [ ] Chat panel opens via **Tools → LibreAI** or toolbar button
- [ ] Config dialog opens via **Tools → LibreAI Settings** (and on first run with no config)
- [ ] Selecting text and choosing **Right-click → Ask LibreAI** pre-fills the selected text area
- [ ] **Grab Selection** button re-reads the current selection from Writer
- [ ] Sending a message returns a response rendered with Markdown formatting (bold, headings, code blocks)
- [ ] **Apply to Document** transfers headings, bold, italic, and list items with correct Writer formatting
- [ ] **Rewrite** replaces document selection with AI response
- [ ] Conversation history accumulates and shows in the history toggle panel
- [ ] **Clear History** empties the history list
- [ ] Provider switch (Ollama → OpenAI → Claude → Grok → Gemini) shows correct credential fields
- [ ] API keys survive a LibreOffice restart (platform keychain)
- [ ] Language change in ConfigDialog immediately relabels all UI strings (no restart needed)
- [ ] Closing and reopening Writer does not crash (singleton cleanup)
- [ ] Log file grows at `~/.config/libreai/libreai.log` when logging is enabled

---

## Unit Tests — Google Test

**Location:** `tests/unit/`  
**Dependencies:** Qt6::Core + Qt6::Network + libgtest — **no UNO runtime required**

### Run locally

```bash
sudo apt-get install libgtest-dev
cmake -S . -B build -DBUILD_TESTS=ON -Wno-dev
cmake --build build --parallel $(nproc)
ctest --test-dir build --output-on-failure
```

### Test suites

| Executable | File | Coverage |
|------------|------|----------|
| `test_config` | `tests/unit/test_config.cpp` | `isConfigured()` for all 5 providers, save/load round-trip, default values |
| `test_logger` | `tests/unit/test_logger.cpp` | `initLogging()` / `closeLogging()`, log level filtering, file creation |
| `test_ai_parsing` | `tests/unit/test_ai_parsing.cpp` | `parseModels()` and `parseResponse()` for Ollama, OpenAI, Anthropic, Grok, Gemini |

All three executables compile all credential backend source files (`CREDENTIAL_SOURCES`) to satisfy vtable requirements without needing a full UNO environment.

### Extending

To add tests: create a new `.cpp` in `tests/unit/`, add it to `tests/unit/CMakeLists.txt` following the existing pattern, link `Qt6::Core` and any provider `.cpp` files needed.

---

## Integration Tests — pytest + python-uno

**Location:** `tests/integration/`  
**What's covered:** OXT is registered in LO, Writer opens/closes, text can be inserted  
**Dependencies:** `python3-uno`, `xvfb`, `pytest`

### Prerequisites

```bash
sudo apt-get install python3-uno xvfb
pip install pytest pytest-timeout
unopkg add libreai.oxt          # extension must be installed first
```

### Run locally

```bash
xvfb-run -a pytest tests/integration/ -v --timeout=60
```

### How it works

`conftest.py` starts LibreOffice in UNO server mode:

```
soffice --headless --accept="socket,host=localhost,port=2002;urp;StarOffice.ServiceManager"
```

Then connects via `com.sun.star.bridge.UnoUrlResolver` and yields the component context to each test. LO is terminated after the test session.

### Files

| File | Contents |
|------|----------|
| `tests/integration/conftest.py` | Session-scoped `lo_context` fixture |
| `tests/integration/test_extension_loads.py` | OXT registration, Writer document lifecycle, text insertion |

---

## Static Analysis

```bash
# cppcheck
sudo apt-get install cppcheck
cppcheck --enable=all --std=c++17 src/

# clang-tidy (needs compile_commands.json)
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B build
clang-tidy src/**/*.cpp -p build/
```
