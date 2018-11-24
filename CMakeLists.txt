cmake_minimum_required(VERSION 3.12)
project(MyReflect)


set(CMAKE_CXX_STANDARD 14)

aux_source_directory(Item Item)

add_executable(MyReflect main.cpp Singleton.h ClassFactory.cpp ClassFactory.h ${Item})

target_link_libraries(MyReflect glog)

