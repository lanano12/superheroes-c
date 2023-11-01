#!/bin/bash

# This command enables your Docker environment to build and run containers of different architectures.
docker run --rm --privileged multiarch/qemu-user-static --reset -p yes

docker build -t arm-cross-compile .