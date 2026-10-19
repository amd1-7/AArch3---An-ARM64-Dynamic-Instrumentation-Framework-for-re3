from LLDB_INIT import lldb, process, logger
import json

thread = process.GetSelectedThread()
frame = thread.GetSelectedFrame()

playerInfo = frame.EvaluateExpression("CWorld::Players[0]")
playerInfoPtr = playerInfo.AddressOf().GetValueAsUnsigned()

money = playerInfo.GetChildMemberWithName("m_nMoney")
moneyPtr = money.AddressOf().GetValueAsUnsigned()

moneyVisible = playerInfo.GetChildMemberWithName("m_nVisibleMoney")
moneyVisiblePtr = moneyVisible.AddressOf().GetValueAsUnsigned()

offsetMoneyInInfo = moneyPtr - playerInfoPtr 
offsetMoneyVisibleInInfo = moneyVisiblePtr - playerInfoPtr 
book = {
    "m_nMoney_offset": offsetMoneyInInfo,
    "m_nMoney_Visible_offset": offsetMoneyVisibleInInfo
}

with open("outputScript/offset_of_money.json", "w") as f:
    json.dump(book, f, indent=4)