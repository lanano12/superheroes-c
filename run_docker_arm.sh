#!/bin/bash
# docker-compose -f docker-compose.arm.yml build
docker-compose -f docker-compose.arm.yml up
#docker run --rm -it -v $(pwd):/var/app arm-cross-compile bash
