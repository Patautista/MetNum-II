cmake_minimum_required(VERSION 3.10)
project(Ipv VERSION 1.0)

include_directories(include)

add_library(${PROJECT_NAME} 
    ./ipv.cpp
    ./euler_method_explict.cpp
    ./euler_method_implict.cpp
    ./adams_bashforth_method_third_order.cpp
    ./adams_bashforth_method_second_order.cpp
    ./range_kutta_method_fourth_order.cpp
    ./range_kutta_method_third_order.cpp
    ./range_kutta_method_second_order.cpp
)