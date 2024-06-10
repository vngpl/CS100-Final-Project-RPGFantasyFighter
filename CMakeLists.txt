cmake_minimum_required(VERSION 3.2)

project(final_project)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(header)

# Gather all source files automatically
file(GLOB SOURCES "src/*.cpp")

# Exclude from the SOURCES list
list(FILTER SOURCES EXCLUDE REGEX "src/Shop.cpp")

# Add executable for the project
add_executable(final_proj ${SOURCES} header/Display.hpp)
