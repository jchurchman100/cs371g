# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.8.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.8.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/downing/cs371g/github/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/downing/cs371g/github/examples/build

# Include any dependencies generated for this target.
include CMakeFiles/FunctionOverloading.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FunctionOverloading.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FunctionOverloading.dir/flags.make

CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o: CMakeFiles/FunctionOverloading.dir/flags.make
CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o: ../FunctionOverloading.c++
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/downing/cs371g/github/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o -c /Users/downing/cs371g/github/examples/FunctionOverloading.c++

CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/downing/cs371g/github/examples/FunctionOverloading.c++ > CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.i

CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/downing/cs371g/github/examples/FunctionOverloading.c++ -o CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.s

CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o.requires:

.PHONY : CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o.requires

CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o.provides: CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o.requires
	$(MAKE) -f CMakeFiles/FunctionOverloading.dir/build.make CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o.provides.build
.PHONY : CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o.provides

CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o.provides.build: CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o


# Object files for target FunctionOverloading
FunctionOverloading_OBJECTS = \
"CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o"

# External object files for target FunctionOverloading
FunctionOverloading_EXTERNAL_OBJECTS =

FunctionOverloading: CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o
FunctionOverloading: CMakeFiles/FunctionOverloading.dir/build.make
FunctionOverloading: CMakeFiles/FunctionOverloading.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/downing/cs371g/github/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FunctionOverloading"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FunctionOverloading.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FunctionOverloading.dir/build: FunctionOverloading

.PHONY : CMakeFiles/FunctionOverloading.dir/build

CMakeFiles/FunctionOverloading.dir/requires: CMakeFiles/FunctionOverloading.dir/FunctionOverloading.c++.o.requires

.PHONY : CMakeFiles/FunctionOverloading.dir/requires

CMakeFiles/FunctionOverloading.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FunctionOverloading.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FunctionOverloading.dir/clean

CMakeFiles/FunctionOverloading.dir/depend:
	cd /Users/downing/cs371g/github/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/downing/cs371g/github/examples /Users/downing/cs371g/github/examples /Users/downing/cs371g/github/examples/build /Users/downing/cs371g/github/examples/build /Users/downing/cs371g/github/examples/build/CMakeFiles/FunctionOverloading.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FunctionOverloading.dir/depend

