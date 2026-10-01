#include "GESUNDHEIT.hpp"
#include <spdlog/spdlog.h>

bool GesundHeit::Activate(pid_t p,mach_vm_address_t addrPlayer){
    mach_port_t task = this->getTask(p);
    if(task == TASK_NULL) return false;

    mach_vm_address_t HealthAdress = addrPlayer + static_cast<mach_vm_address_t>(920);

    bool kr = this->modifyValue(task,HealthAdress,250.0f);
    if (!kr){
        spdlog::error("[GESUNDHEIT.cpp] error modify value");
    }
    return kr;
}
