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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macbook/Projects/SimpleRenderEngineProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macbook/Projects/SimpleRenderEngineProject

# Include any dependencies generated for this target.
include project/Pokeman/CMakeFiles/PokemanProject.dir/depend.make

# Include the progress variables for this target.
include project/Pokeman/CMakeFiles/PokemanProject.dir/progress.make

# Include the compile flags for this target's objects.
include project/Pokeman/CMakeFiles/PokemanProject.dir/flags.make

project/Pokeman/CMakeFiles/PokemanProject.dir/Collidable.cpp.o: project/Pokeman/CMakeFiles/PokemanProject.dir/flags.make
project/Pokeman/CMakeFiles/PokemanProject.dir/Collidable.cpp.o: project/Pokeman/Collidable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macbook/Projects/SimpleRenderEngineProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object project/Pokeman/CMakeFiles/PokemanProject.dir/Collidable.cpp.o"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PokemanProject.dir/Collidable.cpp.o -c /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/Collidable.cpp

project/Pokeman/CMakeFiles/PokemanProject.dir/Collidable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PokemanProject.dir/Collidable.cpp.i"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/Collidable.cpp > CMakeFiles/PokemanProject.dir/Collidable.cpp.i

project/Pokeman/CMakeFiles/PokemanProject.dir/Collidable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PokemanProject.dir/Collidable.cpp.s"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/Collidable.cpp -o CMakeFiles/PokemanProject.dir/Collidable.cpp.s

project/Pokeman/CMakeFiles/PokemanProject.dir/GameObject.cpp.o: project/Pokeman/CMakeFiles/PokemanProject.dir/flags.make
project/Pokeman/CMakeFiles/PokemanProject.dir/GameObject.cpp.o: project/Pokeman/GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macbook/Projects/SimpleRenderEngineProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object project/Pokeman/CMakeFiles/PokemanProject.dir/GameObject.cpp.o"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PokemanProject.dir/GameObject.cpp.o -c /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/GameObject.cpp

project/Pokeman/CMakeFiles/PokemanProject.dir/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PokemanProject.dir/GameObject.cpp.i"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/GameObject.cpp > CMakeFiles/PokemanProject.dir/GameObject.cpp.i

project/Pokeman/CMakeFiles/PokemanProject.dir/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PokemanProject.dir/GameObject.cpp.s"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/GameObject.cpp -o CMakeFiles/PokemanProject.dir/GameObject.cpp.s

project/Pokeman/CMakeFiles/PokemanProject.dir/NPC.cpp.o: project/Pokeman/CMakeFiles/PokemanProject.dir/flags.make
project/Pokeman/CMakeFiles/PokemanProject.dir/NPC.cpp.o: project/Pokeman/NPC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macbook/Projects/SimpleRenderEngineProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object project/Pokeman/CMakeFiles/PokemanProject.dir/NPC.cpp.o"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PokemanProject.dir/NPC.cpp.o -c /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/NPC.cpp

project/Pokeman/CMakeFiles/PokemanProject.dir/NPC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PokemanProject.dir/NPC.cpp.i"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/NPC.cpp > CMakeFiles/PokemanProject.dir/NPC.cpp.i

project/Pokeman/CMakeFiles/PokemanProject.dir/NPC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PokemanProject.dir/NPC.cpp.s"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/NPC.cpp -o CMakeFiles/PokemanProject.dir/NPC.cpp.s

project/Pokeman/CMakeFiles/PokemanProject.dir/Player.cpp.o: project/Pokeman/CMakeFiles/PokemanProject.dir/flags.make
project/Pokeman/CMakeFiles/PokemanProject.dir/Player.cpp.o: project/Pokeman/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macbook/Projects/SimpleRenderEngineProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object project/Pokeman/CMakeFiles/PokemanProject.dir/Player.cpp.o"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PokemanProject.dir/Player.cpp.o -c /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/Player.cpp

project/Pokeman/CMakeFiles/PokemanProject.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PokemanProject.dir/Player.cpp.i"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/Player.cpp > CMakeFiles/PokemanProject.dir/Player.cpp.i

project/Pokeman/CMakeFiles/PokemanProject.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PokemanProject.dir/Player.cpp.s"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/Player.cpp -o CMakeFiles/PokemanProject.dir/Player.cpp.s

project/Pokeman/CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.o: project/Pokeman/CMakeFiles/PokemanProject.dir/flags.make
project/Pokeman/CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.o: project/Pokeman/PokemanGreen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macbook/Projects/SimpleRenderEngineProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object project/Pokeman/CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.o"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.o -c /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/PokemanGreen.cpp

project/Pokeman/CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.i"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/PokemanGreen.cpp > CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.i

project/Pokeman/CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.s"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/PokemanGreen.cpp -o CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.s

project/Pokeman/CMakeFiles/PokemanProject.dir/main.cpp.o: project/Pokeman/CMakeFiles/PokemanProject.dir/flags.make
project/Pokeman/CMakeFiles/PokemanProject.dir/main.cpp.o: project/Pokeman/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macbook/Projects/SimpleRenderEngineProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object project/Pokeman/CMakeFiles/PokemanProject.dir/main.cpp.o"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PokemanProject.dir/main.cpp.o -c /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/main.cpp

project/Pokeman/CMakeFiles/PokemanProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PokemanProject.dir/main.cpp.i"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/main.cpp > CMakeFiles/PokemanProject.dir/main.cpp.i

project/Pokeman/CMakeFiles/PokemanProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PokemanProject.dir/main.cpp.s"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/main.cpp -o CMakeFiles/PokemanProject.dir/main.cpp.s

# Object files for target PokemanProject
PokemanProject_OBJECTS = \
"CMakeFiles/PokemanProject.dir/Collidable.cpp.o" \
"CMakeFiles/PokemanProject.dir/GameObject.cpp.o" \
"CMakeFiles/PokemanProject.dir/NPC.cpp.o" \
"CMakeFiles/PokemanProject.dir/Player.cpp.o" \
"CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.o" \
"CMakeFiles/PokemanProject.dir/main.cpp.o"

# External object files for target PokemanProject
PokemanProject_EXTERNAL_OBJECTS =

project/Pokeman/PokemanProject: project/Pokeman/CMakeFiles/PokemanProject.dir/Collidable.cpp.o
project/Pokeman/PokemanProject: project/Pokeman/CMakeFiles/PokemanProject.dir/GameObject.cpp.o
project/Pokeman/PokemanProject: project/Pokeman/CMakeFiles/PokemanProject.dir/NPC.cpp.o
project/Pokeman/PokemanProject: project/Pokeman/CMakeFiles/PokemanProject.dir/Player.cpp.o
project/Pokeman/PokemanProject: project/Pokeman/CMakeFiles/PokemanProject.dir/PokemanGreen.cpp.o
project/Pokeman/PokemanProject: project/Pokeman/CMakeFiles/PokemanProject.dir/main.cpp.o
project/Pokeman/PokemanProject: project/Pokeman/CMakeFiles/PokemanProject.dir/build.make
project/Pokeman/PokemanProject: thirdparty/macOS/Lua/lib/liblua.a
project/Pokeman/PokemanProject: submodules/SimpleRenderEngine/src/libSRE.a
project/Pokeman/PokemanProject: thirdparty/macOS/Box2D/lib/libBox2D.a
project/Pokeman/PokemanProject: project/Pokeman/CMakeFiles/PokemanProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/macbook/Projects/SimpleRenderEngineProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable PokemanProject"
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PokemanProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
project/Pokeman/CMakeFiles/PokemanProject.dir/build: project/Pokeman/PokemanProject

.PHONY : project/Pokeman/CMakeFiles/PokemanProject.dir/build

project/Pokeman/CMakeFiles/PokemanProject.dir/clean:
	cd /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman && $(CMAKE_COMMAND) -P CMakeFiles/PokemanProject.dir/cmake_clean.cmake
.PHONY : project/Pokeman/CMakeFiles/PokemanProject.dir/clean

project/Pokeman/CMakeFiles/PokemanProject.dir/depend:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macbook/Projects/SimpleRenderEngineProject /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman /Users/macbook/Projects/SimpleRenderEngineProject /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/CMakeFiles/PokemanProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project/Pokeman/CMakeFiles/PokemanProject.dir/depend

