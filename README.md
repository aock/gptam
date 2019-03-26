# GPTAM Fork
This real-time Visual SLAM application is a deep code modification of the brilliant original work by Klein and Murray , "Parallel Tracking and Mapping" (PTAM).

Read the Docs: [gptam](GPTAM.md)

# GPTAM
This fork makes some changes of code structure to use gptam as c++ library.

# Dependencies
- OpenGL
- Glut
- OpenCV

# Build
```console
foo@bar:~/gptam$ mkdir build
foo@bar:~/gptam/build$ cmake .. -DCMAKE_BUILD_TYPE=Release
foo@bar:~/gptam/build$ make
```

# Install
```console
foo@bar:~/gptam/build$ sudo make install
```

# Library Usage
Usage with CMake:
After installing the gptam library, add this to your CMakeLists.txt:
```
find_package(GPTAM REQUIRED)
include_directories(${GPTAM_INCLUDE_DIRS})

add_executable(your_executable
    main.cpp
)

target_link_libraries(your_executable
    ${GPTAM_LIBRARIES}
)
```

