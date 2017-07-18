cmake_minimum_required (VERSION 3.5.1)

project (Examples CXX)

message (${CMAKE_SOURCE_DIR})
message (${CMAKE_BINARY_DIR})

find_program (CLANG-CHECK clang-check)
message      (${CLANG-CHECK})

find_program (MAKE make)
message      (${MAKE})

set (CMAKE_CXX_FLAGS             "-pedantic -Wall -Weffc++")
set (CMAKE_CXX_STANDARD          14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)

set (FILES
    Hello
    Assertions
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
    Functions
    InitializerList
    Initializations
    Auto
    Sets
    Maps)

add_custom_target (run)

foreach (file ${FILES})
    add_executable (${file} ${file}.c++)
    add_custom_command (TARGET ${file}
        COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/${file}.c++ --
        COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/${file}.c++ --
        COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/${file}.c++ --
        COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/${file}.c++ --)
    add_custom_target (${file}.c++x
        COMMAND echo ${CMAKE_BINARY_DIR}/${file}
        COMMAND      ${CMAKE_BINARY_DIR}/${file})
    add_dependencies (${file}.c++x ${file})
    add_custom_command (TARGET run
        COMMAND echo ${MAKE} ${file}.c++x
        COMMAND      ${MAKE} ${file}.c++x)
    set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
        "${file}.plist")
endforeach ()

set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "BoostSerialization.bin")

target_compile_options (Returns            PRIVATE -Wno-return-stack-address)
target_link_libraries  (BoostSerialization PRIVATE boost_serialization)
