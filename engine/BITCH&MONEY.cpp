#include "BITCH&MONEY.hpp"
#include <spdlog/spdlog.h>

bool BitchAndMoney::Activate(pid_t p,mach_vm_address_t addrPlayerInfo){
    mach_port_t task = this->getTask(p);
    if(task == TASK_NULL) return false;

    mach_vm_address_t addrMoney = addrPlayerInfo + static_cast<mach_vm_address_t>(208);
    mach_vm_address_t addrMoneyDisplay = addrPlayerInfo + static_cast<mach_vm_address_t>(212);

    bool modifyMoney = this->modifyValue(task,addrMoney,250000);
    bool modifyMoneyDisplay = this->modifyValue(task,addrMoneyDisplay,250000);

    mach_port_deallocate(mach_task_self(),task);

    if(modifyMoney && modifyMoneyDisplay) return true;

    spdlog::info("[BITCH&MONEY.cpp] error modify value...");
}