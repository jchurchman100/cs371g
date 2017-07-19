.DEFAULT_GOAL := all

FILES :=          \
    .gitignore    \
    Deque.h       \
    Deque.log     \
    html          \
    makefile      \
    TestDeque.c++ \
    TestDeque.out

# uncomment these:
#    .travis.yml

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

html: Doxyfile Deque.h
	$(DOXYGEN) Doxyfile

Deque.log:
	git log > Deque.log

Doxyfile:
	$(DOXYGEN) -g
	# you must manually edit Doxyfile and
	# set EXTRACT_ALL     to YES
	# set EXTRACT_PRIVATE to YES
	# set EXTRACT_STATEIC to YES

TestDeque: Deque.h TestDeque.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) TestDeque.c++ -o TestDeque $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestDeque.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestDeque.c++ --

TestDeque.c++x: TestDeque
	$(VALGRIND) ./TestDeque
	-$(GCOV) -b TestDeque.c++ | grep -A 5 "File '.*Deque.h'"

all: TestDeque

check: $(FILES)

clean:
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.plist
	rm -f  TestDeque
	rm -rf *.dSYM
	rm -rf latex

config:
	git config -l

docker:
	docker run -it -v $(PWD):/usr/deque -w /usr/deque gpdowning/gcc

format:
	$(CLANG-FORMAT) -i Deque.h
	$(CLANG-FORMAT) -i TestDeque.c++

run: TestDeque.c++x

scrub:
	make clean
	rm -f  Deque.log
	rm -f  Doxyfile
	rm -rf html

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

travis: html Deque.log
	make clean
	ls -al
	make
	ls -al
	make run
	ls -al
	make -r check

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
