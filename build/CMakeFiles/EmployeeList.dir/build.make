# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\build

# Include any dependencies generated for this target.
include CMakeFiles/EmployeeList.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/EmployeeList.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/EmployeeList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EmployeeList.dir/flags.make

CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.obj: CMakeFiles/EmployeeList.dir/flags.make
CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.obj: CMakeFiles/EmployeeList.dir/includes_CXX.rsp
CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.obj: D:/HCMUS_Development/Projects/DSAP_Lab/Project_Final/src/EmployeeList.cpp
CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.obj: CMakeFiles/EmployeeList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.obj -MF CMakeFiles\EmployeeList.dir\src\EmployeeList.cpp.obj.d -o CMakeFiles\EmployeeList.dir\src\EmployeeList.cpp.obj -c D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\EmployeeList.cpp

CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\EmployeeList.cpp > CMakeFiles\EmployeeList.dir\src\EmployeeList.cpp.i

CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\EmployeeList.cpp -o CMakeFiles\EmployeeList.dir\src\EmployeeList.cpp.s

CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.obj: CMakeFiles/EmployeeList.dir/flags.make
CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.obj: CMakeFiles/EmployeeList.dir/includes_CXX.rsp
CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.obj: D:/HCMUS_Development/Projects/DSAP_Lab/Project_Final/src/FileHandler.cpp
CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.obj: CMakeFiles/EmployeeList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.obj -MF CMakeFiles\EmployeeList.dir\src\FileHandler.cpp.obj.d -o CMakeFiles\EmployeeList.dir\src\FileHandler.cpp.obj -c D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\FileHandler.cpp

CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\FileHandler.cpp > CMakeFiles\EmployeeList.dir\src\FileHandler.cpp.i

CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\FileHandler.cpp -o CMakeFiles\EmployeeList.dir\src\FileHandler.cpp.s

CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.obj: CMakeFiles/EmployeeList.dir/flags.make
CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.obj: CMakeFiles/EmployeeList.dir/includes_CXX.rsp
CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.obj: D:/HCMUS_Development/Projects/DSAP_Lab/Project_Final/src/UserInterface.cpp
CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.obj: CMakeFiles/EmployeeList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.obj -MF CMakeFiles\EmployeeList.dir\src\UserInterface.cpp.obj.d -o CMakeFiles\EmployeeList.dir\src\UserInterface.cpp.obj -c D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\UserInterface.cpp

CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\UserInterface.cpp > CMakeFiles\EmployeeList.dir\src\UserInterface.cpp.i

CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\UserInterface.cpp -o CMakeFiles\EmployeeList.dir\src\UserInterface.cpp.s

CMakeFiles/EmployeeList.dir/src/main.cpp.obj: CMakeFiles/EmployeeList.dir/flags.make
CMakeFiles/EmployeeList.dir/src/main.cpp.obj: CMakeFiles/EmployeeList.dir/includes_CXX.rsp
CMakeFiles/EmployeeList.dir/src/main.cpp.obj: D:/HCMUS_Development/Projects/DSAP_Lab/Project_Final/src/main.cpp
CMakeFiles/EmployeeList.dir/src/main.cpp.obj: CMakeFiles/EmployeeList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/EmployeeList.dir/src/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EmployeeList.dir/src/main.cpp.obj -MF CMakeFiles\EmployeeList.dir\src\main.cpp.obj.d -o CMakeFiles\EmployeeList.dir\src\main.cpp.obj -c D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\main.cpp

CMakeFiles/EmployeeList.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EmployeeList.dir/src/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\main.cpp > CMakeFiles\EmployeeList.dir\src\main.cpp.i

CMakeFiles/EmployeeList.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EmployeeList.dir/src/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\src\main.cpp -o CMakeFiles\EmployeeList.dir\src\main.cpp.s

# Object files for target EmployeeList
EmployeeList_OBJECTS = \
"CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.obj" \
"CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.obj" \
"CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.obj" \
"CMakeFiles/EmployeeList.dir/src/main.cpp.obj"

# External object files for target EmployeeList
EmployeeList_EXTERNAL_OBJECTS =

EmployeeList.exe: CMakeFiles/EmployeeList.dir/src/EmployeeList.cpp.obj
EmployeeList.exe: CMakeFiles/EmployeeList.dir/src/FileHandler.cpp.obj
EmployeeList.exe: CMakeFiles/EmployeeList.dir/src/UserInterface.cpp.obj
EmployeeList.exe: CMakeFiles/EmployeeList.dir/src/main.cpp.obj
EmployeeList.exe: CMakeFiles/EmployeeList.dir/build.make
EmployeeList.exe: CMakeFiles/EmployeeList.dir/linkLibs.rsp
EmployeeList.exe: CMakeFiles/EmployeeList.dir/objects1.rsp
EmployeeList.exe: CMakeFiles/EmployeeList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable EmployeeList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\EmployeeList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EmployeeList.dir/build: EmployeeList.exe
.PHONY : CMakeFiles/EmployeeList.dir/build

CMakeFiles/EmployeeList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\EmployeeList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/EmployeeList.dir/clean

CMakeFiles/EmployeeList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\build D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\build D:\HCMUS_Development\Projects\DSAP_Lab\Project_Final\build\CMakeFiles\EmployeeList.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/EmployeeList.dir/depend

