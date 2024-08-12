cmake_minimum_required(VERSION 3.10)
project(Visitor VERSION 1.0)

include_directories(include)

add_library(${PROJECT_NAME} ./visitor.cpp)