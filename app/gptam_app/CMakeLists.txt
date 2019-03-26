
add_executable(gptam_app
    main.cpp
    System.cpp
)

target_link_libraries(gptam_app
    gptam_static
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${OpenCV_LIBS}
)
