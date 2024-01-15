# CMake version check
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(monopoly VERSION 1.0)

#Language standard VERSION
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-O2")

include_directories(include)

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES
	src/main.cpp
	src/Player.cpp
	src/LateralBox.cpp
	src/AngularBox.cpp
	src/GameBoard.cpp
	src/Game.cpp
	src/Log.cpp
)


# Add executable target with source files listed in SOURCE_FILES variable
add_executable(monopoly ${SOURCE_FILES})

