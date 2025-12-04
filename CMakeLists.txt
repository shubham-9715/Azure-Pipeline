cmake_minimum_required(VERSION 3.10)
project(DemoProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Build the main application
add_executable(demo src/main.cpp src/math_utils.cpp)

# Build tests
add_executable(test_math tests/test_math.cpp src/math_utils.cpp)

enable_testing()
add_test(NAME MathTest COMMAND test_math)
