.DEFAULT_GOAL := all

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

all:
	cd examples; make all
	@echo
	cd exercises; make all
	@echo
	cd projects/collatz; make all
	@echo
	cd projects/integer; make all
	@echo
	cd projects/deque; make all
	@echo
	cd projects/graph; make all

clean:
	cd examples; make clean
	@echo
	cd exercises; make clean
	@echo
	cd projects/collatz; make clean
	@echo
	cd projects/integer; make clean
	@echo
	cd projects/deque; make clean
	@echo
	cd projects/graph; make clean

config:
	git config -l

docker:
	docker run -it -v $(PWD):/usr/cs371g -w /usr/cs371g gpdowning/gcc

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:gpdowning/cs371g.git
	git push -u origin master

pull:
	make clean
	@echo
	git pull
	git status

push:
	make clean
	@echo
	git add .gitignore
	git add .travis.yml
	git add Dockerfile
	git add examples
	git add exercises
	git add makefile
	git add notes
	git add projects/collatz
	git add projects/integer
	git add projects/deque
	git add projects/graph
	git commit -m "another commit"
	git push
	git status

run:
	cd examples; make run
	@echo
	cd exercises; make run
	@echo
	cd projects/collatz; make run
	@echo
	cd projects/integer; make run
	@echo
	cd projects/deque; make run
	@echo
	cd projects/graph; make run

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

sync:
	@rsync -r -t -u -v --delete             \
    --include "Docker.txt"                  \
    --include "Hello.c++"                   \
    --include "Assertions.c++"              \
    --include "Exceptions.c++"              \
    --include "Exceptions2.c++"             \
    --include "Exceptions3.c++"             \
    --include "Types.c++"                   \
    --include "BoostSerialization.c++"      \
    --include "Operators.c++"               \
    --include "Variables.c++"               \
    --include "Arguments.c++"               \
    --include "Returns.c++"                 \
    --include "Iterators.c++"               \
    --include "Iteration.c++"               \
    --include "FunctionOverloading.c++"     \
    --include "FunctionGenerics.c++"        \
    --include "FunctionSpecializations.c++" \
    --include "InitializerList.c++"         \
    --include "Initializations.c++"         \
    --include "Sets.c++"                    \
    --include "Maps.c++"                    \
    --include "Auto.c++"                    \
    --exclude "*"                           \
    ../../examples/c++/ examples
	@rsync -r -t -u -v --delete             \
    --include "UnitTests1.c++"              \
    --include "UnitTests1.h"                \
    --include "UnitTests2.c++"              \
    --include "UnitTests2.h"                \
    --include "UnitTests3.c++"              \
    --include "UnitTests3.h"                \
    --include "Coverage1.c++"               \
    --include "Coverage1.h"                 \
    --include "Coverage2.c++"               \
    --include "Coverage2.h"                 \
    --include "Coverage3.c++"               \
    --include "Coverage3.h"                 \
    --include "IsPrime1.c++"                \
    --include "IsPrime1.h"                  \
    --include "IsPrime2.c++"                \
    --include "IsPrime2.h"                  \
    --include "StrCmp.c++"                  \
    --include "StrCmp.h"                    \
    --include "Equal.c++"                   \
    --include "Equal.h"                     \
    --include "Incr.c++"                    \
    --include "Incr.h"                      \
    --include "Copy.c++"                    \
    --include "Copy.h"                      \
    --include "Fill.c++"                    \
    --include "Fill.h"                      \
    --include "Count.c++"                   \
    --include "Count.h"                     \
    --include "Reverse.c++"                 \
    --include "Reverse.h"                   \
    --include "RangeIterator.c++"           \
    --include "RangeIterator.h"             \
    --include "Range.c++"                   \
    --include "Range.h"                     \
    --include "RMSE.c++"                    \
    --include "RMSE.h"                      \
    --include "Transform.c++"               \
    --include "Transform.h"                 \
    --include "Accumulate.c++"              \
    --include "Accumulate.h"                \
    --include "Stack.c++"                   \
    --include "Stack.h"                     \
    --include "Queue.c++"                   \
    --include "Queue.h"                     \
    --include "PriorityQueue.c++"           \
    --include "PriorityQueue.h"             \
    --include "Vector1.c++"                 \
    --include "Vector1.h"                   \
    --include "Vector2.c++"                 \
    --include "Vector2.h"                   \
    --include "Vector3.c++"                 \
    --include "Vector3.h"                   \
    --include "Allocator.c++"               \
    --include "Allocator.h"                 \
    --include "Memory.h"                    \
    --include "Vector4.c++"                 \
    --include "Vector4.h"                   \
    --include "Vector5.c++"                 \
    --include "Vector5.h"                   \
    --include "Pair.c++"                    \
    --include "Pair.h"                      \
    --include "BackInserter.c++"            \
    --include "BackInserter.h"              \
    --include "OStreamIterator.c++"         \
    --include "OStreamIterator.h"           \
    --include "IStreamIterator.c++"         \
    --include "IStreamIterator.h"           \
    --include "ReverseIterator.c++"         \
    --include "ReverseIterator.h"           \
    --include "UniquePtr.c++"               \
    --include "UniquePtr.h"                 \
    --include "SharedPtr.c++"               \
    --include "SharedPtr.h"               \
    --exclude "*"                           \
    ../../exercises/c++/ exercises
	@rsync -r -t -u -v --delete             \
    --include "Collatz.c++"                 \
    --include "Collatz.h"                   \
    --include "RunCollatz.c++"              \
    --include "RunCollatz.in"               \
    --include "RunCollatz.out"              \
    --include "TestCollatz.c++"             \
    --include "TestCollatz.out"             \
    --exclude "*"                           \
    ../../projects/c++/collatz/ projects/collatz
	@rsync -r -t -u -v --delete             \
    --include "Integer.h"                   \
    --include "RunInteger.c++"              \
    --include "RunInteger.out"              \
    --include "TestInteger.c++"             \
    --include "TestInteger.out"             \
    --exclude "*"                           \
    ../../projects/c++/integer/ projects/integer
	@rsync -r -t -u -v --delete             \
    --include "Deque.h"                     \
    --include "TestDeque.c++"               \
    --include "TestDeque.out"               \
    --exclude "*"                           \
    ../../projects/c++/deque/ projects/deque
	@rsync -r -t -u -v --delete             \
    --include "Graph.h"                     \
    --include "TestGraph.c++"               \
    --include "TestGraph.out"               \
    --exclude "*"                           \
    ../../projects/c++/graph/ projects/graph

travis:
	cd examples; make travis
	@echo
	cd exercises; make travis
	@echo
	cd projects/collatz; make travis
	@echo
	cd projects/integer; make travis
	@echo
	cd projects/deque; make travis
	@echo
	cd projects/graph; make travis

versions:
	which cmake
	cmake --version
	@echo
	which make
	make --version
	@echo
	which git
	git --version
	@echo
	which $(CXX)
	$(CXX) --version
	@echo
	ls -adl $(INCLUDE)/boost
	@echo
	ls -adl $(INCLUDE)/gtest
	@echo
	ls -al $(LIBB)/libboost_serialization.a
	@echo
	ls -al $(LIBG)/libgtest.a
	ls -al $(LIBG)/libgtest_main.a
	@echo
	which $(CLANG-CHECK)
	-$(CLANG-CHECK) --version
	@echo
	which $(GCOV)
	$(GCOV) --version
	@echo
	which $(VALGRIND)
	$(VALGRIND) --version
	@echo
	which $(DOXYGEN)
	$(DOXYGEN) --version
	@echo
	which $(CLANG-FORMAT)
	-$(CLANG-FORMAT) --version
