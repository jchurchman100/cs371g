cmake_minimum_required (VERSION 3.8.2)

project (Integer CXX)

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

add_executable     (RunInteger RunInteger.c++)
add_custom_command (OUTPUT RunInteger.tmp COMMAND RunInteger < ../RunInteger.in > RunInteger.tmp)
add_custom_target  (RunInteger.c++x diff RunInteger.tmp ../RunInteger.out DEPENDS RunInteger.tmp)

add_test               (RunInteger.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../RunInteger.c++ --)
add_test               (RunInteger.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../RunInteger.c++ --)
add_test               (RunInteger        ${MAKE}                                          RunInteger.c++x)
set_property           (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES             "RunInteger.plist")
target_compile_options (RunInteger PRIVATE -pedantic -Wall -Weffc++)

add_executable     (TestInteger TestInteger.c++)
add_custom_command (OUTPUT TestInteger.tmp COMMAND ${VALGRIND} TestInteger > TestInteger.tmp)
add_custom_target  (TestInteger.c++x DEPENDS TestInteger.tmp)

add_test               (TestInteger.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestInteger.c++ --)
add_test               (TestInteger.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestInteger.c++ --)
add_test               (TestInteger        ${MAKE}                                          TestInteger.c++x)
set_property           (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES              "TestInteger.plist")
target_compile_options (TestInteger PRIVATE -pedantic -Wall -Weffc++)
target_link_libraries  (TestInteger PRIVATE gtest gtest_main)
