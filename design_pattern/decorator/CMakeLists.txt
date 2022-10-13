project(decorator)

add_library(decorator test_decorator.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR})