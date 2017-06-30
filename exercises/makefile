.DEFAULT_GOAL := all

FILES :=          \
    UnitTests3    \
    Coverage1     \
    Coverage2     \
    Coverage3     \
    IsPrime1      \
    IsPrime2      \
    StrCmp        \
    Equal         \
    Copy          \
    Fill          \
    Count         \
    Reverse       \
    RangeIterator \
    Range         \
    RMSE          \
    Transform     \
    Accumulate    \
    Stack

ifeq ($(shell uname), Darwin)                                           # Apple
    CXX          := g++
    INCLUDE      := /usr/local/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/local/lib
    LIBG         := /usr/local/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format
else ifeq ($(CI), true)                                                 # Travis CI
    CXX          := g++-5
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/lib
    LIBG         := $(PWD)/gtest
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov-5
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format
else ifeq ($(shell uname -p), unknown)                                  # Docker
    CXX          := g++
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/lib
    LIBG         := /usr/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format-3.5
else                                                                    # UTCS
    CXX          := g++
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++14 -Wall -Weffc++
    LIBB         := /usr/lib/x86_64-linux-gnu
    LIBG         := /usr/local/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format-3.8
endif

%: %.c++ %.h
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) $< -o $@ $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          $< --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze $< --

%.c++x: %
	./$<
	-$(GCOV) -b $(<:=.c++) | grep -A 5 "File '.*$(<:=.h)'"

all: $(FILES)

clean:
	rm -f *.bin
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.plist
	rm -f $(FILES)

test: $(FILES:=.c++x)
