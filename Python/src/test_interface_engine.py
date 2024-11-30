from setuptools import setup, Extension
import pybind11
from setuptools.command.build_ext import build_ext

class get_pybind_include(object):
    """Helper class to determine the pybind11 include path."""
    def __str__(self):
        return pybind11.get_include()

ext_modules = [
    Extension(
        'InterfaceEngine',
        [
            'src/interface/pybind_module.cpp',
            'src/interface/InterfaceEngine.cpp',
            'src/model/NeuralNetwork.cpp',
            'src/model/Layers/DenseLayer.cpp',
            'src/model/Layers/ConvolutionLayer.cpp',
            'src/model/Layers/RecurrentLayer.cpp',
            'src/model/Layers/TransformerLayer.cpp',
            'src/model/Optimizers/Adam.cpp',
            'src/model/Optimizers/SGD.cpp',
            'src/model/Optimizers/RMSProp.cpp',
            'src/training/LossFunctions/CrossEntropyLoss.cpp',
            'src/training/LossFunctions/MeanSquaredLoss.cpp',
            'src/training/Metrics/Accuracy.cpp',
            'src/training/Metrics/Precision.cpp',
            'src/training/Metrics/Recall.cpp',
            'src/utils/Logger.cpp',
            'src/data/DataLoader.cpp',
            'src/data/Tokenizer.cpp',
            'src/data/Preprocessing/TextCleaner.cpp',
            'src/data/Preprocessing/StopWordsRemover.cpp',
            'src/data/Preprocessing/Lemmatiser.cpp',
            'src/nlp/NLPProcessor.cpp',  # Ensure inclusion
        ],
        include_dirs=[
            get_pybind_include(),
            # Add other include directories if necessary
        ],
        language='c++',
        extra_compile_args=['-O3'],
    ),
]

setup(
    name='InterfaceEngine',
    version='0.1',
    author='Your Name',
    author_email='your.email@example.com',
    description='Pybind11 Interface for C++ Backend',
    ext_modules=ext_modules,
    install_requires=['pybind11'],
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
)


