# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/aleksey/MAI/CLion/clion-2021.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/aleksey/MAI/CLion/clion-2021.1.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aleksey/MAI/DA/exam/SecondTreap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aleksey/MAI/DA/exam/SecondTreap/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SecondTreap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SecondTreap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SecondTreap.dir/flags.make

CMakeFiles/SecondTreap.dir/main.cpp.o: CMakeFiles/SecondTreap.dir/flags.make
CMakeFiles/SecondTreap.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aleksey/MAI/DA/exam/SecondTreap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SecondTreap.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SecondTreap.dir/main.cpp.o -c /home/aleksey/MAI/DA/exam/SecondTreap/main.cpp

CMakeFiles/SecondTreap.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SecondTreap.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aleksey/MAI/DA/exam/SecondTreap/main.cpp > CMakeFiles/SecondTreap.dir/main.cpp.i

CMakeFiles/SecondTreap.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SecondTreap.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aleksey/MAI/DA/exam/SecondTreap/main.cpp -o CMakeFiles/SecondTreap.dir/main.cpp.s

# Object files for target SecondTreap
SecondTreap_OBJECTS = \
"CMakeFiles/SecondTreap.dir/main.cpp.o"

# External object files for target SecondTreap
SecondTreap_EXTERNAL_OBJECTS =

SecondTreap: CMakeFiles/SecondTreap.dir/main.cpp.o
SecondTreap: CMakeFiles/SecondTreap.dir/build.make
SecondTreap: CMakeFiles/SecondTreap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aleksey/MAI/DA/exam/SecondTreap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SecondTreap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SecondTreap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SecondTreap.dir/build: SecondTreap

.PHONY : CMakeFiles/SecondTreap.dir/build

CMakeFiles/SecondTreap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SecondTreap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SecondTreap.dir/clean

CMakeFiles/SecondTreap.dir/depend:
	cd /home/aleksey/MAI/DA/exam/SecondTreap/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aleksey/MAI/DA/exam/SecondTreap /home/aleksey/MAI/DA/exam/SecondTreap /home/aleksey/MAI/DA/exam/SecondTreap/cmake-build-debug /home/aleksey/MAI/DA/exam/SecondTreap/cmake-build-debug /home/aleksey/MAI/DA/exam/SecondTreap/cmake-build-debug/CMakeFiles/SecondTreap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SecondTreap.dir/depend

