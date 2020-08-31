cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(interp)

set(CMAKE_BUILD_TYPE Debug)

# specify the c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the library
add_subdirectory(src)

# add the executable
add_executable(example example.cpp)

target_link_libraries(example PUBLIC interp)

# add the binary tree to the search path for include files
target_include_directories(example PUBLIC "${PROJECT_BINARY_DIR}")

# adds `make install` task
install(TARGETS example DESTINATION bin)
