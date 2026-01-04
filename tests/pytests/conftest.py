from pathlib import Path
import subprocess
import pytest

# Root of the project
ROOT_DIR = Path(__file__).parent.parent.parent

@pytest.fixture
def run_calc():
    calc_path = ROOT_DIR / "build" / "src" / "calc"

    def _run(args):
        result = subprocess.run(
            [str(calc_path)] + args,
            capture_output=True,
            text=True
        )
        return result

    return _run
