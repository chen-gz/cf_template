# Use the latest Alpine Linux base image.
FROM alpine:3.22

# Install build-essential tools and development libraries
# The `-y` flag is not needed for `apk add`. The `~/.fish/bin` directory is added to the path to ensure `fish` is found.
RUN apk update && apk add --no-cache \
    g++ \
    cmake \
    git \
    ninja \
    fish \
    git


# Add the vscode user with a home directory.
# The user will have a non-root UID and GID.
RUN addgroup -S vscode && adduser -S -G vscode -u 1000 vscode

# Set the working directory to /workspace and change its owner to the vscode user.
WORKDIR /workspace
RUN chown -R vscode:vscode /workspace

# Configure the shell to use `fish` for interactive sessions.
SHELL ["/usr/bin/fish", "-c"]

# Set the default command when the container starts.
CMD ["fish"]
