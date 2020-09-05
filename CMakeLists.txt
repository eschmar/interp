cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Interpolator)

set(CMAKE_BUILD_TYPE Debug)

# specify the c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the library
add_subdirectory(src)

# add the executable
add_executable(example example.cpp)

# add plotting dependencies
find_package(Python COMPONENTS Development NumPy)
target_include_directories(example PRIVATE ${Python_INCLUDE_DIRS} ${Python_NumPy_INCLUDE_DIRS} "matplotlib-cpp")

# link libs
target_link_libraries(example PUBLIC Interpolator Python::Python Python::NumPy)

# add the binary tree to the search path for include files
target_include_directories(example PUBLIC "${PROJECT_BINARY_DIR}")

# adds `make install` task
install(TARGETS example DESTINATION bin)
