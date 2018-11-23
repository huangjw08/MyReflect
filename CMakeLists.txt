cmake_minimum_required(VERSION 3.12)
project(MyReflect)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyReflect main.cpp Singleton.h ClassFactory.cpp ClassFactory.h Item.h FileItem.cpp FileItem.h ConsoleItem.cpp ConsoleItem.h)