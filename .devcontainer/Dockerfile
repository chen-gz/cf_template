# 使用 Debian Bookworm 作为基础镜像
FROM debian:bookworm

# 安装必要工具和依赖
RUN apt-get update && apt-get install -y \
    curl \
    build-essential \
    git \
    sudo \
    gcc \
    gdb \
    && rm -rf /var/lib/apt/lists/*

# Install Bazel
RUN apt-get update && apt-get install -y gnupg && \
    curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor -o /usr/share/keyrings/bazel-archive-keyring.gpg && \
    echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] http://storage.googleapis.com/bazel-apt stable jdk1.8" > /etc/apt/sources.list.d/bazel.list && \
    apt-get update && \
    apt-get install -y bazel && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*


# 创建 vscode 用户
RUN groupadd --gid 1000 vscode \
    && useradd --uid 1000 --gid vscode --shell /bin/bash --create-home vscode \
    && echo 'vscode ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

# 切换到 vscode 用户
USER vscode
WORKDIR /home/vscode
