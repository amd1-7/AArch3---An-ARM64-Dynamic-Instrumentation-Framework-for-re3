from LLDB_INIT import lldb,process,logger
import json

thread:lldb.SBThread = process.GetSelectedThread()
frame:lldb.SBFrame = thread.GetSelectedFrame()

player:lldb.SBValue = frame.EvaluateExpression("FindPlayerPed()")
slots:lldb.SBValue = player.GetChildMemberWithName("m_weapons")

book = {}
playerPtr:lldb.SBValue = player.GetValueAsUnsigned()
for i in range(0,13):
    slot:lldb.SBValue = slots.GetChildAtIndex(i)
    slotAddr:lldb.SBValue = slot.AddressOf().GetValueAsUnsigned()

    weapon_type:lldb.SBValue = slot.GetChildMemberWithName("m_eWeaponType").AddressOf().GetValueAsUnsigned() - slotAddr
    weapon_state:lldb.SBValue = slot.GetChildMemberWithName("m_eWeaponState").AddressOf().GetValueAsUnsigned() - slotAddr
    ammo_clip:lldb.SBValue = slot.GetChildMemberWithName("m_nAmmoInClip").AddressOf().GetValueAsUnsigned() - slotAddr
    ammo_total:lldb.SBValue = slot.GetChildMemberWithName("m_nAmmoTotal").AddressOf().GetValueAsUnsigned() - slotAddr
    timer:lldb.SBValue = slot.GetChildMemberWithName("m_nTimer").AddressOf().GetValueAsUnsigned() - slotAddr
    add_rot_offset:lldb.SBValue = slot.GetChildMemberWithName("m_bAddRotOffset").AddressOf().GetValueAsUnsigned() - slotAddr

    book[f"slot {i}"] = {
        "slot" : slotAddr - playerPtr,
        "weapon_type" :weapon_type, 
        "weapon_state" : weapon_state,
        "ammo_clip" : ammo_clip,
        "ammo_total" : ammo_total,
        "timer" : timer,
        "add_rot_offset" : add_rot_offset,
        }

    offsetLastSlot = slot.AddressOf().GetValueAsUnsigned()

with open('outputScript/offset_of_slots.json','w') as f:
    json.dump(book,f,indent=4)