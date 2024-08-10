cmake_minimum_required(VERSION 3.10)
project(EigenvaluesEigenvectors VERSION 1.0)

include_directories(include)

add_library(${PROJECT_NAME}
    ./power_methods/power_methods.cpp
    ./power_methods/power_method.cpp
    ./power_methods/inverse_power_method.cpp
    ./power_methods/shifted_power_method.cpp
    ./power_methods/inverse_power_method_LU.cpp
    ./house_holder/house_holder.cpp
    ./jacobi_method/jacobi_method.cpp
    ./QR/qr_method.cpp
)