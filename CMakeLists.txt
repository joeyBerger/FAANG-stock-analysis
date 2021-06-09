cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(FAANG-stock-analysis)

add_executable(FAANG-stock-analysis src/main.cpp src/stock.cpp src/raw_data.cpp src/strategies.cpp src/data_importer src/data_aggregator)
