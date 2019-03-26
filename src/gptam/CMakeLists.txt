

set(GPTAM_SOURCES
    ARDriver.cpp
    ATANCamera.cpp
    Bundle.cpp
    CalibCornerPatch.cpp
    CalibImage.cpp
    EssentialInit.cpp
    EyeGame.cpp
    GLWindow2.cpp
    GLWindowMenu.cpp
    HomographyInit.cpp
    KeyFrame.cpp
    Map.cpp
    MapMaker.cpp
    MapPoint.cpp
    MapViewer.cpp
    MiniPatch.cpp
    PatchFinder.cpp
    Relocaliser.cpp
    ShiTomasi.cpp
    SmallBlurryImage.cpp
    Tracker.cpp
    VideoSource.cpp

    FAST/fast_10_detect.cpp
    FAST/fast_10_score.cpp
    FAST/fast_11_detect.cpp
    FAST/fast_11_score.cpp
    FAST/fast_12_detect.cpp
    FAST/fast_12_score.cpp
    FAST/fast_7_detect.cpp
    FAST/fast_7_score.cpp
    FAST/fast_8_detect.cpp
    FAST/fast_8_score.cpp
    FAST/fast_9_detect.cpp
    FAST/fast_9_score.cpp
    FAST/fast_corner.cpp
    FAST/nonmax_suppression.cpp

    GCVD/GLText.cpp
    GCVD/GLWindow.cpp
    GCVD/timer.cpp

    Persistence/GStringUtil.cpp
    Persistence/GUI.cpp
    Persistence/GUI_impl_readline.cpp
    Persistence/GUI_language.cpp
    Persistence/GUI_readline.cpp
    Persistence/instances.cpp
    Persistence/PVars.cpp
    Persistence/serialize.cpp
)

set(GPTAM_LIB_DEPENDENCIES
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${OpenCV_LIBS}
    pthread
    m
    readline
)

add_library(gptamcore OBJECT ${GPTAM_SOURCES})

message(STATUS "Building static library")
add_library(gptam_static STATIC $<TARGET_OBJECTS:gptamcore>)
target_link_libraries(gptam_static
    ${GPTAM_LIB_DEPENDENCIES}
)
target_compile_definitions(gptam_static PRIVATE USE_XMMINTRIN=0)
set_property(TARGET gptam_static APPEND_STRING PROPERTY COMPILE_FLAGS "-D_LINUX -Wall -std=c++14 -march=native ")


# message(STATUS "Building shared library")
# add_library(gptam SHARED $<TARGET_OBJECTS:gptamcore>)
# target_link_libraries(gptam
#     ${GPTAM_LIB_DEPENDENCIES}
#     ${GL_LINKER_FLAGS}
#     ${PTHREAD_PROBLEM_LINKER_FLAGS}
# 	${GNU_READLINE_LINKER_FLAG}
# )

# target_compile_definitions(gptam PRIVATE USE_XMMINTRIN=0)
# set_property(TARGET gptam APPEND_STRING PROPERTY COMPILE_FLAGS "-D_LINUX -Wall -std=c++14 -march=native ")
# set_target_properties(gptam PROPERTIES LINK_FLAGS "-Wl,--version-script,exportmap")

install(TARGETS gptam_static
    EXPORT gptamTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)




