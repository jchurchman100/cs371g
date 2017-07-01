cmake_minimum_required (VERSION 3.8.2)

project (Examples CXX)

find_package(Boost REQUIRED COMPONENTS serialization)
find_package(GTest REQUIRED)

#add_compile_options (-fprofile-arcs -ftest-coverage)
add_compile_options (-pedantic -Wall -Weffc++)

set (CMAKE_CXX_STANDARD          14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)

link_libraries (boost_serialization)
link_libraries (gtest)
link_libraries (gtest_main)

set (FILES
    UnitTests3
    Coverage1
    Coverage2
    Coverage3
    IsPrime1
    IsPrime2
    StrCmp
    Equal
    Copy
    Fill
    Count
    Reverse
    RangeIterator
    Range
    RMSE
    Transform
    Accumulate
    Stack
    Queue
    PriorityQueue)

enable_testing()

foreach (file ${FILES})
    add_executable (${file} ${file}.c++)
    add_test       (${file} ${file})
endforeach ()

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
