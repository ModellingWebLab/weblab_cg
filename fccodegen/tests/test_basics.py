#import pytest
import logging


# Show more logging output
logging.getLogger().setLevel(logging.INFO)


class TestBasics(object):
    """
    Tests if the method was installed at all.
    """
    def test_import(self):
        import fccodegen    # noqa

    def test_version(self):
        import fccodegen

        version = fccodegen.version()
        assert isinstance(version, tuple)
        assert len(version) == 3
        assert isinstance(version[0], int)
        assert isinstance(version[1], int)
        assert isinstance(version[2], int)
        assert version[0] >= 0
        assert version[1] >= 0
        assert version[2] >= 0

        version = fccodegen.version(formatted=True)
        assert isinstance(version, str)
        assert len(version) >= 1
