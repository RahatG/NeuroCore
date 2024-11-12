FROM python:3.8-slim

# Install system dependencies
RUN apt-get update && apt-get install -y build-essential cmake && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /home/rahat/NeuroCore

# Copy C++ Backend
COPY C++\ Backend/C++\ Backend ./C++\ Backend

# Build C++ Backend
RUN mkdir -p ./C++\ Backend/build && \
    cd ./C++\ Backend/build && \
    cmake .. && \
    make -j$(nproc)

# Copy Python Server
COPY Python/Python ./Python

# Install Python dependencies
RUN pip install --upgrade pip
RUN pip install -r ./Python/requirements.txt

# Expose port
EXPOSE 8000

# Start the Python server
CMD ["python", "./Python/src/main.py"]
