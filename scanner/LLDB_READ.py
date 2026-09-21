from scanner.LLDB_INIT import process,lldb,logger

pid = process.GetProcessID()
if pid == lldb.LLDB_INVALID_PROCESS_ID:
    logger.error(f"[LLDB_READ.py] error get PID")
    exit()

thread:lldb.SBThread = process.GetSelectedThread()
process.Detach()