cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(interp)

set(CMAKE_BUILD_TYPE Debug)

# specify the c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the library
add_subdirectory(src)

# add dependencies
# set(CPM_DOWNLOAD_VERSION 0.27.3)

# if(CPM_SOURCE_CACHE)
#   set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
# elseif(DEFINED ENV{CPM_SOURCE_CACHE})
#   set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
# else()
#   set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
# endif()

# if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
#   message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
#   file(DOWNLOAD
#        https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
#        ${CPM_DOWNLOAD_LOCATION}
#   )
# endif()

# include(${CPM_DOWNLOAD_LOCATION})

# CPMAddPackage(
#     NAME matplotplusplus
#     GITHUB_REPOSITORY alandefreitas/matplotplusplus
#     GIT_TAG master
# )

# add the executable
add_executable(example example.cpp)

target_link_libraries(example PUBLIC interp)

# add the binary tree to the search path for include files
target_include_directories(example PUBLIC "${PROJECT_BINARY_DIR}")

# adds `make install` task
install(TARGETS example DESTINATION bin)
