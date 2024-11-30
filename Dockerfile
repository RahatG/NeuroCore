# Stage 1: Builder
FROM ubuntu:22.04 AS builder

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV VCPKG_ROOT=/opt/vcpkg

# Install necessary packages and prerequisites
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    wget \
    curl \
    zip \
    unzip \
    libssl-dev \
    libcurl4-openssl-dev \
    pkg-config \
    libtool \
    python3.10 \
    python3-pip \
    gnupg \
    software-properties-common \
    autoconf \
    automake \
    autoconf-archive \
    ca-certificates \
    lsb-release \
    && rm -rf /var/lib/apt/lists/*

# Install CMake 3.24+ from precompiled binary
RUN wget https://github.com/Kitware/CMake/releases/download/v3.31.1/cmake-3.31.1-linux-x86_64.tar.gz && \
    tar -zxvf cmake-3.31.1-linux-x86_64.tar.gz && \
    mv cmake-3.31.1-linux-x86_64 /opt/cmake-3.31.1 && \
    ln -s /opt/cmake-3.31.1/bin/cmake /usr/local/bin/cmake && \
    cmake --version && \
    rm cmake-3.31.1-linux-x86_64.tar.gz

# Clone and bootstrap Vcpkg
RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg && \
    cd /opt/vcpkg && \
    git pull && \
    ./bootstrap-vcpkg.sh -disableMetrics

# Install dependencies via Vcpkg
RUN /opt/vcpkg/vcpkg install \
    boost-asio \
    boost-system \
    openssl \
    curl \
    pybind11 \
    crow \
    nlohmann-json \
    && /opt/vcpkg/vcpkg integrate install \
    && /opt/vcpkg/vcpkg list | grep boost-system

# Set the toolchain file path
ENV TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake

# Set the working directory
WORKDIR /home/rahat/NeuroCore

# Copy the CMakeLists.txt first to leverage Docker cache
COPY cpp_backend/CMakeLists.txt cpp_backend/

# Copy the source files
COPY cpp_backend/src/ cpp_backend/src/

# Build the application
RUN mkdir -p cpp_backend/build && cd cpp_backend/build \
    && cmake .. -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN_FILE \
    && make -j$(nproc)

# Stage 2: Runtime
FROM ubuntu:22.04

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libboost-system1.74.0 \
    libssl-dev \
    libcurl4 \
    python3.10 \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# Create a non-root user for better security
RUN useradd -m neurouser

# Set the working directory
WORKDIR /home/neurouser/NeuroCore

# Change ownership of the working directory
RUN mkdir -p /home/neurouser/NeuroCore && \
    chown -R neurouser:neurouser /home/neurouser/NeuroCore

# Switch to the non-root user
USER neurouser

# Copy the built executable and Python module from the builder stage
COPY --from=builder /home/rahat/NeuroCore/cpp_backend/build/main ./main

# Copy InterfaceEngine.so to Python/src/
COPY --from=builder /home/rahat/NeuroCore/cpp_backend/build/interface/InterfaceEngine.so ./Python/src/

# Copy the Python server
COPY Python/ ./Python

# Install Python dependencies as 'neurouser' and ensure PATH includes local binaries
RUN pip3 install --upgrade pip && \
    pip3 install --user -r ./Python/requirements.txt

# Add /home/neurouser/.local/bin to PATH
ENV PATH="/home/neurouser/.local/bin:${PATH}"

# Set PYTHONPATH to include the Python/src directory
ENV PYTHONPATH="/home/neurouser/NeuroCore/Python/src"

# Expose port
EXPOSE 8000

# Start the Python server using Uvicorn
CMD ["uvicorn", "main:app", "--host", "0.0.0.0", "--port", "8000", "--app-dir", "./Python/src"]