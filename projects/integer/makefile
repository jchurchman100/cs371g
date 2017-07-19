.DEFAULT_GOAL := all

FILES :=            \
    .gitignore      \
    integer-tests   \
    Integer.h       \
    Integer.log     \
    html            \
    makefile        \
    RunInteger.c++  \
    RunInteger.out  \
    TestInteger.c++ \
    TestInteger.out

# uncomment these:
#    .travis.yml                           \
#    integer-tests/GitHubID-RunInteger.out \

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

integer-tests:
	git clone https://github.com/cs371gt-summer-2017/integer-tests.git

html: Doxyfile Integer.h
	$(DOXYGEN) Doxyfile

Integer.log:
	git log > Integer.log

Doxyfile:
	$(DOXYGEN) -g
	# you must manually edit Doxyfile and
	# set EXTRACT_ALL     to YES
	# set EXTRACT_PRIVATE to YES
	# set EXTRACT_STATEIC to YES

RunInteger: Integer.h RunInteger.c++
	$(CXX) $(CXXFLAGS) RunInteger.c++ -o RunInteger
	-$(CLANG-CHECK) -extra-arg=-std=c++11          RunInteger.c++  --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze RunInteger.c++  --

RunInteger.c++x: RunInteger
	./RunInteger > RunInteger.tmp
	-diff RunInteger.tmp RunInteger.out

TestInteger: Integer.h TestInteger.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) TestInteger.c++ -o TestInteger $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestInteger.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestInteger.c++ --

TestInteger.c++x: TestInteger
	$(VALGRIND) ./TestInteger
	-$(GCOV) -b TestInteger.c++ | grep -A 5 "File '.*Integer.h'"

all: RunInteger TestInteger

check: $(FILES)

clean:
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  *.plist
	rm -f  *.tmp
	rm -f  RunInteger
	rm -f  TestInteger
	rm -rf *.dSYM
	rm -rf latex

config:
	git config -l

docker:
	docker run -it -v $(PWD):/usr/integer -w /usr/integer gpdowning/gcc

format:
	$(CLANG-FORMAT) -i Integer.h
	$(CLANG-FORMAT) -i RunInteger.c++
	$(CLANG-FORMAT) -i TestInteger.c++

run: RunInteger.c++x TestInteger.c++x

scrub:
	make clean
	rm -f  Integer.log
	rm -f  Doxyfile
	rm -rf integer-tests
	rm -rf html

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

travis: integer-tests html Integer.log
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
