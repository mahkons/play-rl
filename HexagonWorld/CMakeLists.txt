cmake_minimum_required(VERSION 3.10) # Проверка версии CMake
project(HexagonWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Werror -pedantic")

set(SOURCES 
    src/hello_world.cpp
)

include_directories(inc/)

add_library(lworld STATIC ${SOURCES})
add_executable(world src/main.cpp)
target_link_libraries(world lworld)
