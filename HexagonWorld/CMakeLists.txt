cmake_minimum_required(VERSION 3.10) # Проверка версии CMake
project(HexagonWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Werror -pedantic")

set(SOURCES 
    src/hello_world.cpp
    src/env/hexagonal_map.cpp
    src/env/render/hexagonal_world_renderer.cpp
)

include_directories(inc/)
find_package(GLUT REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})

add_library(lworld STATIC ${SOURCES})
target_link_libraries(lworld ${GLUT_LIBRARIES} ${SDL2_LIBRARIES})

add_executable(world src/main.cpp)
target_link_libraries(world lworld)
