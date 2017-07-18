cmake_minimum_required (VERSION 3.5.1)

project (Examples CXX)

message (${CMAKE_SOURCE_DIR})
message (${CMAKE_BINARY_DIR})
message (${CMAKE_FILES_DIRECTORY})

set     (CMAKE_OBJECT_DIR ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY})
message (${CMAKE_OBJECT_DIR})

find_package (GTest REQUIRED)

find_program (CLANG-CHECK clang-check)
message      (${CLANG-CHECK})

find_program (GCOV gcov)
message      (${GCOV})

find_program (MAKE make)
message      (${MAKE})

set (CMAKE_CXX_FLAGS                    "-fprofile-arcs -ftest-coverage -pedantic -Wall -Weffc++")
set (CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set (CMAKE_CXX_STANDARD                 14)
set (CMAKE_CXX_STANDARD_REQUIRED        ON)
set (CMAKE_CXX_EXTENSIONS               OFF)

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
    PriorityQueue
    Vector1
    Vector2
    Vector3
    Allocator
    Vector4
    Vector5
    Pair
    BackInserter
    OStreamIterator
    IStreamIterator)

add_custom_target (run)

foreach (file ${FILES})
    add_executable (${file} ${file}.c++)
    target_link_libraries (${file} PRIVATE GTest::GTest GTest::Main)
    add_custom_command (TARGET ${file}
        COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/${file}.c++ --
        COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11          ${CMAKE_SOURCE_DIR}/${file}.c++ --
        COMMAND echo ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/${file}.c++ --
        COMMAND      ${CLANG-CHECK} -extra-arg=-std=c++11 -analyze ${CMAKE_SOURCE_DIR}/${file}.c++ --)
    add_custom_command (OUTPUT gcov
        COMMAND echo mkdir -p gcov
        COMMAND      mkdir -p gcov)
    add_custom_target (${file}.c++x
        COMMAND echo ${CMAKE_BINARY_DIR}/${file}
        COMMAND      ${CMAKE_BINARY_DIR}/${file}
        COMMAND echo ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/${file}.dir ${file}.c++ '|' grep -A 5 '"'File "'".*${file}.c++"'"'"'
        COMMAND      ${GCOV} -b -o ${CMAKE_OBJECT_DIR}/${file}.dir ${file}.c++  |  grep -A 5   "File '.*${file}.c++'"
        DEPENDS gcov
        WORKING_DIRECTORY gcov)
    add_dependencies (${file}.c++x ${file})
    add_custom_command (TARGET run
        COMMAND echo ${MAKE} ${file}.c++x
        COMMAND      ${MAKE} ${file}.c++x)
    set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
        "${file}.plist"
        "${CMAKE_OBJECT_DIR}/${file}.dir/${file}.gcda"
        "${CMAKE_OBJECT_DIR}/${file}.dir/${file}.gcno"
        "gcov")
endforeach ()
