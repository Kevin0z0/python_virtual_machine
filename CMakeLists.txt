cmake_minimum_required(VERSION 3.17)
project(pyvm)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        pyvm main.cpp
        utils/ArrayList.cpp
        utils/ArrayList.hpp
        object/Object.cpp
        object/Object.hpp
        object/String.cpp
        object/String.hpp
        object/Integer.cpp
        object/Integer.hpp
        code/CodeObject.cpp
        code/CodeObject.hpp
        code/BinaryFileParser.cpp
        code/BinaryFileParser.hpp
        runtime/Interpreter.cpp
        runtime/Interpreter.hpp
        runtime/Universe.cpp
        runtime/Universe.hpp
        utils/Map.cpp
        utils/Map.hpp
        object/Klass.cpp 
        object/Klass.hpp 
        object/String.cpp 
        object/String.hpp 
        runtime/FrameObject.cpp 
        runtime/FrameObject.hpp 
        runtime/FunctionObject.cpp 
        runtime/FunctionObject.hpp utils/Print.cpp utils/Print.hpp object/List.cpp object/List.hpp)

include_directories(./)