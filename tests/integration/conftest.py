"""
Pytest fixtures for LibreAI integration tests.

Custom options (registered here so they are available before test collection):
    --oxt  Path to an .oxt file for bundle structure tests.

Starts LibreOffice in UNO server mode (headless), yields a connected
ServiceManager, then kills LO after the test session.

Requirements:
    pip install pytest

LO must have the libreai.oxt extension installed beforehand:
    unopkg add libreai_ubuntu2404_x86_64.oxt
"""
import subprocess
import time
import socket
import pytest


def pytest_addoption(parser):
    parser.addoption("--oxt", default=None, help="Path to .oxt file for bundle structure tests")


LO_PORT = 2002
LO_HOST = "localhost"
_lo_proc = None


def _wait_for_port(host: str, port: int, timeout: float = 30.0) -> bool:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        try:
            with socket.create_connection((host, port), timeout=1):
                return True
        except OSError:
            time.sleep(0.5)
    return False


@pytest.fixture(scope="session")
def lo_context():
    """Start headless LO in UNO server mode and return a component context."""
    global _lo_proc

    accept = f"socket,host={LO_HOST},port={LO_PORT};urp;StarOffice.ServiceManager"
    _lo_proc = subprocess.Popen(
        [
            "soffice",
            "--headless",
            "--norestore",
            "--nofirststartwizard",
            f"--accept={accept}",
        ],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )

    assert _wait_for_port(LO_HOST, LO_PORT, timeout=30), \
        "LibreOffice did not open UNO socket in time"

    # Connect via python-uno
    import uno
    from com.sun.star.beans import PropertyValue

    localCtx = uno.getComponentContext()
    resolver = localCtx.ServiceManager.createInstanceWithContext(
        "com.sun.star.bridge.UnoUrlResolver", localCtx
    )
    ctx = resolver.resolve(
        f"uno:socket,host={LO_HOST},port={LO_PORT};urp;StarOffice.ComponentContext"
    )
    yield ctx

    _lo_proc.terminate()
    _lo_proc.wait(timeout=10)
