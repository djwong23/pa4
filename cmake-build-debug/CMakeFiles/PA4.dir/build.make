# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\djwon\Desktop\CS\PA4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\djwon\Desktop\CS\PA4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PA4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PA4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PA4.dir/flags.make

CMakeFiles/PA4.dir/main.c.obj: CMakeFiles/PA4.dir/flags.make
CMakeFiles/PA4.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\djwon\Desktop\CS\PA4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PA4.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PA4.dir\main.c.obj   -c C:\Users\djwon\Desktop\CS\PA4\main.c

CMakeFiles/PA4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PA4.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\djwon\Desktop\CS\PA4\main.c > CMakeFiles\PA4.dir\main.c.i

CMakeFiles/PA4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PA4.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\djwon\Desktop\CS\PA4\main.c -o CMakeFiles\PA4.dir\main.c.s

# Object files for target PA4
PA4_OBJECTS = \
"CMakeFiles/PA4.dir/main.c.obj"

# External object files for target PA4
PA4_EXTERNAL_OBJECTS =

PA4.exe: CMakeFiles/PA4.dir/main.c.obj
PA4.exe: CMakeFiles/PA4.dir/build.make
PA4.exe: CMakeFiles/PA4.dir/linklibs.rsp
PA4.exe: CMakeFiles/PA4.dir/objects1.rsp
PA4.exe: CMakeFiles/PA4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\djwon\Desktop\CS\PA4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PA4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PA4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PA4.dir/build: PA4.exe

.PHONY : CMakeFiles/PA4.dir/build

CMakeFiles/PA4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PA4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PA4.dir/clean

CMakeFiles/PA4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\djwon\Desktop\CS\PA4 C:\Users\djwon\Desktop\CS\PA4 C:\Users\djwon\Desktop\CS\PA4\cmake-build-debug C:\Users\djwon\Desktop\CS\PA4\cmake-build-debug C:\Users\djwon\Desktop\CS\PA4\cmake-build-debug\CMakeFiles\PA4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PA4.dir/depend

