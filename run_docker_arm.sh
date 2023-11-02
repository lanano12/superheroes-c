#!/bin/bash
# If the docker image changes then this needs to be run
# docker-compose -f docker-compose.arm.yml build

# This is for running multiarch
docker run --rm --privileged multiarch/qemu-user-static --reset -p yes

# docker compose
docker-compose -f docker-compose.arm.yml up

#docker run --rm -it -v $(pwd):/var/app arm-cross-compile bash
