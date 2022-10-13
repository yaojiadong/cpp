project(adapter)

add_library(adapter test_adapter.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR})