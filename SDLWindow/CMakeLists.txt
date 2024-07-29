cmake_minimum_required(VERSION 3.10)

project(SDLWindows)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(SDLWindows WIN32 	main.cpp  )

target_link_libraries(SDLWindows ${SDL2_LIBRARIES})
