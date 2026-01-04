include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(calc_unittests unittest/test_calculator.cpp)
target_link_libraries(calc_unittests gtest_main calc_lib)
enable_testing()
add_test(NAME calc_unittests COMMAND calc_unittests)
