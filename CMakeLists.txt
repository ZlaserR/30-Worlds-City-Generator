cmake_minimum_required(VERSION 3.26)
project(30_Worlds_City_Generator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(30_Worlds_City_Generator
        Culture.cpp
        Culture.h
        main.cpp
        NameGenerator.cpp
        NameGenerator.h
        NPC.cpp
        NPC.h)
