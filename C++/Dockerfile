# C++ Backend Dockerfile
FROM ubuntu:20.04
LABEL authors="Rahat"

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install prerequisites and add Kitware's APT repository for newer CMake
RUN apt-get update && apt-get install -y \
    software-properties-common \
    wget \
    gnupg \
    lsb-release \
    # Enable the 'universe' repository
    && add-apt-repository universe \
    # Add Kitware's APT repository for newer CMake
    && wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc | apt-key add - \
    && add-apt-repository 'deb https://apt.kitware.com/ubuntu/ focal main' \
    # Update package lists and install required packages
    && apt-get update && apt-get install -y \
        cmake \
        build-essential \
        git \
        libboost-all-dev \
        libssl-dev \
        libcurl4-openssl-dev \
        libasio-dev \
        libpybind11-dev \
    # Clean up to reduce image size
    && rm -rf /var/lib/apt/lists/*

# Install Crow (a C++ REST SDK)
RUN git clone https://github.com/CrowCpp/Crow.git /opt/Crow \
    && mkdir /opt/Crow/build \
    && cd /opt/Crow/build \
    && cmake .. \
    && make \
    && make install

# Set working directory
WORKDIR /usr/src/app

# Copy C++ Backend source code and CMakeLists.txt
COPY src/ ./src
COPY CMakeLists.txt ./

# Build the C++ application
RUN mkdir build && cd build \
    && cmake .. \
    && make

# Expose the port (e.g., 8080)
EXPOSE 8080

# Set environment variables for data paths
ENV TRAIN_DATA_PATH="/mnt/data/train.parquet"
ENV MODEL_OUTPUT_PATH="/mnt/model"

# Run the C++ application
CMD ["./build/main"]
