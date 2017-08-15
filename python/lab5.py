"""Write a Python script using PEFile to enumerate all imports and exports from 
Kernel32.dll, KernelBase.dll, and ntdll.dll, and store the results in a text file.
Additionally, enumerate the sections in each of those files."""

import pefile

pe = pefile.PE("C:\\Users\\DOTlaptop\\Desktop\\re_quiz\\re_lab4.1_x86.dll")
imps = {entry.dll: [imp.name for imp in entry.imports] for entry in pe.DIRECTORY_ENTRY_IMPORT}
print ' '.join(imps)

pe = pefile.PE("C:\\Users\\DOTlaptop\\Desktop\\re_quiz\\re_lab4.1_x86.dll")
exports = [(exp.name, exp.ordinal) for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols]
print exports
