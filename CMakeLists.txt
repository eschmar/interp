cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(interp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the MathFunctions library
add_subdirectory(src)

# add the executable
add_executable(example example.cpp)

target_link_libraries(example PUBLIC interp)

# add the binary tree to the search path for include files
target_include_directories(example PUBLIC "${PROJECT_BINARY_DIR}")

# adds `make install` task
install(TARGETS example DESTINATION bin)
