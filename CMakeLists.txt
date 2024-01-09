cmake_minimum_required(VERSION 3.17)
project(learn_3dzavr)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# include 3dzavr engine into our project
add_subdirectory(engine)
link_libraries(3DEngine)

add_executable(TEST_SCENE test_scene.cpp)
add_executable(LESSON_1 lesson1.cpp)
add_executable(LESSON_2 lesson2.cpp)
add_executable(LESSON_3 lesson3.cpp)
add_executable(LESSON_4 lesson4.cpp)
add_executable(LESSON_5 lesson5.cpp)
add_executable(LESSON_6 lesson6.cpp)
add_executable(LESSON_7 lesson7.cpp)
add_executable(LESSON_8 lesson8.cpp)
add_executable(LESSON_10
        lesson10/lesson10.cpp
        lesson10/Client.h
        lesson10/Client.cpp
        lesson10/Server.h
        lesson10/Server.cpp)
