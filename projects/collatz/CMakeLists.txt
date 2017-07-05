cmake_minimum_required (VERSION 3.8.2)

project (Collatz CXX)

find_package(Boost REQUIRED COMPONENTS serialization)
find_package(GTest REQUIRED)

find_program (CLANG-CHECK clang-check)
message(${CLANG-CHECK})

find_program(CLANG-FORMAT clang-format)
message(${CLANG-FORMAT})

find_program(GCOV gcov)
message(${GCOV})

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

add_executable     (RunCollatz Collatz.c++ RunCollatz.c++)
add_custom_command (OUTPUT RunCollatz.tmp COMMAND RunCollatz < ../RunCollatz.in > RunCollatz.tmp)
add_custom_target  (RunCollatz.c++x diff RunCollatz.tmp ../RunCollatz.out DEPENDS RunCollatz.tmp)

add_test (RunCollatz.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../Collatz.c++ --)
add_test (RunCollatz.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../Collatz.c++ --)
add_test (RunCollatz.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../RunCollatz.c++ --)
add_test (RunCollatz.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../RunCollatz.c++ --)
add_test (RunCollatz        ${MAKE}                                          RunCollatz.c++x)

set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "RunCollatz.bin" "RunCollatz.plist")

add_executable     (TestCollatz Collatz.c++ TestCollatz.c++)
add_custom_command (OUTPUT TestCollatz.tmp COMMAND ${VALGRIND} TestCollatz > TestCollatz.tmp)
add_custom_target  (TestCollatz.c++x DEPENDS TestCollatz.tmp)

add_test (TestCollatz.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../TestCollatz.c++ --)
add_test (TestCollatz.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../TestCollatz.c++ --)
add_test (TestCollatz        ${MAKE}                                          TestCollatz.c++x)

set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "TestCollatz.bin" "TestCollatz.plist")

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
