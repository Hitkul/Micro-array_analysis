# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/hitkul/code_test/bio_final/linear_regression_module

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hitkul/code_test/bio_final/linear_regression_module

# Include any dependencies generated for this target.
include CMakeFiles/linear_regression.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linear_regression.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linear_regression.dir/flags.make

CMakeFiles/linear_regression.dir/linear_regression.cpp.o: CMakeFiles/linear_regression.dir/flags.make
CMakeFiles/linear_regression.dir/linear_regression.cpp.o: linear_regression.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hitkul/code_test/bio_final/linear_regression_module/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/linear_regression.dir/linear_regression.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/linear_regression.dir/linear_regression.cpp.o -c /home/hitkul/code_test/bio_final/linear_regression_module/linear_regression.cpp

CMakeFiles/linear_regression.dir/linear_regression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linear_regression.dir/linear_regression.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hitkul/code_test/bio_final/linear_regression_module/linear_regression.cpp > CMakeFiles/linear_regression.dir/linear_regression.cpp.i

CMakeFiles/linear_regression.dir/linear_regression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linear_regression.dir/linear_regression.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hitkul/code_test/bio_final/linear_regression_module/linear_regression.cpp -o CMakeFiles/linear_regression.dir/linear_regression.cpp.s

CMakeFiles/linear_regression.dir/linear_regression.cpp.o.requires:
.PHONY : CMakeFiles/linear_regression.dir/linear_regression.cpp.o.requires

CMakeFiles/linear_regression.dir/linear_regression.cpp.o.provides: CMakeFiles/linear_regression.dir/linear_regression.cpp.o.requires
	$(MAKE) -f CMakeFiles/linear_regression.dir/build.make CMakeFiles/linear_regression.dir/linear_regression.cpp.o.provides.build
.PHONY : CMakeFiles/linear_regression.dir/linear_regression.cpp.o.provides

CMakeFiles/linear_regression.dir/linear_regression.cpp.o.provides.build: CMakeFiles/linear_regression.dir/linear_regression.cpp.o

# Object files for target linear_regression
linear_regression_OBJECTS = \
"CMakeFiles/linear_regression.dir/linear_regression.cpp.o"

# External object files for target linear_regression
linear_regression_EXTERNAL_OBJECTS =

linear_regression: CMakeFiles/linear_regression.dir/linear_regression.cpp.o
linear_regression: CMakeFiles/linear_regression.dir/build.make
linear_regression: /usr/local/lib/libopencv_videostab.so.3.0.0
linear_regression: /usr/local/lib/libopencv_videoio.so.3.0.0
linear_regression: /usr/local/lib/libopencv_video.so.3.0.0
linear_regression: /usr/local/lib/libopencv_superres.so.3.0.0
linear_regression: /usr/local/lib/libopencv_stitching.so.3.0.0
linear_regression: /usr/local/lib/libopencv_shape.so.3.0.0
linear_regression: /usr/local/lib/libopencv_photo.so.3.0.0
linear_regression: /usr/local/lib/libopencv_objdetect.so.3.0.0
linear_regression: /usr/local/lib/libopencv_ml.so.3.0.0
linear_regression: /usr/local/lib/libopencv_imgproc.so.3.0.0
linear_regression: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
linear_regression: /usr/local/lib/libopencv_highgui.so.3.0.0
linear_regression: /usr/local/lib/libopencv_hal.a
linear_regression: /usr/local/lib/libopencv_flann.so.3.0.0
linear_regression: /usr/local/lib/libopencv_features2d.so.3.0.0
linear_regression: /usr/local/lib/libopencv_core.so.3.0.0
linear_regression: /usr/local/lib/libopencv_calib3d.so.3.0.0
linear_regression: /usr/local/lib/libopencv_features2d.so.3.0.0
linear_regression: /usr/local/lib/libopencv_ml.so.3.0.0
linear_regression: /usr/local/lib/libopencv_highgui.so.3.0.0
linear_regression: /usr/local/lib/libopencv_videoio.so.3.0.0
linear_regression: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
linear_regression: /usr/local/lib/libopencv_flann.so.3.0.0
linear_regression: /usr/local/lib/libopencv_video.so.3.0.0
linear_regression: /usr/local/lib/libopencv_imgproc.so.3.0.0
linear_regression: /usr/local/lib/libopencv_core.so.3.0.0
linear_regression: /usr/local/lib/libopencv_hal.a
linear_regression: /usr/lib/x86_64-linux-gnu/libGLU.so
linear_regression: /usr/lib/x86_64-linux-gnu/libGL.so
linear_regression: /usr/lib/x86_64-linux-gnu/libSM.so
linear_regression: /usr/lib/x86_64-linux-gnu/libICE.so
linear_regression: /usr/lib/x86_64-linux-gnu/libX11.so
linear_regression: /usr/lib/x86_64-linux-gnu/libXext.so
linear_regression: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
linear_regression: CMakeFiles/linear_regression.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable linear_regression"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linear_regression.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linear_regression.dir/build: linear_regression
.PHONY : CMakeFiles/linear_regression.dir/build

CMakeFiles/linear_regression.dir/requires: CMakeFiles/linear_regression.dir/linear_regression.cpp.o.requires
.PHONY : CMakeFiles/linear_regression.dir/requires

CMakeFiles/linear_regression.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linear_regression.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linear_regression.dir/clean

CMakeFiles/linear_regression.dir/depend:
	cd /home/hitkul/code_test/bio_final/linear_regression_module && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hitkul/code_test/bio_final/linear_regression_module /home/hitkul/code_test/bio_final/linear_regression_module /home/hitkul/code_test/bio_final/linear_regression_module /home/hitkul/code_test/bio_final/linear_regression_module /home/hitkul/code_test/bio_final/linear_regression_module/CMakeFiles/linear_regression.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linear_regression.dir/depend
