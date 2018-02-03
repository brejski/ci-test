cmake_minimum_required(VERSION 3.2)
project(ci_test)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/gtest-cmake)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

###############

file(GLOB_RECURSE TESTS_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp
    )

file(GLOB_RECURSE APP_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/app/*.cpp
    )

file(GLOB_RECURSE LIB_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/*.cpp
    )

###############

include(CTest)
enable_testing()

add_executable(tests_example
    ${TESTS_SRC}
    ${LIB_SRC}
    )

target_link_libraries(tests_example gtest_main)
add_test(gtest ${PROJECT_BINARY_DIR}/tests_example)

###############

add_executable(main_example
    ${LIB_SRC}
    ${APP_SRC}
    )
