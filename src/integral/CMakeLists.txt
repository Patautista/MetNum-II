cmake_minimum_required(VERSION 3.10)
project(Integrals VERSION 3.10)

include_directories(include)

add_library(${PROJECT_NAME}
    ./integral.cpp
    ./integral_gauss.cpp
    ./first_degree_integral_newtoncotes.cpp
    ./first_degree_integral_open_newtoncotes.cpp
    ./second_degree_integral_open_milnerule.cpp
    ./second_degree_integral_simpson_onethird.cpp
    ./second_degree_integral_gausschebyshev.cpp
    ./second_degree_integral_gausshermite.cpp
    ./second_degree_integral_gausslaguerre.cpp
    ./second_degree_integral_gausslegendre.cpp
    ./third_degree_integral_open_newtoncotes.cpp
    ./third_degree_integral_simpson_threeEighths.cpp
    ./third_degree_integral_gausschebyshev.cpp
    ./third_degree_integral_gausshermite.cpp
    ./third_degree_integral_gausslaguerre.cpp
    ./third_degree_integral_gausslegendre.cpp
)