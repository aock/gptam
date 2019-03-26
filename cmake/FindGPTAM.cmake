###############################################################################
# Find gptam library
# 
# This sets the following variables:
# GPTAM_FOUND - True if gptam was found.
# GPTAM_INCLUDE_DIRS - Directories containing the GPTAM include files.
# GPTAM_LIBRARIES - Libraries needed to use GPTAM.
# 

find_package(PkgConfig QUIET)

find_path(GPTAM_INCLUDE_DIRS ATANCamera.h
        HINTS  /usr/local/include/gptam
)

message(STATUS "GPTAM include directory: ${GPTAM_INCLUDE_DIRS}")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GPTAM DEFAULT_MSG GPTAM_INCLUDE_DIRS)

