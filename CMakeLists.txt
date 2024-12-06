# VARIABLES
set(SOURCE_FILES
    src/helloworld.cpp
    src/utils.cpp
    src/animations.cpp
    src/animation.cpp
    src/player.cpp
    src/appState.cpp
    src/transform.cpp
)

set(IMGUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/backends/imgui_impl_sdl3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/backends/imgui_impl_sdlrenderer3.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/backends/imgui_impl_metal.mm
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/misc/cpp/imgui_stdlib.cpp
)

# PROJECT
cmake_minimum_required(VERSION 3.10)
project(hello_world VERSION 1.0)

# COMPILATION AND FLAGS
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS)

# LINUX / APPLE
if(UNIX AND NOT APPLE)
  add_library(SDL3_image::SDL3_image SHARED IMPORTED)
  set_target_properties(SDL3_image::SDL3_image PROPERTIES
    IMPORTED_LOCATION "/usr/local/lib64/libSDL3_image.so"
    )
else ()
  find_package(SDL3_image REQUIRED)
  find_package(glm REQUIRED)
endif()

add_executable(hello_world ${SOURCE_FILES} ${IMGUI_SOURCES})

target_include_directories(hello_world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(hello_world PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/
  ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/backends/
  ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/misc/cpp/
)


target_link_libraries(hello_world PRIVATE SDL3::SDL3)
target_link_libraries(hello_world PRIVATE SDL3_image::SDL3_image)
target_link_libraries(hello_world PRIVATE /usr/local/lib/libSDL3_ttf.dylib) #find_package() doesn't find sdl3_ttf
target_link_libraries(hello_world PRIVATE glm::glm)
