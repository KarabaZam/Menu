cmake_minimum_required(VERSION 3.10)

project(YourProjectName)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(GameMenu main.cpp GameMenu.cpp GameMenu.h)

target_link_libraries(GameMenu PRIVATE sfml-graphics sfml-audio)