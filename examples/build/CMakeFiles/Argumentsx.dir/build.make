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

# Utility rule file for Argumentsx.

# Include the progress variables for this target.
include CMakeFiles/Argumentsx.dir/progress.make

CMakeFiles/Argumentsx:
	./Arguments

Argumentsx: CMakeFiles/Argumentsx
Argumentsx: CMakeFiles/Argumentsx.dir/build.make

.PHONY : Argumentsx

# Rule to build all files generated by this target.
CMakeFiles/Argumentsx.dir/build: Argumentsx

.PHONY : CMakeFiles/Argumentsx.dir/build

CMakeFiles/Argumentsx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Argumentsx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Argumentsx.dir/clean

CMakeFiles/Argumentsx.dir/depend:
	cd /Users/downing/cs371g/github/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/downing/cs371g/github/examples /Users/downing/cs371g/github/examples /Users/downing/cs371g/github/examples/build /Users/downing/cs371g/github/examples/build /Users/downing/cs371g/github/examples/build/CMakeFiles/Argumentsx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Argumentsx.dir/depend

