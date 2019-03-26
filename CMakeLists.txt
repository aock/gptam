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
list( APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(OpenCV REQUIRED)
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