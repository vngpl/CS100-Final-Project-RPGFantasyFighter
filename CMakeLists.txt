cmake_minimum_required(VERSION 3.2)
project(final-project)

include_directories(header)

# file(GLOB SOURCES "src/*.cpp")

# add_executable(final_proj ${SOURCES})

add_executable(final_proj
    src/main.cpp
    src/Character.cpp
    src/Assassin.cpp
    src/Warrior.cpp
    src/Wizard.cpp
    src/Enemy.cpp
    src/Monster.cpp
    src/Inventory.cpp
    src/Item.cpp
    header/Display.hpp
    )