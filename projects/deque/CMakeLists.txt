cmake_minimum_required (VERSION 3.8.2)

project (Deque CXX)

find_program (CLANG-CHECK clang-check)
message(${CLANG-CHECK})

find_program(MAKE make)
message(${MAKE})

find_program(VALGRIND valgrind)
message(${VALGRIND})

set (CMAKE_CXX_STANDARD          14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)

enable_testing()

add_executable     (TestDeque TestDeque.c++)
add_custom_command (OUTPUT TestDeque.tmp COMMAND ${VALGRIND} TestDeque > TestDeque.tmp)
add_custom_target  (TestDeque.c++x DEPENDS TestDeque.tmp)

add_test               (TestDeque.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestDeque.c++ --)
add_test               (TestDeque.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestDeque.c++ --)
add_test               (TestDeque        ${MAKE}                                          TestDeque.c++x)
set_property           (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES              "TestDeque.plist")
target_compile_options (TestDeque PRIVATE -pedantic -Wall -Weffc++)
target_link_libraries  (TestDeque PRIVATE gtest gtest_main)
