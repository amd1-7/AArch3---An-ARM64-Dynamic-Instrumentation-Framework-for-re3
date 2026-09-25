from LLDB_INIT import lldb,process,logger
import json

thread:lldb.SBThread = process.GetSelectedThread()
frame:lldb.SBFrame = thread.GetSelectedFrame()

player:lldb.SBValue = frame.EvaluateExpression("FindPlayerPed()")
playerPtr:lldb.SBValue = player.GetValueAsUnsigned()
health:lldb.SBValue = player.GetChildMemberWithName("m_fHealth")
armour:lldb.SBValue = player.GetChildMemberWithName("m_fArmour")

offsetHealth = health.AddressOf().GetValueAsUnsigned() - playerPtr 
offsetArmour = armour.AddressOf().GetValueAsUnsigned() - playerPtr 

book = {
    "m_fHealth" :offsetHealth,
    "m_fArmour" : offsetArmour
    }
with open('./outputScript/offset_of_health_armour.json','w') as f:
    json.dump(book,f,indent=4)
