cmake_minimum_required(VERSION 3.7)

project(SDLWindows)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
INCLUDE_DIRECTORIES("includes")
INCLUDE_DIRECTORIES("assets")
# Se añade el directorio a la ruta de búsqueda del compilador de turno
FILE(GLOB MiProyecto_SRC "src/*.cpp")
FILE(GLOB MiProyecto_SRC "includes/*.h")
# FILE GLOB selecciona todos los archivos que cumplan la característica y los almacena en MiProyecto_SRC
# GLOB no es recursivo. Si lo necesitas, usa GLOB_RECURSE

add_custom_target(copy-runtime-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/Debug/assets
    DEPENDS ${MY_TARGET})

add_executable(SDL2Test WIN32 	main.cpp  
			      	src/Game.cpp
				includes/Game.h
				)

target_link_libraries(SDL2Test ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

