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
include src/frontend/CMakeFiles/antlrgen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/frontend/CMakeFiles/antlrgen.dir/compiler_depend.make

# Include the progress variables for this target.
include src/frontend/CMakeFiles/antlrgen.dir/progress.make

# Include the compile flags for this target's objects.
include src/frontend/CMakeFiles/antlrgen.dir/flags.make

src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp: src/frontend/TIP.g4
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building TIPGrammar with ANTLR 4.13.1"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/java -jar /u/jnt6mq/sipc-brandon_zhu/include/antlr-4.13.1-complete.jar TIP.g4 -o /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP -no-listener -Dlanguage=Cpp -visitor

src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.tokens: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.tokens

src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.h: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.h

src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.cpp: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.cpp

src/frontend/antlr4cpp_generated_src/TIP/TIPParser.h: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/frontend/antlr4cpp_generated_src/TIP/TIPParser.h

src/frontend/antlr4cpp_generated_src/TIP/TIPParser.cpp: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/frontend/antlr4cpp_generated_src/TIP/TIPParser.cpp

src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.h: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.h

src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp

src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.h: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.h

src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.cpp: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.cpp

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.o: src/frontend/CMakeFiles/antlrgen.dir/flags.make
src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.o: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.cpp
src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.o: src/frontend/CMakeFiles/antlrgen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.o"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.o -MF CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.o.d -o CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.o -c /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.cpp

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.i"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.cpp > CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.i

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.s"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.cpp -o CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.s

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.o: src/frontend/CMakeFiles/antlrgen.dir/flags.make
src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.o: src/frontend/antlr4cpp_generated_src/TIP/TIPParser.cpp
src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.o: src/frontend/CMakeFiles/antlrgen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.o"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.o -MF CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.o.d -o CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.o -c /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPParser.cpp

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.i"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPParser.cpp > CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.i

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.s"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPParser.cpp -o CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.s

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.o: src/frontend/CMakeFiles/antlrgen.dir/flags.make
src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.o: src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp
src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.o: src/frontend/CMakeFiles/antlrgen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.o"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.o -MF CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.o.d -o CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.o -c /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.i"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp > CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.i

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.s"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp -o CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.s

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.o: src/frontend/CMakeFiles/antlrgen.dir/flags.make
src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.o: src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.cpp
src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.o: src/frontend/CMakeFiles/antlrgen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.o"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.o -MF CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.o.d -o CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.o -c /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.cpp

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.i"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.cpp > CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.i

src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.s"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/jnt6mq/sipc-brandon_zhu/src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.cpp -o CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.s

# Object files for target antlrgen
antlrgen_OBJECTS = \
"CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.o" \
"CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.o" \
"CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.o" \
"CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.o"

# External object files for target antlrgen
antlrgen_EXTERNAL_OBJECTS =

src/frontend/libantlrgen.a: src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPLexer.cpp.o
src/frontend/libantlrgen.a: src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPParser.cpp.o
src/frontend/libantlrgen.a: src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp.o
src/frontend/libantlrgen.a: src/frontend/CMakeFiles/antlrgen.dir/antlr4cpp_generated_src/TIP/TIPVisitor.cpp.o
src/frontend/libantlrgen.a: src/frontend/CMakeFiles/antlrgen.dir/build.make
src/frontend/libantlrgen.a: src/frontend/CMakeFiles/antlrgen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/u/jnt6mq/sipc-brandon_zhu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libantlrgen.a"
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && $(CMAKE_COMMAND) -P CMakeFiles/antlrgen.dir/cmake_clean_target.cmake
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/antlrgen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/frontend/CMakeFiles/antlrgen.dir/build: src/frontend/libantlrgen.a
.PHONY : src/frontend/CMakeFiles/antlrgen.dir/build

src/frontend/CMakeFiles/antlrgen.dir/clean:
	cd /u/jnt6mq/sipc-brandon_zhu/src/frontend && $(CMAKE_COMMAND) -P CMakeFiles/antlrgen.dir/cmake_clean.cmake
.PHONY : src/frontend/CMakeFiles/antlrgen.dir/clean

src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.cpp
src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPBaseVisitor.h
src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.cpp
src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.h
src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.interp
src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPLexer.tokens
src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPParser.cpp
src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPParser.h
src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.cpp
src/frontend/CMakeFiles/antlrgen.dir/depend: src/frontend/antlr4cpp_generated_src/TIP/TIPVisitor.h
	cd /u/jnt6mq/sipc-brandon_zhu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/jnt6mq/sipc-brandon_zhu /u/jnt6mq/sipc-brandon_zhu/src/frontend /u/jnt6mq/sipc-brandon_zhu /u/jnt6mq/sipc-brandon_zhu/src/frontend /u/jnt6mq/sipc-brandon_zhu/src/frontend/CMakeFiles/antlrgen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/frontend/CMakeFiles/antlrgen.dir/depend

