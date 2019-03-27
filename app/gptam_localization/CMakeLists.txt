
add_executable(gptam_localization
    main.cpp
    System.cpp
)

target_link_libraries(gptam_localization
    gptam_static
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${OpenCV_LIBS}
)
