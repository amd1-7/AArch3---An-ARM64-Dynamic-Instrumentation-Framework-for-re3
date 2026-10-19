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

template <typename T>
bool Cheat::readValue(mach_port_t task,mach_vm_address_t addr,T& valueOutput){
    mach_vm_size_t size = sizeof(T);
    mach_vm_size_t bytesRead = 0;

    kern_return_t kr = mach_vm_read_overwrite(task,addr,size,reinterpret_cast<mach_vm_address_t>(&valueOutput),&bytesRead);

    if(kr == KERN_SUCCESS && bytesRead == size){
        spdlog::info("[CHEAT.cpp] success of read value");
        return true;
    }
    spdlog::error("[CHEAT.cpp] error of read value");
    return false;
}

template bool Cheat::readValue<int>(mach_port_t, mach_vm_address_t, int&);
template bool Cheat::readValue<float>(mach_port_t, mach_vm_address_t, float&);
template bool Cheat::readValue<double>(mach_port_t, mach_vm_address_t, double&);
template bool Cheat::readValue<uint64_t>(mach_port_t, mach_vm_address_t, uint64_t&);
template bool Cheat::readValue<std::string>(mach_port_t, mach_vm_address_t, std::string&);