cmake_minimum_required(VERSION 3.12)

project(logging
  VERSION 1.0
  LANGUAGES CXX
  DESCRIPTION "Simple logging library"
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "Builds all tests" OFF)

add_library(logging STATIC logging.cpp logging.h)
target_include_directories(logging PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()