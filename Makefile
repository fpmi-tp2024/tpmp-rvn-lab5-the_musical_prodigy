# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/ТПМП/lab5/Music_salon/tpmp-rvn-lab5-the_musical_prodigy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/ТПМП/lab5/Music_salon/tpmp-rvn-lab5-the_musical_prodigy

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\" \"headers\" \"libraries\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/ТПМП/lab5/Music_salon/tpmp-rvn-lab5-the_musical_prodigy/CMakeFiles /mnt/d/ТПМП/lab5/Music_salon/tpmp-rvn-lab5-the_musical_prodigy//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/ТПМП/lab5/Music_salon/tpmp-rvn-lab5-the_musical_prodigy/CMakeFiles 0
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
# Target rules for targets named solution

# Build rule for target.
solution: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 solution
.PHONY : solution

# fast build rule for target.
solution/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/build
.PHONY : solution/fast

#=============================================================================
# Target rules for targets named SQLiteCpp

# Build rule for target.
SQLiteCpp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 SQLiteCpp
.PHONY : SQLiteCpp

# fast build rule for target.
SQLiteCpp/fast:
	$(MAKE) $(MAKESILENT) -f SQLiteCpp/CMakeFiles/SQLiteCpp.dir/build.make SQLiteCpp/CMakeFiles/SQLiteCpp.dir/build
.PHONY : SQLiteCpp/fast

#=============================================================================
# Target rules for targets named SQLiteCpp_cpplint

# Build rule for target.
SQLiteCpp_cpplint: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 SQLiteCpp_cpplint
.PHONY : SQLiteCpp_cpplint

# fast build rule for target.
SQLiteCpp_cpplint/fast:
	$(MAKE) $(MAKESILENT) -f SQLiteCpp/CMakeFiles/SQLiteCpp_cpplint.dir/build.make SQLiteCpp/CMakeFiles/SQLiteCpp_cpplint.dir/build
.PHONY : SQLiteCpp_cpplint/fast

#=============================================================================
# Target rules for targets named sqlite3

# Build rule for target.
sqlite3: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 sqlite3
.PHONY : sqlite3

# fast build rule for target.
sqlite3/fast:
	$(MAKE) $(MAKESILENT) -f SQLiteCpp/sqlite3/CMakeFiles/sqlite3.dir/build.make SQLiteCpp/sqlite3/CMakeFiles/sqlite3.dir/build
.PHONY : sqlite3/fast

MusicSalon.o: MusicSalon.cpp.o
.PHONY : MusicSalon.o

# target to build an object file
MusicSalon.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/MusicSalon.cpp.o
.PHONY : MusicSalon.cpp.o

MusicSalon.i: MusicSalon.cpp.i
.PHONY : MusicSalon.i

# target to preprocess a source file
MusicSalon.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/MusicSalon.cpp.i
.PHONY : MusicSalon.cpp.i

MusicSalon.s: MusicSalon.cpp.s
.PHONY : MusicSalon.s

# target to generate assembly for a file
MusicSalon.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/MusicSalon.cpp.s
.PHONY : MusicSalon.cpp.s

src/Controller/controller.o: src/Controller/controller.cpp.o
.PHONY : src/Controller/controller.o

# target to build an object file
src/Controller/controller.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Controller/controller.cpp.o
.PHONY : src/Controller/controller.cpp.o

src/Controller/controller.i: src/Controller/controller.cpp.i
.PHONY : src/Controller/controller.i

# target to preprocess a source file
src/Controller/controller.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Controller/controller.cpp.i
.PHONY : src/Controller/controller.cpp.i

src/Controller/controller.s: src/Controller/controller.cpp.s
.PHONY : src/Controller/controller.s

# target to generate assembly for a file
src/Controller/controller.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Controller/controller.cpp.s
.PHONY : src/Controller/controller.cpp.s

src/Model/CD.o: src/Model/CD.cpp.o
.PHONY : src/Model/CD.o

# target to build an object file
src/Model/CD.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/CD.cpp.o
.PHONY : src/Model/CD.cpp.o

src/Model/CD.i: src/Model/CD.cpp.i
.PHONY : src/Model/CD.i

# target to preprocess a source file
src/Model/CD.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/CD.cpp.i
.PHONY : src/Model/CD.cpp.i

src/Model/CD.s: src/Model/CD.cpp.s
.PHONY : src/Model/CD.s

# target to generate assembly for a file
src/Model/CD.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/CD.cpp.s
.PHONY : src/Model/CD.cpp.s

src/Model/Model.o: src/Model/Model.cpp.o
.PHONY : src/Model/Model.o

# target to build an object file
src/Model/Model.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/Model.cpp.o
.PHONY : src/Model/Model.cpp.o

src/Model/Model.i: src/Model/Model.cpp.i
.PHONY : src/Model/Model.i

# target to preprocess a source file
src/Model/Model.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/Model.cpp.i
.PHONY : src/Model/Model.cpp.i

src/Model/Model.s: src/Model/Model.cpp.s
.PHONY : src/Model/Model.s

# target to generate assembly for a file
src/Model/Model.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/Model.cpp.s
.PHONY : src/Model/Model.cpp.s

src/Model/MusicalComposition.o: src/Model/MusicalComposition.cpp.o
.PHONY : src/Model/MusicalComposition.o

# target to build an object file
src/Model/MusicalComposition.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/MusicalComposition.cpp.o
.PHONY : src/Model/MusicalComposition.cpp.o

src/Model/MusicalComposition.i: src/Model/MusicalComposition.cpp.i
.PHONY : src/Model/MusicalComposition.i

# target to preprocess a source file
src/Model/MusicalComposition.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/MusicalComposition.cpp.i
.PHONY : src/Model/MusicalComposition.cpp.i

src/Model/MusicalComposition.s: src/Model/MusicalComposition.cpp.s
.PHONY : src/Model/MusicalComposition.s

# target to generate assembly for a file
src/Model/MusicalComposition.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/MusicalComposition.cpp.s
.PHONY : src/Model/MusicalComposition.cpp.s

src/Model/Operation.o: src/Model/Operation.cpp.o
.PHONY : src/Model/Operation.o

# target to build an object file
src/Model/Operation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/Operation.cpp.o
.PHONY : src/Model/Operation.cpp.o

src/Model/Operation.i: src/Model/Operation.cpp.i
.PHONY : src/Model/Operation.i

# target to preprocess a source file
src/Model/Operation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/Operation.cpp.i
.PHONY : src/Model/Operation.cpp.i

src/Model/Operation.s: src/Model/Operation.cpp.s
.PHONY : src/Model/Operation.s

# target to generate assembly for a file
src/Model/Operation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/Operation.cpp.s
.PHONY : src/Model/Operation.cpp.s

src/Model/User.o: src/Model/User.cpp.o
.PHONY : src/Model/User.o

# target to build an object file
src/Model/User.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/User.cpp.o
.PHONY : src/Model/User.cpp.o

src/Model/User.i: src/Model/User.cpp.i
.PHONY : src/Model/User.i

# target to preprocess a source file
src/Model/User.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/User.cpp.i
.PHONY : src/Model/User.cpp.i

src/Model/User.s: src/Model/User.cpp.s
.PHONY : src/Model/User.s

# target to generate assembly for a file
src/Model/User.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/Model/User.cpp.s
.PHONY : src/Model/User.cpp.s

src/View/command.o: src/View/command.cpp.o
.PHONY : src/View/command.o

# target to build an object file
src/View/command.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/View/command.cpp.o
.PHONY : src/View/command.cpp.o

src/View/command.i: src/View/command.cpp.i
.PHONY : src/View/command.i

# target to preprocess a source file
src/View/command.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/View/command.cpp.i
.PHONY : src/View/command.cpp.i

src/View/command.s: src/View/command.cpp.s
.PHONY : src/View/command.s

# target to generate assembly for a file
src/View/command.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/View/command.cpp.s
.PHONY : src/View/command.cpp.s

src/View/view.o: src/View/view.cpp.o
.PHONY : src/View/view.o

# target to build an object file
src/View/view.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/View/view.cpp.o
.PHONY : src/View/view.cpp.o

src/View/view.i: src/View/view.cpp.i
.PHONY : src/View/view.i

# target to preprocess a source file
src/View/view.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/View/view.cpp.i
.PHONY : src/View/view.cpp.i

src/View/view.s: src/View/view.cpp.s
.PHONY : src/View/view.s

# target to generate assembly for a file
src/View/view.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/solution.dir/build.make CMakeFiles/solution.dir/src/View/view.cpp.s
.PHONY : src/View/view.cpp.s

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
	@echo "... rebuild_cache"
	@echo "... SQLiteCpp_cpplint"
	@echo "... SQLiteCpp"
	@echo "... solution"
	@echo "... sqlite3"
	@echo "... MusicSalon.o"
	@echo "... MusicSalon.i"
	@echo "... MusicSalon.s"
	@echo "... src/Controller/controller.o"
	@echo "... src/Controller/controller.i"
	@echo "... src/Controller/controller.s"
	@echo "... src/Model/CD.o"
	@echo "... src/Model/CD.i"
	@echo "... src/Model/CD.s"
	@echo "... src/Model/Model.o"
	@echo "... src/Model/Model.i"
	@echo "... src/Model/Model.s"
	@echo "... src/Model/MusicalComposition.o"
	@echo "... src/Model/MusicalComposition.i"
	@echo "... src/Model/MusicalComposition.s"
	@echo "... src/Model/Operation.o"
	@echo "... src/Model/Operation.i"
	@echo "... src/Model/Operation.s"
	@echo "... src/Model/User.o"
	@echo "... src/Model/User.i"
	@echo "... src/Model/User.s"
	@echo "... src/View/command.o"
	@echo "... src/View/command.i"
	@echo "... src/View/command.s"
	@echo "... src/View/view.o"
	@echo "... src/View/view.i"
	@echo "... src/View/view.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
