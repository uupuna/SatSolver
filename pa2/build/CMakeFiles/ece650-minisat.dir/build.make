# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/q28zhang/q28zhang/new_pa2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/q28zhang/q28zhang/new_pa2/build

# Include any dependencies generated for this target.
include CMakeFiles/ece650-minisat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ece650-minisat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ece650-minisat.dir/flags.make

CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.o: CMakeFiles/ece650-minisat.dir/flags.make
CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.o: ../ece650-minisat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/q28zhang/q28zhang/new_pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.o -c /home/q28zhang/q28zhang/new_pa2/ece650-minisat.cpp

CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/q28zhang/q28zhang/new_pa2/ece650-minisat.cpp > CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.i

CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/q28zhang/q28zhang/new_pa2/ece650-minisat.cpp -o CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.s

# Object files for target ece650-minisat
ece650__minisat_OBJECTS = \
"CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.o"

# External object files for target ece650-minisat
ece650__minisat_EXTERNAL_OBJECTS =

ece650-minisat: CMakeFiles/ece650-minisat.dir/ece650-minisat.cpp.o
ece650-minisat: CMakeFiles/ece650-minisat.dir/build.make
ece650-minisat: minisat/libminisat.a
ece650-minisat: /usr/lib/x86_64-linux-gnu/libz.so
ece650-minisat: CMakeFiles/ece650-minisat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/q28zhang/q28zhang/new_pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ece650-minisat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ece650-minisat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ece650-minisat.dir/build: ece650-minisat

.PHONY : CMakeFiles/ece650-minisat.dir/build

CMakeFiles/ece650-minisat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ece650-minisat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ece650-minisat.dir/clean

CMakeFiles/ece650-minisat.dir/depend:
	cd /home/q28zhang/q28zhang/new_pa2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/q28zhang/q28zhang/new_pa2 /home/q28zhang/q28zhang/new_pa2 /home/q28zhang/q28zhang/new_pa2/build /home/q28zhang/q28zhang/new_pa2/build /home/q28zhang/q28zhang/new_pa2/build/CMakeFiles/ece650-minisat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ece650-minisat.dir/depend

