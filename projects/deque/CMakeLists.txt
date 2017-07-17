cmake_minimum_required (VERSION 3.5.1)

project (Deque CXX)

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

add_executable (TestDeque TestDeque.c++)
target_compile_options (TestDeque PUBLIC -fprofile-arcs -ftest-coverage -pedantic -Wall -Weffc++)
target_link_libraries  (TestDeque PUBLIC -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET TestDeque
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestDeque.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestDeque.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestDeque.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestDeque.c++ --)
add_custom_target (TestDeque.c++x
    COMMAND echo ${VALGRIND} ./TestDeque
    COMMAND      ${VALGRIND} ./TestDeque
    COMMAND echo ${GCOV} -b -o ${DIR}/TestDeque.dir TestDeque.c++ '|' grep -A 5 '"'File "'".*Deque.h"'"'"'
    COMMAND      ${GCOV} -b -o ${DIR}/TestDeque.dir TestDeque.c++  |  grep -A 5   "File '.*Deque.h'")
add_dependencies (TestDeque.c++x TestDeque)
add_custom_command (TARGET run
    COMMAND ${MAKE} TestDeque.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "TestDeque.dSYM" "TestDeque.plist")
