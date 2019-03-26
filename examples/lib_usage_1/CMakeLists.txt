cmake_minimum_required(VERSION 3.4)

project(gptamLibraryUsage1)

set(CMAKE_CXX_STANDARD 14)

find_package(GPTAM REQUIRED)

if(GPTAM_FOUND)
    message(STATUS "gptam library found!")
    message(STATUS "gptam include dirs: ${GPTAM_INCLUDE_DIRS}" )
    message(STATUS "gptam libraries: ${GPTAM_LIBRARIES}" )
    message(STATUS "gptam definitions: ${GPTAM_DEFINITIONS}")
endif()
include_directories(${GPTAM_INCLUDE_DIRS})

add_executable(gptam_app_example
    app/main.cpp
    app/System.cpp
)

target_link_libraries(gptam_app_example
    ${GPTAM_LIBRARIES}
)
