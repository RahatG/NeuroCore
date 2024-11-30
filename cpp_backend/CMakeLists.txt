cmake_minimum_required(VERSION 3.25)
project(NeuroCore)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable debug symbols
set(CMAKE_BUILD_TYPE Debug)

# Find packages using vcpkg's toolchain
find_package(pybind11 REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenSSL REQUIRED)
find_package(CURL REQUIRED)
find_package(Threads REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Arrow CONFIG REQUIRED)
find_package(Parquet CONFIG REQUIRED)

# Define CoreLib as a static library containing all common sources
add_library(CoreLib STATIC
    src/model/NeuralNetwork.cpp
    src/model/Layers/DenseLayer.cpp
    src/model/Layers/ConvolutionLayer.cpp
    src/model/Layers/RecurrentLayer.cpp
    src/model/Layers/TransformerLayer.cpp
    src/model/Optimizers/Adam.cpp
    src/model/Optimizers/SGD.cpp
    src/model/Optimizers/RMSProp.cpp
    src/training/LossFunctions/CrossEntropyLoss.cpp
    src/training/LossFunctions/MeanSquaredLoss.cpp
    src/training/Metrics/Accuracy.cpp
    src/training/Metrics/Precision.cpp
    src/training/Metrics/Recall.cpp
    src/training/Trainer.cpp
    src/utils/Config.cpp
    src/utils/FileUtils.cpp
    src/utils/Logger.cpp
    src/data/DataLoader.cpp
    src/data/Tokenizer.cpp
    src/data/Preprocessing/TextCleaner.cpp
    src/data/Preprocessing/StopWordsRemover.cpp
    src/data/Preprocessing/Lemmatiser.cpp
    src/nlp/NLPProcessor.cpp
    src/nlp/SentimentAnalysis.cpp
    src/nlp/NamedEntityRecognition.cpp
    src/nlp/PartOfSpeechTagger.cpp
    src/model/Activation/ReLU.cpp
    src/model/Activation/Sigmoid.cpp
    src/model/Activation/Softmax.cpp
    src/model/Activation/Tanh.cpp
)

# Enable Position Independent Code for CoreLib
set_target_properties(CoreLib PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Link libraries to CoreLib
target_link_libraries(CoreLib PRIVATE
    Boost::system
    OpenSSL::SSL
    CURL::libcurl
    Threads::Threads
    nlohmann_json::nlohmann_json
    Arrow::arrow_static        # Use static Arrow library
    Parquet::parquet_static    # Use static Parquet library
)

# Specify include directories for CoreLib
target_include_directories(CoreLib PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/model
    ${CMAKE_SOURCE_DIR}/src/layers
    ${CMAKE_SOURCE_DIR}/src/interface
    ${CMAKE_SOURCE_DIR}/src/data
    ${CMAKE_SOURCE_DIR}/src/nlp
    ${CMAKE_SOURCE_DIR}/src/training
    ${CMAKE_SOURCE_DIR}/src/utils
    ${Arrow_INCLUDE_DIRS}
    ${Parquet_INCLUDE_DIRS}  # Include Parquet directories
)

# Define InterfaceEngine module linked against CoreLib
add_library(InterfaceEngine MODULE
    src/interface/InterfaceEngine.cpp
    src/interface/pybind_module.cpp
)

# Link libraries to InterfaceEngine
target_link_libraries(InterfaceEngine PRIVATE
    pybind11::module
    CoreLib
    Arrow::arrow_static        # Link Arrow static library if needed
    Parquet::parquet_static    # Link Parquet static library if needed
)

# Specify include directories for InterfaceEngine
target_include_directories(InterfaceEngine PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/model
    ${CMAKE_SOURCE_DIR}/src/layers
    ${CMAKE_SOURCE_DIR}/src/interface
    ${CMAKE_SOURCE_DIR}/src/data
    ${CMAKE_SOURCE_DIR}/src/nlp
    ${CMAKE_SOURCE_DIR}/src/training
    ${CMAKE_SOURCE_DIR}/src/utils
)

# Collect main source files excluding interface-related and CoreLib source files
file(GLOB_RECURSE MAIN_SOURCES "src/*.cpp")
# Exclude sources already included in CoreLib
list(FILTER MAIN_SOURCES EXCLUDE REGEX "src/(model|layers|training|utils|data|nlp|activation)/.*\\.cpp$")
# Exclude interface sources
list(FILTER MAIN_SOURCES EXCLUDE REGEX "src/interface/.*\\.cpp$")

# Add main executable
add_executable(main src/main.cpp)

# Link libraries to main
target_link_libraries(main PRIVATE
    pybind11::embed
    CoreLib
    Arrow::arrow_static        # Link Arrow static library if needed
    Parquet::parquet_static    # Link Parquet static library if needed
)

# Enable compiler warnings for all targets
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(CoreLib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(InterfaceEngine PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Specify C++ standard features
target_compile_features(CoreLib PUBLIC cxx_std_17)
target_compile_features(InterfaceEngine PRIVATE cxx_std_17)
target_compile_features(main PRIVATE cxx_std_17)

# Set output directory for InterfaceEngine
set_target_properties(InterfaceEngine PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/interface
    PREFIX ""
    SUFFIX ".so"
)

# Optional: Install rule for InterfaceEngine
install(TARGETS InterfaceEngine DESTINATION ${CMAKE_BINARY_DIR}/interface)
