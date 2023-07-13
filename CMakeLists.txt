cmake_minimum_required(VERSION 3.20)


project(scode)

option(SCODE_BUILD_EXAMPLES "Build Examples" OFF)
option(SCODE_BUILD_TESTS "Build Tests" OFF)

add_subdirectory(src)

if(${SCODE_BUILD_EXAMPLES})
    add_subdirectory(examples)
endif()

if(${SCODE_BUILD_EXAMPLES})
    add_subdirectory(tests)
endif()
