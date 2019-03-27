cmake_minimum_required(VERSION 3.4)

project(GPTAM VERSION 1)

set(CMAKE_CXX_STANDARD 14)
set_property(GLOBAL PROPERTY USE_FOLDERS On)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(GNUInstallDirs)


add_compile_options(-fmessage-length=0 -fPIC -Wno-deprecated)

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
add_subdirectory(app/gptam_app)
add_subdirectory(app/gptam_camera_calibrator)
add_subdirectory(app/gptam_localization)


########## CMAKE FILES #################
#####################################################

install(EXPORT gptamTargets
    FILE gptamTargets.cmake
    NAMESPACE gptam::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/gptam)

include(CMakePackageConfigHelpers)
set(INCLUDE_INSTALL_DIR include/)
set(LIB_INSTALL_DIR lib/)
set(SYSCONFIG_INSTALL_DIR etc/gptam/)

configure_package_config_file(GPTAMConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/GPTAMConfig.cmake
  INSTALL_DESTINATION ${LIB_INSTALL_DIR}/cmake/gptam
  PATH_VARS INCLUDE_INSTALL_DIR SYSCONFIG_INSTALL_DIR
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/GPTAMConfigVersion.cmake
  COMPATIBILITY SameMajorVersion
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/GPTAMConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/GPTAMConfigVersion.cmake
              DESTINATION ${LIB_INSTALL_DIR}/cmake/gptam )

# install(FILES
#     CMakeModules/FindEigen3.cmake
#     CMakeModules/FindNabo.cmake
#     CMakeModules/FindSTANN.cmake
#     DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lvr2/Modules)
