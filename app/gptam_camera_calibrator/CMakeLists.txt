
add_executable(gcalibrator
    main.cpp
    CameraCalibrator.cpp
)

target_link_libraries(gcalibrator
    gptam_static
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${OpenCV_LIBS}
)