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
include src/codegen/CMakeFiles/codegen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/codegen/CMakeFiles/codegen.dir/compiler_depend.make

# Include the progress variables for this target.
include src/codegen/CMakeFiles/codegen.dir/progress.make

# Include the compile flags for this target's objects.
include src/codegen/CMakeFiles/codegen.dir/flags.make

src/codegen/CMakeFiles/codegen.dir/CodeGenerator.cpp.o: src/codegen/CMakeFiles/codegen.dir/flags.make
src/codegen/CMakeFiles/codegen.dir/CodeGenerator.cpp.o: src/codegen/CodeGenerator.cpp
src/codegen/CMakeFiles/codegen.dir/CodeGenerator.cpp.o: src/codegen/CMakeFiles/codegen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/codegen/CMakeFiles/codegen.dir/CodeGenerator.cpp.o"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/codegen/CMakeFiles/codegen.dir/CodeGenerator.cpp.o -MF CMakeFiles/codegen.dir/CodeGenerator.cpp.o.d -o CMakeFiles/codegen.dir/CodeGenerator.cpp.o -c /u/jnt6mq/sipc-brandon_zhu/src/codegen/CodeGenerator.cpp

src/codegen/CMakeFiles/codegen.dir/CodeGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/codegen.dir/CodeGenerator.cpp.i"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/jnt6mq/sipc-brandon_zhu/src/codegen/CodeGenerator.cpp > CMakeFiles/codegen.dir/CodeGenerator.cpp.i

src/codegen/CMakeFiles/codegen.dir/CodeGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/codegen.dir/CodeGenerator.cpp.s"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/jnt6mq/sipc-brandon_zhu/src/codegen/CodeGenerator.cpp -o CMakeFiles/codegen.dir/CodeGenerator.cpp.s

src/codegen/CMakeFiles/codegen.dir/CodeGenFunctions.cpp.o: src/codegen/CMakeFiles/codegen.dir/flags.make
src/codegen/CMakeFiles/codegen.dir/CodeGenFunctions.cpp.o: src/codegen/CodeGenFunctions.cpp
src/codegen/CMakeFiles/codegen.dir/CodeGenFunctions.cpp.o: src/codegen/CMakeFiles/codegen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/codegen/CMakeFiles/codegen.dir/CodeGenFunctions.cpp.o"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/codegen/CMakeFiles/codegen.dir/CodeGenFunctions.cpp.o -MF CMakeFiles/codegen.dir/CodeGenFunctions.cpp.o.d -o CMakeFiles/codegen.dir/CodeGenFunctions.cpp.o -c /u/jnt6mq/sipc-brandon_zhu/src/codegen/CodeGenFunctions.cpp

src/codegen/CMakeFiles/codegen.dir/CodeGenFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/codegen.dir/CodeGenFunctions.cpp.i"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/jnt6mq/sipc-brandon_zhu/src/codegen/CodeGenFunctions.cpp > CMakeFiles/codegen.dir/CodeGenFunctions.cpp.i

src/codegen/CMakeFiles/codegen.dir/CodeGenFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/codegen.dir/CodeGenFunctions.cpp.s"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/jnt6mq/sipc-brandon_zhu/src/codegen/CodeGenFunctions.cpp -o CMakeFiles/codegen.dir/CodeGenFunctions.cpp.s

src/codegen/CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.o: src/codegen/CMakeFiles/codegen.dir/flags.make
src/codegen/CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.o: externals/loguru/loguru.cpp
src/codegen/CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.o: src/codegen/CMakeFiles/codegen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/codegen/CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.o"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/codegen/CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.o -MF CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.o.d -o CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.o -c /u/jnt6mq/sipc-brandon_zhu/externals/loguru/loguru.cpp

src/codegen/CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.i"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/jnt6mq/sipc-brandon_zhu/externals/loguru/loguru.cpp > CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.i

src/codegen/CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.s"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/jnt6mq/sipc-brandon_zhu/externals/loguru/loguru.cpp -o CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.s

# Object files for target codegen
codegen_OBJECTS = \
"CMakeFiles/codegen.dir/CodeGenerator.cpp.o" \
"CMakeFiles/codegen.dir/CodeGenFunctions.cpp.o" \
"CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.o"

# External object files for target codegen
codegen_EXTERNAL_OBJECTS =

src/codegen/libcodegen.a: src/codegen/CMakeFiles/codegen.dir/CodeGenerator.cpp.o
src/codegen/libcodegen.a: src/codegen/CMakeFiles/codegen.dir/CodeGenFunctions.cpp.o
src/codegen/libcodegen.a: src/codegen/CMakeFiles/codegen.dir/__/__/externals/loguru/loguru.cpp.o
src/codegen/libcodegen.a: src/codegen/CMakeFiles/codegen.dir/build.make
src/codegen/libcodegen.a: src/codegen/CMakeFiles/codegen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libcodegen.a"
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && $(CMAKE_COMMAND) -P CMakeFiles/codegen.dir/cmake_clean_target.cmake
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codegen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/codegen/CMakeFiles/codegen.dir/build: src/codegen/libcodegen.a
.PHONY : src/codegen/CMakeFiles/codegen.dir/build

src/codegen/CMakeFiles/codegen.dir/clean:
	cd /u/jnt6mq/sipc-brandon_zhu/src/codegen && $(CMAKE_COMMAND) -P CMakeFiles/codegen.dir/cmake_clean.cmake
.PHONY : src/codegen/CMakeFiles/codegen.dir/clean

src/codegen/CMakeFiles/codegen.dir/depend:
	cd /u/jnt6mq/sipc-brandon_zhu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/jnt6mq/sipc-brandon_zhu /u/jnt6mq/sipc-brandon_zhu/src/codegen /u/jnt6mq/sipc-brandon_zhu /u/jnt6mq/sipc-brandon_zhu/src/codegen /u/jnt6mq/sipc-brandon_zhu/src/codegen/CMakeFiles/codegen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/codegen/CMakeFiles/codegen.dir/depend

