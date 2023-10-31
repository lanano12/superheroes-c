project(Program)

# Create executable
add_executable(main main.c)

# Set the directory for the executables
set_target_properties(main  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Export include files for both
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR})

