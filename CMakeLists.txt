cmake_minimum_required(VERSION 3.10)
project(NumericalMethods VERSION 1.0)

include_directories(include)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/derivate)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/context_class)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/visitor)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/integral)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/matrix)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/eigenvalues_eingenvectors)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/IPV)


add_executable(${PROJECT_NAME} ./main.cpp)

target_link_libraries(${PROJECT_NAME} Derivates Context Visitor Integrals Matrix EigenvaluesEigenvectors Ipv)