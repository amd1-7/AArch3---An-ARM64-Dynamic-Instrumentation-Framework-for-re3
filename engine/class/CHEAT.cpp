#include "CHEAT.hpp"
#include <spdlog/spdlog.h>
#include <mach/mach_vm.h>

mach_port_t Cheat::getTask(pid_t p){
   mach_port_t task;
   
   kern_return_t kr = task_for_pid(mach_task_self(),p,&task);
   if (kr != KERN_SUCCESS){
    spdlog::error("[CHEAT.cpp] error get task");
    task = TASK_NULL;
    return task;
    }

    spdlog::info("[CHEAT.cpp] success get task");
    return task;
}

bool Cheat::modifyValue(mach_port_t task,mach_vm_address_t addr,float newValue){
    if (task == TASK_NULL) return false;

    kern_return_t kr = mach_vm_write(task,addr,(vm_offset_t)&newValue,sizeof(newValue));
    if (kr != KERN_SUCCESS){
        spdlog::error("[CHEAT.cpp] error modify value");
        return false;
    }
    return true;
}

bool Cheat::modifyValue(mach_port_t task,mach_vm_address_t addr,int newValue){
    if (task == TASK_NULL) return false;

    kern_return_t kr = mach_vm_write(task,addr,(vm_offset_t)&newValue,sizeof(newValue));
    if (kr != KERN_SUCCESS){
        spdlog::error("[CHEAT.cpp] error modify value");
        return false;
    }
    return true;
}