FROM ubuntu:24.04

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    vim \
    git \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /workspace

# Install C++ extensions for Visual Studio Code
RUN apt-get update && apt-get install -y \
    code \
    && rm -rf /var/lib/apt/lists/*

# Clean up
RUN apt-get clean && apt-get autoremove -y

# Set the default command
CMD ["bash"]