def test_add(run_calc):
    result = run_calc(["add", "2", "3"])
    assert result.returncode == 0
    assert result.stdout.strip() == "5"

def test_sub(run_calc):
    result = run_calc(["sub", "5", "2"])
    assert result.returncode == 0
    assert result.stdout.strip() == "3"
