#!/bin/bash

ceedling clobber gcov:all
gcovr -r . --html --html-details -o ./build/artifacts/gcov/gcovr-report.html
