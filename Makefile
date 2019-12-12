# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Applications/CMake.app/Contents/bin/cmake-gui -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(CMAKE_COMMAND) -E cmake_progress_start /Users/macbook/Projects/SimpleRenderEngineProject/CMakeFiles /Users/macbook/Projects/SimpleRenderEngineProject/project/Pokeman/CMakeFiles/progress.marks
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f CMakeFiles/Makefile2 project/Pokeman/all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/macbook/Projects/SimpleRenderEngineProject/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f CMakeFiles/Makefile2 project/Pokeman/clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f CMakeFiles/Makefile2 project/Pokeman/preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f CMakeFiles/Makefile2 project/Pokeman/preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

# Convenience name for target.
project/Pokeman/CMakeFiles/Pokeman.dir/rule:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f CMakeFiles/Makefile2 project/Pokeman/CMakeFiles/Pokeman.dir/rule
.PHONY : project/Pokeman/CMakeFiles/Pokeman.dir/rule

# Convenience name for target.
Pokeman: project/Pokeman/CMakeFiles/Pokeman.dir/rule

.PHONY : Pokeman

# fast build rule for target.
Pokeman/fast:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/build
.PHONY : Pokeman/fast

BackgroundComponent.o: BackgroundComponent.cpp.o

.PHONY : BackgroundComponent.o

# target to build an object file
BackgroundComponent.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/BackgroundComponent.cpp.o
.PHONY : BackgroundComponent.cpp.o

BackgroundComponent.i: BackgroundComponent.cpp.i

.PHONY : BackgroundComponent.i

# target to preprocess a source file
BackgroundComponent.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/BackgroundComponent.cpp.i
.PHONY : BackgroundComponent.cpp.i

BackgroundComponent.s: BackgroundComponent.cpp.s

.PHONY : BackgroundComponent.s

# target to generate assembly for a file
BackgroundComponent.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/BackgroundComponent.cpp.s
.PHONY : BackgroundComponent.cpp.s

Box2DDebugDraw.o: Box2DDebugDraw.cpp.o

.PHONY : Box2DDebugDraw.o

# target to build an object file
Box2DDebugDraw.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Box2DDebugDraw.cpp.o
.PHONY : Box2DDebugDraw.cpp.o

Box2DDebugDraw.i: Box2DDebugDraw.cpp.i

.PHONY : Box2DDebugDraw.i

# target to preprocess a source file
Box2DDebugDraw.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Box2DDebugDraw.cpp.i
.PHONY : Box2DDebugDraw.cpp.i

Box2DDebugDraw.s: Box2DDebugDraw.cpp.s

.PHONY : Box2DDebugDraw.s

# target to generate assembly for a file
Box2DDebugDraw.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Box2DDebugDraw.cpp.s
.PHONY : Box2DDebugDraw.cpp.s

CameraController.o: CameraController.cpp.o

.PHONY : CameraController.o

# target to build an object file
CameraController.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/CameraController.cpp.o
.PHONY : CameraController.cpp.o

CameraController.i: CameraController.cpp.i

.PHONY : CameraController.i

# target to preprocess a source file
CameraController.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/CameraController.cpp.i
.PHONY : CameraController.cpp.i

CameraController.s: CameraController.cpp.s

.PHONY : CameraController.s

# target to generate assembly for a file
CameraController.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/CameraController.cpp.s
.PHONY : CameraController.cpp.s

Component.o: Component.cpp.o

.PHONY : Component.o

# target to build an object file
Component.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Component.cpp.o
.PHONY : Component.cpp.o

Component.i: Component.cpp.i

.PHONY : Component.i

# target to preprocess a source file
Component.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Component.cpp.i
.PHONY : Component.cpp.i

Component.s: Component.cpp.s

.PHONY : Component.s

# target to generate assembly for a file
Component.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Component.cpp.s
.PHONY : Component.cpp.s

Creature.o: Creature.cpp.o

.PHONY : Creature.o

# target to build an object file
Creature.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Creature.cpp.o
.PHONY : Creature.cpp.o

Creature.i: Creature.cpp.i

.PHONY : Creature.i

# target to preprocess a source file
Creature.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Creature.cpp.i
.PHONY : Creature.cpp.i

Creature.s: Creature.cpp.s

.PHONY : Creature.s

# target to generate assembly for a file
Creature.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Creature.cpp.s
.PHONY : Creature.cpp.s

GameObject.o: GameObject.cpp.o

.PHONY : GameObject.o

# target to build an object file
GameObject.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/GameObject.cpp.o
.PHONY : GameObject.cpp.o

GameObject.i: GameObject.cpp.i

.PHONY : GameObject.i

# target to preprocess a source file
GameObject.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/GameObject.cpp.i
.PHONY : GameObject.cpp.i

GameObject.s: GameObject.cpp.s

.PHONY : GameObject.s

# target to generate assembly for a file
GameObject.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/GameObject.cpp.s
.PHONY : GameObject.cpp.s

PhysicsComponent.o: PhysicsComponent.cpp.o

.PHONY : PhysicsComponent.o

# target to build an object file
PhysicsComponent.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/PhysicsComponent.cpp.o
.PHONY : PhysicsComponent.cpp.o

PhysicsComponent.i: PhysicsComponent.cpp.i

.PHONY : PhysicsComponent.i

# target to preprocess a source file
PhysicsComponent.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/PhysicsComponent.cpp.i
.PHONY : PhysicsComponent.cpp.i

PhysicsComponent.s: PhysicsComponent.cpp.s

.PHONY : PhysicsComponent.s

# target to generate assembly for a file
PhysicsComponent.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/PhysicsComponent.cpp.s
.PHONY : PhysicsComponent.cpp.s

PokemanGame.o: PokemanGame.cpp.o

.PHONY : PokemanGame.o

# target to build an object file
PokemanGame.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/PokemanGame.cpp.o
.PHONY : PokemanGame.cpp.o

PokemanGame.i: PokemanGame.cpp.i

.PHONY : PokemanGame.i

# target to preprocess a source file
PokemanGame.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/PokemanGame.cpp.i
.PHONY : PokemanGame.cpp.i

PokemanGame.s: PokemanGame.cpp.s

.PHONY : PokemanGame.s

# target to generate assembly for a file
PokemanGame.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/PokemanGame.cpp.s
.PHONY : PokemanGame.cpp.s

Projectile.o: Projectile.cpp.o

.PHONY : Projectile.o

# target to build an object file
Projectile.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Projectile.cpp.o
.PHONY : Projectile.cpp.o

Projectile.i: Projectile.cpp.i

.PHONY : Projectile.i

# target to preprocess a source file
Projectile.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Projectile.cpp.i
.PHONY : Projectile.cpp.i

Projectile.s: Projectile.cpp.s

.PHONY : Projectile.s

# target to generate assembly for a file
Projectile.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/Projectile.cpp.s
.PHONY : Projectile.cpp.s

SpriteAnimationComponent.o: SpriteAnimationComponent.cpp.o

.PHONY : SpriteAnimationComponent.o

# target to build an object file
SpriteAnimationComponent.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/SpriteAnimationComponent.cpp.o
.PHONY : SpriteAnimationComponent.cpp.o

SpriteAnimationComponent.i: SpriteAnimationComponent.cpp.i

.PHONY : SpriteAnimationComponent.i

# target to preprocess a source file
SpriteAnimationComponent.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/SpriteAnimationComponent.cpp.i
.PHONY : SpriteAnimationComponent.cpp.i

SpriteAnimationComponent.s: SpriteAnimationComponent.cpp.s

.PHONY : SpriteAnimationComponent.s

# target to generate assembly for a file
SpriteAnimationComponent.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/SpriteAnimationComponent.cpp.s
.PHONY : SpriteAnimationComponent.cpp.s

SpriteComponent.o: SpriteComponent.cpp.o

.PHONY : SpriteComponent.o

# target to build an object file
SpriteComponent.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/SpriteComponent.cpp.o
.PHONY : SpriteComponent.cpp.o

SpriteComponent.i: SpriteComponent.cpp.i

.PHONY : SpriteComponent.i

# target to preprocess a source file
SpriteComponent.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/SpriteComponent.cpp.i
.PHONY : SpriteComponent.cpp.i

SpriteComponent.s: SpriteComponent.cpp.s

.PHONY : SpriteComponent.s

# target to generate assembly for a file
SpriteComponent.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/SpriteComponent.cpp.s
.PHONY : SpriteComponent.cpp.s

TrainerController.o: TrainerController.cpp.o

.PHONY : TrainerController.o

# target to build an object file
TrainerController.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/TrainerController.cpp.o
.PHONY : TrainerController.cpp.o

TrainerController.i: TrainerController.cpp.i

.PHONY : TrainerController.i

# target to preprocess a source file
TrainerController.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/TrainerController.cpp.i
.PHONY : TrainerController.cpp.i

TrainerController.s: TrainerController.cpp.s

.PHONY : TrainerController.s

# target to generate assembly for a file
TrainerController.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/TrainerController.cpp.s
.PHONY : TrainerController.cpp.s

WorldGenerator.o: WorldGenerator.cpp.o

.PHONY : WorldGenerator.o

# target to build an object file
WorldGenerator.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/WorldGenerator.cpp.o
.PHONY : WorldGenerator.cpp.o

WorldGenerator.i: WorldGenerator.cpp.i

.PHONY : WorldGenerator.i

# target to preprocess a source file
WorldGenerator.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/WorldGenerator.cpp.i
.PHONY : WorldGenerator.cpp.i

WorldGenerator.s: WorldGenerator.cpp.s

.PHONY : WorldGenerator.s

# target to generate assembly for a file
WorldGenerator.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/WorldGenerator.cpp.s
.PHONY : WorldGenerator.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(MAKE) -f project/Pokeman/CMakeFiles/Pokeman.dir/build.make project/Pokeman/CMakeFiles/Pokeman.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Pokeman"
	@echo "... BackgroundComponent.o"
	@echo "... BackgroundComponent.i"
	@echo "... BackgroundComponent.s"
	@echo "... Box2DDebugDraw.o"
	@echo "... Box2DDebugDraw.i"
	@echo "... Box2DDebugDraw.s"
	@echo "... CameraController.o"
	@echo "... CameraController.i"
	@echo "... CameraController.s"
	@echo "... Component.o"
	@echo "... Component.i"
	@echo "... Component.s"
	@echo "... Creature.o"
	@echo "... Creature.i"
	@echo "... Creature.s"
	@echo "... GameObject.o"
	@echo "... GameObject.i"
	@echo "... GameObject.s"
	@echo "... PhysicsComponent.o"
	@echo "... PhysicsComponent.i"
	@echo "... PhysicsComponent.s"
	@echo "... PokemanGame.o"
	@echo "... PokemanGame.i"
	@echo "... PokemanGame.s"
	@echo "... Projectile.o"
	@echo "... Projectile.i"
	@echo "... Projectile.s"
	@echo "... SpriteAnimationComponent.o"
	@echo "... SpriteAnimationComponent.i"
	@echo "... SpriteAnimationComponent.s"
	@echo "... SpriteComponent.o"
	@echo "... SpriteComponent.i"
	@echo "... SpriteComponent.s"
	@echo "... TrainerController.o"
	@echo "... TrainerController.i"
	@echo "... TrainerController.s"
	@echo "... WorldGenerator.o"
	@echo "... WorldGenerator.i"
	@echo "... WorldGenerator.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	cd /Users/macbook/Projects/SimpleRenderEngineProject && $(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

