# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rusik/ClionProjects/huyorg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rusik/ClionProjects/huyorg/cmake-build-debug

# Include any dependencies generated for this target.
include test/libgtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include test/libgtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include test/libgtest/CMakeFiles/gtest.dir/flags.make

test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: test/libgtest/CMakeFiles/gtest.dir/flags.make
test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: /Users/rusik/Downloads/googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rusik/ClionProjects/huyorg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/libgtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /Users/rusik/Downloads/googletest/googletest/src/gtest-all.cc

test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/libgtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rusik/Downloads/googletest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/libgtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rusik/Downloads/googletest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:

.PHONY : test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f test/libgtest/CMakeFiles/gtest.dir/build.make test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

test/libgtest/libgtest.a: test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
test/libgtest/libgtest.a: test/libgtest/CMakeFiles/gtest.dir/build.make
test/libgtest/libgtest.a: test/libgtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rusik/ClionProjects/huyorg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd /Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/libgtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/libgtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/libgtest/CMakeFiles/gtest.dir/build: test/libgtest/libgtest.a

.PHONY : test/libgtest/CMakeFiles/gtest.dir/build

test/libgtest/CMakeFiles/gtest.dir/requires: test/libgtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

.PHONY : test/libgtest/CMakeFiles/gtest.dir/requires

test/libgtest/CMakeFiles/gtest.dir/clean:
	cd /Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/libgtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : test/libgtest/CMakeFiles/gtest.dir/clean

test/libgtest/CMakeFiles/gtest.dir/depend:
	cd /Users/rusik/ClionProjects/huyorg/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rusik/ClionProjects/huyorg /Users/rusik/Downloads/googletest/googletest /Users/rusik/ClionProjects/huyorg/cmake-build-debug /Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/libgtest /Users/rusik/ClionProjects/huyorg/cmake-build-debug/test/libgtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/libgtest/CMakeFiles/gtest.dir/depend

