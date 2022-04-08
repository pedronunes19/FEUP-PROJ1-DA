cmake_minimum_required(VERSION 3.20)
project(DA_PROJ_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(project main.cpp include/menu.h src/menu.cpp include/Company.h src/Company.cpp include/Delivery.h src/Delivery.cpp)