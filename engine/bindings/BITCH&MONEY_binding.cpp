#include "BITCH&MONEY.hpp"
#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(BITCHANDMONEY,m){
    m.doc() = "This module give to player 250k dollars.";
    py::class_<BitchAndMoney>(m,"BITCHANDMONEY")
        .def(py::init<std::string>(),py::arg("name"))
        .def("Activate",py::overload_cast<pid_t,mach_vm_address_t>(&BitchAndMoney::Activate),
        py::arg("pid"),
        py::arg("addrPlayerInfo"),
        "Activate this module give to player 250k dollars."
        );
}