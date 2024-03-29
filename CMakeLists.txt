cmake_minimum_required(VERSION 3.10)

project(Ursidae VERSION 1.0 DESCRIPTION "CSV shared lib")


# set compiler and flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set(SOURCES
    src/ursidae.cpp
    src/main.cpp
)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif()



option(BUILD_SHARED_LIB "Specifies whether to build Shared Library" OFF)
option(BUILD_DOCUMENTATION "Specifies whether to build the documentation for the API" OFF )


if (BUILD_SHARED_LIB)
   add_library(Ursidae SHARED
    src/ursidae.cpp)
else()
   add_library(Ursidae STATIC
    src/ursidae.cpp)
endif()

if(BUILD_DOCUMENTATION)
    add_subdirectory(docs)
endif()



target_include_directories(Ursidae
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)


