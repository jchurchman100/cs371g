cmake_minimum_required (VERSION 3.8.2)

project (Examples CXX)

find_program (CLANG-CHECK clang-check)
message(${CLANG-CHECK})

set (CMAKE_CXX_STANDARD          14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)

set (FILES
    GTest
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
    PriorityQueue
    Vector1)

enable_testing()

foreach (file ${FILES})
    add_executable         (${file}                                                      ../${file}.c++)
    add_test               (${file}.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../${file}.c++ --)
    add_test               (${file}.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../${file}.c++ --)
    add_test               (${file}                                                         ${file})
    set_property           (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES          "${file}.plist")
    target_compile_options (${file} PRIVATE -pedantic -Wall -Weffc++)
    target_link_libraries  (${file} PRIVATE gtest gtest_main)
endforeach ()
