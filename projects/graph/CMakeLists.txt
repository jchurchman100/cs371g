cmake_minimum_required (VERSION 3.5.1)

project (Graph CXX)

find_package(GTest REQUIRED)

find_program (CLANG-CHECK clang-check)
message(${CLANG-CHECK})

find_program (GCOV gcov)
message (${GCOV})

find_program(MAKE make)
message(${MAKE})

find_program(VALGRIND valgrind)
message(${VALGRIND})

set (CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set (CMAKE_CXX_STANDARD                 14)
set (CMAKE_CXX_STANDARD_REQUIRED        ON)
set (CMAKE_CXX_EXTENSIONS               OFF)

set (DIR ${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY})
message (${DIR})

add_custom_target (run)

add_executable (TestGraph TestGraph.c++)
target_compile_options (TestGraph PUBLIC -fprofile-arcs -ftest-coverage -pedantic -Wall -Weffc++)
target_link_libraries  (TestGraph PUBLIC -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET TestGraph
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestGraph.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestGraph.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestGraph.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestGraph.c++ --)
add_custom_target (TestGraph.c++x
    COMMAND echo ${VALGRIND} ./TestGraph
    COMMAND      ${VALGRIND} ./TestGraph
    COMMAND echo ${GCOV} -b -o ${DIR}/TestGraph.dir TestGraph.c++ '|' grep -A 5 '"'File "'".*Graph.h"'"'"'
    COMMAND      ${GCOV} -b -o ${DIR}/TestGraph.dir TestGraph.c++  |  grep -A 5   "File '.*Graph.h'")
add_dependencies (TestGraph.c++x TestGraph)
add_custom_command (TARGET run
    COMMAND ${MAKE} TestGraph.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "TestGraph.dSYM" "TestGraph.plist")
