cmake_minimum_required (VERSION 3.8.2)

project (Collatz CXX)

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

enable_testing()

add_executable     (RunCollatz Collatz.c++ RunCollatz.c++)
add_custom_command (OUTPUT RunCollatz.tmp COMMAND RunCollatz < ../RunCollatz.in > RunCollatz.tmp)
add_custom_target  (run ALL DEPENDS RunCollatz.tmp)
add_test           (RunCollatz diff RunCollatz.tmp ../RunCollatz.out)

add_executable (TestCollatz Collatz.c++ TestCollatz.c++)
add_test       (TestCollatz TestCollatz)
