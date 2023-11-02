# Cross-compile stage
FROM ubuntu:20.04 AS arm-cross-compile

RUN apt-get update && \
    apt-get install -y \
    gcc-arm-linux-gnueabi \
    g++-arm-linux-gnueabi \
    cmake \
    make \
    patchelf \
    qemu-user-static && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /var/app

# Run Stage
FROM arm32v7/ubuntu:20.04 AS runner

RUN apt-get update && \
    apt-get install -y qemu-user-static libc6-armhf-cross patchelf && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /var/app
