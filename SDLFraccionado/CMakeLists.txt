cmake_minimum_required(VERSION 3.10)

project(SDLFraccionado)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
INCLUDE_DIRECTORIES("includes")
# Se añade el directorio a la ruta de búsqueda del compilador de turno
FILE(GLOB MiProyecto_SRC "src/*.cpp")
FILE(GLOB MiProyecto_SRC "includes/*.h")
# FILE GLOB selecciona todos los archivos que cumplan la característica y los almacena en MiProyecto_SRC
# GLOB no es recursivo. Si lo necesitas, usa GLOB_RECURSE

add_executable(SDLFraccionado WIN32 	main.cpp  
			      	src/Game.cpp
				includes/Game.h
			      	
				)

target_link_libraries(SDLFraccionado ${SDL2_LIBRARIES})
