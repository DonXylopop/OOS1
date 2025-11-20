cmake_minimum_required(VERSION 3.28.0)
project(MathDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
aufgabe14
    main.cpp
)

target_sources(
aufgabe14
    PRIVATE
        FILE_SET CXX_MODULES FILES
            Employee.cpp
            Manager.cpp
            Worker.cpp
)