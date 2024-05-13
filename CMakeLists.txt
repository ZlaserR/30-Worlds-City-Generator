cmake_minimum_required(VERSION 3.26)
project(30_Worlds_City_Generator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(30_Worlds_City_Generator
        main.cpp
        City.h
        City.cpp
        District.cpp
        District.h
        Culture.cpp
        Culture.h
        NotableLocation.cpp
        NotableLocation.h
        NPC.cpp
        NPC.h
        NameGenerator.cpp
        NameGenerator.h
        )
