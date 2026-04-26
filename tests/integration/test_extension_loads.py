"""
Integration tests — verify the LibreAI extension loads in LibreOffice.

Run:
    xvfb-run -a pytest tests/integration/ -v
"""
import pytest


def test_lo_is_reachable(lo_context):
    """LibreOffice started and UNO bridge connected."""
    assert lo_context is not None


def test_libreai_extension_registered(lo_context):
    """LibreAI OXT is installed and its job service is registered."""
    smgr = lo_context.ServiceManager
    # The extension registers these two UNO services
    job = smgr.createInstanceWithContext(
        "org.libreai.job", lo_context
    )
    assert job is not None, \
        "org.libreai.job service not found — is libreai.oxt installed? (unopkg add ...)"


def test_open_writer_document(lo_context):
    """Can open a blank Writer document via UNO."""
    import uno
    from com.sun.star.beans import PropertyValue

    desktop = lo_context.ServiceManager.createInstanceWithContext(
        "com.sun.star.frame.Desktop", lo_context
    )
    doc = desktop.loadComponentFromURL(
        "private:factory/swriter", "_blank", 0, ()
    )
    assert doc is not None, "Failed to open a blank Writer document"

    # Clean up
    doc.close(True)


def test_writer_text_insertion(lo_context):
    """Can insert and read back text in a Writer document."""
    import uno
    from com.sun.star.beans import PropertyValue

    desktop = lo_context.ServiceManager.createInstanceWithContext(
        "com.sun.star.frame.Desktop", lo_context
    )
    doc = desktop.loadComponentFromURL(
        "private:factory/swriter", "_blank", 0, ()
    )
    text = doc.getText()
    cursor = text.createTextCursor()
    text.insertString(cursor, "LibreAI test", False)

    assert doc.getText().getString() == "LibreAI test"
    doc.close(True)
