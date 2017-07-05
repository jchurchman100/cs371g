cmake_minimum_required (VERSION 3.8.2)

project (Examples CXX)

find_package(Boost REQUIRED COMPONENTS serialization)
find_package(GTest REQUIRED)

find_program (CLANG-CHECK clang-check)
message(${CLANG-CHECK})

add_compile_options (-pedantic -Wall -Weffc++)

set (CMAKE_CXX_STANDARD          14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)

link_libraries (boost_serialization)
link_libraries (gtest)
link_libraries (gtest_main)

set (FILES
    Boost
    GTest
    Hello
    Exceptions
    Exceptions2
    Exceptions3
    Types
    BoostSerialization
    Operators
    Variables
    Arguments
    Returns
    Iterators
    Iteration
    FunctionOverloading
    FunctionGenerics
    FunctionSpecializations
    Functions)

enable_testing()

foreach (file ${FILES})
    add_executable (${file} ../${file}.c++)

    add_test (${file}.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../${file}.c++ --)
    add_test (${file}.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../${file}.c++ --)
    add_test (${file}                                                         ${file})

    set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "${file}.bin" "${file}.plist")
endforeach ()

target_compile_options (Returns PRIVATE -Wno-return-stack-address)

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
