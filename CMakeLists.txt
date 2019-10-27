cmake_minimum_required(VERSION 3.14)
project(citadel)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME citadel)


set(SOURCE_FILES main.cpp)

add_executable(citadel ${SOURCE_FILES} Tile.cpp Tile.h Game.cpp Game.h TextureManager.cpp TextureManager.h Map.cpp Map.h)
add_library(core ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

find_package(SFML 2 REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
