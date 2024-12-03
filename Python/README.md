# NeuroCore Python Server

This Python server provides a RESTful API for interacting with the NeuroCore AI model. It handles client requests, manages training and inference processes, and serves predictions.

## Features

- **API Endpoints**: `/predict`, `/train`, `/status`, `/upload`, `/health`
- **Authentication**: JWT-based authentication for secure access
- **NLP Processing**: Tokenization, Embeddings, Named Entity Recognition, Sentiment Analysis, POS Tagging
- **Model Training and Inference**: Interfaces with the C++ backend to train models and perform predictions
- **Dockerized Deployment**: Consistent environment setup using Docker and Docker Compose

## Setup Instructions

1. **Navigate to the Python Directory**
   ```bash
   cd NeuroCore/Python


source /home/rahat/NeuroCore/Python/.venv/bin/activate
python --version
