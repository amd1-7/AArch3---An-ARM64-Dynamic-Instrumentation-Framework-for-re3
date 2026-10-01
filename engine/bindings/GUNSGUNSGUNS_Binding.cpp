#include "GUNSGUNSGUNS.hpp"
#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(GUNSGUNSGUNS,m){
    m.doc() = "This module give to the play every gun.";
    py::class_<GunsGunsGuns>(m,"GUNSGUNSGUNS")
        .def(py::init<std::string>(),py::arg("name"))
        .def("Activate",py::overload_cast<pid_t,mach_vm_address_t>(&GunsGunsGuns::Activate),
        py::arg("p"),
        py::arg("addrPlayer"),
        "Actiavate this module give every gun to the player."
    );
}
