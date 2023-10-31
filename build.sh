#!/bin/bash

folder_name="build"

# Check if the folder exists
if [ ! -d "$folder_name" ]; then
    # Create the folder
    mkdir "$folder_name"
    echo "Folder created: $folder_name"
fi

cd build

echo "Run cmake from the build folder"
cmake ..

echo "Run make from the build folder"
make

echo "Run Program"
./bin/main
