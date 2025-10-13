from elftools.elf.elffile import ELFFile
from elftools.elf.sections import SymbolTableSection
from ghidrecomp import get_parser, decompile as ghidra_decompile
from utils import BIN_PATH
from pathlib import Path
import sys, hashlib, shelve

CACHE_PATH = Path('.cache')

def get_user_functions(f):
    """Returns set of user-defined functions"""
    e = ELFFile(f)
    funcs = set()
    for sec in e.iter_sections():
        if not isinstance(sec, SymbolTableSection):
            continue

        for sym in sec.iter_symbols():
            if sym.entry.st_info['type'] == 'STT_FUNC' and sym.entry.st_size != 0 and sym.name[0] != '_':
                funcs.add(sym.name)
    return funcs

def decompile():
    cache = shelve.open(CACHE_PATH)
    with open(BIN_PATH, 'rb') as f:
        file_hash = _bin_hash()
        user_functions = get_user_functions(f)
    
    if file_hash in cache:
        source = cache[file_hash]
        cache.close()
        return source
    
    args = get_parser().parse_args([str(BIN_PATH), '--skip-cache', '-o', '/tmp/ghidrecomp'])
    data = ghidra_decompile(args)
    all_funcs, decompilations = data[0], data[1]

    funcs = {}
    for f in decompilations:
        func_name = f[0].split('-')[0]
        if func_name not in user_functions:
            continue
        # Remove decompiler comment in the header
        body = '\n'.join([line for line in f[1].strip().split('\n') if not line.startswith('/*')])
        funcs[func_name] = body.strip()

    source = '\n\n'.join(funcs.values()).strip()
    cache[file_hash] = source
    cache.close()
    return source

def _bin_hash(chunk_size=8192):
    h = hashlib.sha256()
    with open(BIN_PATH, "rb") as f:
        for chunk in iter(lambda: f.read(chunk_size), b""):
            h.update(chunk)
    return h.hexdigest()


if __name__ == '__main__':
    code = decompile()
    sys.stdout.write(f'SOURCE_CODE_START\n{code}')
