# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/magjico/Bureau/Informatique_Graphique/Projet_M1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/magjico/Bureau/Informatique_Graphique/Projet_M1

# Include any dependencies generated for this target.
include Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/compiler_depend.make

# Include the progress variables for this target.
include Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/progress.make

# Include the compile flags for this target's objects.
include Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/flags.make

Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/tearing.c.o: Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/flags.make
Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/tearing.c.o: Libs/glfw-3.3.4/tests/tearing.c
Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/tearing.c.o: Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/magjico/Bureau/Informatique_Graphique/Projet_M1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/tearing.c.o"
	cd /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/tearing.c.o -MF CMakeFiles/tearing.dir/tearing.c.o.d -o CMakeFiles/tearing.dir/tearing.c.o -c /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests/tearing.c

Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/tearing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/tearing.c.i"
	cd /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests/tearing.c > CMakeFiles/tearing.dir/tearing.c.i

Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/tearing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/tearing.c.s"
	cd /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests/tearing.c -o CMakeFiles/tearing.dir/tearing.c.s

Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o: Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/flags.make
Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o: Libs/glfw-3.3.4/deps/glad_gl.c
Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o: Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/magjico/Bureau/Informatique_Graphique/Projet_M1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o"
	cd /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o -MF CMakeFiles/tearing.dir/__/deps/glad_gl.c.o.d -o CMakeFiles/tearing.dir/__/deps/glad_gl.c.o -c /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/deps/glad_gl.c

Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/__/deps/glad_gl.c.i"
	cd /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/deps/glad_gl.c > CMakeFiles/tearing.dir/__/deps/glad_gl.c.i

Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/__/deps/glad_gl.c.s"
	cd /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/deps/glad_gl.c -o CMakeFiles/tearing.dir/__/deps/glad_gl.c.s

# Object files for target tearing
tearing_OBJECTS = \
"CMakeFiles/tearing.dir/tearing.c.o" \
"CMakeFiles/tearing.dir/__/deps/glad_gl.c.o"

# External object files for target tearing
tearing_EXTERNAL_OBJECTS =

Libs/glfw-3.3.4/tests/tearing: Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/tearing.c.o
Libs/glfw-3.3.4/tests/tearing: Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o
Libs/glfw-3.3.4/tests/tearing: Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/build.make
Libs/glfw-3.3.4/tests/tearing: Libs/glfw-3.3.4/src/libglfw3.a
Libs/glfw-3.3.4/tests/tearing: /usr/lib/x86_64-linux-gnu/libm.so
Libs/glfw-3.3.4/tests/tearing: /usr/lib/x86_64-linux-gnu/librt.so
Libs/glfw-3.3.4/tests/tearing: /usr/lib/x86_64-linux-gnu/libm.so
Libs/glfw-3.3.4/tests/tearing: /usr/lib/x86_64-linux-gnu/libX11.so
Libs/glfw-3.3.4/tests/tearing: Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/magjico/Bureau/Informatique_Graphique/Projet_M1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable tearing"
	cd /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tearing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/build: Libs/glfw-3.3.4/tests/tearing
.PHONY : Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/build

Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/clean:
	cd /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests && $(CMAKE_COMMAND) -P CMakeFiles/tearing.dir/cmake_clean.cmake
.PHONY : Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/clean

Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/depend:
	cd /home/magjico/Bureau/Informatique_Graphique/Projet_M1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/magjico/Bureau/Informatique_Graphique/Projet_M1 /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests /home/magjico/Bureau/Informatique_Graphique/Projet_M1 /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests /home/magjico/Bureau/Informatique_Graphique/Projet_M1/Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Libs/glfw-3.3.4/tests/CMakeFiles/tearing.dir/depend

