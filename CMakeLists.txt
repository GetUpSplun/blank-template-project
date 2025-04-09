cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NAME_PROJECT game)

project(${NAME_PROJECT} VERSION 0.1)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(${NAME_PROJECT} ${SRC_FILES})

target_include_directories(${NAME_PROJECT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${NAME_PROJECT} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)
