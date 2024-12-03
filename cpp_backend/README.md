# NeuroCore C++ Backend

NeuroCore is a C++ backend for the AI project, handling data preprocessing, neural network operations, training, and NLP tasks. It interfaces with the Python server using `pybind11` to facilitate seamless communication.

## Features

- Data Loading and Preprocessing
- Neural Network Architecture with Dense, Convolutional, Recurrent, and Transformer Layers
- Activation Functions: ReLU, Sigmoid, Softmax, Tanh
- Optimizers: SGD, Adam, RMSProp
- Training Loop with Loss Functions and Metrics
- NLP Processing: Tokenization, Stop Words Removal, Lemmatization, Named Entity Recognition, Sentiment Analysis, POS Tagging

## Setup Instructions

1. **Clone the Repository**
   ```bash
   git clone https://github.com/yourusername/NeuroCore.git
2. **Build Docker Image**
   ```bash
   docker build -t neurocore:latest .
3. **Run Docker Container**
   ```bash
   docker run --rm neurocore:latest

## Future
1. **Google Test**

## Run
cd ~/NeuroCore/cpp_backend
rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/home/rahat/vcpkg/scripts/buildsystems/vcpkg.cmake
make -j$(nproc)
cp interface/InterfaceEngine.so /home/rahat/NeuroCore/Python/.venv/lib/python3.12/site-packages/
