# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "D:\Program Files\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\zkw\Desktop\python_virtual_machine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/pyvm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pyvm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pyvm.dir/flags.make

CMakeFiles/pyvm.dir/main.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/main.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pyvm.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\main.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\main.cpp

CMakeFiles/pyvm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\main.cpp > CMakeFiles\pyvm.dir\main.cpp.i

CMakeFiles/pyvm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\main.cpp -o CMakeFiles\pyvm.dir\main.cpp.s

CMakeFiles/pyvm.dir/utils/ArrayList.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/utils/ArrayList.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/utils/ArrayList.cpp.obj: ../utils/ArrayList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pyvm.dir/utils/ArrayList.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\utils\ArrayList.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\utils\ArrayList.cpp

CMakeFiles/pyvm.dir/utils/ArrayList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/utils/ArrayList.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\utils\ArrayList.cpp > CMakeFiles\pyvm.dir\utils\ArrayList.cpp.i

CMakeFiles/pyvm.dir/utils/ArrayList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/utils/ArrayList.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\utils\ArrayList.cpp -o CMakeFiles\pyvm.dir\utils\ArrayList.cpp.s

CMakeFiles/pyvm.dir/object/Object.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/object/Object.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/object/Object.cpp.obj: ../object/Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pyvm.dir/object/Object.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\object\Object.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\object\Object.cpp

CMakeFiles/pyvm.dir/object/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/object/Object.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\object\Object.cpp > CMakeFiles\pyvm.dir\object\Object.cpp.i

CMakeFiles/pyvm.dir/object/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/object/Object.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\object\Object.cpp -o CMakeFiles\pyvm.dir\object\Object.cpp.s

CMakeFiles/pyvm.dir/object/String.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/object/String.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/object/String.cpp.obj: ../object/String.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pyvm.dir/object/String.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\object\String.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\object\String.cpp

CMakeFiles/pyvm.dir/object/String.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/object/String.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\object\String.cpp > CMakeFiles\pyvm.dir\object\String.cpp.i

CMakeFiles/pyvm.dir/object/String.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/object/String.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\object\String.cpp -o CMakeFiles\pyvm.dir\object\String.cpp.s

CMakeFiles/pyvm.dir/object/Integer.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/object/Integer.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/object/Integer.cpp.obj: ../object/Integer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pyvm.dir/object/Integer.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\object\Integer.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\object\Integer.cpp

CMakeFiles/pyvm.dir/object/Integer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/object/Integer.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\object\Integer.cpp > CMakeFiles\pyvm.dir\object\Integer.cpp.i

CMakeFiles/pyvm.dir/object/Integer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/object/Integer.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\object\Integer.cpp -o CMakeFiles\pyvm.dir\object\Integer.cpp.s

CMakeFiles/pyvm.dir/code/CodeObject.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/code/CodeObject.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/code/CodeObject.cpp.obj: ../code/CodeObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pyvm.dir/code/CodeObject.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\code\CodeObject.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\code\CodeObject.cpp

CMakeFiles/pyvm.dir/code/CodeObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/code/CodeObject.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\code\CodeObject.cpp > CMakeFiles\pyvm.dir\code\CodeObject.cpp.i

CMakeFiles/pyvm.dir/code/CodeObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/code/CodeObject.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\code\CodeObject.cpp -o CMakeFiles\pyvm.dir\code\CodeObject.cpp.s

CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.obj: ../code/BinaryFileParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\code\BinaryFileParser.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\code\BinaryFileParser.cpp

CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\code\BinaryFileParser.cpp > CMakeFiles\pyvm.dir\code\BinaryFileParser.cpp.i

CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\code\BinaryFileParser.cpp -o CMakeFiles\pyvm.dir\code\BinaryFileParser.cpp.s

CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.obj: ../runtime/Interpreter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\runtime\Interpreter.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\runtime\Interpreter.cpp

CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\runtime\Interpreter.cpp > CMakeFiles\pyvm.dir\runtime\Interpreter.cpp.i

CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\runtime\Interpreter.cpp -o CMakeFiles\pyvm.dir\runtime\Interpreter.cpp.s

CMakeFiles/pyvm.dir/runtime/Universe.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/runtime/Universe.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/runtime/Universe.cpp.obj: ../runtime/Universe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pyvm.dir/runtime/Universe.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\runtime\Universe.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\runtime\Universe.cpp

CMakeFiles/pyvm.dir/runtime/Universe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/runtime/Universe.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\runtime\Universe.cpp > CMakeFiles\pyvm.dir\runtime\Universe.cpp.i

CMakeFiles/pyvm.dir/runtime/Universe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/runtime/Universe.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\runtime\Universe.cpp -o CMakeFiles\pyvm.dir\runtime\Universe.cpp.s

CMakeFiles/pyvm.dir/utils/Map.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/utils/Map.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/utils/Map.cpp.obj: ../utils/Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/pyvm.dir/utils/Map.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\utils\Map.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\utils\Map.cpp

CMakeFiles/pyvm.dir/utils/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/utils/Map.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\utils\Map.cpp > CMakeFiles\pyvm.dir\utils\Map.cpp.i

CMakeFiles/pyvm.dir/utils/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/utils/Map.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\utils\Map.cpp -o CMakeFiles\pyvm.dir\utils\Map.cpp.s

CMakeFiles/pyvm.dir/object/Klass.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/object/Klass.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/object/Klass.cpp.obj: ../object/Klass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/pyvm.dir/object/Klass.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\object\Klass.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\object\Klass.cpp

CMakeFiles/pyvm.dir/object/Klass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/object/Klass.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\object\Klass.cpp > CMakeFiles\pyvm.dir\object\Klass.cpp.i

CMakeFiles/pyvm.dir/object/Klass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/object/Klass.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\object\Klass.cpp -o CMakeFiles\pyvm.dir\object\Klass.cpp.s

CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.obj: ../runtime/FrameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\runtime\FrameObject.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\runtime\FrameObject.cpp

CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\runtime\FrameObject.cpp > CMakeFiles\pyvm.dir\runtime\FrameObject.cpp.i

CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\runtime\FrameObject.cpp -o CMakeFiles\pyvm.dir\runtime\FrameObject.cpp.s

CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.obj: CMakeFiles/pyvm.dir/flags.make
CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.obj: CMakeFiles/pyvm.dir/includes_CXX.rsp
CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.obj: ../runtime/FunctionObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pyvm.dir\runtime\FunctionObject.cpp.obj -c C:\Users\zkw\Desktop\python_virtual_machine\runtime\FunctionObject.cpp

CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zkw\Desktop\python_virtual_machine\runtime\FunctionObject.cpp > CMakeFiles\pyvm.dir\runtime\FunctionObject.cpp.i

CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zkw\Desktop\python_virtual_machine\runtime\FunctionObject.cpp -o CMakeFiles\pyvm.dir\runtime\FunctionObject.cpp.s

# Object files for target pyvm
pyvm_OBJECTS = \
"CMakeFiles/pyvm.dir/main.cpp.obj" \
"CMakeFiles/pyvm.dir/utils/ArrayList.cpp.obj" \
"CMakeFiles/pyvm.dir/object/Object.cpp.obj" \
"CMakeFiles/pyvm.dir/object/String.cpp.obj" \
"CMakeFiles/pyvm.dir/object/Integer.cpp.obj" \
"CMakeFiles/pyvm.dir/code/CodeObject.cpp.obj" \
"CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.obj" \
"CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.obj" \
"CMakeFiles/pyvm.dir/runtime/Universe.cpp.obj" \
"CMakeFiles/pyvm.dir/utils/Map.cpp.obj" \
"CMakeFiles/pyvm.dir/object/Klass.cpp.obj" \
"CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.obj" \
"CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.obj"

# External object files for target pyvm
pyvm_EXTERNAL_OBJECTS =

pyvm.exe: CMakeFiles/pyvm.dir/main.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/utils/ArrayList.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/object/Object.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/object/String.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/object/Integer.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/code/CodeObject.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/code/BinaryFileParser.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/runtime/Interpreter.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/runtime/Universe.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/utils/Map.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/object/Klass.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/runtime/FrameObject.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/runtime/FunctionObject.cpp.obj
pyvm.exe: CMakeFiles/pyvm.dir/build.make
pyvm.exe: CMakeFiles/pyvm.dir/linklibs.rsp
pyvm.exe: CMakeFiles/pyvm.dir/objects1.rsp
pyvm.exe: CMakeFiles/pyvm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable pyvm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pyvm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pyvm.dir/build: pyvm.exe

.PHONY : CMakeFiles/pyvm.dir/build

CMakeFiles/pyvm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pyvm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pyvm.dir/clean

CMakeFiles/pyvm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\zkw\Desktop\python_virtual_machine C:\Users\zkw\Desktop\python_virtual_machine C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage C:\Users\zkw\Desktop\python_virtual_machine\cmake-build-debug-coverage\CMakeFiles\pyvm.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pyvm.dir/depend

