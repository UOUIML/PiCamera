# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/pi/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/server/build

# Include any dependencies generated for this target.
include CMakeFiles/servernogui.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/servernogui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/servernogui.dir/flags.make

CMakeFiles/servernogui.dir/main.cpp.o: CMakeFiles/servernogui.dir/flags.make
CMakeFiles/servernogui.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/servernogui.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servernogui.dir/main.cpp.o -c /home/pi/server/main.cpp

CMakeFiles/servernogui.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servernogui.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/server/main.cpp > CMakeFiles/servernogui.dir/main.cpp.i

CMakeFiles/servernogui.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servernogui.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/server/main.cpp -o CMakeFiles/servernogui.dir/main.cpp.s

CMakeFiles/servernogui.dir/MyServer.cpp.o: CMakeFiles/servernogui.dir/flags.make
CMakeFiles/servernogui.dir/MyServer.cpp.o: ../MyServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/servernogui.dir/MyServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servernogui.dir/MyServer.cpp.o -c /home/pi/server/MyServer.cpp

CMakeFiles/servernogui.dir/MyServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servernogui.dir/MyServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/server/MyServer.cpp > CMakeFiles/servernogui.dir/MyServer.cpp.i

CMakeFiles/servernogui.dir/MyServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servernogui.dir/MyServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/server/MyServer.cpp -o CMakeFiles/servernogui.dir/MyServer.cpp.s

CMakeFiles/servernogui.dir/MyThread.cpp.o: CMakeFiles/servernogui.dir/flags.make
CMakeFiles/servernogui.dir/MyThread.cpp.o: ../MyThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/servernogui.dir/MyThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servernogui.dir/MyThread.cpp.o -c /home/pi/server/MyThread.cpp

CMakeFiles/servernogui.dir/MyThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servernogui.dir/MyThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/server/MyThread.cpp > CMakeFiles/servernogui.dir/MyThread.cpp.i

CMakeFiles/servernogui.dir/MyThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servernogui.dir/MyThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/server/MyThread.cpp -o CMakeFiles/servernogui.dir/MyThread.cpp.s

CMakeFiles/servernogui.dir/sensor.cpp.o: CMakeFiles/servernogui.dir/flags.make
CMakeFiles/servernogui.dir/sensor.cpp.o: ../sensor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/servernogui.dir/sensor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servernogui.dir/sensor.cpp.o -c /home/pi/server/sensor.cpp

CMakeFiles/servernogui.dir/sensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servernogui.dir/sensor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/server/sensor.cpp > CMakeFiles/servernogui.dir/sensor.cpp.i

CMakeFiles/servernogui.dir/sensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servernogui.dir/sensor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/server/sensor.cpp -o CMakeFiles/servernogui.dir/sensor.cpp.s

CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.o: CMakeFiles/servernogui.dir/flags.make
CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.o: servernogui_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.o -c /home/pi/server/build/servernogui_autogen/mocs_compilation.cpp

CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/server/build/servernogui_autogen/mocs_compilation.cpp > CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.i

CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/server/build/servernogui_autogen/mocs_compilation.cpp -o CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.s

# Object files for target servernogui
servernogui_OBJECTS = \
"CMakeFiles/servernogui.dir/main.cpp.o" \
"CMakeFiles/servernogui.dir/MyServer.cpp.o" \
"CMakeFiles/servernogui.dir/MyThread.cpp.o" \
"CMakeFiles/servernogui.dir/sensor.cpp.o" \
"CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.o"

# External object files for target servernogui
servernogui_EXTERNAL_OBJECTS =

servernogui: CMakeFiles/servernogui.dir/main.cpp.o
servernogui: CMakeFiles/servernogui.dir/MyServer.cpp.o
servernogui: CMakeFiles/servernogui.dir/MyThread.cpp.o
servernogui: CMakeFiles/servernogui.dir/sensor.cpp.o
servernogui: CMakeFiles/servernogui.dir/servernogui_autogen/mocs_compilation.cpp.o
servernogui: CMakeFiles/servernogui.dir/build.make
servernogui: /usr/lib/arm-linux-gnueabihf/libQt5Widgets.so.5.11.3
servernogui: /usr/lib/arm-linux-gnueabihf/libQt5SerialPort.so.5.11.3
servernogui: /usr/lib/arm-linux-gnueabihf/libQt5Network.so.5.11.3
servernogui: /usr/local/lib/libopencv_shape.so.3.2.0
servernogui: /usr/local/lib/libopencv_stitching.so.3.2.0
servernogui: /usr/local/lib/libopencv_superres.so.3.2.0
servernogui: /usr/local/lib/libopencv_videostab.so.3.2.0
servernogui: /usr/lib/arm-linux-gnueabihf/libQt5Gui.so.5.11.3
servernogui: /usr/lib/arm-linux-gnueabihf/libQt5Core.so.5.11.3
servernogui: /usr/local/lib/libopencv_objdetect.so.3.2.0
servernogui: /usr/local/lib/libopencv_calib3d.so.3.2.0
servernogui: /usr/local/lib/libopencv_features2d.so.3.2.0
servernogui: /usr/local/lib/libopencv_flann.so.3.2.0
servernogui: /usr/local/lib/libopencv_highgui.so.3.2.0
servernogui: /usr/local/lib/libopencv_ml.so.3.2.0
servernogui: /usr/local/lib/libopencv_photo.so.3.2.0
servernogui: /usr/local/lib/libopencv_video.so.3.2.0
servernogui: /usr/local/lib/libopencv_videoio.so.3.2.0
servernogui: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
servernogui: /usr/local/lib/libopencv_imgproc.so.3.2.0
servernogui: /usr/local/lib/libopencv_core.so.3.2.0
servernogui: CMakeFiles/servernogui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable servernogui"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/servernogui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/servernogui.dir/build: servernogui

.PHONY : CMakeFiles/servernogui.dir/build

CMakeFiles/servernogui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/servernogui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/servernogui.dir/clean

CMakeFiles/servernogui.dir/depend:
	cd /home/pi/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/server /home/pi/server /home/pi/server/build /home/pi/server/build /home/pi/server/build/CMakeFiles/servernogui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/servernogui.dir/depend

