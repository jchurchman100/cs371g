cmake_minimum_required (VERSION 3.5.1)

project (Deque CXX)

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

add_executable (TestDeque TestDeque.c++)
target_compile_options (TestDeque PRIVATE -fprofile-arcs -ftest-coverage)
target_link_libraries  (TestDeque PRIVATE -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET TestDeque
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/TestDeque.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/TestDeque.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/TestDeque.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/TestDeque.c++ --)
add_custom_command (OUTPUT gcov
    COMMAND echo mkdir -p gcov
    COMMAND      mkdir -p gcov)
add_custom_target (TestDeque.c++x
    COMMAND echo ${VALGRIND} ${CMAKE_BINARY_DIR}/TestDeque
    COMMAND      ${VALGRIND} ${CMAKE_BINARY_DIR}/TestDeque
    COMMAND echo ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/TestDeque.dir TestDeque.c++ '|' grep -A 5 '"'File "'".*Deque.h"'"'"'
    COMMAND      ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/TestDeque.dir TestDeque.c++  |  grep -A 5   "File '.*Deque.h'"
    DEPENDS gcov
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcov)
add_dependencies (TestDeque.c++x TestDeque)
add_custom_command (TARGET run
    COMMAND echo ${MAKE} TestDeque.c++x
    COMMAND      ${MAKE} TestDeque.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "${CMAKE_OBJECT_DIR}/TestDeque.dir/TestDeque.gcda"
    "${CMAKE_OBJECT_DIR}/TestDeque.dir/TestDeque.gcno"
    "gcov"
    "TestDeque.dSYM"
    "TestDeque.plist")
