cmake_minimum_required (VERSION 3.8.2)

project (Integer CXX)

find_package(Boost REQUIRED COMPONENTS serialization)
find_package(GTest REQUIRED)

find_program (CLANG-CHECK clang-check)
message(${CLANG-CHECK})

find_program(CLANG-FORMAT clang-format)
message(${CLANG-FORMAT})

find_program(GCOV gcov)
message(${GCOV})

find_program(MAKE make)
message(${MAKE})

find_program(VALGRIND valgrind)
message(${VALGRIND})

#add_compile_options (-fprofile-arcs -ftest-coverage)
add_compile_options (-pedantic -Wall -Weffc++)

set (CMAKE_CXX_STANDARD          14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)

link_libraries (boost_serialization)
link_libraries (gtest)
link_libraries (gtest_main)

enable_testing()

add_executable     (RunInteger RunInteger.c++)
add_custom_command (OUTPUT RunInteger.tmp COMMAND RunInteger > RunInteger.tmp)
add_custom_target  (RunInteger.c++x diff RunInteger.tmp ../RunInteger.out DEPENDS RunInteger.tmp)

add_test (RunInteger.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../RunInteger.c++ --)
add_test (RunInteger.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../RunInteger.c++ --)
add_test (RunInteger        ${MAKE}                                          RunInteger.c++x)

set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "RunInteger.bin" "RunInteger.plist")

add_executable     (TestInteger TestInteger.c++)
add_custom_command (OUTPUT TestInteger.tmp COMMAND ${VALGRIND} TestInteger > TestInteger.tmp)
add_custom_target  (TestInteger.c++x DEPENDS TestInteger.tmp)

add_test (TestInteger.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestInteger.c++ --)
add_test (TestInteger.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestInteger.c++ --)
add_test (TestInteger        ${MAKE}                                          TestInteger.c++x)

set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "TestInteger.bin" "TestInteger.plist")

add_custom_target (versions)

set (APPS
    clang-check
    clang-format
    cmake
    doxygen
    g++
    gcov
    git
    make
    valgrind)

foreach (app ${APPS})
    add_custom_command (TARGET versions
        COMMAND echo which ${app}
        COMMAND      which ${app}
        COMMAND echo ${app} --version
        COMMAND      ${app} --version
        COMMAND echo)
endforeach ()

set (PKGS
    Boost
    GTest)

foreach (pkg ${PKGS})
    add_custom_command (TARGET versions
        COMMAND echo ${pkg}_VERSION
        COMMAND echo ${${pkg}_VERSION}
        COMMAND echo)
endforeach ()
