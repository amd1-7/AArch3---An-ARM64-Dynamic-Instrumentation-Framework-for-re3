# AArch3---An-ARM64-Dynamic-Instrumentation-Framework-for-re3

## Requirements:
 - **uv**: I use uv as package manager.
- **lldb**: lldb is native debugger of Apple Silicon Macos but it is unvailable into PyPi's package.
so to get lldb into your venv you must do this.
```bash
lldb -P > "$(.venv/bin/python -c 'import site; print(site.getsitepackages()[0])')/lldb.pth" # with python 3.9
```