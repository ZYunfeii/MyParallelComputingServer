# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/yunfei/MyProject/MyCGIServer/ComputingService

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yunfei/MyProject/MyCGIServer/ComputingService/build

# Include any dependencies generated for this target.
include CMakeFiles/ComputingSrv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ComputingSrv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ComputingSrv.dir/flags.make

CMakeFiles/ComputingSrv.dir/src/main.cpp.o: CMakeFiles/ComputingSrv.dir/flags.make
CMakeFiles/ComputingSrv.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yunfei/MyProject/MyCGIServer/ComputingService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ComputingSrv.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputingSrv.dir/src/main.cpp.o -c /home/yunfei/MyProject/MyCGIServer/ComputingService/src/main.cpp

CMakeFiles/ComputingSrv.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputingSrv.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yunfei/MyProject/MyCGIServer/ComputingService/src/main.cpp > CMakeFiles/ComputingSrv.dir/src/main.cpp.i

CMakeFiles/ComputingSrv.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputingSrv.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yunfei/MyProject/MyCGIServer/ComputingService/src/main.cpp -o CMakeFiles/ComputingSrv.dir/src/main.cpp.s

CMakeFiles/ComputingSrv.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/ComputingSrv.dir/src/main.cpp.o.requires

CMakeFiles/ComputingSrv.dir/src/main.cpp.o.provides: CMakeFiles/ComputingSrv.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ComputingSrv.dir/build.make CMakeFiles/ComputingSrv.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/ComputingSrv.dir/src/main.cpp.o.provides

CMakeFiles/ComputingSrv.dir/src/main.cpp.o.provides.build: CMakeFiles/ComputingSrv.dir/src/main.cpp.o


CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o: CMakeFiles/ComputingSrv.dir/flags.make
CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o: ../src/myinverse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yunfei/MyProject/MyCGIServer/ComputingService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o -c /home/yunfei/MyProject/MyCGIServer/ComputingService/src/myinverse.cpp

CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yunfei/MyProject/MyCGIServer/ComputingService/src/myinverse.cpp > CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.i

CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yunfei/MyProject/MyCGIServer/ComputingService/src/myinverse.cpp -o CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.s

CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o.requires:

.PHONY : CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o.requires

CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o.provides: CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o.requires
	$(MAKE) -f CMakeFiles/ComputingSrv.dir/build.make CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o.provides.build
.PHONY : CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o.provides

CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o.provides.build: CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o


CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o: CMakeFiles/ComputingSrv.dir/flags.make
CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o: ../src/myinverse_initialize.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yunfei/MyProject/MyCGIServer/ComputingService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o -c /home/yunfei/MyProject/MyCGIServer/ComputingService/src/myinverse_initialize.cpp

CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yunfei/MyProject/MyCGIServer/ComputingService/src/myinverse_initialize.cpp > CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.i

CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yunfei/MyProject/MyCGIServer/ComputingService/src/myinverse_initialize.cpp -o CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.s

CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o.requires:

.PHONY : CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o.requires

CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o.provides: CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o.requires
	$(MAKE) -f CMakeFiles/ComputingSrv.dir/build.make CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o.provides.build
.PHONY : CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o.provides

CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o.provides.build: CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o


CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o: CMakeFiles/ComputingSrv.dir/flags.make
CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o: ../src/myinverse_terminate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yunfei/MyProject/MyCGIServer/ComputingService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o -c /home/yunfei/MyProject/MyCGIServer/ComputingService/src/myinverse_terminate.cpp

CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yunfei/MyProject/MyCGIServer/ComputingService/src/myinverse_terminate.cpp > CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.i

CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yunfei/MyProject/MyCGIServer/ComputingService/src/myinverse_terminate.cpp -o CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.s

CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o.requires:

.PHONY : CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o.requires

CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o.provides: CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o.requires
	$(MAKE) -f CMakeFiles/ComputingSrv.dir/build.make CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o.provides.build
.PHONY : CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o.provides

CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o.provides.build: CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o


# Object files for target ComputingSrv
ComputingSrv_OBJECTS = \
"CMakeFiles/ComputingSrv.dir/src/main.cpp.o" \
"CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o" \
"CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o" \
"CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o"

# External object files for target ComputingSrv
ComputingSrv_EXTERNAL_OBJECTS =

ComputingSrv: CMakeFiles/ComputingSrv.dir/src/main.cpp.o
ComputingSrv: CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o
ComputingSrv: CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o
ComputingSrv: CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o
ComputingSrv: CMakeFiles/ComputingSrv.dir/build.make
ComputingSrv: CMakeFiles/ComputingSrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yunfei/MyProject/MyCGIServer/ComputingService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ComputingSrv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ComputingSrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ComputingSrv.dir/build: ComputingSrv

.PHONY : CMakeFiles/ComputingSrv.dir/build

CMakeFiles/ComputingSrv.dir/requires: CMakeFiles/ComputingSrv.dir/src/main.cpp.o.requires
CMakeFiles/ComputingSrv.dir/requires: CMakeFiles/ComputingSrv.dir/src/myinverse.cpp.o.requires
CMakeFiles/ComputingSrv.dir/requires: CMakeFiles/ComputingSrv.dir/src/myinverse_initialize.cpp.o.requires
CMakeFiles/ComputingSrv.dir/requires: CMakeFiles/ComputingSrv.dir/src/myinverse_terminate.cpp.o.requires

.PHONY : CMakeFiles/ComputingSrv.dir/requires

CMakeFiles/ComputingSrv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ComputingSrv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ComputingSrv.dir/clean

CMakeFiles/ComputingSrv.dir/depend:
	cd /home/yunfei/MyProject/MyCGIServer/ComputingService/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yunfei/MyProject/MyCGIServer/ComputingService /home/yunfei/MyProject/MyCGIServer/ComputingService /home/yunfei/MyProject/MyCGIServer/ComputingService/build /home/yunfei/MyProject/MyCGIServer/ComputingService/build /home/yunfei/MyProject/MyCGIServer/ComputingService/build/CMakeFiles/ComputingSrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ComputingSrv.dir/depend

