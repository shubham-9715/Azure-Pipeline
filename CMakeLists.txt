cmake_minimum_required(VERSION 3.10)
project(DemoProject VERSION 1.0.0 LANGUAGES CXX)

# ------------------------------------------------------
# C++ Standard
# ------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ------------------------------------------------------
# Library
# ------------------------------------------------------
add_library(math_utils src/math_utils.cpp)

target_include_directories(math_utils
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# ------------------------------------------------------
# Main Application
# ------------------------------------------------------
add_executable(demo app/main.cpp)
target_link_libraries(demo PRIVATE math_utils)

# ------------------------------------------------------
# Tests (GoogleTest)
# ------------------------------------------------------
enable_testing()
find_package(GTest REQUIRED)

add_executable(test_math tests/test_math.cpp)
target_link_libraries(test_math
    PRIVATE
        math_utils
        GTest::gtest
        GTest::gtest_main
)

add_test(NAME MathUtilsTests COMMAND test_math)

# ------------------------------------------------------
# Install Rules
# ------------------------------------------------------
install(TARGETS math_utils
        EXPORT math_utils_targets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
)

install(TARGETS demo
        RUNTIME DESTINATION bin
)

install(DIRECTORY include/
        DESTINATION include
)

# ------------------------------------------------------
# Debian Package (CPack)
# ------------------------------------------------------
set(CPACK_PACKAGE_NAME "demo-project")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "Shubham <shubhamkapare95@gmail.com>")

set(CPACK_GENERATOR "DEB")

# Debian-specific metadata
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Shubham")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.31)")

include(CPack)
