# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ryan/dev/rational/gtest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ryan/dev/rational/gtest/mybuild

# Include any dependencies generated for this target.
include CMakeFiles/sample10_unittest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sample10_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sample10_unittest.dir/flags.make

CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o: CMakeFiles/sample10_unittest.dir/flags.make
CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o: ../samples/sample10_unittest.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ryan/dev/rational/gtest/mybuild/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Wall -Wshadow -DGTEST_HAS_PTHREAD=1 -fexceptions -o CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o -c /home/ryan/dev/rational/gtest/samples/sample10_unittest.cc

CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Wall -Wshadow -DGTEST_HAS_PTHREAD=1 -fexceptions -E /home/ryan/dev/rational/gtest/samples/sample10_unittest.cc > CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.i

CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Wall -Wshadow -DGTEST_HAS_PTHREAD=1 -fexceptions -S /home/ryan/dev/rational/gtest/samples/sample10_unittest.cc -o CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.s

CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o.requires:
.PHONY : CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o.requires

CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o.provides: CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o.requires
	$(MAKE) -f CMakeFiles/sample10_unittest.dir/build.make CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o.provides.build
.PHONY : CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o.provides

CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o.provides.build: CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o
.PHONY : CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o.provides.build

# Object files for target sample10_unittest
sample10_unittest_OBJECTS = \
"CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o"

# External object files for target sample10_unittest
sample10_unittest_EXTERNAL_OBJECTS =

sample10_unittest: CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o
sample10_unittest: libgtest.a
sample10_unittest: CMakeFiles/sample10_unittest.dir/build.make
sample10_unittest: CMakeFiles/sample10_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sample10_unittest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample10_unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sample10_unittest.dir/build: sample10_unittest
.PHONY : CMakeFiles/sample10_unittest.dir/build

CMakeFiles/sample10_unittest.dir/requires: CMakeFiles/sample10_unittest.dir/samples/sample10_unittest.cc.o.requires
.PHONY : CMakeFiles/sample10_unittest.dir/requires

CMakeFiles/sample10_unittest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sample10_unittest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sample10_unittest.dir/clean

CMakeFiles/sample10_unittest.dir/depend:
	cd /home/ryan/dev/rational/gtest/mybuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ryan/dev/rational/gtest /home/ryan/dev/rational/gtest /home/ryan/dev/rational/gtest/mybuild /home/ryan/dev/rational/gtest/mybuild /home/ryan/dev/rational/gtest/mybuild/CMakeFiles/sample10_unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sample10_unittest.dir/depend

