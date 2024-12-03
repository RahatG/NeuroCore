# setup.py
from setuptools import setup, Extension
import pybind11
from setuptools.command.build_ext import build_ext

class get_pybind_include(object):
    """Helper class to determine the pybind11 include path
    The purpose of this class is to postpone importing pybind11
    until it is actually installed, so that the `get_include()`
    method can be invoked."""

    def __str__(self):
        return pybind11.get_include()

ext_modules = [
    Extension(
        'InterfaceEngine',
        [
            'src/interface/InterfaceEngine.cpp', 
            'src/model/Layers/DenseLayer.cpp',
            'src/model/NeuralNetwork.cpp',
            # Add other C++ source files as needed
        ],
        include_dirs=[
            get_pybind_include(),
            # Add other include directories if necessary
        ],
        language='c++',
        extra_compile_args=['-std=c++14'],
    ),
]

setup(
    name='InterfaceEngine',
    version='0.1',
    author='Rahat',
    description='InterfaceEngine Python bindings',
    ext_modules=ext_modules,
    install_requires=['pybind11>=2.5.0'],
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
)
