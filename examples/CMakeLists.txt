cmake_minimum_required (VERSION 3.8.2)

project (Examples CXX)

find_program (CLANG-CHECK clang-check)
message(${CLANG-CHECK})

set (CMAKE_CXX_STANDARD          14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)

set (FILES
    Boost
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

enable_testing()

foreach (file ${FILES})
    add_executable         (${file}                                                      ../${file}.c++)
    add_test               (${file}.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../${file}.c++ --)
    add_test               (${file}.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../${file}.c++ --)
    add_test               (${file}                                                         ${file})
    set_property           (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES          "${file}.plist")
    target_compile_options (${file} PRIVATE -pedantic -Wall -Weffc++)
endforeach ()

set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "BoostSerialization.bin")

target_compile_options (Returns PRIVATE -Wno-return-stack-address)

target_link_libraries (BoostSerialization PRIVATE boost_serialization)

add_executable         (CommandLine                                                      ../CommandLine.c++)
add_test               (CommandLine.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../CommandLine.c++ --)
add_test               (CommandLine.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../CommandLine.c++ --)
add_test               (CommandLine                                                         CommandLine nothing to be done)
set_property           (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES              "CommandLine.plist")
target_compile_options (CommandLine PRIVATE -pedantic -Wall -Weffc++)

add_executable         (FileInputOutput                                                      ../FileInputOutput.c++)
add_test               (FileInputOutput.check1 ${CLANG-CHECK} -extra-arg=-std=c++11          ../FileInputOutput.c++ --)
add_test               (FileInputOutput.check2 ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ../FileInputOutput.c++ --)
add_test               (FileInputOutput                                                         FileInputOutput ../FileInputOutput.c++)
set_property           (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES                  "FileInputOutput.plist")
target_compile_options (FileInputOutput PRIVATE -pedantic -Wall -Weffc++)
