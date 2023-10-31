#!/bin/bash
# sudo apt-get install gcc-arm-linux-gnueabi g++-arm-linux-gnueabi

folder_name="arm-build"

# Check if the folder exists
if [ ! -d "$folder_name" ]; then
    # Create the folder
    mkdir "$folder_name"
    echo "Folder created: $folder_name"
fi

cd "$folder_name"

echo "Run cmake with ARM toolchain from the build folder"
cmake -DCMAKE_TOOLCHAIN_FILE=arm-toolchain.cmake ..

echo "Run make from the build folder"
make

# Note: You won't be able to run the ARM binary on a non-ARM machine directly
# Uncomment the following if you're running this on an ARM machine
# echo "Run Program"
# ./bin/main
