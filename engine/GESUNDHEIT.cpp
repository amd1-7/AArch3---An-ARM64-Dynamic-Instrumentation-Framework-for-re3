#include "GESUNDHEIT.hpp"
#include <spdlog/spdlog.h>
#include <pybind11/pybind11.h>
namespace py = pybind11;

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

PYBIND11_MODULE(GESUNDHEIT,m){
    m.doc() = "This module restore player's health value.";
    py::class_<GesundHeit>(m,"GESUNDHEIT")
        .def(py::init<std::string>(),py::arg("name"))
        .def("Activate",py::overload_cast<pid_t,mach_vm_address_t>(&GesundHeit::Activate),
        py::arg("pid"),
        py::arg("addrPlayer"),
        "Activate this module restore the player's health value."
        );
}
