# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/perspectivecube.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/perspectivecube.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/perspectivecube.dir/flags.make

CMakeFiles/perspectivecube.dir/main.cpp.obj: CMakeFiles/perspectivecube.dir/flags.make
CMakeFiles/perspectivecube.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/perspectivecube.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\perspectivecube.dir\main.cpp.obj -c C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5\main.cpp

CMakeFiles/perspectivecube.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/perspectivecube.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5\main.cpp > CMakeFiles\perspectivecube.dir\main.cpp.i

CMakeFiles/perspectivecube.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/perspectivecube.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5\main.cpp -o CMakeFiles\perspectivecube.dir\main.cpp.s

# Object files for target perspectivecube
perspectivecube_OBJECTS = \
"CMakeFiles/perspectivecube.dir/main.cpp.obj"

# External object files for target perspectivecube
perspectivecube_EXTERNAL_OBJECTS =

perspectivecube.exe: CMakeFiles/perspectivecube.dir/main.cpp.obj
perspectivecube.exe: CMakeFiles/perspectivecube.dir/build.make
perspectivecube.exe: CMakeFiles/perspectivecube.dir/linklibs.rsp
perspectivecube.exe: CMakeFiles/perspectivecube.dir/objects1.rsp
perspectivecube.exe: CMakeFiles/perspectivecube.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable perspectivecube.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\perspectivecube.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/perspectivecube.dir/build: perspectivecube.exe
.PHONY : CMakeFiles/perspectivecube.dir/build

CMakeFiles/perspectivecube.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\perspectivecube.dir\cmake_clean.cmake
.PHONY : CMakeFiles/perspectivecube.dir/clean

CMakeFiles/perspectivecube.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5 C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5 C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5\cmake-build-debug C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5\cmake-build-debug C:\Users\ivopr\Desktop\git\unir\cg\aula-1\atv-5\cmake-build-debug\CMakeFiles\perspectivecube.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/perspectivecube.dir/depend
