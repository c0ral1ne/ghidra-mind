from elftools.elf.elffile import ELFFile
from elftools.elf.sections import SymbolTableSection
from ghidrecomp import get_parser, decompile
from time import time

def get_user_functions(file):
    """Returns set of user-defined functions"""
    e = ELFFile(file)
    funcs = set()

    for sec in e.iter_sections():
        if not isinstance(sec, SymbolTableSection):
            continue

        for sym in sec.iter_symbols():
            if sym.entry.st_info['type'] == 'STT_FUNC' and sym.entry.st_size != 0 and sym.name[0] != '_':
                funcs.add(sym.name)

    return funcs

def ghidra_decompile(filename, user_functions):
    args = get_parser().parse_args([filename, '--skip-cache'])
    data = decompile(args)
    all_funcs, decompilations = data[0], data[1]

    funcs = [f[1].strip() for f in decompilations if f[0].split('-')[0] in user_functions]
    source = '\n'.join(funcs).strip()
    # Remove decompiler comments
    cleaned_source = '\n'.join([line for line in source.split('\n') if not line.startswith('/*')])
    return cleaned_source


if __name__ == '__main__':
    filename = 'examples/horcruxes'
    with open(filename, 'rb') as f:
        user_funcs = get_user_functions(f)
    
    bin = filename.split('/')[-1]
    source = ghidra_decompile(filename, user_funcs)
    with open(f'output/{bin}_{round(time())}.c', 'w') as file:
        file.write(source)
    