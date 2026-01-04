cmake_minimum_required(VERSION 3.10)
project(cpp_devops_build_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

set(CPACK_PACKAGE_NAME "cpp-devops-demo")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "shubhamkapare95@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION "Simple package for calc executable")
set(CPACK_GENERATOR "DEB")

# Tell CPack which files to include in the package
install(TARGETS calc DESTINATION /usr/local/bin)

include(CPack)