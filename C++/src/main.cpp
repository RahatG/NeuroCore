#include "interface/InterfaceEngine.h"
#include <pybind11/embed.h>

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{};
    py::module::import("PythonModule"); // Import the Python bindings
    return 0;
}
