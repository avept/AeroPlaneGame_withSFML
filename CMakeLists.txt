cmake_minimum_required(VERSION 2.8)
project(sfml_app)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB Game.cpp)

add_executable(main ${SOURCE_EXE})
add_library(Game STATIC ${SOURCE_LIB})	

target_link_libraries(main Game sfml-graphics sfml-window sfml-system)	
