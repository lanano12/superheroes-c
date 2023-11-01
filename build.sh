#!/bin/bash

folder_name="build"

rm -f CMakeCache.txt

# If the folder exists, delete it
if [ -d "$folder_name" ]; then
    sudo rm -rf "$folder_name"
    echo "Folder deleted: $folder_name"
fi

# Create the folder
mkdir "$folder_name"
echo "Folder created: $folder_name"

cd build

echo "Run cmake from the build folder"
cmake ..

echo "Run make from the build folder"
make

echo "Run Program"
if [ -f ./bin/main ]; then
    echo "Run Program"
    ./bin/main ../input/dc_battles.csv
else
    echo "Error: Binary not found!"
fi

