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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ingvar/Documents/projects/Test_DB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ingvar/Documents/projects/Test_DB/build

# Include any dependencies generated for this target.
include CMakeFiles/include.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/include.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/include.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/include.dir/flags.make

CMakeFiles/include.dir/dbfunctions.c.o: CMakeFiles/include.dir/flags.make
CMakeFiles/include.dir/dbfunctions.c.o: ../dbfunctions.c
CMakeFiles/include.dir/dbfunctions.c.o: CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ingvar/Documents/projects/Test_DB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/include.dir/dbfunctions.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/include.dir/dbfunctions.c.o -MF CMakeFiles/include.dir/dbfunctions.c.o.d -o CMakeFiles/include.dir/dbfunctions.c.o -c /home/ingvar/Documents/projects/Test_DB/dbfunctions.c

CMakeFiles/include.dir/dbfunctions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/include.dir/dbfunctions.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ingvar/Documents/projects/Test_DB/dbfunctions.c > CMakeFiles/include.dir/dbfunctions.c.i

CMakeFiles/include.dir/dbfunctions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/include.dir/dbfunctions.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ingvar/Documents/projects/Test_DB/dbfunctions.c -o CMakeFiles/include.dir/dbfunctions.c.s

# Object files for target include
include_OBJECTS = \
"CMakeFiles/include.dir/dbfunctions.c.o"

# External object files for target include
include_EXTERNAL_OBJECTS =

libinclude.a: CMakeFiles/include.dir/dbfunctions.c.o
libinclude.a: CMakeFiles/include.dir/build.make
libinclude.a: CMakeFiles/include.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ingvar/Documents/projects/Test_DB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libinclude.a"
	$(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/include.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/include.dir/build: libinclude.a
.PHONY : CMakeFiles/include.dir/build

CMakeFiles/include.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean.cmake
.PHONY : CMakeFiles/include.dir/clean

CMakeFiles/include.dir/depend:
	cd /home/ingvar/Documents/projects/Test_DB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ingvar/Documents/projects/Test_DB /home/ingvar/Documents/projects/Test_DB /home/ingvar/Documents/projects/Test_DB/build /home/ingvar/Documents/projects/Test_DB/build /home/ingvar/Documents/projects/Test_DB/build/CMakeFiles/include.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/include.dir/depend

