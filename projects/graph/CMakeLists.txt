cmake_minimum_required (VERSION 3.5.1)

project (Graph CXX)

message (${CMAKE_SOURCE_DIR})
message (${CMAKE_BINARY_DIR})
message (${CMAKE_FILES_DIRECTORY})

set     (CMAKE_OBJECT_DIR ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY})
message (${CMAKE_OBJECT_DIR})

find_package (GTest REQUIRED)

find_program (CLANG-CHECK clang-check)
message      (${CLANG-CHECK})

find_program (GCOV gcov)
message      (${GCOV})

find_program (MAKE make)
message      (${MAKE})

find_program (VALGRIND valgrind)
message      (${VALGRIND})

set (CMAKE_CXX_FLAGS                    "-pedantic -Wall -Weffc++")
set (CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set (CMAKE_CXX_STANDARD                 14)
set (CMAKE_CXX_STANDARD_REQUIRED        ON)
set (CMAKE_CXX_EXTENSIONS               OFF)

add_custom_target (run)

add_executable (TestGraph TestGraph.c++)
target_compile_options (TestGraph PRIVATE -fprofile-arcs -ftest-coverage)
target_link_libraries  (TestGraph PRIVATE -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET TestGraph
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/TestGraph.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/TestGraph.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/TestGraph.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/TestGraph.c++ --)
add_custom_command (OUTPUT gcov
    COMMAND echo mkdir -p gcov
    COMMAND      mkdir -p gcov)
add_custom_target (TestGraph.c++x
    COMMAND echo ${VALGRIND} ${CMAKE_BINARY_DIR}/TestGraph
    COMMAND      ${VALGRIND} ${CMAKE_BINARY_DIR}/TestGraph
    COMMAND echo ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/TestGraph.dir TestGraph.c++ '|' grep -A 5 '"'File "'".*Graph.h"'"'"'
    COMMAND      ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/TestGraph.dir TestGraph.c++  |  grep -A 5   "File '.*Graph.h'"
    DEPENDS gcov
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcov)
add_dependencies (TestGraph.c++x TestGraph)
add_custom_command (TARGET run
    COMMAND echo ${MAKE} TestGraph.c++x
    COMMAND      ${MAKE} TestGraph.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "${CMAKE_OBJECT_DIR}/TestGraph.dir/TestGraph.gcda"
    "${CMAKE_OBJECT_DIR}/TestGraph.dir/TestGraph.gcno"
    "gcov"
    "TestGraph.dSYM"
    "TestGraph.plist")
