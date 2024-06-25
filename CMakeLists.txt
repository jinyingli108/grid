cmake_minimum_required (VERSION 3.29)

project("grid")

# Language settings.
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build configuration settings.
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

# Compiler warning settings.
if(MSVC)
    add_compile_options("/Wall")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic")
endif()

add_subdirectory("grid_static")
