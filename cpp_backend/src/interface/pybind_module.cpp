// src/interface/pybind_module.cpp

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  // Enable automatic conversion for STL containers
#include "InterfaceEngine.h"
#include "data/DataLoader.h"

namespace py = pybind11;

PYBIND11_MODULE(InterfaceEngine, m) {
    m.doc() = "InterfaceEngine Python bindings";

    // Register custom exceptions
    py::register_exception<std::invalid_argument>(m, "InvalidArgumentError");
    py::register_exception<std::runtime_error>(m, "RuntimeError");

    // Expose DataLoader
    py::class_<DataLoader>(m, "DataLoader")
        .def(py::init<const std::string&>(), py::arg("data_path"))
        .def("load_data", &DataLoader::load_data);

    // Expose InterfaceEngine
    py::class_<InterfaceEngine>(m, "InterfaceEngine")
        .def(py::init<const std::string&, const std::string&>(),
             py::arg("data_path"),
             py::arg("model_output_path"))
        .def("predict", &InterfaceEngine::predict)
        .def("train", &InterfaceEngine::train);
}
