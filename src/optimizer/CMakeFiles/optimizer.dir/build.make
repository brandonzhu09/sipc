# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /u/jnt6mq/sipc-brandon_zhu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u/jnt6mq/sipc-brandon_zhu

# Include any dependencies generated for this target.
include src/optimizer/CMakeFiles/optimizer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/optimizer/CMakeFiles/optimizer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/optimizer/CMakeFiles/optimizer.dir/progress.make

# Include the compile flags for this target's objects.
include src/optimizer/CMakeFiles/optimizer.dir/flags.make

src/optimizer/CMakeFiles/optimizer.dir/Optimizer.cpp.o: src/optimizer/CMakeFiles/optimizer.dir/flags.make
src/optimizer/CMakeFiles/optimizer.dir/Optimizer.cpp.o: src/optimizer/Optimizer.cpp
src/optimizer/CMakeFiles/optimizer.dir/Optimizer.cpp.o: src/optimizer/CMakeFiles/optimizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/optimizer/CMakeFiles/optimizer.dir/Optimizer.cpp.o"
	cd /u/jnt6mq/sipc-brandon_zhu/src/optimizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/optimizer/CMakeFiles/optimizer.dir/Optimizer.cpp.o -MF CMakeFiles/optimizer.dir/Optimizer.cpp.o.d -o CMakeFiles/optimizer.dir/Optimizer.cpp.o -c /u/jnt6mq/sipc-brandon_zhu/src/optimizer/Optimizer.cpp

src/optimizer/CMakeFiles/optimizer.dir/Optimizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/optimizer.dir/Optimizer.cpp.i"
	cd /u/jnt6mq/sipc-brandon_zhu/src/optimizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/jnt6mq/sipc-brandon_zhu/src/optimizer/Optimizer.cpp > CMakeFiles/optimizer.dir/Optimizer.cpp.i

src/optimizer/CMakeFiles/optimizer.dir/Optimizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/optimizer.dir/Optimizer.cpp.s"
	cd /u/jnt6mq/sipc-brandon_zhu/src/optimizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/jnt6mq/sipc-brandon_zhu/src/optimizer/Optimizer.cpp -o CMakeFiles/optimizer.dir/Optimizer.cpp.s

# Object files for target optimizer
optimizer_OBJECTS = \
"CMakeFiles/optimizer.dir/Optimizer.cpp.o"

# External object files for target optimizer
optimizer_EXTERNAL_OBJECTS =

src/optimizer/liboptimizer.a: src/optimizer/CMakeFiles/optimizer.dir/Optimizer.cpp.o
src/optimizer/liboptimizer.a: src/optimizer/CMakeFiles/optimizer.dir/build.make
src/optimizer/liboptimizer.a: src/optimizer/CMakeFiles/optimizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liboptimizer.a"
	cd /u/jnt6mq/sipc-brandon_zhu/src/optimizer && $(CMAKE_COMMAND) -P CMakeFiles/optimizer.dir/cmake_clean_target.cmake
	cd /u/jnt6mq/sipc-brandon_zhu/src/optimizer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/optimizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/optimizer/CMakeFiles/optimizer.dir/build: src/optimizer/liboptimizer.a
.PHONY : src/optimizer/CMakeFiles/optimizer.dir/build

src/optimizer/CMakeFiles/optimizer.dir/clean:
	cd /u/jnt6mq/sipc-brandon_zhu/src/optimizer && $(CMAKE_COMMAND) -P CMakeFiles/optimizer.dir/cmake_clean.cmake
.PHONY : src/optimizer/CMakeFiles/optimizer.dir/clean

src/optimizer/CMakeFiles/optimizer.dir/depend:
	cd /u/jnt6mq/sipc-brandon_zhu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/jnt6mq/sipc-brandon_zhu /u/jnt6mq/sipc-brandon_zhu/src/optimizer /u/jnt6mq/sipc-brandon_zhu /u/jnt6mq/sipc-brandon_zhu/src/optimizer /u/jnt6mq/sipc-brandon_zhu/src/optimizer/CMakeFiles/optimizer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/optimizer/CMakeFiles/optimizer.dir/depend

