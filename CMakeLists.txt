set(SOURCE_FILES
    src/helloworld.cpp
    src/utils.cpp
    src/animations.cpp
    src/animation.cpp
    src/player.cpp
    src/appState.cpp
    src/vector2.cpp
    src/transform.cpp
)

cmake_minimum_required(VERSION 3.10)
project(hello_world VERSION 1.0)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS)

if(UNIX AND NOT APPLE)
  add_library(SDL3_image::SDL3_image SHARED IMPORTED)
  set_target_properties(SDL3_image::SDL3_image PROPERTIES
    IMPORTED_LOCATION "/usr/local/lib64/libSDL3_image.so"
    )
else ()
  find_package(SDL3_image REQUIRED)
endif()

add_executable(hello_world ${SOURCE_FILES})
target_include_directories(hello_world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(hello_world PRIVATE SDL3::SDL3)
target_link_libraries(hello_world PRIVATE SDL3_image::SDL3_image)
