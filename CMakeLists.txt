cmake_minimum_required(VERSION 3.24)

add_subdirectory(design_pattern)

project(main)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE decorator adapter)

