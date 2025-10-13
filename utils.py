import subprocess
from pathlib import Path

BIN_PATH = Path('/tmp/ghidra_mind-bin')

def run_ghidra(uploaded_file):
    """Streamlit behaves weirdly with multi-threaded logic, which is used in ghidrecomp
    Instead, call as a subprocess
    """
    with open(BIN_PATH, 'wb') as f:
        f.write(uploaded_file.getvalue())

    res = subprocess.run(['python', 'decompile.py'], capture_output=True, text=True, check=True)
    ghidra_logs, _, decompiled = res.stdout.partition('SOURCE_CODE_START')

    return decompiled
