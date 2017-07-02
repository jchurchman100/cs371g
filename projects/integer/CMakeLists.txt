cmake_minimum_required (VERSION 3.8.2)

project (Integer CXX)

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

add_executable     (RunInteger RunInteger.c++)
add_custom_command (OUTPUT RunInteger.tmp COMMAND RunInteger > RunInteger.tmp)
add_custom_target  (run ALL DEPENDS RunInteger.tmp)
add_test           (RunInteger diff RunInteger.tmp ../RunInteger.out)

add_executable (TestInteger TestInteger.c++)
add_test       (TestInteger TestInteger)
