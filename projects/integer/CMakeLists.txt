cmake_minimum_required (VERSION 3.5.1)

project (Integer CXX)

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

add_executable (RunInteger RunInteger.c++)
target_compile_options (RunInteger PUBLIC -fprofile-arcs -ftest-coverage -pedantic -Wall -Weffc++)
target_link_libraries  (RunInteger PUBLIC -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET RunInteger
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ../RunInteger.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ../RunInteger.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../RunInteger.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../RunInteger.c++ --)
add_custom_target (RunInteger.c++x
    COMMAND echo ./RunInteger '>' RunInteger.tmp
    COMMAND      ./RunInteger  >  RunInteger.tmp
    COMMAND echo diff RunInteger.tmp ../RunInteger.out
    COMMAND      diff RunInteger.tmp ../RunInteger.out)
add_dependencies (RunInteger.c++x RunInteger)
add_custom_command (TARGET run
    COMMAND ${MAKE} RunInteger.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "RunInteger.plist" "RunInteger.tmp")

add_executable (TestInteger TestInteger.c++)
target_compile_options (TestInteger PUBLIC -fprofile-arcs -ftest-coverage -pedantic -Wall -Weffc++)
target_link_libraries  (TestInteger PUBLIC -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET TestInteger
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestInteger.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestInteger.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestInteger.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestInteger.c++ --)
add_custom_target (TestInteger.c++x
    COMMAND echo ${VALGRIND} ./TestInteger
    COMMAND      ${VALGRIND} ./TestInteger
    COMMAND echo ${GCOV} -b -o ${DIR}/TestInteger.dir TestInteger.c++ '|' grep -A 5 '"'File "'".*Integer.h"'"'"'
    COMMAND      ${GCOV} -b -o ${DIR}/TestInteger.dir TestInteger.c++  |  grep -A 5   "File '.*Integer.h'")
add_dependencies (TestInteger.c++x TestInteger)
add_custom_command (TARGET run
    COMMAND ${MAKE} TestInteger.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "TestInteger.dSYM" "TestInteger.plist")
