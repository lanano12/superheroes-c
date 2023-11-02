#!/bin/bash
# sudo apt-get install gcc-arm-linux-gnueabi g++-arm-linux-gnueabi qemu-user-static

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

echo "Run ARM target using QEMU"
export LD_LIBRARY_PATH=/usr/arm-linux-gnueabi/lib:$LD_LIBRARY_PATH
patchelf --set-interpreter /usr/arm-linux-gnueabi/lib/ld-linux.so.3 ./bin/main
qemu-arm-static ./bin/main ../input/dc_battles.csv
