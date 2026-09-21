from dotenv import load_dotenv
from loguru import logger
import lldb
import os
load_dotenv()
RE3 = os.getenv("gamesPath")
print(RE3)
debugger:lldb.SBDebugger = lldb.SBDebugger().Create()
target:lldb.SBTarget = debugger.CreateTarget("")
error = lldb.SBError()
process:lldb.SBProcess = target.AttachToProcessWithName(listener=lldb.SBListener(),wait_for=False,name=RE3,error=error)

if not error.Success():
    logger.error(f"[LLDB_INIT.py] process error access: {error.GetCString()}")
    exit()
logger.success("[LLDB_INIT.py] process success access")

