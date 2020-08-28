cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(interp VERSION 0.1.0)

add_library(interp interp.cpp)
# set_target_properties(interp PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(interp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# adds `make install` task
install(TARGETS interp DESTINATION lib)
install(FILES interp.h DESTINATION include)
