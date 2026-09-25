from scanner.LLDB_INIT import process,lldb,logger

pid = process.GetProcessID()
if pid == lldb.LLDB_INVALID_PROCESS_ID:
    logger.error(f"[LLDB_READ.py] error get PID")
    exit()


thread:lldb.SBThread = process.GetSelectedThread()
frame:lldb.SBFrame = thread.GetSelectedFrame()

player:lldb.SBValue = frame.EvaluateExpression("FindPlayerPed()")
playerPtr:lldb.SBValue = player.GetValueAsUnsigned()

if not playerPtr:
    logger.error("[LLDB_READ.py] error get playter's pointer")
    exit()

logger.success("[LLDB_READ.py] success get playter's pointer")
process.Detach()