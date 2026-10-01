#include "TORTOISE.hpp"

bool Tortoise::Activate(pid_t p,mach_vm_address_t addrPlayer){
    mach_port_t task = this->getTask(p);
    if (task == TASK_NULL) return false;

    mach_vm_address_t ArmourAddress = addrPlayer + static_cast<mach_vm_address_t>(924);
    bool kr = this->modifyValue(task,ArmourAddress,100.f);
    mach_port_deallocate(mach_task_self(),task);
    return kr;
}