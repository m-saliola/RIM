cmake_minimum_required(VERSION 3.10)
project(main)

if (APPLE)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

file(GLOB SRC_FILES
"${CMAKE_SOURCE_DIR}/source/*.cpp"
"${CMAKE_SOURCE_DIR}/source/*.c"
"${CMAKE_SOURCE_DIR}/source/vendor/**/*.cpp"
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

link_directories(${CMAKE_SOURCE_DIR}/lib)

find_library(GLFW_LIB NAMES glfw3 libglfw3 PATHS "${CMAKE_SOURCE_DIR}/lib" NO_DEFAULT_PATH)

target_include_directories(${PROJECT_NAME} PRIVATE include)

if (WIN32)
    if (GLFW_LIB)
        target_link_libraries(${PROJECT_NAME}
            ${GLFW_LIB}
            opengl32
            gdi32
        )
    else()
        target_link_libraries(${PROJECT_NAME}
            glfw3
            opengl32
            gdi32
        )
    endif()

    target_link_options(${PROJECT_NAME} PRIVATE
        -static-libstdc++
        -static-libgcc
    )
elseif (APPLE)
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} glfw ${OPENGL_LIBRARIES})
    find_package(glfw3 REQUIRED)
else()
    if(POLICY CMP0072)
        cmake_policy(SET CMP0072 NEW)
    endif()

    find_package(OpenGL REQUIRED)
    find_package(X11 REQUIRED)
    target_link_libraries(${PROJECT_NAME}
        glfw
        ${OPENGL_LIBRARIES}
        ${X11_LIBRARIES}
        pthread
        dl
    )
endif()
