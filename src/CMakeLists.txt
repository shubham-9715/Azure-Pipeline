add_library(calc_lib
    calculator.cpp
)

# Include the root include directory
target_include_directories(calc_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(calc
    main.cpp
)

target_link_libraries(calc calc_lib)
