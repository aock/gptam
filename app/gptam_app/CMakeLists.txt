
add_executable(gptam
    main.cpp
)

target_link_libraries(gptam
    gptam_static
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${OpenCV_LIBS}
)
