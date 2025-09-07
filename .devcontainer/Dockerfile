# 使用 Debian Bookworm 作为基础镜像
FROM debian:bookworm

# 安装必要工具和依赖
RUN apt-get update && apt-get install -y \
    curl \
    build-essential \
    git \
    sudo \
    gcc \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# USER root
# RUN chsh -s /usr/bin/fish vscode

# Switch back to the non-root user for the rest of the build and runtime
# USER vscode