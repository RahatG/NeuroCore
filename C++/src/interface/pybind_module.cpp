#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "InterfaceEngine.h"

namespace py = pybind11;

PYBIND11_MODULE(InterfaceEngine, m) {
    py::class_<InterfaceEngine>(m, "InterfaceEngine")
        .def(py::init<const std::string&, const std::string&>())
        .def("predict", &InterfaceEngine::predict)
        .def("train", &InterfaceEngine::train);
}
