cmake_minimum_required(VERSION 3.4)

project(GPTAM VERSION 1)

set(CMAKE_CXX_STANDARD 14)
set_property(GLOBAL PROPERTY USE_FOLDERS On)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(GNUInstallDirs)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


######################################
# The external reference directory (searching) for cmake
set(EXT_DIR ${CMAKE_SOURCE_DIR}/cmake )
list( APPEND CMAKE_MODULE_PATH
  ${EXT_DIR}
)

## find openCV
set( OpenCV_INCLUDE_DIRS
	"/usr/local/include/opencv"
	"/usr/local/include/opencv2"
)

set( OpenCV_LIBS
	"/usr/local/lib/libopencv_calib3d.so"
	"/usr/local/lib/libopencv_core.so"
	"/usr/local/lib/libopencv_features2d.so"
	"/usr/local/lib/libopencv_flann.so"
	"/usr/local/lib/libopencv_highgui.so"
	#"/usr/local/lib/libopencv_imgcodecs.so"
	"/usr/local/lib/libopencv_imgproc.so"
	"/usr/local/lib/libopencv_ml.so"
	"/usr/local/lib/libopencv_objdetect.so"
	"/usr/local/lib/libopencv_photo.so"
	#"/usr/local/lib/libopencv_shape.so"
	"/usr/local/lib/libopencv_stitching.so"
	"/usr/local/lib/libopencv_superres.so"
	"/usr/local/lib/libopencv_video.so"
	"/usr/local/lib/libopencv_videoio.so"
	"/usr/local/lib/libopencv_videostab.so"
)

set(OPENCV_FOUND True)

include_directories(${OpenCV_INCLUDE_DIRS})

## find OpenGL
find_package(OPENGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})



########## GPTAM LIBRARY  ###################
install(DIRECTORY include/gptam DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include_directories(include)
add_subdirectory(src/gptam)

########## GPTAM APP  ###################
add_subdirectory(app)