#include "TORTOISE.hpp"
#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(TORTOISE,m){
    m.doc() = "This module give you the most armour possible(100)";

    py::class_<Tortoise>(m,"TORTOISE")
        .def(py::init<std::string>(),py::arg("name"))
        .def("Activate",
            py::overload_cast<pid_t,mach_vm_address_t>(&Tortoise::Activate),
            py::arg("pid"),
            py::arg("addrPlayer"),
            "Activate this module give you 100 value of armour"
        );
}
