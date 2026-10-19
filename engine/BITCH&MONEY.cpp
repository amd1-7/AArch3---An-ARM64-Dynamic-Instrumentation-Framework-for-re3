#include "BITCH&MONEY.hpp"
#include <spdlog/spdlog.h>

bool BitchAndMoney::Activate(pid_t p,mach_vm_address_t addrPlayerInfo){
    mach_port_t task = this->getTask(p);
    if(task == TASK_NULL) return false;

    mach_vm_address_t addrMoney = addrPlayerInfo + static_cast<mach_vm_address_t>(208);
    mach_vm_address_t addrMoneyDisplay = addrPlayerInfo + static_cast<mach_vm_address_t>(212);

    int money = 0;
    bool readMoneyValue = this->readValue(task,addrMoney,money);

    if(!readMoneyValue)return false;
    money += 250000;
    if(money < 0) money = 2147483647;

    bool modifyMoney = this->modifyValue(task,addrMoney,money);
    bool modifyMoneyDisplay = this->modifyValue(task,addrMoneyDisplay,money);

    mach_port_deallocate(mach_task_self(),task);

    if(modifyMoney && modifyMoneyDisplay) return true;

    spdlog::info("[BITCH&MONEY.cpp] error modify value...");
    return false;
}