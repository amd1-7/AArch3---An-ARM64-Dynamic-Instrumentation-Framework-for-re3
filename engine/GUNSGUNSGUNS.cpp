#include "GUNSGUNSGUNS.hpp"
#include "spdlog/spdlog.h"

bool GunsGunsGuns::Activate(pid_t p, mach_vm_address_t addrPlayer) {
    mach_port_t task = this->getTask(p);
    if (task == TASK_NULL) {
        spdlog::error("[GUNSGUNSGUNS.cpp] error task access");
        return false;
    }

    bool krType = true;
    bool krState = true;
    bool krClip = true;
    bool krAmmoT = true;
    bool krTimer = true;

    mach_vm_address_t slotRealAddr = addrPlayer + this->OffsetSlot0;

    for (int i = 0; i <= 12; i++) {
        krType  &= this->modifyValue(task, slotRealAddr + static_cast<mach_vm_address_t>(OffsetVariable::Weapontype), i);
        krState &= this->modifyValue(task, slotRealAddr + static_cast<mach_vm_address_t>(OffsetVariable::WeaponState), 1);
        krClip  &= this->modifyValue(task, slotRealAddr + static_cast<mach_vm_address_t>(OffsetVariable::AmmoClip), 999999);
        krAmmoT &= this->modifyValue(task, slotRealAddr + static_cast<mach_vm_address_t>(OffsetVariable::AmmoTotal), 999999);
        krTimer &= this->modifyValue(task, slotRealAddr + static_cast<mach_vm_address_t>(OffsetVariable::Timer), 0);

        slotRealAddr += 24;
    }

    mach_port_deallocate(mach_task_self(), task);
    return (krType && krState && krClip && krAmmoT && krTimer);
}