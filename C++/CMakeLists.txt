cmake_minimum_required(VERSION 3.21)
project(NeuroCore)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# Find pybind11
find_package(pybind11 REQUIRED)

# Find Crow
find_package(Crow REQUIRED)

# Include directories
include_directories(src)

# Add source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Add pybind11 module
pybind11_add_module(InterfaceEngine src/interface/pybind_module.cpp ${SOURCES})

# Link libraries
target_link_libraries(InterfaceEngine PRIVATE Crow::Crow)
