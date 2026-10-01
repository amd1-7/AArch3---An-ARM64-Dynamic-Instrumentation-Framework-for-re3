#include "GESUNDHEIT.hpp"
#include <pybind11/pybind11.h>
namespace py = pybind11;

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