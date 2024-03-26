cmake_minimum_required(VERSION 3.22.1)

project(game-animation)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_NAME "executable")

add_subdirectory(external/glfw)
add_subdirectory(external/glm)

add_executable(${EXECUTABLE_NAME}
    external/glad/src/glad.c

    src/window/window.cpp
    src/tool/logger.cpp

    app/main.cpp
)

target_include_directories(${EXECUTABLE_NAME}
    
    PRIVATE external/glfw/include
    PRIVATE external/glm
    PRIVATE external/glad/include

    PRIVATE src/include

    PRIVATE src/window/include
    PRIVATE src/tool/include
)

target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE glfw
)