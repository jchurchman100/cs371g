cmake_minimum_required (VERSION 3.8.2)

project (Collatz CXX)

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

add_executable     (RunCollatz Collatz.c++ RunCollatz.c++)
add_custom_command (OUTPUT RunCollatz.tmp COMMAND RunCollatz < ../RunCollatz.in > RunCollatz.tmp)
add_custom_target  (RunCollatz.c++x diff RunCollatz.tmp ../RunCollatz.out DEPENDS RunCollatz.tmp)

add_test               (RunCollatz.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../Collatz.c++ --)
add_test               (RunCollatz.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../Collatz.c++ --)
add_test               (RunCollatz.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../RunCollatz.c++ --)
add_test               (RunCollatz.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../RunCollatz.c++ --)
add_test               (RunCollatz        ${MAKE}                                          RunCollatz.c++x)
set_property           (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES             "RunCollatz.plist")
target_compile_options (RunCollatz PRIVATE -pedantic -Wall -Weffc++)

add_executable     (TestCollatz Collatz.c++ TestCollatz.c++)
add_custom_command (OUTPUT TestCollatz.tmp COMMAND ${VALGRIND} TestCollatz > TestCollatz.tmp)
add_custom_target  (TestCollatz.c++x DEPENDS TestCollatz.tmp)

add_test               (TestCollatz.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestCollatz.c++ --)
add_test               (TestCollatz.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestCollatz.c++ --)
add_test               (TestCollatz        ${MAKE}                                          TestCollatz.c++x)
set_property           (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES              "TestCollatz.plist")
target_compile_options (TestCollatz PRIVATE -pedantic -Wall -Weffc++)
target_link_libraries  (TestCollatz PRIVATE gtest gtest_main)
