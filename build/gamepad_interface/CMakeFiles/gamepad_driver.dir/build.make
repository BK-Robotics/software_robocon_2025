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
CMAKE_SOURCE_DIR = /home/ddon/software_robocon_2025/gamepad_interface

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ddon/software_robocon_2025/build/gamepad_interface

# Include any dependencies generated for this target.
include CMakeFiles/gamepad_driver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gamepad_driver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gamepad_driver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gamepad_driver.dir/flags.make

CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.o: CMakeFiles/gamepad_driver.dir/flags.make
CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.o: /home/ddon/software_robocon_2025/gamepad_interface/src/gamepad.cpp
CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.o: CMakeFiles/gamepad_driver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ddon/software_robocon_2025/build/gamepad_interface/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.o -MF CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.o.d -o CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.o -c /home/ddon/software_robocon_2025/gamepad_interface/src/gamepad.cpp

CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ddon/software_robocon_2025/gamepad_interface/src/gamepad.cpp > CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.i

CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ddon/software_robocon_2025/gamepad_interface/src/gamepad.cpp -o CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.s

# Object files for target gamepad_driver
gamepad_driver_OBJECTS = \
"CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.o"

# External object files for target gamepad_driver
gamepad_driver_EXTERNAL_OBJECTS =

libgamepad_driver.a: CMakeFiles/gamepad_driver.dir/src/gamepad.cpp.o
libgamepad_driver.a: CMakeFiles/gamepad_driver.dir/build.make
libgamepad_driver.a: CMakeFiles/gamepad_driver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ddon/software_robocon_2025/build/gamepad_interface/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgamepad_driver.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gamepad_driver.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gamepad_driver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gamepad_driver.dir/build: libgamepad_driver.a
.PHONY : CMakeFiles/gamepad_driver.dir/build

CMakeFiles/gamepad_driver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gamepad_driver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gamepad_driver.dir/clean

CMakeFiles/gamepad_driver.dir/depend:
	cd /home/ddon/software_robocon_2025/build/gamepad_interface && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ddon/software_robocon_2025/gamepad_interface /home/ddon/software_robocon_2025/gamepad_interface /home/ddon/software_robocon_2025/build/gamepad_interface /home/ddon/software_robocon_2025/build/gamepad_interface /home/ddon/software_robocon_2025/build/gamepad_interface/CMakeFiles/gamepad_driver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gamepad_driver.dir/depend

