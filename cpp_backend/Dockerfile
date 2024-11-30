# Stage 1: Builder
FROM ubuntu:22.04 AS builder

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV VCPKG_ROOT=/opt/vcpkg

# Install necessary packages and prerequisites for adding new repositories
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
RUN wget https://github.com/Kitware/CMake/releases/download/v3.24.3/cmake-3.24.3-linux-x86_64.tar.gz && \
    tar -zxvf cmake-3.24.3-linux-x86_64.tar.gz && \
    mv cmake-3.24.3-linux-x86_64 /opt/cmake-3.24.3 && \
    ln -s /opt/cmake-3.24.3/bin/cmake /usr/local/bin/cmake && \
    cmake --version

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
FROM python:3.10-slim-bullseye

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libboost-system1.74.0 \
    libssl1.1 \
    libcurl4 \
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
COPY --from=builder /home/rahat/NeuroCore/cpp_backend/build/interface/InterfaceEngine.so /usr/local/lib/python3.10/site-packages/

# Copy the Python server
COPY Python/ ./Python

# Install Python dependencies as 'neurouser' and ensure PATH includes local binaries
RUN pip install --upgrade pip && \
    pip install --user -r ./Python/requirements.txt

# Add /home/neurouser/.local/bin to PATH
ENV PATH="/home/neurouser/.local/bin:${PATH}"

# Set PYTHONPATH to include the Python directory
ENV PYTHONPATH="/home/neurouser/NeuroCore/Python:${PYTHONPATH}"

# Expose port
EXPOSE 8000

# Start the Python server using Uvicorn
CMD ["uvicorn", "src.main:app", "--host", "0.0.0.0", "--port", "8000"]
