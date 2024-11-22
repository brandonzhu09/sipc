# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Run CPack packaging tool..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package
.PHONY : package/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Run CPack packaging tool for source..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cpack --config ./CPackSourceConfig.cmake /u/jnt6mq/sipc-brandon_zhu/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source
.PHONY : package_source/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running tests..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/sw/ubuntu-22.04/cmake/3.26.4/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Available install components are: \"Unspecified\" \"dev\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/u/jnt6mq/.cache/JetBrains/RemoteDev/dist/ce40994fdc0ab_CLion-2024.2.1/bin/cmake/linux/x64/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /u/jnt6mq/sipc-brandon_zhu/CMakeFiles /u/jnt6mq/sipc-brandon_zhu//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /u/jnt6mq/sipc-brandon_zhu/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named intrinsics_gen

# Build rule for target.
intrinsics_gen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 intrinsics_gen
.PHONY : intrinsics_gen

# fast build rule for target.
intrinsics_gen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/intrinsics_gen.dir/build.make CMakeFiles/intrinsics_gen.dir/build
.PHONY : intrinsics_gen/fast

#=============================================================================
# Target rules for targets named omp_gen

# Build rule for target.
omp_gen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 omp_gen
.PHONY : omp_gen

# fast build rule for target.
omp_gen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/omp_gen.dir/build.make CMakeFiles/omp_gen.dir/build
.PHONY : omp_gen/fast

#=============================================================================
# Target rules for targets named acc_gen

# Build rule for target.
acc_gen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 acc_gen
.PHONY : acc_gen

# fast build rule for target.
acc_gen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/acc_gen.dir/build.make CMakeFiles/acc_gen.dir/build
.PHONY : acc_gen/fast

#=============================================================================
# Target rules for targets named loguru

# Build rule for target.
loguru: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 loguru
.PHONY : loguru

# fast build rule for target.
loguru/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/loguru.dir/build.make CMakeFiles/loguru.dir/build
.PHONY : loguru/fast

#=============================================================================
# Target rules for targets named antlr4_static

# Build rule for target.
antlr4_static: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 antlr4_static
.PHONY : antlr4_static

# fast build rule for target.
antlr4_static/fast:
	$(MAKE) $(MAKESILENT) -f _deps/antlr-build/runtime/CMakeFiles/antlr4_static.dir/build.make _deps/antlr-build/runtime/CMakeFiles/antlr4_static.dir/build
.PHONY : antlr4_static/fast

#=============================================================================
# Target rules for targets named tipc

# Build rule for target.
tipc: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 tipc
.PHONY : tipc

# fast build rule for target.
tipc/fast:
	$(MAKE) $(MAKESILENT) -f src/CMakeFiles/tipc.dir/build.make src/CMakeFiles/tipc.dir/build
.PHONY : tipc/fast

#=============================================================================
# Target rules for targets named error

# Build rule for target.
error: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 error
.PHONY : error

# fast build rule for target.
error/fast:
	$(MAKE) $(MAKESILENT) -f src/error/CMakeFiles/error.dir/build.make src/error/CMakeFiles/error.dir/build
.PHONY : error/fast

#=============================================================================
# Target rules for targets named antlrgen

# Build rule for target.
antlrgen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 antlrgen
.PHONY : antlrgen

# fast build rule for target.
antlrgen/fast:
	$(MAKE) $(MAKESILENT) -f src/frontend/CMakeFiles/antlrgen.dir/build.make src/frontend/CMakeFiles/antlrgen.dir/build
.PHONY : antlrgen/fast

#=============================================================================
# Target rules for targets named frontend

# Build rule for target.
frontend: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 frontend
.PHONY : frontend

# fast build rule for target.
frontend/fast:
	$(MAKE) $(MAKESILENT) -f src/frontend/CMakeFiles/frontend.dir/build.make src/frontend/CMakeFiles/frontend.dir/build
.PHONY : frontend/fast

#=============================================================================
# Target rules for targets named ast

# Build rule for target.
ast: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ast
.PHONY : ast

# fast build rule for target.
ast/fast:
	$(MAKE) $(MAKESILENT) -f src/frontend/ast/CMakeFiles/ast.dir/build.make src/frontend/ast/CMakeFiles/ast.dir/build
.PHONY : ast/fast

#=============================================================================
# Target rules for targets named iterators

# Build rule for target.
iterators: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 iterators
.PHONY : iterators

# fast build rule for target.
iterators/fast:
	$(MAKE) $(MAKESILENT) -f src/frontend/iterators/CMakeFiles/iterators.dir/build.make src/frontend/iterators/CMakeFiles/iterators.dir/build
.PHONY : iterators/fast

#=============================================================================
# Target rules for targets named prettyprint

# Build rule for target.
prettyprint: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 prettyprint
.PHONY : prettyprint

# fast build rule for target.
prettyprint/fast:
	$(MAKE) $(MAKESILENT) -f src/frontend/prettyprint/CMakeFiles/prettyprint.dir/build.make src/frontend/prettyprint/CMakeFiles/prettyprint.dir/build
.PHONY : prettyprint/fast

#=============================================================================
# Target rules for targets named semantic

# Build rule for target.
semantic: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 semantic
.PHONY : semantic

# fast build rule for target.
semantic/fast:
	$(MAKE) $(MAKESILENT) -f src/semantic/CMakeFiles/semantic.dir/build.make src/semantic/CMakeFiles/semantic.dir/build
.PHONY : semantic/fast

#=============================================================================
# Target rules for targets named weeding

# Build rule for target.
weeding: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 weeding
.PHONY : weeding

# fast build rule for target.
weeding/fast:
	$(MAKE) $(MAKESILENT) -f src/semantic/weeding/CMakeFiles/weeding.dir/build.make src/semantic/weeding/CMakeFiles/weeding.dir/build
.PHONY : weeding/fast

#=============================================================================
# Target rules for targets named symboltable

# Build rule for target.
symboltable: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 symboltable
.PHONY : symboltable

# fast build rule for target.
symboltable/fast:
	$(MAKE) $(MAKESILENT) -f src/semantic/symboltable/CMakeFiles/symboltable.dir/build.make src/semantic/symboltable/CMakeFiles/symboltable.dir/build
.PHONY : symboltable/fast

#=============================================================================
# Target rules for targets named types

# Build rule for target.
types: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 types
.PHONY : types

# fast build rule for target.
types/fast:
	$(MAKE) $(MAKESILENT) -f src/semantic/types/CMakeFiles/types.dir/build.make src/semantic/types/CMakeFiles/types.dir/build
.PHONY : types/fast

#=============================================================================
# Target rules for targets named cfa

# Build rule for target.
cfa: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 cfa
.PHONY : cfa

# fast build rule for target.
cfa/fast:
	$(MAKE) $(MAKESILENT) -f src/semantic/cfa/CMakeFiles/cfa.dir/build.make src/semantic/cfa/CMakeFiles/cfa.dir/build
.PHONY : cfa/fast

#=============================================================================
# Target rules for targets named codegen

# Build rule for target.
codegen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 codegen
.PHONY : codegen

# fast build rule for target.
codegen/fast:
	$(MAKE) $(MAKESILENT) -f src/codegen/CMakeFiles/codegen.dir/build.make src/codegen/CMakeFiles/codegen.dir/build
.PHONY : codegen/fast

#=============================================================================
# Target rules for targets named optimizer

# Build rule for target.
optimizer: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optimizer
.PHONY : optimizer

# fast build rule for target.
optimizer/fast:
	$(MAKE) $(MAKESILENT) -f src/optimizer/CMakeFiles/optimizer.dir/build.make src/optimizer/CMakeFiles/optimizer.dir/build
.PHONY : optimizer/fast

#=============================================================================
# Target rules for targets named Catch2

# Build rule for target.
Catch2: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Catch2
.PHONY : Catch2

# fast build rule for target.
Catch2/fast:
	$(MAKE) $(MAKESILENT) -f _deps/catch2-build/src/CMakeFiles/Catch2.dir/build.make _deps/catch2-build/src/CMakeFiles/Catch2.dir/build
.PHONY : Catch2/fast

#=============================================================================
# Target rules for targets named Catch2WithMain

# Build rule for target.
Catch2WithMain: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Catch2WithMain
.PHONY : Catch2WithMain

# fast build rule for target.
Catch2WithMain/fast:
	$(MAKE) $(MAKESILENT) -f _deps/catch2-build/src/CMakeFiles/Catch2WithMain.dir/build.make _deps/catch2-build/src/CMakeFiles/Catch2WithMain.dir/build
.PHONY : Catch2WithMain/fast

#=============================================================================
# Target rules for targets named test_helpers

# Build rule for target.
test_helpers: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_helpers
.PHONY : test_helpers

# fast build rule for target.
test_helpers/fast:
	$(MAKE) $(MAKESILENT) -f test/unit/helpers/CMakeFiles/test_helpers.dir/build.make test/unit/helpers/CMakeFiles/test_helpers.dir/build
.PHONY : test_helpers/fast

#=============================================================================
# Target rules for targets named codegen_unit_tests

# Build rule for target.
codegen_unit_tests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 codegen_unit_tests
.PHONY : codegen_unit_tests

# fast build rule for target.
codegen_unit_tests/fast:
	$(MAKE) $(MAKESILENT) -f test/unit/codegen/CMakeFiles/codegen_unit_tests.dir/build.make test/unit/codegen/CMakeFiles/codegen_unit_tests.dir/build
.PHONY : codegen_unit_tests/fast

#=============================================================================
# Target rules for targets named frontend_unit_tests

# Build rule for target.
frontend_unit_tests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 frontend_unit_tests
.PHONY : frontend_unit_tests

# fast build rule for target.
frontend_unit_tests/fast:
	$(MAKE) $(MAKESILENT) -f test/unit/frontend/CMakeFiles/frontend_unit_tests.dir/build.make test/unit/frontend/CMakeFiles/frontend_unit_tests.dir/build
.PHONY : frontend_unit_tests/fast

#=============================================================================
# Target rules for targets named semantic_unit_tests

# Build rule for target.
semantic_unit_tests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 semantic_unit_tests
.PHONY : semantic_unit_tests

# fast build rule for target.
semantic_unit_tests/fast:
	$(MAKE) $(MAKESILENT) -f test/unit/semantic/CMakeFiles/semantic_unit_tests.dir/build.make test/unit/semantic/CMakeFiles/semantic_unit_tests.dir/build
.PHONY : semantic_unit_tests/fast

#=============================================================================
# Target rules for targets named typeinference_unit_tests

# Build rule for target.
typeinference_unit_tests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 typeinference_unit_tests
.PHONY : typeinference_unit_tests

# fast build rule for target.
typeinference_unit_tests/fast:
	$(MAKE) $(MAKESILENT) -f test/unit/semantic/types/CMakeFiles/typeinference_unit_tests.dir/build.make test/unit/semantic/types/CMakeFiles/typeinference_unit_tests.dir/build
.PHONY : typeinference_unit_tests/fast

#=============================================================================
# Target rules for targets named call_graph_unit_tests

# Build rule for target.
call_graph_unit_tests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 call_graph_unit_tests
.PHONY : call_graph_unit_tests

# fast build rule for target.
call_graph_unit_tests/fast:
	$(MAKE) $(MAKESILENT) -f test/unit/semantic/cfa/CMakeFiles/call_graph_unit_tests.dir/build.make test/unit/semantic/cfa/CMakeFiles/call_graph_unit_tests.dir/build
.PHONY : call_graph_unit_tests/fast

externals/loguru/loguru.o: externals/loguru/loguru.cpp.o
.PHONY : externals/loguru/loguru.o

# target to build an object file
externals/loguru/loguru.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/loguru.dir/build.make CMakeFiles/loguru.dir/externals/loguru/loguru.cpp.o
.PHONY : externals/loguru/loguru.cpp.o

externals/loguru/loguru.i: externals/loguru/loguru.cpp.i
.PHONY : externals/loguru/loguru.i

# target to preprocess a source file
externals/loguru/loguru.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/loguru.dir/build.make CMakeFiles/loguru.dir/externals/loguru/loguru.cpp.i
.PHONY : externals/loguru/loguru.cpp.i

externals/loguru/loguru.s: externals/loguru/loguru.cpp.s
.PHONY : externals/loguru/loguru.s

# target to generate assembly for a file
externals/loguru/loguru.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/loguru.dir/build.make CMakeFiles/loguru.dir/externals/loguru/loguru.cpp.s
.PHONY : externals/loguru/loguru.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... package"
	@echo "... package_source"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... acc_gen"
	@echo "... intrinsics_gen"
	@echo "... omp_gen"
	@echo "... Catch2"
	@echo "... Catch2WithMain"
	@echo "... antlr4_static"
	@echo "... antlrgen"
	@echo "... ast"
	@echo "... call_graph_unit_tests"
	@echo "... cfa"
	@echo "... codegen"
	@echo "... codegen_unit_tests"
	@echo "... error"
	@echo "... frontend"
	@echo "... frontend_unit_tests"
	@echo "... iterators"
	@echo "... loguru"
	@echo "... optimizer"
	@echo "... prettyprint"
	@echo "... semantic"
	@echo "... semantic_unit_tests"
	@echo "... symboltable"
	@echo "... test_helpers"
	@echo "... tipc"
	@echo "... typeinference_unit_tests"
	@echo "... types"
	@echo "... weeding"
	@echo "... externals/loguru/loguru.o"
	@echo "... externals/loguru/loguru.i"
	@echo "... externals/loguru/loguru.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

