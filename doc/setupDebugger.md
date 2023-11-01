# Setting Up VSCode for C/C++ Development on Ubuntu

Setting up VSCode for Make and CMake on Ubuntu using GCC for compiling and GDB for debugging is a fairly common and well-supported configuration. Here's a step-by-step guide to help you set up your environment:

## 1. Prerequisites

Make sure you have the required tools installed:

\```bash
sudo apt update
sudo apt install -y gcc g++ gdb make cmake
\```

## 2. Install Necessary Extensions in VSCode

- **C/C++ by Microsoft**: This provides IntelliSense, debugging, and code navigation capabilities for C/C++ development.
- **CMake Tools by Microsoft**: This helps in configuring, building, and debugging CMake projects in VSCode.

### Installation Steps:
1. Open VSCode.
2. Go to the Extensions view by clicking on the square icon on the sidebar or pressing `Ctrl + Shift + X`.
3. Search for the extensions mentioned above and install them.

## 3. Configure C/C++ Extension

After installing the C/C++ extension:
1. Open the command palette with `Ctrl + Shift + P`.
2. Type “C/C++” and select “Edit Configurations (UI)”.
3. Make sure the compiler path points to GCC. It typically would be `/usr/bin/gcc`.
4. Set the `intelliSenseMode` to `gcc-x64`.
5. Debugger should automatically choose `gdb` for debugging on Linux.

## 4. Set Up CMake Tools

After installing the CMake Tools extension:
1. Open a folder where you want your project to reside.
2. In the root of your project, you'd typically have a `CMakeLists.txt` file.
3. Press `Ctrl + Shift + P` to open the command palette.
4. Type “CMake” and select “CMake: Configure”. This will prompt you to select a kit. Choose the one that corresponds to GCC. It'll typically look like `GCC for x86_64-linux-gnu`.
5. Once configured, you can build the project by selecting “CMake: Build” from the command palette.

## 5. Debugging

With the C/C++ extension and CMake Tools installed:
1. Go to the Debug view by clicking on the bug icon on the sidebar.
2. Click on the gear icon and choose `C++ (GDB/LLDB)`.
3. It will generate a `launch.json` file. Ensure the following:
    - `"request"` is set to `"launch"`.
    - `"program"` points to the path of your built executable.
    - `"miDebuggerPath"` points to the path of GDB (`/usr/bin/gdb`).

Now, you can set breakpoints in your code by clicking on the left margin next to the line numbers. To start debugging, click on the green arrow at the top of the Debug view.

## Final Notes:

- If you're working with Make specifically (without CMake), then your build process would revolve around running Make commands from VSCode's terminal. The debugging setup remains the same.
- Remember to frequently consult the documentation or settings of the extensions if you encounter issues or need advanced configurations. VSCode's ecosystem is continuously evolving, and newer features or changes can enhance your development experience.
