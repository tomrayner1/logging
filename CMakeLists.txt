cmake_minimum_required(VERSION 3.12)

project(logging
  VERSION 1.0
  LANGUAGES CXX
  DESCRIPTION "Simple logging library"
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add_library(logging STATIC Logging.cpp Logging.h)