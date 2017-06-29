cmake_minimum_required (VERSION 3.8.2)

project (Tests CXX)

add_compile_options (-pedantic -Wall -Weffc++)

set (CMAKE_CXX_STANDARD          14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)

set (EXES
    RMSE
    Test1)

foreach (exe ${EXES})
    add_executable (${exe} ${exe}.c++)
endforeach ()

target_compile_options (Test1 PRIVATE -Wno-sizeof-array-argument)

enable_testing()

set (TESTS1
    Test1)

foreach (test ${TESTS1})
    add_test (${test} ${test})
endforeach ()

set (TESTS2
    RMSE1
    RMSE2
    RMSE3)

foreach (test ${TESTS2})
    add_custom_command (OUTPUT ${test}.tmp
        COMMAND RMSE < ${test}.in > ${test}.tmp)
    add_custom_target (${test} ALL DEPENDS ${test}.tmp)
    add_test          (${test} diff ${test}.tmp ${test}.out)
endforeach ()
