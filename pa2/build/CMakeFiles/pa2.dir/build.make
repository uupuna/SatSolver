# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/q28zhang/q28zhang/new_pa2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/q28zhang/q28zhang/new_pa2/build

# Include any dependencies generated for this target.
include CMakeFiles/pa2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pa2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pa2.dir/flags.make

CMakeFiles/pa2.dir/pa2.cc.o: CMakeFiles/pa2.dir/flags.make
CMakeFiles/pa2.dir/pa2.cc.o: ../pa2.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/q28zhang/q28zhang/new_pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pa2.dir/pa2.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2.dir/pa2.cc.o -c /home/q28zhang/q28zhang/new_pa2/pa2.cc

CMakeFiles/pa2.dir/pa2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2.dir/pa2.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/q28zhang/q28zhang/new_pa2/pa2.cc > CMakeFiles/pa2.dir/pa2.cc.i

CMakeFiles/pa2.dir/pa2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2.dir/pa2.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/q28zhang/q28zhang/new_pa2/pa2.cc -o CMakeFiles/pa2.dir/pa2.cc.s

CMakeFiles/pa2.dir/parser.cc.o: CMakeFiles/pa2.dir/flags.make
CMakeFiles/pa2.dir/parser.cc.o: ../parser.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/q28zhang/q28zhang/new_pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pa2.dir/parser.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2.dir/parser.cc.o -c /home/q28zhang/q28zhang/new_pa2/parser.cc

CMakeFiles/pa2.dir/parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2.dir/parser.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/q28zhang/q28zhang/new_pa2/parser.cc > CMakeFiles/pa2.dir/parser.cc.i

CMakeFiles/pa2.dir/parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2.dir/parser.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/q28zhang/q28zhang/new_pa2/parser.cc -o CMakeFiles/pa2.dir/parser.cc.s

CMakeFiles/pa2.dir/tokenizer.cc.o: CMakeFiles/pa2.dir/flags.make
CMakeFiles/pa2.dir/tokenizer.cc.o: ../tokenizer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/q28zhang/q28zhang/new_pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pa2.dir/tokenizer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2.dir/tokenizer.cc.o -c /home/q28zhang/q28zhang/new_pa2/tokenizer.cc

CMakeFiles/pa2.dir/tokenizer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2.dir/tokenizer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/q28zhang/q28zhang/new_pa2/tokenizer.cc > CMakeFiles/pa2.dir/tokenizer.cc.i

CMakeFiles/pa2.dir/tokenizer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2.dir/tokenizer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/q28zhang/q28zhang/new_pa2/tokenizer.cc -o CMakeFiles/pa2.dir/tokenizer.cc.s

CMakeFiles/pa2.dir/tseitinTransformer.cc.o: CMakeFiles/pa2.dir/flags.make
CMakeFiles/pa2.dir/tseitinTransformer.cc.o: ../tseitinTransformer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/q28zhang/q28zhang/new_pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pa2.dir/tseitinTransformer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa2.dir/tseitinTransformer.cc.o -c /home/q28zhang/q28zhang/new_pa2/tseitinTransformer.cc

CMakeFiles/pa2.dir/tseitinTransformer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa2.dir/tseitinTransformer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/q28zhang/q28zhang/new_pa2/tseitinTransformer.cc > CMakeFiles/pa2.dir/tseitinTransformer.cc.i

CMakeFiles/pa2.dir/tseitinTransformer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa2.dir/tseitinTransformer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/q28zhang/q28zhang/new_pa2/tseitinTransformer.cc -o CMakeFiles/pa2.dir/tseitinTransformer.cc.s

# Object files for target pa2
pa2_OBJECTS = \
"CMakeFiles/pa2.dir/pa2.cc.o" \
"CMakeFiles/pa2.dir/parser.cc.o" \
"CMakeFiles/pa2.dir/tokenizer.cc.o" \
"CMakeFiles/pa2.dir/tseitinTransformer.cc.o"

# External object files for target pa2
pa2_EXTERNAL_OBJECTS =

pa2: CMakeFiles/pa2.dir/pa2.cc.o
pa2: CMakeFiles/pa2.dir/parser.cc.o
pa2: CMakeFiles/pa2.dir/tokenizer.cc.o
pa2: CMakeFiles/pa2.dir/tseitinTransformer.cc.o
pa2: CMakeFiles/pa2.dir/build.make
pa2: minisat/libminisat.a
pa2: /usr/lib/x86_64-linux-gnu/libz.so
pa2: CMakeFiles/pa2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/q28zhang/q28zhang/new_pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable pa2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pa2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pa2.dir/build: pa2

.PHONY : CMakeFiles/pa2.dir/build

CMakeFiles/pa2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pa2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pa2.dir/clean

CMakeFiles/pa2.dir/depend:
	cd /home/q28zhang/q28zhang/new_pa2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/q28zhang/q28zhang/new_pa2 /home/q28zhang/q28zhang/new_pa2 /home/q28zhang/q28zhang/new_pa2/build /home/q28zhang/q28zhang/new_pa2/build /home/q28zhang/q28zhang/new_pa2/build/CMakeFiles/pa2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pa2.dir/depend

