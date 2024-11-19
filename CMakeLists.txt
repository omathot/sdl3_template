set(SOURCE_FILES
    src/helloworld.cpp
    src/utils.cpp
)


cmake_minimum_required(VERSION 3.10)
project(hello_world VERSION 1.0)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS)
find_package(SDL3_image REQUIRED)

add_executable(hello_world ${SOURCE_FILES})
target_include_directories(hello_world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(hello_world PRIVATE SDL3::SDL3)
target_link_libraries(hello_world PRIVATE SDL3_image::SDL3_image)
