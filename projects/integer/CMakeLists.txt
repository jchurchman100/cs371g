cmake_minimum_required (VERSION 3.5.1)

project (Integer CXX)

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

add_executable (RunInteger RunInteger.c++)
target_link_libraries  (RunInteger PRIVATE GTest::GTest GTest::Main)
add_custom_command (TARGET RunInteger
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/RunInteger.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/RunInteger.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/RunInteger.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/RunInteger.c++ --)
add_custom_target (RunInteger.c++x
    COMMAND echo ${CMAKE_BINARY_DIR}/RunInteger '>' RunInteger.tmp
    COMMAND      ${CMAKE_BINARY_DIR}/RunInteger  >  RunInteger.tmp
    COMMAND echo diff RunInteger.tmp ${CMAKE_SOURCE_DIR}/RunInteger.out
    COMMAND      diff RunInteger.tmp ${CMAKE_SOURCE_DIR}/RunInteger.out)
add_dependencies (RunInteger.c++x RunInteger)
add_custom_command (TARGET run
    COMMAND echo ${MAKE} RunInteger.c++x
    COMMAND      ${MAKE} RunInteger.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "Integer.plist"
    "RunInteger.plist"
    "RunInteger.tmp")

add_executable (TestInteger TestInteger.c++)
target_compile_options (TestInteger PRIVATE -fprofile-arcs -ftest-coverage)
target_link_libraries  (TestInteger PRIVATE -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET TestInteger
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/TestInteger.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/TestInteger.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/TestInteger.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/TestInteger.c++ --)
add_custom_command (OUTPUT gcov
    COMMAND echo mkdir -p gcov
    COMMAND      mkdir -p gcov)
add_custom_target (TestInteger.c++x
    COMMAND echo ${VALGRIND} ${CMAKE_BINARY_DIR}/TestInteger
    COMMAND      ${VALGRIND} ${CMAKE_BINARY_DIR}/TestInteger
    COMMAND echo ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/TestInteger.dir TestInteger.c++ '|' grep -A 5 '"'File "'".*Integer.h"'"'"'
    COMMAND      ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/TestInteger.dir TestInteger.c++  |  grep -A 5   "File '.*Integer.h'"
    DEPENDS gcov
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcov)
add_dependencies (TestInteger.c++x TestInteger)
add_custom_command (TARGET run
    COMMAND echo ${MAKE} TestInteger.c++x
    COMMAND      ${MAKE} TestInteger.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "${CMAKE_OBJECT_DIR}/TestInteger.dir/TestInteger.gcda"
    "${CMAKE_OBJECT_DIR}/TestInteger.dir/TestInteger.gcno"
    "gcov"
    "TestInteger.dSYM"
    "TestInteger.plist")
