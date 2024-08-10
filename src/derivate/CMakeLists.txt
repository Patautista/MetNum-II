cmake_minimum_required(VERSION 3.10)
project(Derivates VERSION  1.0)

include_directories(include)

add_library(${PROJECT_NAME} 
    ./derivate.cpp 
    ./first_derivate_foraward_approach.cpp 
    ./first_derivate_backward_approach.cpp
    ./first_derivate_central_approach.cpp
    ./second_derivate_forward_approach.cpp
    ./second_derivate_backward_approach.cpp
    ./second_derivate_central_approach.cpp
    ./third_derivate_newton_approach.cpp
)