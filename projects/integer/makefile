.DEFAULT_GOAL := all

FILES :=            \
    .gitignore      \
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

RunInteger.tmp: RunInteger
	./RunInteger > RunInteger.tmp
	-diff RunInteger.tmp RunInteger.out

TestInteger: Integer.h TestInteger.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) TestInteger.c++ -o TestInteger $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestInteger.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestInteger.c++ --

TestInteger.tmp: TestInteger
	$(VALGRIND) ./TestInteger                                    >  TestInteger.tmp 2>&1
	-$(GCOV) -b TestInteger.c++ | grep -A 5 "File '.*Integer.h'" >> TestInteger.tmp
	cat TestInteger.tmp

all: RunInteger TestInteger

check:
	@not_found=0;                                 \
    for i in $(FILES);                            \
    do                                            \
        if [ -e $$i ];                            \
        then                                      \
            echo "$$i found";                     \
        else                                      \
            echo "$$i NOT FOUND";                 \
            not_found=`expr "$$not_found" + "1"`; \
        fi                                        \
    done;                                         \
    if [ $$not_found -ne 0 ];                     \
    then                                          \
        echo "$$not_found failures";              \
        exit 1;                                   \
    fi;                                           \
    echo "success";

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
	docker run -it -v $(PWD):/usr/cs371g -w /usr/cs371g gpdowning/gcc

format:
	$(CLANG-FORMAT) -i Integer.h
	$(CLANG-FORMAT) -i RunInteger.c++
	$(CLANG-FORMAT) -i TestInteger.c++

run: RunInteger.tmp

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

test: TestInteger.tmp

travis: integer-tests html Integer.log
	make clean
	ls -al
	make
	ls -al
	make run
	ls -al
	make test
	ls -al
	make check

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
	ls -ald $(INCLUDE)/boost
	@echo
	ls -ald $(INCLUDE)/gtest
	@echo
	ls -al $(LIBB)/*boost*
	@echo
	ls -al $(LIBG)/*gtest*
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
