# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build

# Include any dependencies generated for this target.
include CMakeFiles/FAANG-stock-analysis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FAANG-stock-analysis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FAANG-stock-analysis.dir/flags.make

CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.o: CMakeFiles/FAANG-stock-analysis.dir/flags.make
CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.o -c /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/main.cpp

CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/main.cpp > CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.i

CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/main.cpp -o CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.s

CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.o: CMakeFiles/FAANG-stock-analysis.dir/flags.make
CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.o: ../src/stock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.o -c /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/stock.cpp

CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/stock.cpp > CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.i

CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/stock.cpp -o CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.s

CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.o: CMakeFiles/FAANG-stock-analysis.dir/flags.make
CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.o: ../src/raw_data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.o -c /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/raw_data.cpp

CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/raw_data.cpp > CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.i

CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/raw_data.cpp -o CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.s

CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.o: CMakeFiles/FAANG-stock-analysis.dir/flags.make
CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.o: ../src/strategies.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.o -c /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/strategies.cpp

CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/strategies.cpp > CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.i

CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/strategies.cpp -o CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.s

CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.o: CMakeFiles/FAANG-stock-analysis.dir/flags.make
CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.o: ../src/data_importer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.o -c /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/data_importer.cpp

CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/data_importer.cpp > CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.i

CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/data_importer.cpp -o CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.s

CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.o: CMakeFiles/FAANG-stock-analysis.dir/flags.make
CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.o: ../src/data_aggregator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.o -c /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/data_aggregator.cpp

CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/data_aggregator.cpp > CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.i

CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/data_aggregator.cpp -o CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.s

CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.o: CMakeFiles/FAANG-stock-analysis.dir/flags.make
CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.o: ../src/data_anaylzer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.o -c /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/data_anaylzer.cpp

CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/data_anaylzer.cpp > CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.i

CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/src/data_anaylzer.cpp -o CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.s

# Object files for target FAANG-stock-analysis
FAANG__stock__analysis_OBJECTS = \
"CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.o" \
"CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.o" \
"CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.o" \
"CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.o" \
"CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.o" \
"CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.o" \
"CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.o"

# External object files for target FAANG-stock-analysis
FAANG__stock__analysis_EXTERNAL_OBJECTS =

FAANG-stock-analysis: CMakeFiles/FAANG-stock-analysis.dir/src/main.cpp.o
FAANG-stock-analysis: CMakeFiles/FAANG-stock-analysis.dir/src/stock.cpp.o
FAANG-stock-analysis: CMakeFiles/FAANG-stock-analysis.dir/src/raw_data.cpp.o
FAANG-stock-analysis: CMakeFiles/FAANG-stock-analysis.dir/src/strategies.cpp.o
FAANG-stock-analysis: CMakeFiles/FAANG-stock-analysis.dir/src/data_importer.cpp.o
FAANG-stock-analysis: CMakeFiles/FAANG-stock-analysis.dir/src/data_aggregator.cpp.o
FAANG-stock-analysis: CMakeFiles/FAANG-stock-analysis.dir/src/data_anaylzer.cpp.o
FAANG-stock-analysis: CMakeFiles/FAANG-stock-analysis.dir/build.make
FAANG-stock-analysis: CMakeFiles/FAANG-stock-analysis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable FAANG-stock-analysis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FAANG-stock-analysis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FAANG-stock-analysis.dir/build: FAANG-stock-analysis

.PHONY : CMakeFiles/FAANG-stock-analysis.dir/build

CMakeFiles/FAANG-stock-analysis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FAANG-stock-analysis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FAANG-stock-analysis.dir/clean

CMakeFiles/FAANG-stock-analysis.dir/depend:
	cd /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build /Users/joeyberger/Documents/GitHub/FAANG-stock-analysis/build/CMakeFiles/FAANG-stock-analysis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FAANG-stock-analysis.dir/depend

