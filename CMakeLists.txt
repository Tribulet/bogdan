cmake_minimum_required(VERSION 3.0.0)
project(bogdan VERSION 0.1.0)
set(SOURCES
    src/field.cpp
    src/food.cpp
    src/position.cpp
    src/snake.cpp
    src/main.cpp
)

add_executable(bogdan ${SOURCES})

target_include_directories(bogdan
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)