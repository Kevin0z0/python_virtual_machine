cmake_minimum_required(VERSION 3.17)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp main.cpp utils/ArrayList.cpp utils/ArrayList.hpp object/Object.cpp object/Object.hpp object/String.cpp object/String.hpp object/Integer.cpp object/Integer.hpp code/CodeObject.cpp code/CodeObject.hpp code/BinaryFileParser.cpp code/BinaryFileParser.hpp runtime/Interpreter.cpp runtime/Interpreter.hpp runtime/Universe.cpp runtime/Universe.hpp)