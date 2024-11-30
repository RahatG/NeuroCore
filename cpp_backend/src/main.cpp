#include "interface/InterfaceEngine.h"
#include <pybind11/embed.h>

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{};
    py::module::import("InterfaceEngine"); // Correct module name
    return 0;
}
