# Use an Ubuntu base image
FROM ubuntu:20.04

# Install the necessary tools
RUN apt-get update && \
    apt-get install -y \
    qemu-system-arm qemu-user \
    gcc-arm-linux-gnueabi \
    g++-arm-linux-gnueabi \
    cmake \
    make && \
    rm -rf /var/lib/apt/lists/*
