cmake_minimum_required(VERSION 3.30)
project(BugsProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(BugsProject
        src/Main.cpp
        src/Main.h
        src/LoadFile.cpp
        src/LoadFile.h
        src/SaveFile.cpp
        src/SaveFile.h
        src/Bug.cpp
        src/Bug.h
        src/Crawler.cpp
        src/Crawler.h
        src/Hopper.cpp
        src/Hopper.h)
