cmake_minimum_required(VERSION 3.20)
project(CPrimerExercise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/utf-8)
endif()

add_subdirectory(part_one)
add_subdirectory(part_two)
add_subdirectory(part_three)
add_subdirectory(part_four)
