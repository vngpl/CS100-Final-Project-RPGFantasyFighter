cmake_minimum_required(VERSION 3.20)
project(final_project)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/header)
include_directories(${CMAKE_SOURCE_DIR}/test)
include_directories(${CMAKE_SOURCE_DIR}/googletest/include/)
# include_directories(${CMAKE_SOURCE_DIR}/googlemock/include/)

# Gather all source files automatically
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

# Add Google Test as a subdirectory
add_subdirectory(googletest)

# Add executable for the main project
add_executable(final_proj ${SOURCES})
target_compile_options(final_proj PRIVATE -Wall -Wuninitialized -Werror)

# Add executable for tests
add_executable(test_runner ${TEST_SOURCES})
target_compile_options(test_runner PRIVATE -Wall -Wuninitialized -Werror)

# Link Google Test libraries and other required libraries for the test_runner target
target_link_libraries(test_runner gtest_main)

# Link other libraries to the main project if needed
# For example: target_link_libraries(final_proj some_other_library)

# Run clang-format on all source files
add_custom_command(
    TARGET final_proj test_runner
    PRE_BUILD
    COMMAND clang-format -i ${SOURCES} ${TEST_SOURCES}
    COMMENT "Running clang-format on source files"
)
