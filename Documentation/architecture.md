
### **Documentation/architecture.md**

```markdown
# System Architecture

## Overview

NeuroCore is composed of two main components:

1. **C++ Backend**: Handles data preprocessing, neural network operations, training, and NLP tasks.
2. **Python Server**: Provides a RESTful API for interacting with the AI model, handling client requests, and serving predictions.

## Components Interaction

1. **Data Flow**:
    - Data is loaded from the specified dataset path using the `DataLoader`.
    - Preprocessing steps are performed using `TextCleaner`, `StopWordsRemover`, and `Lemmatiser`.
    - Tokenization is handled by the `Tokenizer`.
    - Embeddings are loaded using `WordEmbeddings`.
    - The processed data is fed into the `NeuralNetwork` for training or inference.

2. **Training Process**:
    - The Python server sends a training request to the C++ backend via the `Trainer`.
    - The `Trainer` orchestrates the training loop, computes loss using `LossFunction`, and evaluates metrics using `Metric`.
    - Optimizers update the model parameters accordingly.

3. **Inference Process**:
    - The Python server receives a prediction request.
    - The `InterfaceEngine` in the C++ backend processes the input text using `NLPProcessor`.
    - The processed input is passed through the `NeuralNetwork` to obtain predictions.
    - Predictions are returned to the Python server and sent back to the client.

4. **NLP Tasks**:
    - NLP-specific tasks such as Named Entity Recognition (NER), Sentiment Analysis, and Part-of-Speech (POS) Tagging are handled by their respective classes in the C++ backend.
    - These tasks enhance the model's understanding and processing of input text.

## Communication

- **Pybind11**: The C++ backend is exposed to the Python server using `pybind11`, allowing direct invocation of C++ classes and methods from Python.
- **Docker**: Both C++ and Python components are containerized, ensuring a consistent environment across development and production.

## Data Paths

- **Input Data**: `E:\AI Model\arxiver\data\train.parquet`
- **Model Output**: `E:\AI Model\model`

## Logging

- Both C++ and Python components utilize logging configurations specified in `logging.conf` to track operations, errors, and performance metrics.

## Deployment

- Docker is used to build and deploy the entire system.
- Deployment scripts automate the setup and launch processes.
