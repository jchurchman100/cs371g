cmake_minimum_required (VERSION 3.5.1)

project (Collatz CXX)

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

add_executable (RunCollatz Collatz.c++ RunCollatz.c++)
target_compile_options (RunCollatz PUBLIC -fprofile-arcs -ftest-coverage -pedantic -Wall -Weffc++)
target_link_libraries  (RunCollatz PUBLIC -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET RunCollatz
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ../Collatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ../Collatz.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../Collatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../Collatz.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ../RunCollatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ../RunCollatz.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../RunCollatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../RunCollatz.c++ --)
add_custom_target (RunCollatz.c++x
    COMMAND echo ./RunCollatz '<' ../RunCollatz.in '>' RunCollatz.tmp
    COMMAND      ./RunCollatz  <  ../RunCollatz.in  >  RunCollatz.tmp
    COMMAND echo diff RunCollatz.tmp ../RunCollatz.out
    COMMAND      diff RunCollatz.tmp ../RunCollatz.out)
add_dependencies (RunCollatz.c++x RunCollatz)
add_custom_command (TARGET run
    COMMAND ${MAKE} RunCollatz.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "RunCollatz.plist" "RunCollatz.tmp")

add_executable (TestCollatz Collatz.c++ TestCollatz.c++)
target_compile_options (TestCollatz PUBLIC -fprofile-arcs -ftest-coverage -pedantic -Wall -Weffc++)
target_link_libraries  (TestCollatz PUBLIC -fprofile-arcs -ftest-coverage GTest::GTest GTest::Main)
add_custom_command (TARGET TestCollatz
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestCollatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestCollatz.c++ --
    COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestCollatz.c++ --
    COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestCollatz.c++ --)
add_custom_target (TestCollatz.c++x
    COMMAND echo ${VALGRIND} ./TestCollatz
    COMMAND      ${VALGRIND} ./TestCollatz
    COMMAND echo ${GCOV} -b -o ${DIR}/TestCollatz.dir Collatz.c++ '|' grep -A 5 '"'File "'".*Collatz.c++"'"'"'
    COMMAND      ${GCOV} -b -o ${DIR}/TestCollatz.dir Collatz.c++  |  grep -A 5   "File '.*Collatz.c++'")
add_dependencies (TestCollatz.c++x TestCollatz)
add_custom_command (TARGET run
    COMMAND ${MAKE} TestCollatz.c++x)
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "TestCollatz.dSYM" "TestCollatz.plist")
